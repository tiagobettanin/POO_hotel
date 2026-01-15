#ifndef JANELA2_H
#define JANELA2_H

#include <QDialog>
#include "backend.h"

namespace Ui {
class Janela2;
}

class Janela2 : public QDialog
{
    Q_OBJECT

public:
    explicit Janela2(Atendente* atendente, QWidget *parent = nullptr);
    ~Janela2();

private slots:
    void on_consultaButton_clicked();

    void on_reservaButton_clicked();

    void on_listarButton_clicked();

    void on_sairButton_clicked();

private:
    Ui::Janela2 *ui;
    Atendente* atendenteLogado;
};

#endif // JANELA2_H
