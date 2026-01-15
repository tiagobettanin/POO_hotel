#include "janela4.h"
#include "ui_janela4.h"
#include <QMessageBox>
#include <QDate>

Janela4::Janela4(Atendente* atendenteLogado, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Janela4)
{
    ui->setupUi(this);
    this->atendente = atendenteLogado;
    this->setWindowTitle("Realizar Nova Reserva");
    carregarComboBoxes();
    ui->dataCheckinEdit->setDate(QDate::currentDate());
}

Janela4::~Janela4()
{
    delete ui;
}

void Janela4::carregarComboBoxes()
{
    ui->localComboBox->addItems({"Jericoacoara", "CanoaQuebrada", "Cumbuco"});
    ui->quartoComboBox->addItems({"Solteiro", "Duplo", "Casal", "Triplo", "Quadruplo"});
    ui->descontoComboBox->addItems({"Sem desconto", "Cliente VIP (10%)", "Baixa temporada (20%)"});
}

void Janela4::on_confirmarButton_clicked()
{
    QString local = ui->localComboBox->currentText();
    QString tipoQuarto = ui->quartoComboBox->currentText();
    QDate data = ui->dataCheckinEdit->date();
    int diarias = ui->diariasSpinBox->value();
    QString nomeCliente = ui->nomeLineEdit->text();
    QString cpfCliente = ui->cpfLineEdit->text();
    int descontoIndex = ui->descontoComboBox->currentIndex();

    if (nomeCliente.isEmpty() || cpfCliente.isEmpty()) {
        QMessageBox::warning(this, "Erro", "Por favor, preencha o nome e o CPF do cliente.");
        return;
    }

    Desconto* desconto;
    if (descontoIndex == 1)      desconto = new DescontoVIP();
    else if (descontoIndex == 2) desconto = new DescontoBaixa();
    else                         desconto = new SemDesconto();

    float valorDiaria = 0;
    if (tipoQuarto == "Solteiro")      valorDiaria = 200;
    else if (tipoQuarto == "Duplo")    valorDiaria = 300;
    else if (tipoQuarto == "Casal")    valorDiaria = 350;
    else if (tipoQuarto == "Triplo")   valorDiaria = 450;
    else if (tipoQuarto == "Quadruplo") valorDiaria = 550;

    float valorBruto = valorDiaria * diarias;
    float valorFinal = desconto->aplicar(valorBruto);
    float valorDoDesconto = valorBruto - valorFinal;

    string dataStr = data.toString("dd/MM/yyyy").toStdString();
    string chave = local.toStdString() + "_" + tipoQuarto.toStdString() + "_" + dataStr;
    string statusDisp = BancoDeReservas::getInstancia()->verificarECancelarReservaPendente(chave, dataStr, diarias);

    if (statusDisp.find("Indisponível") != string::npos) {
        QMessageBox::critical(this, "Erro na Reserva", QString::fromStdString(statusDisp));
        delete desconto;
        return;
    }

    Reserva novaReserva;
    novaReserva.atendente = this->atendente->getNome();
    novaReserva.cliente = nomeCliente.toStdString();
    novaReserva.cpf = cpfCliente.toStdString();
    novaReserva.local = local.toStdString();
    novaReserva.tipoQuarto = tipoQuarto.toStdString();
    novaReserva.data = dataStr;
    novaReserva.diarias = diarias;
    novaReserva.desc = desconto->descricao();
    novaReserva.valorTotal = valorFinal;
    novaReserva.entrada = novaReserva.valorTotal / 3.0f;
    novaReserva.confirmada = true;

    BancoDeReservas::getInstancia()->criarNovaReserva(novaReserva);

    QString resumo = QString("Reserva Confirmada para: %1 (CPF: %2)\n")
                         .arg(nomeCliente, cpfCliente) +
                     QString("Local: %1, Quarto: %2\n").arg(local, tipoQuarto) +
                     QString("Check-in: %1 por %2 diárias\n")
                         .arg(data.toString("dd/MM/yyyy"))
                         .arg(diarias) +
                     QString("\nSubtotal: R$ %1\n").arg(valorBruto, 0, 'f', 2) +
                     QString("Desconto (%1): - R$ %2\n")
                         .arg(QString::fromStdString(desconto->descricao()), QString::number(valorDoDesconto, 'f', 2)) +
                     QString("VALOR FINAL: R$ %1").arg(valorFinal, 0, 'f', 2);

    if (!ui->resumoTextEdit->toPlainText().isEmpty()) {
        ui->resumoTextEdit->append("\n----------------------------------------\n");
    }
    ui->resumoTextEdit->append(resumo);

    QMessageBox::information(this, "Sucesso", "Reserva realizada com sucesso!");

    ui->nomeLineEdit->clear();
    ui->cpfLineEdit->clear();
    ui->nomeLineEdit->setFocus();

    delete desconto;
}
