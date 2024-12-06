/********************************************************************************
** Form generated from reading UI file 'welcomewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WELCOMEWINDOW_H
#define UI_WELCOMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_welcomewindow
{
public:
    QPushButton *pushButtonPLAY;
    QPushButton *pushButtonQUIT;
    QLabel *labeltitle;

    void setupUi(QDialog *welcomewindow)
    {
        if (welcomewindow->objectName().isEmpty())
            welcomewindow->setObjectName("welcomewindow");
        welcomewindow->resize(769, 455);
        pushButtonPLAY = new QPushButton(welcomewindow);
        pushButtonPLAY->setObjectName("pushButtonPLAY");
        pushButtonPLAY->setGeometry(QRect(230, 110, 271, 111));
        QFont font;
        font.setPointSize(28);
        pushButtonPLAY->setFont(font);
        pushButtonQUIT = new QPushButton(welcomewindow);
        pushButtonQUIT->setObjectName("pushButtonQUIT");
        pushButtonQUIT->setGeometry(QRect(230, 280, 271, 111));
        pushButtonQUIT->setFont(font);
        labeltitle = new QLabel(welcomewindow);
        labeltitle->setObjectName("labeltitle");
        labeltitle->setGeometry(QRect(220, 40, 341, 51));
        labeltitle->setFont(font);

        retranslateUi(welcomewindow);

        QMetaObject::connectSlotsByName(welcomewindow);
    } // setupUi

    void retranslateUi(QDialog *welcomewindow)
    {
        welcomewindow->setWindowTitle(QCoreApplication::translate("welcomewindow", "Dialog", nullptr));
        pushButtonPLAY->setText(QCoreApplication::translate("welcomewindow", "PLAY", nullptr));
        pushButtonQUIT->setText(QCoreApplication::translate("welcomewindow", "QUIT", nullptr));
        labeltitle->setText(QCoreApplication::translate("welcomewindow", "Super Mario Game ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class welcomewindow: public Ui_welcomewindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WELCOMEWINDOW_H
