/********************************************************************************
** Form generated from reading UI file 'tili_saldo.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TILI_SALDO_H
#define UI_TILI_SALDO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tili_saldo
{
public:
    QGroupBox *groupBox;
    QTextEdit *textEdit;
    QLineEdit *lineEdit;
    QPushButton *pushButton;

    void setupUi(QWidget *Tili_saldo)
    {
        if (Tili_saldo->objectName().isEmpty())
            Tili_saldo->setObjectName(QString::fromUtf8("Tili_saldo"));
        Tili_saldo->resize(1319, 652);
        groupBox = new QGroupBox(Tili_saldo);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(410, 300, 421, 91));
        textEdit = new QTextEdit(groupBox);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(90, 30, 221, 41));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(90, 70, 221, 21));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(330, 40, 75, 41));

        retranslateUi(Tili_saldo);

        QMetaObject::connectSlotsByName(Tili_saldo);
    } // setupUi

    void retranslateUi(QWidget *Tili_saldo)
    {
        Tili_saldo->setWindowTitle(QCoreApplication::translate("Tili_saldo", "Form", nullptr));
        groupBox->setTitle(QString());
        textEdit->setHtml(QCoreApplication::translate("Tili_saldo", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:18pt;\">Tilin saldo</span></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("Tili_saldo", "Lopeta", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tili_saldo: public Ui_Tili_saldo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TILI_SALDO_H
