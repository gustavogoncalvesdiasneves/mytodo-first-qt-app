#include "mytodo.h"
#include "ui_mytodo.h"


MyTodo::MyTodo(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MyTodo)
{
    ui->setupUi(this);

    //start();
    db.setDatabaseName(user);


    // IF TERNARIO
    !db.open() ? qDebug() << "Falha ao encontrar o arquivo do banco: " + user : qDebug() << "Arquivo do banco encontrado com sucesso!";
    show_data();
}

MyTodo::~MyTodo()
{
    delete ui;
}


// Uso especifico em sistemas Unix
//
//void MyTodo::start()
//{
//    QFile quser(user);
//
//    if(!quser.exists())
//    {
//        QFile::copy(data, user);
//        //system("chmod 600 ~/.config/mytodo.db"); // Define as permissões para arquivos e diretorios em sistemas Unix
//        qDebug() << "O arquivo inicial foi copiado";
//    }
//}


void MyTodo::show_data()
{
    QSqlQuery query;
    QString sql = "SELECT * FROM todos ORDER BY id DESC";
    query.prepare(sql);

    if(query.exec())
    {
        int i = 0;

        ui->tableWidget->setColumnCount(3);

        while(query.next())
        {
            ui->tableWidget->insertRow(i); // insere os dados da base
            ui->tableWidget->setItem(i, 0, new QTableWidgetItem(query.value(0).toString()) );
            ui->tableWidget->setItem(i, 1, new QTableWidgetItem(query.value(1).toString()) );
            ui->tableWidget->setItem(i, 2, new QTableWidgetItem(query.value(2).toString()) );

            ++i;
        }


        QStringList headers = {"ID", "Tarefa", "Data/Hora"};
        ui->tableWidget->setHorizontalHeaderLabels(headers);

        ui->tableWidget->setColumnWidth(0, 30);
        ui->tableWidget->setColumnWidth(1, 360);
        ui->tableWidget->setColumnWidth(2, 120);


        // Limpar as linhas sempre que atualizar a tabela
        while (i < ui->tableWidget->rowCount())
        {
            ui->tableWidget->removeRow(i);
        }


        ui->tableWidget->verticalHeader()->setVisible(false);
    }
    else
    {
        qDebug() << "Falha ao consultar os dados";
    }
}


void MyTodo::on_actionSair_triggered()
{
    close();
}


void MyTodo::on_actionSobre_triggered()
{
    QMessageBox::about(this,
                       "Sobre esse projeto",
                       "<h2>MyTodo 1.0.0</h2>"
                       "<p>Desenvolvido por Marcus Faria<br/>"
                       "<i>Copyright (c) 2022 mfaria-tech<i/></p>"
                       "<p>Primeira aplicação versionada em C++.<br/>"
                       "Projeto desenvolvido com o intuito de aplicar<br/>"
                       "os conhecimentos aprendidos durante<br/>"
                       "o estudo com o Framework Qt</p>"
                       "<p>Conheça outros projetos: <a href='https://github.com/mfaria-tech'>github.com/mfaria-tech</p>"
                       "<p><i>The program is provided AS IS with NO WARRANTY<br/>"
                       "OF DESIGN, MERCHANTABILITY AND FITNESS FOR A<br/>"
                       "PARTICULAR PURPOSE.</i></p>");
}


void MyTodo::on_pushButton_clicked()
{
    if(ui->lineEdit->text() == "")
    {
        QMessageBox::warning(this, "Aviso", "Preencha o campo da tarefa.");
        return;
    }

    if(!db.isOpen())
    {
        QMessageBox::warning(this, "Aviso", "Falha ao conectar ao banco de dados.");
        return;
    }


    QSqlQuery query;
    QString sql = "INSERT INTO todos ( todos ) VALUES ( '" + ui->lineEdit->text() + "' )";
    query.prepare(sql);

    if(query.exec())
    {
        ui->statusbar->showMessage("Dados inseridos com sucesso");


        QTimer::singleShot(2000, [&](){ ui->statusbar->showMessage(""); } );


        ui->lineEdit->clear();
        ui->lineEdit->setFocus();

        ui->tableWidget->clear();
        show_data();
    }
    else
    {
        qDebug() << "Falha ao inserir dados: " + sql;
    }
}


void MyTodo::on_tableWidget_cellClicked(int row, int column)
{
    column = 0;
    int id = ui->tableWidget->item(row, column)->text().toInt();
    QString todo = ui->tableWidget->item(row, 1)->text();

    Editar e(this, id, todo);
    e.exec();

    show_data();
}

