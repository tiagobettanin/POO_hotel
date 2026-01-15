#ifndef JANELA4_H
#define JANELA4_H

#include <QDialog>
#include "backend.h"

namespace Ui {
class Janela4;
}

class Janela4 : public QDialog
{
    Q_OBJECT

public:
    explicit Janela4(Atendente* atendenteLogado, QWidget *parent = nullptr);
    ~Janela4();

private slots:
    void on_confirmarButton_clicked();

private:
    Ui::Janela4 *ui;
    Atendente* atendente;
    void carregarComboBoxes();
};

#endif // JANELA4_H
