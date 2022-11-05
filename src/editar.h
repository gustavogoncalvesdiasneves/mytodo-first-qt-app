#ifndef EDITAR_H
#define EDITAR_H

#include <QDialog>
#include <QtSql>
#include <QDebug>
#include <QMessageBox>


namespace Ui {
class Editar;
}

class Editar : public QDialog
{
    Q_OBJECT

public:
    explicit Editar(QWidget *parent = nullptr, int id = 0, QString todo = NULL);
    ~Editar();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Editar *ui;
};

#endif // EDITAR_H
