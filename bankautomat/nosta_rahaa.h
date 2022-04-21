#ifndef NOSTA_RAHAA_H
#define NOSTA_RAHAA_H

#include <QWidget>
#include "lopetus.h"

namespace Ui {
class Nosta_rahaa;
}

class Nosta_rahaa : public QWidget
{
    Q_OBJECT

public:
    explicit Nosta_rahaa(QString cardSerial, QString balance, QString token, QWidget *parent = nullptr);
    ~Nosta_rahaa();

signals:
    void returning();

private slots:
    void on_btn20Withdraw_clicked();

    void on_btn40Withdraw_clicked();

    void on_btn80Withdraw_clicked();

    void on_btn120Withdraw_clicked();

    void on_btnCustomAmount_clicked();

    void on_btnReturn_clicked();

private:
    Ui::Nosta_rahaa *ui;
    Lopetus*lopeta;
};

#endif // NOSTA_RAHAA_H
