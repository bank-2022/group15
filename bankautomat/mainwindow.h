#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tunnusluku.h"
#include <QTimer>
#include "rfidserial.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString userId; //tähän tallennetaan kortista luettu ID

public slots:
    void TimeOut();
    void StopTimer();
    void ResetTimer();
    void ReturningSlot();


private slots:
    void on_login_clicked();
    void on_card_read();

private:
    Ui::MainWindow *ui;
    Tunnusluku*pTunnusLuku;
    QTimer*timer;
    Rfidserial*pRfidSerial;
};
#endif // MAINWINDOW_H
