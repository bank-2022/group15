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
}
