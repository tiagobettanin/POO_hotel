/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *lineEditSenha;
    QLabel *label;
    QLabel *laabel_2;
    QLabel *labelErro;
    QPushButton *pushButtonAtenticar;
    QLineEdit *lineEditUsuario;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        lineEditSenha = new QLineEdit(centralwidget);
        lineEditSenha->setObjectName("lineEditSenha");
        lineEditSenha->setGeometry(QRect(320, 290, 141, 24));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(320, 190, 71, 20));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        laabel_2 = new QLabel(centralwidget);
        laabel_2->setObjectName("laabel_2");
        laabel_2->setGeometry(QRect(320, 260, 71, 20));
        laabel_2->setFont(font);
        labelErro = new QLabel(centralwidget);
        labelErro->setObjectName("labelErro");
        labelErro->setGeometry(QRect(320, 370, 391, 31));
        QFont font1;
        font1.setPointSize(12);
        labelErro->setFont(font1);
        pushButtonAtenticar = new QPushButton(centralwidget);
        pushButtonAtenticar->setObjectName("pushButtonAtenticar");
        pushButtonAtenticar->setGeometry(QRect(320, 340, 91, 24));
        pushButtonAtenticar->setFont(font1);
        lineEditUsuario = new QLineEdit(centralwidget);
        lineEditUsuario->setObjectName("lineEditUsuario");
        lineEditUsuario->setGeometry(QRect(320, 220, 141, 24));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Usu\303\241rio:", nullptr));
        laabel_2->setText(QCoreApplication::translate("MainWindow", "Senha:", nullptr));
        labelErro->setText(QString());
        pushButtonAtenticar->setText(QCoreApplication::translate("MainWindow", "Autenticar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
