#include "nosta_rahaa.h"
#include "ui_nosta_rahaa.h"
#include <QMessageBox>


Nosta_rahaa::Nosta_rahaa(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Nosta_rahaa)
{
    ui->setupUi(this);
    lopeta = new Lopetus;

}

Nosta_rahaa::~Nosta_rahaa()
{
    delete ui;
    delete lopeta;
}

void Nosta_rahaa::on_pushButton_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("Nostit 20€");
    msgBox.exec();
    lopeta->show();
    this->close();
}


void Nosta_rahaa::on_pushButton_4_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("Nostit 80€");
    msgBox.exec();
    lopeta->show();
    this->close();
}


void Nosta_rahaa::on_pushButton_2_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("Nostit 40€");
    msgBox.exec();
    lopeta->show();
    this->close();
}


void Nosta_rahaa::on_pushButton_5_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("Nostit 120€");
    msgBox.exec();
    lopeta->show();
    this->close();
}


void Nosta_rahaa::on_pushButton_3_clicked()
{
    this->close();
}


void Nosta_rahaa::on_pushButton_6_clicked()
{
    //muu summa valitse itse
}

