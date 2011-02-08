#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "aboutwindow.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionUrDiary_triggered()
{
    //Show "about dialog"
    AboutWindow about;
    about.exec();
}

void MainWindow::on_actionClose_triggered()
{
    this->close();
}

void MainWindow::setDbQuery(QSqlQuery *query){
    this->dbQuery = query;
}
