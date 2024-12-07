/********************************************************************************
** Form generated from reading UI file 'levelcomplete.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEVELCOMPLETE_H
#define UI_LEVELCOMPLETE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_levelcomplete
{
public:
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *levelcomplete)
    {
        if (levelcomplete->objectName().isEmpty())
            levelcomplete->setObjectName("levelcomplete");
        levelcomplete->resize(754, 469);
        label = new QLabel(levelcomplete);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 20, 691, 101));
        QFont font;
        font.setPointSize(24);
        label->setFont(font);
        label_2 = new QLabel(levelcomplete);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(170, 120, 521, 41));
        QFont font1;
        font1.setPointSize(22);
        label_2->setFont(font1);
        pushButton = new QPushButton(levelcomplete);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(200, 193, 271, 91));
        QFont font2;
        font2.setPointSize(24);
        font2.setBold(true);
        pushButton->setFont(font2);
        pushButton_2 = new QPushButton(levelcomplete);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(200, 313, 271, 91));
        pushButton_2->setFont(font2);

        retranslateUi(levelcomplete);

        QMetaObject::connectSlotsByName(levelcomplete);
    } // setupUi

    void retranslateUi(QDialog *levelcomplete)
    {
        levelcomplete->setWindowTitle(QCoreApplication::translate("levelcomplete", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("levelcomplete", "Congratulations!!! You've completed the level.", nullptr));
        label_2->setText(QCoreApplication::translate("levelcomplete", " Do you wanna continue?", nullptr));
        pushButton->setText(QCoreApplication::translate("levelcomplete", "Continue", nullptr));
        pushButton_2->setText(QCoreApplication::translate("levelcomplete", "QUIT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class levelcomplete: public Ui_levelcomplete {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEVELCOMPLETE_H
