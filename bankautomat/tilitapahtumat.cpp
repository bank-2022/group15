#include "tilitapahtumat.h"
#include "ui_tilitapahtumat.h"

tilitapahtumat::tilitapahtumat(QString cardSerial, QByteArray token, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tilitapahtumat)
{
    ui->setupUi(this);
    objectMyUrl = new MyUrl;
    base_url = objectMyUrl->getBase_url();
    this->cardSerial = cardSerial;
    this->token = token;
}

tilitapahtumat::~tilitapahtumat()
{
    delete ui;
}

void tilitapahtumat::on_btnPrev_clicked()
{

}


void tilitapahtumat::on_btnNext_clicked()
{

}


void tilitapahtumat::on_btnReturn_clicked()
{
    emit returning();
    this->close();
}

void tilitapahtumat::getEvents()
{
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

void tilitapahtumat::getEventsSlot(QNetworkReply *)
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
        //events.chop(14);
        events+="\n";
    }
    qDebug()<<"events : "+events;
    ui->eventsBox->setText(events);
}


