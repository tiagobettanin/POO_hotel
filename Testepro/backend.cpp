#include "backend.h"

#include <QDate>
#include <QStandardPaths>
#include <QDir>


float SemDesconto::aplicar(float valor) {
    return valor;
}
string SemDesconto::descricao() {
    return "Sem desconto";
}

float DescontoVIP::aplicar(float valor) {
    return valor * 0.9f;
}
string DescontoVIP::descricao() {
    return "Cliente VIP (10%)";
}

float DescontoBaixa::aplicar(float valor) {
    return valor * 0.8f;
}
string DescontoBaixa::descricao() {
    return "Baixa temporada (20%)";
}

// ================== ATENDENTE ==================

Atendente::Atendente(string nome, string senha) {
    this->nome = nome;
    this->senha = senha;
}

bool Atendente::autenticar(string senhaInformada) {
    return senhaInformada == senha;
}

string Atendente::getNome() {
    return nome;
}

void Atendente::alterarSenha(string novaSenha) {
    senha = novaSenha;
}

// ================== CALENDARIO ==================

Calendario::Calendario() {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 31; j++) {
            calendario[i][j] = 0;
        }
    }
    calendario[1][28] = -1; calendario[1][29] = -1; calendario[1][30] = -1;
    calendario[3][30] = -1;
    calendario[5][30] = -1;
    calendario[8][30] = -1;
    calendario[10][30] = -1;
}

bool Calendario::disponibilidadeCalendario(string data, int dias) {
    int dia = stoi(data.substr(0, 2)) - 1;
    int mes = stoi(data.substr(3, 2)) - 1;

    for (int i = 0; i < dias; i++) {
        if (mes >= 12 || dia >= 31 || calendario[mes][dia] == 1 || calendario[mes][dia] == -1) {
            return false;
        }
        dia++;
        if (dia >= 31 || calendario[mes][dia] == -1) {
            mes++;
            dia = 0;
            if (mes >= 12) return false;
        }
    }
    return true;
}

void Calendario::marcarComoOcupado(string data, int dias) {
    int dia = stoi(data.substr(0, 2)) - 1;
    int mes = stoi(data.substr(3, 2)) - 1;

    for (int i = 0; i < dias; i++) {
        if (mes < 12 && dia < 31 && calendario[mes][dia] == 0) {
            calendario[mes][dia] = 1;
        }
        dia++;
        if (dia >= 31 || (mes < 12 && calendario[mes][dia] == -1) ) {
            mes++;
            dia = 0;
        }
    }
}


// ================== BANCO DE RESERVAS (SINGLETON) ==================

BancoDeReservas* BancoDeReservas::instancia = nullptr;

BancoDeReservas::BancoDeReservas() {
    this->calendario = new Calendario();

    atendentesRegistrados.push_back(Atendente("atendente1", "senha1"));
    atendentesRegistrados.push_back(Atendente("atendente2", "senha2"));
    atendentesRegistrados.push_back(Atendente("atendente3", "senha3"));
    atendentesRegistrados.push_back(Atendente("atendente4", "senha4"));
}

BancoDeReservas* BancoDeReservas::getInstancia() {
    if (!instancia) {
        instancia = new BancoDeReservas();
    }
    return instancia;
}

Atendente* BancoDeReservas::autenticar(const string& login, const string& senha) {
    for (Atendente& atendente : atendentesRegistrados) {
        if (atendente.getNome() == login) {
            if (atendente.autenticar(senha)) {
                return &atendente;
            } else {
                return nullptr;
            }
        }
    }
    return nullptr;
}

bool BancoDeReservas::checarDisponibilidade(const string& local, const string& tipoQuarto, const string& data, int diarias) {
    QDate dataInicioNova = QDate::fromString(QString::fromStdString(data), "dd/MM/yyyy");
    QDate dataFimNova = dataInicioNova.addDays(diarias - 1);

    for (const Reserva& r : reservas) {
        if (r.local == local && r.tipoQuarto == tipoQuarto && r.confirmada) {

            QDate dataInicioExistente = QDate::fromString(QString::fromStdString(r.data), "dd/MM/yyyy");
            QDate dataFimExistente = dataInicioExistente.addDays(r.diarias - 1);

            if (dataInicioNova <= dataFimExistente && dataFimNova >= dataInicioExistente) {
                return false;
            }
        }
    }

    return true;
}

string BancoDeReservas::verificarECancelarReservaPendente(const string& chave, const string& data, int diarias) {
    for (int i = 0; i < reservas.size(); ++i) {
        string chaveReserva = reservas[i].local + "_" + reservas[i].tipoQuarto + "_" + reservas[i].data;
        if (chaveReserva == chave) {
            if (reservas[i].confirmada) {
                return "Indisponível: Já existe uma reserva CONFIRMADA para esta data e quarto.";
            } else {
                string msg = "Aviso: A reserva pendente do cliente " + reservas[i].cliente + " (CPF: " + reservas[i].cpf + ") foi cancelada por falta de pagamento.";
                reservas.erase(reservas.begin() + i);
                if(!calendario->disponibilidadeCalendario(data, diarias)){
                    return "Indisponível: O período solicitado não está mais disponível no calendário.";
                }
                return msg;
            }
        }
    }
    if(!calendario->disponibilidadeCalendario(data, diarias)){
        return "Indisponível: O período solicitado conflita com outra reserva no calendário.";
    }

    return "Disponível";
}

void BancoDeReservas::criarNovaReserva(const Reserva& r) {
    this->reservas.push_back(r);

}

const vector<Reserva>& BancoDeReservas::getReservas() const {
    return reservas;
}

bool BancoDeReservas::gerarArquivo() {
    FILE *arquivo = fopen("dados_reservas.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo de reservas.\n");
        return false;
    }

    fprintf(arquivo, "\n=== Relatório de Reservas ===\n\n");

    for (const Reserva& r : reservas) {
        float valorDiaria = 0;
        if (r.tipoQuarto == "Solteiro")      valorDiaria = 200;
        else if (r.tipoQuarto == "Duplo")    valorDiaria = 300;
        else if (r.tipoQuarto == "Casal")    valorDiaria = 350;
        else if (r.tipoQuarto == "Triplo")   valorDiaria = 450;
        else if (r.tipoQuarto == "Quadruplo") valorDiaria = 550;

        float valorBruto = valorDiaria * r.diarias;
        float valorDoDesconto = valorBruto - r.valorTotal;

        fprintf(arquivo,
                "Atendente: %s\n"
                "Cliente: %s - CPF: %s\n"
                "Local: %s, Quarto: %s\n"
                "Check-in: %s, Diárias: %d\n"
                "Subtotal: R$%.2f\n"
                "Desconto (%s): - R$%.2f\n"
                "VALOR FINAL: R$%.2f\n"
                "Entrada: R$%.2f\n"
                "Status: %s\n\n",
                r.atendente.c_str(),
                r.cliente.c_str(), r.cpf.c_str(),
                r.local.c_str(), r.tipoQuarto.c_str(),
                r.data.c_str(), r.diarias,
                valorBruto,
                r.desc.c_str(),
                valorDoDesconto,
                r.valorTotal,
                r.entrada,
                r.confirmada ? "Confirmada" : "Pendente");
    }

    fclose(arquivo);
    return true;
}
