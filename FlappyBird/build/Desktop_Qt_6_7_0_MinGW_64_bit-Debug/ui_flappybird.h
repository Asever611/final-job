/********************************************************************************
** Form generated from reading UI file 'flappybird.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FLAPPYBIRD_H
#define UI_FLAPPYBIRD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FlappyBird
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *FlappyBird)
    {
        if (FlappyBird->objectName().isEmpty())
            FlappyBird->setObjectName("FlappyBird");
        FlappyBird->resize(800, 600);
        centralwidget = new QWidget(FlappyBird);
        centralwidget->setObjectName("centralwidget");
        FlappyBird->setCentralWidget(centralwidget);
        menubar = new QMenuBar(FlappyBird);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
        FlappyBird->setMenuBar(menubar);
        statusbar = new QStatusBar(FlappyBird);
        statusbar->setObjectName("statusbar");
        FlappyBird->setStatusBar(statusbar);

        retranslateUi(FlappyBird);

        QMetaObject::connectSlotsByName(FlappyBird);
    } // setupUi

    void retranslateUi(QMainWindow *FlappyBird)
    {
        FlappyBird->setWindowTitle(QCoreApplication::translate("FlappyBird", "FlappyBird", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FlappyBird: public Ui_FlappyBird {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FLAPPYBIRD_H
