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
    void TimeOut();
    void StopTimer();
    void ResetTimer();


private slots:
    void on_login_clicked();

private:
    Ui::MainWindow *ui;
    Tunnusluku*pTunnusLuku;
    QTimer*timer;
};
#endif // MAINWINDOW_H
