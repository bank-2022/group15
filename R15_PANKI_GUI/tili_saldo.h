#ifndef TILI_SALDO_H
#define TILI_SALDO_H

#include <QWidget>

namespace Ui {
class Tili_saldo;
}

class Tili_saldo : public QWidget
{
    Q_OBJECT

public:
    explicit Tili_saldo(QWidget *parent = nullptr);
    ~Tili_saldo();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Tili_saldo *ui;
};

#endif // TILI_SALDO_H
