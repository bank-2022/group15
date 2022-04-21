#include "nosta_rahaa.h"
#include "ui_nosta_rahaa.h"



Nosta_rahaa::Nosta_rahaa(QString cardSerial, QString balance, QByteArray token, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Nosta_rahaa)
{
    cardSerial1 = cardSerial;
    balance1 = balance;
    token1 = token;
    ui->setupUi(this);
    lopeta = new Lopetus;
    connect(this, SIGNAL(withdrawal(int)), this, SLOT(withdrawEvent(int)));

    objectMyUrl = new MyUrl;
    base_url = objectMyUrl->getBase_url();
}

Nosta_rahaa::~Nosta_rahaa()
{
    delete ui;
    ui = nullptr;
    delete lopeta;
    lopeta = nullptr;
}

//void Nosta_rahaa::on_pushButton_clicked()
//{
//    QMessageBox msgBox;
//    msgBox.setText("Nostit 20€");
//    msgBox.exec();
//    lopeta->show();
//    this->close();


void Nosta_rahaa::on_btn20Withdraw_clicked()
{
    emit withdrawal(20);
}


void Nosta_rahaa::on_btn40Withdraw_clicked()
{
    emit withdrawal(40);
}


void Nosta_rahaa::on_btn80Withdraw_clicked()
{
    emit withdrawal(80);
}


void Nosta_rahaa::on_btn120Withdraw_clicked()
{
    emit withdrawal(120);
}


void Nosta_rahaa::on_btnCustomAmount_clicked()
{

}


void Nosta_rahaa::on_btnReturn_clicked()
{
    emit returning();
    this->hide();
}

void Nosta_rahaa::withdrawEvent(int n)
{
    if (balance1.toInt()<n)
    {
        QMessageBox msgBox;
        msgBox.setText("Kate ei riitä");
        msgBox.exec();

    }
    else {
        amount = n;
        QMessageBox msgBox;
        msgBox.setText("Nostetaan "+QString::number(n)+"€...");
        msgBox.exec();


        QJsonObject jsonObj;
        QNetworkRequest request((base_url+"/accounts/"+cardSerial1+"/withdraw/"+QString::number(n)));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

        //WEBTOKEN AUTH
        request.setRawHeader(QByteArray("Authorization"), (token1));
        //WEBTOKEN AUTH END
        loginManager = new QNetworkAccessManager(this);
        connect(loginManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(withdrawSlot(QNetworkReply*)));
        reply = loginManager->put(request, QJsonDocument(jsonObj).toJson());
    }
}

void Nosta_rahaa::withdrawSlot(QNetworkReply*)
{
    response_data=reply->readAll();
    qDebug()<<"DATA : "+response_data;
    if (response_data == "Withdrawn successfully")
    {
        QJsonObject jsonObj;
        jsonObj.insert("cardSerial", cardSerial1);
        jsonObj.insert("dateTime", qAika.currentDateTime().toString());
        jsonObj.insert("eventType", "nosto");
        jsonObj.insert("amount", QString::number(amount.toInt()));
        QNetworkRequest request((base_url+"/events/add"));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

        //WEBTOKEN AUTH
        request.setRawHeader(QByteArray("Authorization"), (token1));
        //WEBTOKEN AUTH END

        loginManager = new QNetworkAccessManager(this);
        connect(loginManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(withdrawFinishSlot(QNetworkReply*)));

        reply = loginManager->post(request,QJsonDocument(jsonObj).toJson());
    }
//    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
//    QJsonArray json_array = json_doc.array();
//    foreach (const QJsonValue &value, json_array) {
//        QJsonObject json_obj = value.toObject();
//        witResult+=json_obj["name"].toString();
//    }
    //    qDebug()<<"name : "+name;
}

void Nosta_rahaa::withdrawFinishSlot(QNetworkReply *)
{
    response_data=reply->readAll();
    qDebug()<<"DATA : "+response_data;
}




