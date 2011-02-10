#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "aboutwindow.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDate>

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

void MainWindow::disableForm(){
    ui->plainTextEdit->setDisabled(true);
    ui->plainTextEdit_2->setDisabled(true);
    ui->plainTextEdit_3->setDisabled(true);
    ui->plainTextEdit_4->setDisabled(true);
    ui->plainTextEdit_5->setDisabled(true);
    ui->plainTextEdit_6->setDisabled(true);
    ui->plainTextEdit_7->setDisabled(true);
    ui->plainTextEdit_8->setDisabled(true);
    ui->lineEdit_anniversary->setDisabled(true);
    ui->lineEdit_birth->setDisabled(true);
    ui->lineEdit_fate->setDisabled(true);
    ui->lineEdit_meet->setDisabled(true);
    ui->lineEdit_specialDate->setDisabled(true);
    ui->lineEdit_weather->setDisabled(true);
}

void MainWindow::EnableForm(){
    ui->plainTextEdit->setEnabled(true);
    ui->plainTextEdit_2->setEnabled(true);
    ui->plainTextEdit_3->setEnabled(true);
    ui->plainTextEdit_4->setEnabled(true);
    ui->plainTextEdit_5->setEnabled(true);
    ui->plainTextEdit_6->setEnabled(true);
    ui->plainTextEdit_7->setEnabled(true);
    ui->plainTextEdit_8->setEnabled(true);
    ui->lineEdit_anniversary->setEnabled(true);
    ui->lineEdit_birth->setEnabled(true);
    ui->lineEdit_fate->setEnabled(true);
    ui->lineEdit_meet->setEnabled(true);
    ui->lineEdit_specialDate->setEnabled(true);
    ui->lineEdit_weather->setEnabled(true);
}

void MainWindow::on_pushButton_clicked()
{
    // Check the date, update DB and ui
}
