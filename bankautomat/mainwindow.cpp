#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tunnusluku.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pToka = new Tunnusluku;
}

MainWindow::~MainWindow()
{
    delete ui;
    ui = nullptr;
    delete pToka;
    pToka = nullptr;
}

void MainWindow::on_auki_clicked()
{
    //aukaise seuraava ikkuna ja sulke nykyinen kun kortti on skannattu ja olet painanut ok
    pToka->show();
    this->close();
}

