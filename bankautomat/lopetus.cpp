#include "lopetus.h"
#include "ui_lopetus.h"
#include <QMessageBox>

Lopetus::Lopetus(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Lopetus)
{
    ui->setupUi(this);

}

Lopetus::~Lopetus()
{
    delete ui;
    ui = nullptr;

}

void Lopetus::on_pushButton_2_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("Tulostetaan kuittia");
    msgBox.exec();
    this->close();
}


void Lopetus::on_pushButton_clicked()
{
    this->close();
}

