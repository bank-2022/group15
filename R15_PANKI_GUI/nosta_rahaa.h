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
    explicit Nosta_rahaa(QWidget *parent = nullptr);
    ~Nosta_rahaa();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::Nosta_rahaa *ui;
    Lopetus*lopeta;
};

#endif // NOSTA_RAHAA_H
