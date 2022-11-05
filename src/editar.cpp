#include "editar.h"
#include "ui_editar.h"


Editar::Editar(QWidget *parent, int id, QString todo) :
    QDialog(parent),
    ui(new Ui::Editar)
{
    ui->setupUi(this);

    ui->label->setText(QString::number(id));
    ui->lineEdit->setText(todo);
}


Editar::~Editar()
{
    delete ui;
}


void Editar::on_pushButton_2_clicked()
{
    if(ui->lineEdit->text() == "")
    {
        QMessageBox::warning(this, "Aviso", "Campo não pode ficar vazio !");
        return;
    }

    QString id = ui->label->text();

    QSqlQuery query;
    QString sql = "UPDATE todos SET todos='" + ui->lineEdit->text() + "', curr_date=CURRENT_TIMESTAMP WHERE id=" + id;
    query.prepare(sql);

    if(query.exec())
    {
        close();
    }
    else
    {
        qDebug() << "Falha ao atualizar os dados";
    }
}


void Editar::on_pushButton_clicked()
{
    QString id = ui->label->text();

    QSqlQuery query;
    QString sql = "DELETE FROM todos WHERE id=" + id;
    query.prepare(sql);

    if(query.exec())
    {
        close();
    }
    else
    {
        qDebug() << "Falha ao deletar os dados";
    }
}

