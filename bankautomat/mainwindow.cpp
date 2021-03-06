#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tunnusluku.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pRfidSerial = new Rfidserial;

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(TimeOut())); //timerin signaali jne
    timer->setInterval(10000); //asetetaan timerin aika ja annetaan singaali

    connect(pRfidSerial,SIGNAL(serialReady())
            ,this, SLOT(on_card_read()));    //liitetään lukijan signaalit
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
    pRfidSerial->restartSerial();
}

void MainWindow::on_login_clicked()
{
    //aukaise seuraava ikkuna ja sulke nykyinen kun kortti on skannattu ja olet painanut ok

    pTunnusLuku = new Tunnusluku;
    //pTunnusLuku->cardSerial = "123456";
    pTunnusLuku->cardSerial = "0600064158";
    connect(pTunnusLuku, SIGNAL(Login()), SLOT(StopTimer()));           //kun tunnusluku-ikkunassa login, pysäyttää timerin
    connect(pTunnusLuku, SIGNAL(ButtonPushed()), SLOT(ResetTimer()));   //kun tunnusluku-ikkunassa painetaan jotain nappia, resettaa timerin
    timer->start();
    pTunnusLuku->show();
    pTunnusLuku->ResetPinWindow();
    connect(pTunnusLuku, SIGNAL(Returning()), this, SLOT(ReturningSlot()));
    this->hide();
}

void MainWindow::on_card_read()
{
    //aukaise seuraava ikkuna kun kortti luettu
    //userId muuttujaan otetaan talteen kortilta luettu ID, jota voidaan sitten verrata db:n käyttäjätunnuksiin

    pTunnusLuku = new Tunnusluku;
    userId = pRfidSerial->readValue();
    pTunnusLuku->cardSerial = userId;
    qDebug()<<userId;
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
    pRfidSerial->restartSerial();
}
