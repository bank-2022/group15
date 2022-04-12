#ifndef VALIKKO_H
#define VALIKKO_H

#include <QDialog>
#include "nosta_rahaa.h"
#include "tili_saldo.h"

namespace Ui {
class valikko;
}

class valikko : public QDialog
{
    Q_OBJECT

public:
    explicit valikko(QWidget *parent = nullptr);
    ~valikko();
    QString getText();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::valikko *ui;
    Nosta_rahaa*Nosta;
    Tili_saldo*Saldo;
};

#endif // VALIKKO_H
