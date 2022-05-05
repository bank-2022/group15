#ifndef RFIDSERIAL_H
#define RFIDSERIAL_H

#include "rfidserial_global.h"
#include <QObject>
#include "rfidengine.h"

class /*RFIDSERIAL_EXPORT*/ Rfidserial : public QObject
{
    Q_OBJECT
public:
    Rfidserial(QObject * parent = nullptr);
    ~Rfidserial();

    QString readValue();
    void restartSerial();

private slots:
    void serialRead();

signals:
    void serialReady();

private:
    rfidengine *engine;
    QString returnData;

};

#endif // RFIDSERIAL_H
