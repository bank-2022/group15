/********************************************************************************
** Form generated from reading UI file 'valikko.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VALIKKO_H
#define UI_VALIKKO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_valikko
{
public:
    QGroupBox *groupBox;
    QTextEdit *textEdit_2;
    QTextEdit *textEdit;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QLineEdit *Laatikko2;

    void setupUi(QDialog *valikko)
    {
        if (valikko->objectName().isEmpty())
            valikko->setObjectName(QString::fromUtf8("valikko"));
        valikko->resize(1350, 667);
        groupBox = new QGroupBox(valikko);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(460, 220, 291, 151));
        textEdit_2 = new QTextEdit(groupBox);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setGeometry(QRect(10, 100, 171, 51));
        textEdit = new QTextEdit(groupBox);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 50, 171, 51));
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(190, 100, 101, 51));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(190, 50, 101, 51));
        Laatikko2 = new QLineEdit(groupBox);
        Laatikko2->setObjectName(QString::fromUtf8("Laatikko2"));
        Laatikko2->setGeometry(QRect(10, 20, 171, 20));

        retranslateUi(valikko);

        QMetaObject::connectSlotsByName(valikko);
    } // setupUi

    void retranslateUi(QDialog *valikko)
    {
        valikko->setWindowTitle(QCoreApplication::translate("valikko", "Dialog", nullptr));
        groupBox->setTitle(QString());
        textEdit_2->setHtml(QCoreApplication::translate("valikko", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:20pt;\">Tilitiedot</span></p></body></html>", nullptr));
        textEdit->setHtml(QCoreApplication::translate("valikko", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:20pt;\">Nosta rahaa</span></p></body></html>", nullptr));
        pushButton_2->setText(QCoreApplication::translate("valikko", "PushButton", nullptr));
        pushButton->setText(QCoreApplication::translate("valikko", "PushButton", nullptr));
        Laatikko2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class valikko: public Ui_valikko {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VALIKKO_H
