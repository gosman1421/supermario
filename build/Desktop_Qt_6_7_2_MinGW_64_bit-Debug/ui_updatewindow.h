/********************************************************************************
** Form generated from reading UI file 'updatewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPDATEWINDOW_H
#define UI_UPDATEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_updatewindow
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *updatewindow)
    {
        if (updatewindow->objectName().isEmpty())
            updatewindow->setObjectName("updatewindow");
        updatewindow->resize(768, 457);
        pushButton = new QPushButton(updatewindow);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(140, 80, 431, 111));
        QFont font;
        font.setPointSize(28);
        font.setBold(true);
        pushButton->setFont(font);
        pushButton_2 = new QPushButton(updatewindow);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(140, 260, 431, 111));
        pushButton_2->setFont(font);

        retranslateUi(updatewindow);

        QMetaObject::connectSlotsByName(updatewindow);
    } // setupUi

    void retranslateUi(QDialog *updatewindow)
    {
        updatewindow->setWindowTitle(QCoreApplication::translate("updatewindow", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("updatewindow", "Continue Playing", nullptr));
        pushButton_2->setText(QCoreApplication::translate("updatewindow", "QUIT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class updatewindow: public Ui_updatewindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPDATEWINDOW_H
