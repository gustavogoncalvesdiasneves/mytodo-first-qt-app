#ifndef MYTODO_H
#define MYTODO_H

#include <QMessageBox>
#include <QMainWindow>
#include <QtSql>
#include <QFileInfo>
#include <QDebug>
#include "editar.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MyTodo; }
QT_END_NAMESPACE

class MyTodo : public QMainWindow
{
    Q_OBJECT

public:
    MyTodo(QWidget *parent = nullptr);
    //QString path = getenv("HOME"); // Uso especifico para sistemas Unix
    //void start();
    QString dir = qApp->applicationDirPath();
    QString user = dir + "/mytodo.db";

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    void show_data();
    ~MyTodo();

private slots:
    void on_actionSair_triggered();

    void on_actionSobre_triggered();

    void on_pushButton_clicked();

    void on_tableWidget_cellClicked(int row, int column);

private:
    Ui::MyTodo *ui;
};
#endif // MYTODO_H
