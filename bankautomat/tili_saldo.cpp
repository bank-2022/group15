#include "tili_saldo.h"
#include "ui_tili_saldo.h"

Tili_saldo::Tili_saldo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tili_saldo)
{
    ui->setupUi(this);
}

Tili_saldo::~Tili_saldo()
{
    delete ui;
    ui = nullptr;
}

void Tili_saldo::on_pushButton_clicked()
{
    this->close();
}

