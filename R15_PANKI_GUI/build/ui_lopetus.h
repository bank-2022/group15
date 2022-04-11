/********************************************************************************
** Form generated from reading UI file 'lopetus.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOPETUS_H
#define UI_LOPETUS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Lopetus
{
public:
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QPushButton *pushButton_2;
    QPushButton *pushButton;

    void setupUi(QWidget *Lopetus)
    {
        if (Lopetus->objectName().isEmpty())
            Lopetus->setObjectName(QString::fromUtf8("Lopetus"));
        Lopetus->resize(1309, 658);
        groupBox = new QGroupBox(Lopetus);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(540, 210, 191, 131));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        textEdit = new QTextEdit(groupBox);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout->addWidget(textEdit);

        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);


        retranslateUi(Lopetus);

        QMetaObject::connectSlotsByName(Lopetus);
    } // setupUi

    void retranslateUi(QWidget *Lopetus)
    {
        Lopetus->setWindowTitle(QCoreApplication::translate("Lopetus", "Form", nullptr));
        groupBox->setTitle(QString());
        textEdit->setHtml(QCoreApplication::translate("Lopetus", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt;\">Haluatko tiedot?</span></p></body></html>", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Lopetus", "Kuitille", nullptr));
        pushButton->setText(QCoreApplication::translate("Lopetus", "Ei kuittia", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Lopetus: public Ui_Lopetus {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOPETUS_H
