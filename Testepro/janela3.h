#ifndef JANELA3_H
#define JANELA3_H

#include <QDialog>

namespace Ui {
class janela3;
}

class janela3 : public QDialog
{
    Q_OBJECT

public:
    explicit janela3(QWidget *parent = nullptr);
    ~janela3();

private slots:
    void on_consultarButton_clicked();

private:
    Ui::janela3 *ui;
    void carregarComboBoxes();

};

#endif // JANELA3_H
