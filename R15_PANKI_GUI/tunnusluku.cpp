#include "tunnusluku.h"
#include "ui_tunnusluku.h"
#include <QMessageBox>
#include "valikko.h"


Tunnusluku::Tunnusluku(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tunnusluku)
{
    ui->setupUi(this);
    valikkoo = new valikko;
}

Tunnusluku::~Tunnusluku()
{
    delete ui;
    delete valikkoo;
}

void Tunnusluku::on_pushButton_clicked()
{
    ui->Laatikko->setText("1"); //aseta haluamasi numero laatikkoon
}

void Tunnusluku::on_pushButton_2_clicked()
{
    ui->Laatikko->setText("2");
}

void Tunnusluku::on_pushButton_3_clicked()
{
    ui->Laatikko->setText("3");
}

void Tunnusluku::on_pushButton_4_clicked()
{
    ui->Laatikko->setText("4");
}

void Tunnusluku::on_pushButton_5_clicked()
{
    ui->Laatikko->setText("5");
}
void Tunnusluku::on_pushButton_6_clicked()
{
    ui->Laatikko->setText("6");
}

void Tunnusluku::on_pushButton_7_clicked()
{
    ui->Laatikko->setText("7");
}

void Tunnusluku::on_pushButton_8_clicked()
{
    ui->Laatikko->setText("8");
}

void Tunnusluku::on_pushButton_9_clicked()
{
    ui->Laatikko->setText("9");
}

void Tunnusluku::on_pushButton_10_clicked()
{
    ui->Laatikko->setText("0");
}

void Tunnusluku::on_pushButton_11_clicked() //voit poistaa laatikkoon tulleet numerot
{
    ui->Laatikko->setText("poista numero");
}

void Tunnusluku::on_pushButton_12_clicked() //jos oikea pinkoodi ilmestyy laatikkoon niin sulje ja näytä seuraava kohta
{                                           //jos taas pin koodi on väärä niin ilmoita yritysten määrä kunnes viimeinen on käytetty sitten sulje automaatti
    QString pinkoodi = ui->Laatikko->text();

    if (pinkoodi == "1234") {

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

void Idletimer();
{
//jos 15 sekunttia on kulunut ilman inputtia niin palaa alkuruutuun
}
 }
