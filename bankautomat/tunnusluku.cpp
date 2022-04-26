#include "tunnusluku.h"
#include "ui_tunnusluku.h"
#include "valikko.h"


Tunnusluku::Tunnusluku(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tunnusluku)
{
    pinko = "";
    ui->setupUi(this);

    objectMyUrl = new MyUrl;
    base_url = objectMyUrl->getBase_url();
    tries = 3;
}

Tunnusluku::~Tunnusluku()
{
    delete ui;
    ui = nullptr;
    delete valikkoo;
    valikkoo = nullptr;
    delete objectMyUrl;
    objectMyUrl = nullptr;
}

void Tunnusluku::ResetPinWindow(){
    pinko = "";
    ui->Laatikko->setText("");
}

void Tunnusluku::on_pushButton_clicked()
{
    pinko.append("1");
    ui->Laatikko->setText(pinko); //aseta haluamasi numero laatikkoon
    emit ButtonPushed();
}

void Tunnusluku::on_pushButton_2_clicked()
{
    pinko.append("2");
    ui->Laatikko->setText(pinko);
    emit ButtonPushed();
}

void Tunnusluku::on_pushButton_3_clicked()
{
    pinko.append("3");
    ui->Laatikko->setText(pinko);
    emit ButtonPushed();
}

void Tunnusluku::on_pushButton_4_clicked()
{
    pinko.append("4");
    ui->Laatikko->setText(pinko);
    emit ButtonPushed();
}

void Tunnusluku::on_pushButton_5_clicked()
{
    pinko.append("5");
    ui->Laatikko->setText(pinko);
    emit ButtonPushed();
}
void Tunnusluku::on_pushButton_6_clicked()
{
    pinko.append("6");
    ui->Laatikko->setText(pinko);
    emit ButtonPushed();
}

void Tunnusluku::on_pushButton_7_clicked()
{
    pinko.append("7");
    ui->Laatikko->setText(pinko);
    emit ButtonPushed();
}

void Tunnusluku::on_pushButton_8_clicked()
{
    pinko.append("8");
    ui->Laatikko->setText(pinko);
    emit ButtonPushed();
}

void Tunnusluku::on_pushButton_9_clicked()
{
    pinko.append("9");
    ui->Laatikko->setText(pinko);
    emit ButtonPushed();
}

void Tunnusluku::on_pushButton_10_clicked()
{
    pinko.append("0");
    ui->Laatikko->setText(pinko);
    emit ButtonPushed();
}

void Tunnusluku::on_pushButton_11_clicked() //voit poistaa laatikkoon tulleet numerot
{
    //ui->Laatikko->setText("poista numero");
    ui->Laatikko->setText("");
    pinko = "";
    emit ButtonPushed();
}

void Tunnusluku::on_pushButton_12_clicked() //jos oikea pinkoodi ilmestyy laatikkoon niin sulje ja näytä seuraava kohta
{                                           //jos taas pin koodi on väärä niin ilmoita yritysten määrä kunnes viimeinen on käytetty sitten sulje automaatti
    if (pinko == ""){
        ui->Laatikko->setText("Syötä pin");
        emit ButtonPushed();
    }
    else
    {
        if(tries>0){
            emit Login();
            ui->Laatikko->setText("Connecting...");
            QJsonObject jsonObj;
            jsonObj.insert("username", "4258145576238597");
            jsonObj.insert("password", pinko);
            QNetworkRequest request((base_url+"/login"));
            request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

            loginManager = new QNetworkAccessManager(this);
            connect(loginManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(loginSlot(QNetworkReply*)));

            reply = loginManager->post(request,QJsonDocument(jsonObj).toJson());
        }
        else{
            ui->Laatikko->setText("Korttisi on lukittu.");
        }
        pinko = "";
    }

    /*
      if (pinko == "1234") {

        QMessageBox msgBox;
        msgBox.setText("pinkoodi oikein");
        msgBox.exec();

        valikkoo->show();
        this-> close();
       }

    else {
        QMessageBox msgBox;
        msgBox.setText("pinkoodi väärin, yritä uudestaan");
        msgBox.exec();
      }

    */

}


void Tunnusluku::loginSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<"DATA : "+response_data;
    if (response_data == "false")
    {
        tries--;
        if(tries>0){
            ui->Laatikko->setText("Väärä pin, "+QString::number(tries)+" yritystä jäljellä.");
        }
        else{
            ui->Laatikko->setText("Kortti lukittu, ota yhteyttä asiakaspalveluun");
        }
    }

    else{
        tries = 3;
        ui->Laatikko->setText("Logging in..");

        token = "Bearer "+response_data;
        name = "";
        balance = "";
        events = "";
        cardSerial = "4258145576238597";

        QNetworkRequest request((base_url+"/customers/"+cardSerial));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

        //WEBTOKEN AUTH
        request.setRawHeader(QByteArray("Authorization"), (token));
        //WEBTOKEN AUTH END
        loginManager->deleteLater();
        loginManager = new QNetworkAccessManager(this);
        connect(loginManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getCustomerSlot(QNetworkReply*)));

        reply = loginManager->get(request);
    }

    //QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    //QJsonArray json_array = json_doc.array();
}


void Tunnusluku::getCustomerSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<"DATA : "+response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    foreach (const QJsonValue &value, json_array) {
        QJsonObject json_obj = value.toObject();
        name+=json_obj["name"].toString();
    }
    qDebug()<<"name : "+name;

    QNetworkRequest request((base_url+"/accounts/"+cardSerial));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    //WEBTOKEN AUTH
    request.setRawHeader(QByteArray("Authorization"), (token));
    //WEBTOKEN AUTH END
    loginManager->deleteLater();
    loginManager = new QNetworkAccessManager(this);
    connect(loginManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getAccountSlot(QNetworkReply*)));

    reply = loginManager->get(request);


}

void Tunnusluku::getAccountSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<"DATA : "+response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    foreach (const QJsonValue &value, json_array) {
        QJsonObject json_obj = value.toObject();
        balance+=json_obj["balance"].toString();
    }
    qDebug()<<"balance : "+balance;

    QNetworkRequest request((base_url+"/events/"+cardSerial));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    //WEBTOKEN AUTH
    request.setRawHeader(QByteArray("Authorization"), (token));
    //WEBTOKEN AUTH END
    loginManager->deleteLater();
    loginManager = new QNetworkAccessManager(this);
    connect(loginManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getEventsSlot(QNetworkReply*)));

    reply = loginManager->get(request);
}


void Tunnusluku::getEventsSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<"DATA : "+response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    foreach (const QJsonValue &value, json_array) {
        QJsonObject json_obj = value.toObject();
        if(json_obj["eventType"].toString() == "nosto")
        {
            events+="-"+QString::number(json_obj["amount"].toInt())+"€, "+json_obj["eventType"].toString()+", "+json_obj["dateTime"].toString();
        }
        else if (json_obj["eventType"].toString() == "talletus")
        {
            events+="+"+QString::number(json_obj["amount"].toInt())+"€, "+json_obj["eventType"].toString()+", "+json_obj["dateTime"].toString();
        }
        events.chop(14);
        events+="\n";
    }
    qDebug()<<"events : "+events;

    valikkoo = new valikko(name, balance, events, cardSerial, token);
    valikkoo->show();
    this-> close();
}
