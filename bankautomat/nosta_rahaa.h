#ifndef NOSTA_RAHAA_H
#define NOSTA_RAHAA_H

#include <QWidget>
#include "lopetus.h"
#include "myurl.h"

#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

namespace Ui {
class Nosta_rahaa;
}

class Nosta_rahaa : public QWidget
{
    Q_OBJECT

public:
    explicit Nosta_rahaa(QString cardSerial, QString balance, QByteArray token, QWidget *parent = nullptr);
    ~Nosta_rahaa();

signals:
    void returning();
    int withdrawal(int n);

private slots:
    void on_btn20Withdraw_clicked();

    void on_btn40Withdraw_clicked();

    void on_btn80Withdraw_clicked();

    void on_btn120Withdraw_clicked();

    void on_btnCustomAmount_clicked();

    void on_btnReturn_clicked();

    void withdrawEvent(int n);

private:
    Ui::Nosta_rahaa *ui;
    Lopetus*lopeta;
    QString balance1;
    QByteArray token1;
    QString cardSerial1;
    MyUrl *objectMyUrl;
    QString base_url;
    QNetworkAccessManager *loginManager;
    QNetworkReply *reply;
    QByteArray response_data;
};

#endif // NOSTA_RAHAA_H
