#include "valikko.h"
#include "ui_valikko.h"


valikko::valikko(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::valikko)
{
    ui->setupUi(this);
    Nosta = new Nosta_rahaa;
    Saldo = new Tili_saldo;
}

valikko::~valikko()
{
    delete ui;
    delete Nosta;
    delete Saldo;
}
void valikko::on_pushButton_clicked()
{
    Nosta->show();
    this->close();
}


void valikko::on_pushButton_2_clicked()
{
    Saldo->show();
    this->close();
}

