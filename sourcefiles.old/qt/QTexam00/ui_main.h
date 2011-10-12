/********************************************************************************
** Form generated from reading UI file 'main.ui'
**
** Created: Sun May 29 19:38:02 2011
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_H
#define UI_MAIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_main
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *main)
    {
        if (main->objectName().isEmpty())
            main->setObjectName(QString::fromUtf8("main"));
        main->resize(600, 400);
        menuBar = new QMenuBar(main);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        main->setMenuBar(menuBar);
        mainToolBar = new QToolBar(main);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        main->addToolBar(mainToolBar);
        centralWidget = new QWidget(main);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        main->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(main);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        main->setStatusBar(statusBar);

        retranslateUi(main);

        QMetaObject::connectSlotsByName(main);
    } // setupUi

    void retranslateUi(QMainWindow *main)
    {
        main->setWindowTitle(QApplication::translate("main", "main", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class main: public Ui_main {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_H
