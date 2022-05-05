#ifndef TILITAPAHTUMAT_H
#define TILITAPAHTUMAT_H

#include <QWidget>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include "myurl.h"



namespace Ui {
class tilitapahtumat;
}

class tilitapahtumat : public QWidget
{
    Q_OBJECT

public:
    explicit tilitapahtumat(QString cardSerial, QByteArray token, QWidget *parent = nullptr);
    ~tilitapahtumat();
    void getEvents();

signals:
    void returning();
    void resetTimer();
    void stopTimer();

private slots:
    void on_btnPrev_clicked();

    void on_btnNext_clicked();

    void on_btnReturn_clicked();

    void getEventsSlot(QNetworkReply*);

private:
    Ui::tilitapahtumat *ui;
    MyUrl *objectMyUrl;
    QString base_url;
    QNetworkAccessManager *loginManager;
    QNetworkReply *reply;
    QByteArray response_data;
    QByteArray token;
    QString cardSerial;
    QString events;
};

#endif // TILITAPAHTUMAT_H
