/********************************************************************************
** Form generated from reading UI file 'janela3.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JANELA3_H
#define UI_JANELA3_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_janela3
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QComboBox *localComboBox;
    QComboBox *quartoComboBox;
    QDateEdit *dataCheckinEdit;
    QSpinBox *diariasSpinBox;
    QPushButton *consultarButton;

    void setupUi(QDialog *janela3)
    {
        if (janela3->objectName().isEmpty())
            janela3->setObjectName("janela3");
        janela3->resize(800, 600);
        label = new QLabel(janela3);
        label->setObjectName("label");
        label->setGeometry(QRect(200, 160, 240, 21));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        label_2 = new QLabel(janela3);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(200, 220, 240, 21));
        label_2->setFont(font);
        label_3 = new QLabel(janela3);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(200, 280, 240, 21));
        label_3->setFont(font);
        label_4 = new QLabel(janela3);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(200, 340, 240, 21));
        label_4->setFont(font);
        localComboBox = new QComboBox(janela3);
        localComboBox->setObjectName("localComboBox");
        localComboBox->setGeometry(QRect(200, 190, 131, 24));
        quartoComboBox = new QComboBox(janela3);
        quartoComboBox->setObjectName("quartoComboBox");
        quartoComboBox->setGeometry(QRect(200, 250, 131, 24));
        dataCheckinEdit = new QDateEdit(janela3);
        dataCheckinEdit->setObjectName("dataCheckinEdit");
        dataCheckinEdit->setGeometry(QRect(200, 310, 110, 25));
        dataCheckinEdit->setDateTime(QDateTime(QDate(2025, 1, 1), QTime(0, 0, 0)));
        diariasSpinBox = new QSpinBox(janela3);
        diariasSpinBox->setObjectName("diariasSpinBox");
        diariasSpinBox->setGeometry(QRect(200, 370, 42, 25));
        diariasSpinBox->setMinimum(1);
        consultarButton = new QPushButton(janela3);
        consultarButton->setObjectName("consultarButton");
        consultarButton->setGeometry(QRect(480, 260, 101, 31));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        consultarButton->setFont(font1);

        retranslateUi(janela3);

        QMetaObject::connectSlotsByName(janela3);
    } // setupUi

    void retranslateUi(QDialog *janela3)
    {
        janela3->setWindowTitle(QCoreApplication::translate("janela3", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("janela3", "Localidade:", nullptr));
        label_2->setText(QCoreApplication::translate("janela3", "Tipo de Quarto:", nullptr));
        label_3->setText(QCoreApplication::translate("janela3", "Data de Check-in:", nullptr));
        label_4->setText(QCoreApplication::translate("janela3", "N\303\272mero de Di\303\241rias:", nullptr));
        consultarButton->setText(QCoreApplication::translate("janela3", "Consultar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class janela3: public Ui_janela3 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JANELA3_H
