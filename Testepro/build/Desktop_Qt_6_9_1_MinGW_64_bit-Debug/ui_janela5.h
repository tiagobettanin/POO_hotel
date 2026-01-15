/********************************************************************************
** Form generated from reading UI file 'janela5.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JANELA5_H
#define UI_JANELA5_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_Janela5
{
public:
    QTableWidget *reservasTableWidget;

    void setupUi(QDialog *Janela5)
    {
        if (Janela5->objectName().isEmpty())
            Janela5->setObjectName("Janela5");
        Janela5->resize(800, 600);
        reservasTableWidget = new QTableWidget(Janela5);
        reservasTableWidget->setObjectName("reservasTableWidget");
        reservasTableWidget->setGeometry(QRect(5, 5, 790, 590));
        reservasTableWidget->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);

        retranslateUi(Janela5);

        QMetaObject::connectSlotsByName(Janela5);
    } // setupUi

    void retranslateUi(QDialog *Janela5)
    {
        Janela5->setWindowTitle(QCoreApplication::translate("Janela5", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Janela5: public Ui_Janela5 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JANELA5_H
