#include "valikko.h"
#include "ui_valikko.h"


valikko::valikko(QString name, QString balance, QString events, QString cardSerial, QByteArray token, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::valikko)
{
    ui->setupUi(this);
    ui->lblWelcome->setText("Welcome "+name);
    ui->lblBalance->setText(balance);
    ui->lblEvents->setText(events);
    Nosta = new Nosta_rahaa;
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
    Nosta->show();
    this->close();
}


void valikko::on_btnDeposit_clicked()
{
    Nosta->show();
    this->close();
}

