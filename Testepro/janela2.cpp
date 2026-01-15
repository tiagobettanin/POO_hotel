#include "janela2.h"
#include "ui_janela2.h"
#include <QString>
#include <QDir>
#include <QMessageBox>
#include <QStandardPaths>

#include<janela3.h>
#include<janela4.h>
#include<janela5.h>

Janela2::Janela2(Atendente* atendente, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Janela2)
{
    ui->setupUi(this);
    this->atendenteLogado = atendente;
    this->setWindowTitle("Tela Principal");

    QString mensagem = "Login bem-sucedido!";

    QString mensagem2 =  "Bem-vindo(a), " + QString::fromStdString(atendenteLogado->getNome());

    if (ui->labelBoasVindas) {
        ui->labelBoasVindas->setText(mensagem);
    }

    if( ui->objectNome){
        ui->objectNome->setText(mensagem2);
    }
}

Janela2::~Janela2()
{
    delete ui;
}

void Janela2::on_consultaButton_clicked()
{
    janela3 telaConsulta(this);
    telaConsulta.exec();
}

void Janela2::on_reservaButton_clicked()
{
    Janela4 telaReserva(this->atendenteLogado, this);
    telaReserva.exec();
}

void Janela2::on_listarButton_clicked()
{
    Janela5 telaListagem(this);
    telaListagem.exec();
}

void Janela2::on_sairButton_clicked()
{
    bool testeArquivo = BancoDeReservas::getInstancia()->gerarArquivo();

    if(testeArquivo) {
        QString caminhoDaApp = QApplication::applicationDirPath();
        QString caminhoCompleto = QDir(caminhoDaApp).filePath("dados_reservas.txt");

        QMessageBox::information(this,
                                 "Arquivo Salvo com Sucesso",
                                 QString("O arquivo 'dados_reservas.txt' foi salvo na pasta da aplicação.\n\nCaminho: %1").arg(caminhoCompleto)
                                 );
    } else {
        QMessageBox::warning(this,
                             "Erro ao Salvar",
                             "Não foi possível gerar o arquivo de reservas.");
    }

    QApplication::quit();
}

