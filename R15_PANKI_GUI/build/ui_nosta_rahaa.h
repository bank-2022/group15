/********************************************************************************
** Form generated from reading UI file 'nosta_rahaa.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOSTA_RAHAA_H
#define UI_NOSTA_RAHAA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Nosta_rahaa
{
public:
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_4;
    QPushButton *pushButton_2;
    QPushButton *pushButton_5;
    QPushButton *pushButton_3;
    QPushButton *pushButton_6;

    void setupUi(QWidget *Nosta_rahaa)
    {
        if (Nosta_rahaa->objectName().isEmpty())
            Nosta_rahaa->setObjectName(QString::fromUtf8("Nosta_rahaa"));
        Nosta_rahaa->resize(1319, 664);
        groupBox = new QGroupBox(Nosta_rahaa);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(450, 190, 361, 211));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

        pushButton_4 = new QPushButton(groupBox);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 0, 1, 1, 1);

        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 1, 0, 1, 1);

        pushButton_5 = new QPushButton(groupBox);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        gridLayout->addWidget(pushButton_5, 1, 1, 1, 1);

        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 2, 0, 1, 1);

        pushButton_6 = new QPushButton(groupBox);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        gridLayout->addWidget(pushButton_6, 2, 1, 1, 1);


        retranslateUi(Nosta_rahaa);

        QMetaObject::connectSlotsByName(Nosta_rahaa);
    } // setupUi

    void retranslateUi(QWidget *Nosta_rahaa)
    {
        Nosta_rahaa->setWindowTitle(QCoreApplication::translate("Nosta_rahaa", "Form", nullptr));
        groupBox->setTitle(QString());
        pushButton->setText(QCoreApplication::translate("Nosta_rahaa", "20", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Nosta_rahaa", "80", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Nosta_rahaa", "40", nullptr));
        pushButton_5->setText(QCoreApplication::translate("Nosta_rahaa", "120", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Nosta_rahaa", "Lopeta", nullptr));
        pushButton_6->setText(QCoreApplication::translate("Nosta_rahaa", "Muu summa", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Nosta_rahaa: public Ui_Nosta_rahaa {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOSTA_RAHAA_H
