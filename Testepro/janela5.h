#ifndef JANELA5_H
#define JANELA5_H

#include <QDialog>

namespace Ui {
class Janela5;
}

class Janela5 : public QDialog
{
    Q_OBJECT

public:
    explicit Janela5(QWidget *parent = nullptr);
    ~Janela5();

private:
    Ui::Janela5 *ui;
    void popularTabela();
    void configurarTabela();
};

#endif // JANELA5_H
