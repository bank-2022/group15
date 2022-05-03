#include "rfidengine.h"

rfidengine::rfidengine()
{
    qDebug()<<"engine constructor";
    pSerialInfo = new QSerialPortInfo;
    pSerial = new QSerialPort;
    connect(pSerial,SIGNAL(readyRead()),this,SLOT(recvSignal()));

    pSerial->setPortName("com4");
    qDebug()<<pSerial->portName();
    pSerial->setBaudRate(9600);
    pSerial->setDataBits(QSerialPort::Data8);
    pSerial->setParity(QSerialPort::NoParity);
    pSerial->setStopBits(QSerialPort::OneStop);
    pSerial->setFlowControl(QSerialPort::HardwareControl);
    pSerial->open(QIODevice::ReadWrite);
}

rfidengine::~rfidengine()
{
    delete pSerial;
    delete pSerialInfo;
    pSerial=nullptr;
    pSerialInfo=nullptr;
}

void rfidengine::restartRfid()
{
    qDebug()<<"restart rfid function";
    pSerial->open(QIODevice::ReadWrite);
}

QString rfidengine::getId() const
{
    qDebug()<<"getID function";
    return id;
}

void rfidengine::recvSignal()
{
    qDebug()<<"recvSignal function";
    QByteArray code = pSerial->readAll();
    code.remove(0,3);
    code.chop(3);
    pSerial->close();
    id=code;
    emit idRead();
}
