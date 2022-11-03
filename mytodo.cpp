#include "mytodo.h"
#include "ui_mytodo.h"

MyTodo::MyTodo(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MyTodo)
{
    ui->setupUi(this);
}

MyTodo::~MyTodo()
{
    delete ui;
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
                       "<i>Copyright 2022 mfaria-tech<i/></p>"
                       "<p>Primeira aplicação versionada em C++.<br/>"
                       "Projeto desenvolvido com o intuito de aplicar<br/>"
                       "os conhecimentos aprendidos durante<br/>"
                       "o estudo com o Framework Qt</p>"
                       "<p>Conheça outros projetos: <a href='https://github.com/mfaria-tech'>github.com/mfaria-tech</p>"
                       "<p><i>The program is provided AS IS with NO WARRANTY<br/>"
                       "OF DESIGN, MERCHANTABILITY AND FITNESS FOR A<br/>"
                       "PARTICULAR PURPOSE.</i></p>");
}

