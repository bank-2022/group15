#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tunnusluku.h"
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void aikaulos();

private slots:

    void on_auki_clicked();
    void paluupaluusta();

private:
    Ui::MainWindow *ui;
    Tunnusluku*pToka;
    QTimer*timer;
};
#endif // MAINWINDOW_H
