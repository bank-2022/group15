#include "nosta_rahaa.h"
#include "ui_nosta_rahaa.h"



Nosta_rahaa::Nosta_rahaa(QString cardSerial, QString balance, QByteArray token, QString type, QString cardType, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Nosta_rahaa)
{
    cardSerial1 = cardSerial;
    balance1 = balance;
    token1 = token;
    ui->setupUi(this);

    objectMyUrl = new MyUrl;
    base_url = objectMyUrl->getBase_url();
    this->cardType = cardType;
    trType = type;
}
Nosta_rahaa::~Nosta_rahaa()
{
    delete ui;
    ui = nullptr;
}

//void Nosta_rahaa::on_pushButton_clicked()
//{
//    QMessageBox msgBox;
//    msgBox.setText("Nostit 20€");
//    msgBox.exec();
//    lopeta->show();
//    this->close();


void Nosta_rahaa::on_btn20Transaction_clicked()
{
    transactionEvent(20);
}


void Nosta_rahaa::on_btn40Transaction_clicked()
{
    transactionEvent(40);
}


void Nosta_rahaa::on_btn80Transaction_clicked()
{
    transactionEvent(80);
}


void Nosta_rahaa::on_btn120Transaction_clicked()
{
    transactionEvent(120);
}


void Nosta_rahaa::on_btnCustomAmount_clicked()
{
    emit resetTimer();
    bool ok;
    int n = QInputDialog::getInt( this, tr("Custom amount"), tr("Määrä:"), 10, 10, 400, 10, &ok);
    if(n!=0&&ok)
    {
        transactionEvent(n);
    }
}


void Nosta_rahaa::on_btnReturn_clicked()
{
    emit returning();
    this->close();
}

void Nosta_rahaa::transactionEvent(int n)
{
    emit stopTimer();
    qDebug("clicked transaction, stop timer");
    qDebug()<<balance1;
    if (trType == "withdrawal")
    {
        if (balance1.toInt()<n && cardType=="Debit")
        {
            QMessageBox msgBox;
            msgBox.setText("Kate ei riitä");
            msgBox.exec();
            emit resetTimer();
        }
        else {

            amount = QString::number(n);
            QMessageBox msgBox;
            msgBox.setText("Nostetaan "+QString::number(n)+"€...");
            msgBox.exec();


            QJsonObject jsonObj;
            QString evtype="";
            if (cardType=="Debit") {
                evtype="/withdraw/";
            }
            else if (cardType=="Credit") {
                evtype="/credit/";
            }
            QNetworkRequest request((base_url+"/accounts/"+cardSerial1+evtype+QString::number(n)));


            request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

            //WEBTOKEN AUTH
            request.setRawHeader(QByteArray("Authorization"), (token1));
            //WEBTOKEN AUTH END
            loginManager = new QNetworkAccessManager(this);
            connect(loginManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(transactionSlot(QNetworkReply*)));
            reply = loginManager->put(request, QJsonDocument(jsonObj).toJson());
        }
    }
    else if (trType == "deposit" && cardType=="Debit")
    {
        amount = QString::number(n);
        QMessageBox msgBox;
        msgBox.setText("Talletetaan "+QString::number(n)+"€...");
        msgBox.exec();


        QJsonObject jsonObj;
        QNetworkRequest request((base_url+"/accounts/"+cardSerial1+"/deposit/"+QString::number(n)));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

        //WEBTOKEN AUTH
        request.setRawHeader(QByteArray("Authorization"), (token1));
        //WEBTOKEN AUTH END
        loginManager = new QNetworkAccessManager(this);
        connect(loginManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(transactionSlot(QNetworkReply*)));
        reply = loginManager->put(request, QJsonDocument(jsonObj).toJson());
    }
    else { qDebug()<<"error"; }

}

void Nosta_rahaa::transactionSlot(QNetworkReply*)
{
    response_data=reply->readAll();
    qDebug()<<"DATA : "+response_data;
    if (response_data == "Withdrawn successfully" || response_data == "Credit used")
    {
        QJsonObject jsonObj;
        jsonObj.insert("cardSerial", cardSerial1);
        qAika = QDateTime::currentDateTime();
        jsonObj.insert("dateTime", qAika.toString("yyyy-MM-ddThh:mm:ss.zzzZ"));
        if (cardType=="Credit"){
            jsonObj.insert("eventType", "credit");
        }
        else if (cardType=="Debit"){
            jsonObj.insert("eventType", "nosto");
        }
        jsonObj.insert("amount", amount.toInt());
        QNetworkRequest request((base_url+"/events/add"));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

        //WEBTOKEN AUTH
        request.setRawHeader(QByteArray("Authorization"), (token1));
        //WEBTOKEN AUTH END

        loginManager = new QNetworkAccessManager(this);
        connect(loginManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(transactionFinishSlot(QNetworkReply*)));

        reply = loginManager->post(request,QJsonDocument(jsonObj).toJson());
    }
    else if(response_data == "Deposited successfully")
    {
        QJsonObject jsonObj;
        jsonObj.insert("cardSerial", cardSerial1);
        qAika = QDateTime::currentDateTime();
        jsonObj.insert("dateTime", qAika.toString("yyyy-MM-ddThh:mm:ss.zzzZ"));
        jsonObj.insert("eventType", "talletus");
        jsonObj.insert("amount", amount.toInt());
        QNetworkRequest request((base_url+"/events/add"));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

        //WEBTOKEN AUTH
        request.setRawHeader(QByteArray("Authorization"), (token1));
        //WEBTOKEN AUTH END

        loginManager = new QNetworkAccessManager(this);
        connect(loginManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(transactionFinishSlot(QNetworkReply*)));

        reply = loginManager->post(request,QJsonDocument(jsonObj).toJson());
    }
    else { qDebug()<<"error1"; }
//    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
//    QJsonArray json_array = json_doc.array();
//    foreach (const QJsonValue &value, json_array) {
//        QJsonObject json_obj = value.toObject();
//        witResult+=json_obj["name"].toString();
//    }
    //    qDebug()<<"name : "+name;
}

void Nosta_rahaa::transactionFinishSlot(QNetworkReply *)
{
    response_data=reply->readAll();
    qDebug()<<"DATA : "+response_data;
    emit returning();
    this->close();
}




