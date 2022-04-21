#include "valikko.h"
#include "ui_valikko.h"


valikko::valikko(QString name, QString balance, QString events, QString cardSerial, QByteArray token, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::valikko)
{
    balance1 = balance;
    cardSerial1 = cardSerial;
    token1 = token;
    ui->setupUi(this);
    ui->lblWelcome->setText("Welcome "+name);
    ui->lblBalance->setText(balance);
    ui->lblEvents->setText(events);

    objectMyUrl = new MyUrl;
    base_url = objectMyUrl->getBase_url();
}

valikko::~valikko()
{
    delete ui;
    ui = nullptr;
    delete Nosta;
    Nosta = nullptr;
}

void valikko::on_btnEvents_clicked()
{

}


void valikko::on_btnWithdraw_clicked()
{
    Nosta = new Nosta_rahaa (cardSerial1, balance1, token1);
    Nosta->show();
    this->hide();
    connect(Nosta, SIGNAL(returning()), SLOT(returningFromChild()));
}


void valikko::on_btnDeposit_clicked()
{
    //Nosta->show();
    this->close();
}


void valikko::returningFromChild()
{
    this->show();
    QNetworkRequest request((base_url+"/accounts/"+cardSerial1));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    //WEBTOKEN AUTH
    request.setRawHeader(QByteArray("Authorization"), (token1));
    //WEBTOKEN AUTH END
    loginManager = new QNetworkAccessManager(this);
    connect(loginManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getAccountSlot(QNetworkReply*)));

    reply = loginManager->get(request);
}

void valikko::getAccountSlot(QNetworkReply *reply)
{
    balance1 = "";
    response_data=reply->readAll();
    qDebug()<<"DATA : "+response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    foreach (const QJsonValue &value, json_array) {
        QJsonObject json_obj = value.toObject();
        balance1+=json_obj["balance"].toString();
    }
    qDebug()<<"balance : "+balance1;

    QNetworkRequest request((base_url+"/events/"+cardSerial1));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    //WEBTOKEN AUTH
    request.setRawHeader(QByteArray("Authorization"), (token1));
    //WEBTOKEN AUTH END
    loginManager->deleteLater();
    loginManager = new QNetworkAccessManager(this);
    connect(loginManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getEventsSlot(QNetworkReply*)));

    reply = loginManager->get(request);
}

void valikko::getEventsSlot(QNetworkReply *reply)
{
    events1 = "";
    response_data=reply->readAll();
    qDebug()<<"DATA : "+response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    foreach (const QJsonValue &value, json_array) {
        QJsonObject json_obj = value.toObject();
        if(json_obj["eventType"].toString() == "nosto")
        {
            events1+="-"+QString::number(json_obj["amount"].toInt())+"€, "+json_obj["eventType"].toString()+", "+json_obj["dateTime"].toString();
        }
        else if (json_obj["eventType"].toString() == "talletus")
        {
            events1+="+"+QString::number(json_obj["amount"].toInt())+"€, "+json_obj["eventType"].toString()+", "+json_obj["dateTime"].toString();
        }
        events1.chop(14);
        events1+="\n";
    }
    qDebug()<<"events : "+events1;
    ui->lblBalance->setText(balance1);
    ui->lblEvents->setText(events1);

}
