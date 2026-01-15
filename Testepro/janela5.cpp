#include "janela5.h"
#include "ui_janela5.h"
#include "backend.h"
#include <QDate>
#include <algorithm>

Janela5::Janela5(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Janela5)
{
    ui->setupUi(this);
    this->setWindowTitle("Listagem de Todas as Reservas");
    configurarTabela();
    popularTabela();
}

Janela5::~Janela5()
{
    delete ui;
}

void Janela5::configurarTabela()
{
    ui->reservasTableWidget->setColumnCount(9);
    QStringList headers = {"Status", "Atendente", "Cliente", "CPF", "Local", "Quarto", "Check-in", "Diárias", "Valor Total"};
    ui->reservasTableWidget->setHorizontalHeaderLabels(headers);
    ui->reservasTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void Janela5::popularTabela()
{
    vector<Reserva> reservas = BancoDeReservas::getInstancia()->getReservas();
    std::sort(reservas.begin(), reservas.end(), [](const Reserva& a, const Reserva& b) {
        QDate dateA = QDate::fromString(QString::fromStdString(a.data), "dd/MM/yyyy");
        QDate dateB = QDate::fromString(QString::fromStdString(b.data), "dd/MM/yyyy");
        return dateA < dateB;
    });

    ui->reservasTableWidget->setRowCount(reservas.size());

    int linha = 0;
    for (const auto& reserva : reservas) {
        QTableWidgetItem *itemStatus = new QTableWidgetItem(reserva.confirmada ? "Confirmada" : "Pendente");
        QTableWidgetItem *itemAtendente = new QTableWidgetItem(QString::fromStdString(reserva.atendente));
        QTableWidgetItem *itemCliente = new QTableWidgetItem(QString::fromStdString(reserva.cliente));
        QTableWidgetItem *itemCpf = new QTableWidgetItem(QString::fromStdString(reserva.cpf));
        QTableWidgetItem *itemLocal = new QTableWidgetItem(QString::fromStdString(reserva.local));
        QTableWidgetItem *itemQuarto = new QTableWidgetItem(QString::fromStdString(reserva.tipoQuarto));
        QTableWidgetItem *itemData = new QTableWidgetItem(QString::fromStdString(reserva.data));
        QTableWidgetItem *itemDiarias = new QTableWidgetItem(QString::number(reserva.diarias));
        QTableWidgetItem *itemValor = new QTableWidgetItem(QString("R$ %1").arg(reserva.valorTotal, 0, 'f', 2));

        QColor corFundo = reserva.confirmada ? QColor(200, 255, 200) : QColor(255, 255, 200);
        itemStatus->setBackground(corFundo);

        ui->reservasTableWidget->setItem(linha, 0, itemStatus);
        ui->reservasTableWidget->setItem(linha, 1, itemAtendente);
        ui->reservasTableWidget->setItem(linha, 2, itemCliente);
        ui->reservasTableWidget->setItem(linha, 3, itemCpf);
        ui->reservasTableWidget->setItem(linha, 4, itemLocal);
        ui->reservasTableWidget->setItem(linha, 5, itemQuarto);
        ui->reservasTableWidget->setItem(linha, 6, itemData);
        ui->reservasTableWidget->setItem(linha, 7, itemDiarias);
        ui->reservasTableWidget->setItem(linha, 8, itemValor);

        linha++;
    }
}
