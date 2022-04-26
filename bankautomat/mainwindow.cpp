#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tunnusluku.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pToka = new Tunnusluku;

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(aikaulos())); //timerin signaali jne
    timer->setInterval(5000); //asetetaan timerin aika ja annetaan singaali

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
    connect(pToka, SIGNAL(paluu()), SLOT(paluupaluusta())); //kun nappia painettu pitäisi lähettää signaali
    timer->start();

    pToka->show();
    this->hide();
}

void MainWindow::aikaulos()
{
    QMessageBox msgBox;
    msgBox.setText("istunto päättynyt");
    msgBox.exec();
    if ("istunto päättynyt")
    {
        timer->stop();
    }
}
