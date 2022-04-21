#include "nosta_rahaa.h"
#include "ui_nosta_rahaa.h"
#include <QMessageBox>


Nosta_rahaa::Nosta_rahaa(QString cardSerial, QString balance, QString token, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Nosta_rahaa)
{
    ui->setupUi(this);
    lopeta = new Lopetus;

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

}


void Nosta_rahaa::on_btn40Withdraw_clicked()
{

}


void Nosta_rahaa::on_btn80Withdraw_clicked()
{

}


void Nosta_rahaa::on_btn120Withdraw_clicked()
{

}


void Nosta_rahaa::on_btnCustomAmount_clicked()
{

}


void Nosta_rahaa::on_btnReturn_clicked()
{
    emit returning();
    this->hide();
}

