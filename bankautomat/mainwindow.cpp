#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tunnusluku.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pTunnusLuku = new Tunnusluku;

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(TimeOut())); //timerin signaali jne
    timer->setInterval(5000); //asetetaan timerin aika ja annetaan singaali
}

MainWindow::~MainWindow()
{
    delete ui;
    ui = nullptr;
    delete pTunnusLuku;
    pTunnusLuku = nullptr;
}

void MainWindow::StopTimer(){
    timer->stop();
    qDebug("Logged in - stop timer");
}

void MainWindow::ResetTimer(){
    timer->stop();
    timer->start();
    qDebug("Button pressed - reset timer");
}

void MainWindow::ReturningSlot()
{
    this->show();
}

void MainWindow::on_login_clicked()
{
    //aukaise seuraava ikkuna ja sulke nykyinen kun kortti on skannattu ja olet painanut ok
    connect(pTunnusLuku, SIGNAL(Login()), SLOT(StopTimer()));           //kun tunnusluku-ikkunassa login, pysäyttää timerin
    connect(pTunnusLuku, SIGNAL(ButtonPushed()), SLOT(ResetTimer()));   //kun tunnusluku-ikkunassa painetaan jotain nappia, resettaa timerin
    timer->start();
    pTunnusLuku->show();
    pTunnusLuku->ResetPinWindow();
    connect(pTunnusLuku, SIGNAL(Returning()), this, SLOT(ReturningSlot()));
    this->hide();
}

void MainWindow::TimeOut()
{
    QMessageBox msgBox;
    msgBox.setText("istunto päättynyt");
    msgBox.exec();
    StopTimer();
    pTunnusLuku->hide();
    this->show();
}
