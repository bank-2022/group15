#include "tilitapahtumat.h"
#include "ui_tilitapahtumat.h"

tilitapahtumat::tilitapahtumat(QString cardSerial, QByteArray token, QString cardType, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tilitapahtumat)
{
    ui->setupUi(this);
    objectMyUrl = new MyUrl;
    base_url = objectMyUrl->getBase_url();
    this->cardSerial = cardSerial;
    this->token = token;
    this->cardType = cardType;
    connect(this, SIGNAL(eventBegin()), this, SLOT(getEvents()));
    emit eventBegin();
}

tilitapahtumat::~tilitapahtumat()
{
    delete ui;
}

void tilitapahtumat::on_btnPrev_clicked()
{
    if (iterator==0 && iteMax>=10){iteMax=10;}
    else if (iteMax == eventList.count() && eventList.count()<10){}
    else if (iteMax == eventList.count() && eventList.count()>=10) {iteMax=iterator; iterator-=10;}
    else {iterator -= 10; iteMax-=10;}
    eventPrint="";

    qDebug()<<"iterator :"+QString::number(iterator);
    qDebug()<<"iteMax: "+QString::number(iteMax);
    qDebug()<<"eventList.count() :"+QString::number(eventList.count());
    for (int i = iterator;  i != iteMax; ++i)
    {
        eventPrint.append(eventList.value(i));
        qDebug()<<QString::number(i);
        qDebug()<<eventList.value(i);
    }

    ui->eventsBox->setText(eventPrint);
    if (pgNum==1){} else {pgNum--;}
    ui->pageLabel->setText(QString::number(pgNum)+"/"+QString::number(pgMax));
    emit resetTimer();
}


void tilitapahtumat::on_btnNext_clicked()
{
    if (iteMax == eventList.count()){}
    else if (iteMax+10 < eventList.count()) {iteMax+=10; iterator+= 10;}
    else{iteMax = eventList.count(); iterator+=10;}
    eventPrint="";

    qDebug()<<"iterator :"+QString::number(iterator);
    qDebug()<<"iteMax: "+QString::number(iteMax);
    qDebug()<<"eventList.count() :"+QString::number(eventList.count());
    for (int i = iterator;  i != iteMax; ++i)
    {
        eventPrint.append(eventList.value(i));
        qDebug()<<QString::number(i);
        qDebug()<<eventList.value(i);
    }

    ui->eventsBox->setText(eventPrint);
    if (pgNum+1>pgMax){} else {pgNum++;}
    ui->pageLabel->setText(QString::number(pgNum)+"/"+QString::number(pgMax));
    emit resetTimer();
}


void tilitapahtumat::on_btnReturn_clicked()
{
    emit returning();
    this->close();
}

void tilitapahtumat::getEvents()
{
    emit stopTimer();
    QNetworkRequest request((base_url+"/events/"+cardSerial));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    //WEBTOKEN AUTH
    request.setRawHeader(QByteArray("Authorization"), (token));
    //WEBTOKEN AUTH END
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
        if(json_obj["eventType"].toString() == "nosto" && cardType == "Debit")
        {
            events="-"+QString::number(json_obj["amount"].toInt())+"€, "+json_obj["eventType"].toString()+", "+json_obj["dateTime"].toString().replace("-", " ").replace("T", " ");
            events.chop(8);
            events+="\n";
        }
        else if (json_obj["eventType"].toString() == "talletus" && cardType == "Debit")
        {
            events="+"+QString::number(json_obj["amount"].toInt())+"€, "+json_obj["eventType"].toString()+", "+json_obj["dateTime"].toString().replace("-", " ").replace("T", " ");
            events.chop(8);
            events+="\n";
        }
        else if (json_obj["eventType"].toString() == "credit" && cardType == "Credit"){
            events="-"+QString::number(json_obj["amount"].toInt())+"€, "+json_obj["eventType"].toString()+", "+json_obj["dateTime"].toString().replace("-", " ").replace("T", " ");
            events.chop(8);
            events+="\n";
        }
        eventList.append(events);
    }
    iterator = 0;
    iteMax = 10;
    if (iteMax > eventList.count()){iteMax=eventList.count();}
    for (int i = iterator;  i < iteMax; ++i)
    {
        eventPrint.append(eventList[i]);
    }
    qDebug()<<"events : "+eventPrint;
    ui->eventsBox->setText(eventPrint);
    pgMax = eventList.count()/10.0;
    pgMax = ceil(pgMax);
    pgNum = 1;
    ui->pageLabel->setText(QString::number(pgNum)+"/"+QString::number(pgMax));
    emit resetTimer();
}

