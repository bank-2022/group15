#include "rfidserial.h"


Rfidserial::Rfidserial(QObject *parent) : QObject(parent)
{
    qDebug()<<"rfid serial constructor";
    engine = new rfidengine;
    connect(engine,SIGNAL(idRead()),this,SLOT(serialRead()));
}

Rfidserial::~Rfidserial()
{
    delete engine;
    engine = nullptr;
}

QString Rfidserial::readValue()
{
    return returnData;
    qDebug()<<returnData;
}

void Rfidserial::restartSerial()
{
    engine->restartRfid();
}

void Rfidserial::serialRead()
{
    returnData=engine->getId();
    emit serialReady();
}
