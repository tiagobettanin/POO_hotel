/********************************************************************************
** Form generated from reading UI file 'janela2.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JANELA2_H
#define UI_JANELA2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Janela2
{
public:
    QLabel *objectNome;
    QLabel *labelBoasVindas;
    QPushButton *consultaButton;
    QPushButton *reservaButton;
    QPushButton *listarButton;
    QPushButton *sairButton;

    void setupUi(QDialog *Janela2)
    {
        if (Janela2->objectName().isEmpty())
            Janela2->setObjectName("Janela2");
        Janela2->resize(800, 600);
        objectNome = new QLabel(Janela2);
        objectNome->setObjectName("objectNome");
        objectNome->setGeometry(QRect(230, 180, 301, 31));
        QFont font;
        font.setPointSize(11);
        objectNome->setFont(font);
        objectNome->setAlignment(Qt::AlignmentFlag::AlignCenter);
        labelBoasVindas = new QLabel(Janela2);
        labelBoasVindas->setObjectName("labelBoasVindas");
        labelBoasVindas->setGeometry(QRect(110, 140, 551, 41));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setStyleStrategy(QFont::PreferDefault);
        labelBoasVindas->setFont(font1);
        labelBoasVindas->setAlignment(Qt::AlignmentFlag::AlignCenter);
        consultaButton = new QPushButton(Janela2);
        consultaButton->setObjectName("consultaButton");
        consultaButton->setGeometry(QRect(280, 220, 201, 24));
        consultaButton->setFont(font);
        reservaButton = new QPushButton(Janela2);
        reservaButton->setObjectName("reservaButton");
        reservaButton->setGeometry(QRect(280, 250, 201, 24));
        reservaButton->setFont(font);
        listarButton = new QPushButton(Janela2);
        listarButton->setObjectName("listarButton");
        listarButton->setGeometry(QRect(280, 280, 201, 24));
        listarButton->setFont(font);
        sairButton = new QPushButton(Janela2);
        sairButton->setObjectName("sairButton");
        sairButton->setGeometry(QRect(280, 310, 201, 24));
        sairButton->setFont(font);

        retranslateUi(Janela2);

        QMetaObject::connectSlotsByName(Janela2);
    } // setupUi

    void retranslateUi(QDialog *Janela2)
    {
        Janela2->setWindowTitle(QCoreApplication::translate("Janela2", "Dialog", nullptr));
        objectNome->setText(QCoreApplication::translate("Janela2", "TextLabel", nullptr));
        labelBoasVindas->setText(QCoreApplication::translate("Janela2", "TextLabel", nullptr));
        consultaButton->setText(QCoreApplication::translate("Janela2", "Consultar Disponibilidade", nullptr));
        reservaButton->setText(QCoreApplication::translate("Janela2", "Realizar Reserva", nullptr));
        listarButton->setText(QCoreApplication::translate("Janela2", "Listar Reservas Feitas", nullptr));
        sairButton->setText(QCoreApplication::translate("Janela2", "Sair do Sistema", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Janela2: public Ui_Janela2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JANELA2_H
