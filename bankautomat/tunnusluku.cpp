#include "tunnusluku.h"
#include "ui_tunnusluku.h"
#include "valikko.h"


Tunnusluku::Tunnusluku(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tunnusluku)
{
    pinko = "";
    ui->setupUi(this);
    valikkoo = new valikko;
    objectMyUrl = new MyUrl;
    base_url = objectMyUrl->getBase_url();
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

void Tunnusluku::loginSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<"DATA : "+response_data;
    //QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    //QJsonArray json_array = json_doc.array();

}

void Tunnusluku::on_pushButton_clicked()
{
    pinko.append("1");
    ui->Laatikko->setText(pinko); //aseta haluamasi numero laatikkoon
}

void Tunnusluku::on_pushButton_2_clicked()
{
    pinko.append("2");
    ui->Laatikko->setText(pinko);
}

void Tunnusluku::on_pushButton_3_clicked()
{
    pinko.append("3");
    ui->Laatikko->setText(pinko);
}

void Tunnusluku::on_pushButton_4_clicked()
{
    pinko.append("4");
    ui->Laatikko->setText(pinko);
}

void Tunnusluku::on_pushButton_5_clicked()
{
    pinko.append("5");
    ui->Laatikko->setText(pinko);
}
void Tunnusluku::on_pushButton_6_clicked()
{
    pinko.append("6");
    ui->Laatikko->setText(pinko);
}

void Tunnusluku::on_pushButton_7_clicked()
{
    pinko.append("7");
    ui->Laatikko->setText(pinko);
}

void Tunnusluku::on_pushButton_8_clicked()
{
    pinko.append("8");
    ui->Laatikko->setText(pinko);
}

void Tunnusluku::on_pushButton_9_clicked()
{
    pinko.append("9");
    ui->Laatikko->setText(pinko);
}

void Tunnusluku::on_pushButton_10_clicked()
{
    pinko.append("0");
    ui->Laatikko->setText(pinko);
}

void Tunnusluku::on_pushButton_11_clicked() //voit poistaa laatikkoon tulleet numerot
{
    ui->Laatikko->setText("poista numero");
    pinko = "";
}

void Tunnusluku::on_pushButton_12_clicked() //jos oikea pinkoodi ilmestyy laatikkoon niin sulje ja näytä seuraava kohta
{                                           //jos taas pin koodi on väärä niin ilmoita yritysten määrä kunnes viimeinen on käytetty sitten sulje automaatti
    QNetworkRequest request((base_url+"/cards/4258145576238597/"+pinko));
    loginManager = new QNetworkAccessManager(this);

    connect(loginManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(loginSlot(QNetworkReply*)));

    reply = loginManager->get(request);


//    if (pinko == "1234") {

//        QMessageBox msgBox;
//        msgBox.setText("pinkoodi oikein");
//        msgBox.exec();

//        valikkoo->show();
//        this-> close();
//       }

//    else {
//        QMessageBox msgBox;
//        msgBox.setText("pinkoodi väärin, yritä uudestaan");
//        msgBox.exec();
      }

