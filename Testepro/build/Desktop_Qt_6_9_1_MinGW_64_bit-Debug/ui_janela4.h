/********************************************************************************
** Form generated from reading UI file 'janela4.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JANELA4_H
#define UI_JANELA4_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_Janela4
{
public:
    QLabel *label_4;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QSpinBox *diariasSpinBox;
    QDateEdit *dataCheckinEdit;
    QComboBox *quartoComboBox;
    QComboBox *localComboBox;
    QLineEdit *nomeLineEdit;
    QLineEdit *cpfLineEdit;
    QComboBox *descontoComboBox;
    QFrame *line;
    QPushButton *confirmarButton;
    QLabel *label_8;
    QTextEdit *resumoTextEdit;
    QLabel *label_9;

    void setupUi(QDialog *Janela4)
    {
        if (Janela4->objectName().isEmpty())
            Janela4->setObjectName("Janela4");
        Janela4->resize(800, 600);
        label_4 = new QLabel(Janela4);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 230, 240, 21));
        QFont font;
        font.setPointSize(16);
        label_4->setFont(font);
        label = new QLabel(Janela4);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 50, 240, 21));
        label->setFont(font);
        label_2 = new QLabel(Janela4);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 110, 240, 21));
        label_2->setFont(font);
        label_3 = new QLabel(Janela4);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 170, 240, 21));
        label_3->setFont(font);
        label_5 = new QLabel(Janela4);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 290, 240, 21));
        label_5->setFont(font);
        label_6 = new QLabel(Janela4);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 350, 240, 21));
        label_6->setFont(font);
        label_7 = new QLabel(Janela4);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 410, 240, 21));
        label_7->setFont(font);
        diariasSpinBox = new QSpinBox(Janela4);
        diariasSpinBox->setObjectName("diariasSpinBox");
        diariasSpinBox->setGeometry(QRect(10, 260, 42, 25));
        diariasSpinBox->setMinimum(1);
        dataCheckinEdit = new QDateEdit(Janela4);
        dataCheckinEdit->setObjectName("dataCheckinEdit");
        dataCheckinEdit->setGeometry(QRect(10, 200, 110, 25));
        dataCheckinEdit->setDateTime(QDateTime(QDate(2025, 1, 1), QTime(6, 0, 0)));
        quartoComboBox = new QComboBox(Janela4);
        quartoComboBox->setObjectName("quartoComboBox");
        quartoComboBox->setGeometry(QRect(10, 140, 131, 24));
        localComboBox = new QComboBox(Janela4);
        localComboBox->setObjectName("localComboBox");
        localComboBox->setGeometry(QRect(10, 80, 131, 24));
        nomeLineEdit = new QLineEdit(Janela4);
        nomeLineEdit->setObjectName("nomeLineEdit");
        nomeLineEdit->setGeometry(QRect(10, 320, 321, 24));
        cpfLineEdit = new QLineEdit(Janela4);
        cpfLineEdit->setObjectName("cpfLineEdit");
        cpfLineEdit->setGeometry(QRect(10, 380, 321, 24));
        descontoComboBox = new QComboBox(Janela4);
        descontoComboBox->setObjectName("descontoComboBox");
        descontoComboBox->setGeometry(QRect(10, 440, 131, 24));
        line = new QFrame(Janela4);
        line->setObjectName("line");
        line->setGeometry(QRect(400, -40, 3, 800));
        QFont font1;
        font1.setPointSize(14);
        line->setFont(font1);
        line->setFrameShadow(QFrame::Shadow::Raised);
        line->setLineWidth(15);
        line->setFrameShape(QFrame::Shape::VLine);
        confirmarButton = new QPushButton(Janela4);
        confirmarButton->setObjectName("confirmarButton");
        confirmarButton->setGeometry(QRect(10, 490, 161, 31));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        confirmarButton->setFont(font2);
        label_8 = new QLabel(Janela4);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(420, 20, 240, 21));
        QFont font3;
        font3.setPointSize(16);
        font3.setBold(true);
        label_8->setFont(font3);
        resumoTextEdit = new QTextEdit(Janela4);
        resumoTextEdit->setObjectName("resumoTextEdit");
        resumoTextEdit->setGeometry(QRect(420, 50, 361, 531));
        resumoTextEdit->setReadOnly(true);
        label_9 = new QLabel(Janela4);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(10, 20, 291, 21));
        label_9->setFont(font3);

        retranslateUi(Janela4);

        QMetaObject::connectSlotsByName(Janela4);
    } // setupUi

    void retranslateUi(QDialog *Janela4)
    {
        Janela4->setWindowTitle(QCoreApplication::translate("Janela4", "Dialog", nullptr));
        label_4->setText(QCoreApplication::translate("Janela4", "N\303\272mero de Di\303\241rias:", nullptr));
        label->setText(QCoreApplication::translate("Janela4", "Localidade:", nullptr));
        label_2->setText(QCoreApplication::translate("Janela4", "Tipo de Quarto:", nullptr));
        label_3->setText(QCoreApplication::translate("Janela4", "Data de Check-in:", nullptr));
        label_5->setText(QCoreApplication::translate("Janela4", "Nome do Cliente:", nullptr));
        label_6->setText(QCoreApplication::translate("Janela4", "CPF do Cliente:", nullptr));
        label_7->setText(QCoreApplication::translate("Janela4", "Desconto:", nullptr));
        confirmarButton->setText(QCoreApplication::translate("Janela4", "Confirmar Reserva", nullptr));
        label_8->setText(QCoreApplication::translate("Janela4", "Resumo da Reserva:", nullptr));
        label_9->setText(QCoreApplication::translate("Janela4", "Inserir Dados para Reserva", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Janela4: public Ui_Janela4 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JANELA4_H
