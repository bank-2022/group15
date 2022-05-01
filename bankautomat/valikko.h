#ifndef VALIKKO_H
#define VALIKKO_H

#include <QDialog>
#include "nosta_rahaa.h"
#include "tili_saldo.h"
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

namespace Ui {
class valikko;
}

class valikko : public QDialog
{
    Q_OBJECT

public:
    explicit valikko(QString name, QString balance, QString events, QString cardSerial, QByteArray token, QWidget *parent = nullptr);
    ~valikko();
    QString getText();

public slots:
    void ResetTimer();
    void StopTimer();

    void StartTimerPar(QWidget*);

private slots:
    void on_btnEvents_clicked();

    void on_btnWithdraw_clicked();

    void on_btnDeposit_clicked();

    void returningFromChild();

    void getAccountSlot(QNetworkReply*);
    void getEventsSlot(QNetworkReply*);

    void TimeOut();
    void TimeOutLogout();

private:
    Ui::valikko *ui;
    Nosta_rahaa*Nosta;
    QString balance1;
    QString cardSerial1;
    QString pin1;
    QByteArray token1;
    MyUrl *objectMyUrl;
    QString base_url;
    QNetworkAccessManager *loginManager;
    QNetworkReply *reply;
    QByteArray response_data;
    QString events1;
    QTimer *timer;
    QWidget *timedWindow;
};

#endif // VALIKKO_H