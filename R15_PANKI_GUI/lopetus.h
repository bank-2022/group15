#ifndef LOPETUS_H
#define LOPETUS_H

#include <QWidget>

namespace Ui {
class Lopetus;
}

class Lopetus : public QWidget
{
    Q_OBJECT

public:
    explicit Lopetus(QWidget *parent = nullptr);
    ~Lopetus();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Lopetus *ui;
};

#endif // LOPETUS_H
