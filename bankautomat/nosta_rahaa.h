#ifndef NOSTA_RAHAA_H
#define NOSTA_RAHAA_H

#include <QWidget>
#include "lopetus.h"
#include "myurl.h"
#include <QDateTime>
#include <QMessageBox>
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
    explicit Nosta_rahaa(QString cardSerial, QString balance, QByteArray token, QString type, QWidget *parent = nullptr);
    ~Nosta_rahaa();

    void transactionEvent(int n);

signals:
    void returning();

private slots:
    void on_btn20Transaction_clicked();

    void on_btn40Transaction_clicked();

    void on_btn80Transaction_clicked();

    void on_btn120Transaction_clicked();

    void on_btnCustomAmount_clicked();

    void on_btnReturn_clicked();

    void transactionSlot(QNetworkReply*);

    void transactionFinishSlot(QNetworkReply*);

private:
    Ui::Nosta_rahaa *ui;
    Lopetus*lopeta;
    QString balance1;
    QByteArray token1;
    QString cardSerial1;
    QString amount;
    MyUrl *objectMyUrl;
    QString base_url;
    QNetworkAccessManager *loginManager;
    QNetworkReply *reply;
    QByteArray response_data;
    QString transactionResult;
    QDateTime qAika;
    QString trType;
};

#endif // NOSTA_RAHAA_H
