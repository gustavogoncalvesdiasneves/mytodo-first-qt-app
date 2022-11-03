#ifndef MYTODO_H
#define MYTODO_H

#include <QMainWindow>
#include <QMessageBox>
#include <QtSql>
#include <QFileInfo>
#include <QDebug>


QT_BEGIN_NAMESPACE
namespace Ui { class MyTodo; }
QT_END_NAMESPACE

class MyTodo : public QMainWindow
{
    Q_OBJECT

public:
    MyTodo(QWidget *parent = nullptr);
    QString path = "C:/Users/mfaria/OneDrive/logica/study-teste/cpp-studies/MyTodo";
    void start();
    QString data = ":/data/mytodo.db";
    QString user = path + "/.config/mytodo.db";

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    void show_data();
    ~MyTodo();

private slots:
    void on_actionSair_triggered();

    void on_actionSobre_triggered();

private:
    Ui::MyTodo *ui;
};
#endif // MYTODO_H
