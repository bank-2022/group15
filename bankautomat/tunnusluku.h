#ifndef TUNNUSLUKU_H
#define TUNNUSLUKU_H

#include <QWidget>
#include "myurl.h"
#include "valikko.h"
#include <QMessageBox>
#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

namespace Ui {
class Tunnusluku;
}

class Tunnusluku : public QWidget
{
    Q_OBJECT

public:
    explicit Tunnusluku(QWidget *parent = nullptr);
    ~Tunnusluku();



private slots:
    void loginSlot(QNetworkReply *reply);

    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_11_clicked();
    void on_pushButton_12_clicked();



private:
    Ui::Tunnusluku *ui;
    valikko*valikkoo;
    QString pinko;
    MyUrl *objectMyUrl;
    QString base_url;
    QNetworkAccessManager *loginManager;
    QNetworkReply *reply;
    QByteArray response_data;
    int tries;
};

#endif // TUNNUSLUKU_H
