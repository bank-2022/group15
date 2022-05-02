#ifndef RFIDENGINE_H
#define RFIDENGINE_H

#include <QObject>
#include <QtSerialPort/QtSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include <QByteArray>

class rfidengine : public QObject
{
    Q_OBJECT
public:
    rfidengine();
    ~rfidengine();
    void restartRfid();

    QString getId() const;


public slots:
    void recvSignal();

signals:
    void idRead();

private:
    QSerialPort *pSerial;
    QSerialPortInfo *pSerialInfo;
    QString id;

};

#endif // RFIDENGINE_H
