/********************************************************************************
** Form generated from reading UI file 'QtWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTWINDOW_H
#define UI_QTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QMenuBar *menubar;

    void setupUi(QMainWindow *QtWindow)
    {
        if (QtWindow->objectName().isEmpty())
            QtWindow->setObjectName(QString::fromUtf8("QtWindow"));
        QtWindow->resize(800, 600);
        centralwidget = new QWidget(QtWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setMaximumSize(QSize(800, 580));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(150, 170, 256, 192));
        QtWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(QtWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setEnabled(true);
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menubar->setLayoutDirection(Qt::RightToLeft);
        QtWindow->setMenuBar(menubar);

        retranslateUi(QtWindow);

        QMetaObject::connectSlotsByName(QtWindow);
    } // setupUi

    void retranslateUi(QMainWindow *QtWindow)
    {
        QtWindow->setWindowTitle(QCoreApplication::translate("QtWindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtWindow: public Ui_QtWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTWINDOW_H
