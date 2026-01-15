#include "janela3.h"
#include "ui_janela3.h"
#include "backend.h"
#include <QMessageBox>
#include <QDate>

janela3::janela3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::janela3)
{
    ui->setupUi(this);
    this->setWindowTitle("Consulta de Disponibilidade");
    carregarComboBoxes();
    ui->dataCheckinEdit->setDate(QDate::currentDate());
}

janela3::~janela3()
{
    delete ui;
}

void janela3::carregarComboBoxes()
{
    ui->localComboBox->addItem("Jericoacoara");
    ui->localComboBox->addItem("CanoaQuebrada");
    ui->localComboBox->addItem("Cumbuco");

    ui->quartoComboBox->addItem("Solteiro");
    ui->quartoComboBox->addItem("Duplo");
    ui->quartoComboBox->addItem("Casal");
    ui->quartoComboBox->addItem("Triplo");
    ui->quartoComboBox->addItem("Quadruplo");
}

void janela3::on_consultarButton_clicked()
{
    QString local = ui->localComboBox->currentText();
    QString tipoQuarto = ui->quartoComboBox->currentText();
    QDate data = ui->dataCheckinEdit->date();
    int diarias = ui->diariasSpinBox->value();

    bool disponivel = BancoDeReservas::getInstancia()->checarDisponibilidade(
        local.toStdString(),
        tipoQuarto.toStdString(),
        data.toString("dd/MM/yyyy").toStdString(),
        diarias
        );

    if (disponivel) {
        QMessageBox::information(this, "Disponibilidade", "O quarto está disponível para o período selecionado!");
    } else {
        QMessageBox::warning(this, "Disponibilidade", "Indisponível! O quarto não está disponível para o período selecionado.");
    }
}
