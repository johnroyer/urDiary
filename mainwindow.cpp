#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "aboutwindow.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDate>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    if( formModified == true ){
        saveForm();
    }
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

void MainWindow::initForm(){
    if( dbQuery != NULL ){
        currDate = QDate::currentDate();
        dbQuery->exec("select * from diary where date = " + currDate.toString("yyyyMMdd") );
        if( dbQuery->next() == true ){
//            QMessageBox::about(0,"init",dbQuery->lastQuery());
//            ui->pushButton->setText(dbQuery->value(1).toString());
            ui->plainTextEdit->setPlainText(dbQuery->value(2).toString());
            ui->plainTextEdit_2->setPlainText(dbQuery->value((3)).toString());
            ui->plainTextEdit_3->setPlainText(dbQuery->value((4)).toString());
            ui->plainTextEdit_4->setPlainText(dbQuery->value((5)).toString());
            ui->plainTextEdit_5->setPlainText(dbQuery->value((6)).toString());
            ui->plainTextEdit_6->setPlainText(dbQuery->value((7)).toString());
            ui->plainTextEdit_7->setPlainText(dbQuery->value((8)).toString());
            ui->plainTextEdit_8->setPlainText(dbQuery->value((9)).toString());
            ui->lineEdit_anniversary->setText(dbQuery->value(10).toString());
            ui->lineEdit_birth->setText(dbQuery->value(11).toString());
            ui->lineEdit_fate->setText(dbQuery->value(12).toString());
            ui->lineEdit_meet->setText(dbQuery->value(13).toString());
            ui->lineEdit_specialDate->setText(dbQuery->value(14).toString());
            ui->lineEdit_weather->setText(dbQuery->value(15).toString());
            EnableForm();
            ui->pushButton->setText(dbQuery->value(16).toString());
            ui->pushButton->setDisabled(true);
        }
    }
    ui->label_currDate->setText(currDate.toString("<center> yyyy 年 M 月 dd 日 </center>"));
}

int MainWindow::saveForm(){
    bool stat = dbQuery->exec("update diary set "
                  " field1 = '" + ui->plainTextEdit->toPlainText() + "', "
                  " field2 = '" + ui->plainTextEdit_2->toPlainText() + "', "
                  " field3 = '" + ui->plainTextEdit_3->toPlainText() + "', "
                  " field4 = '" + ui->plainTextEdit_4->toPlainText() + "', "
                  " field5 = '" + ui->plainTextEdit_5->toPlainText() + "', "
                  " field6 = '" + ui->plainTextEdit_6->toPlainText() + "', "
                  " field7 = '" + ui->plainTextEdit_7->toPlainText() + "', "
                  " field8 = '" + ui->plainTextEdit_8->toPlainText() + "', "
                  " anniversary = '" + ui->lineEdit_anniversary->text() + "', "
                  " birth = '" + ui->lineEdit_birth->text() + "', "
                  " fate = '" + ui->lineEdit_fate->text() + "', "
                  " meet = '" + ui->lineEdit_meet->text() + "', "
                  " specialDate = '"+ ui->lineEdit_specialDate->text() + "', "
                  " weather = '" + ui->lineEdit_weather->text() + "' "
                  " where date = " + currDate.toString("yyyyMMdd") );
    if( stat == false){
//        QMessageBox::about(0,"save info","Failed to save \n " + dbQuery->lastQuery() );
        formModified = false;
        return 1;
    }
    return 0;
}

void MainWindow::on_pushButton_clicked()
{
    // Create new data and enable all form
    QString currTime = QTime::currentTime().toString("hh:mm");
    bool res = dbQuery->exec("insert into diary "
                             "(date, getup) "
                             "values ('" + currDate.toString("yyyyMMdd") + "','" + currTime + "')");
    //QMessageBox::about(0,"Result",dbQuery->lastQuery());
    if( res == true ){
        ui->pushButton->setDisabled(true);
        ui->pushButton->setText(currTime);
        currDate = QDate::currentDate();
        ui->label_currDate->setText(currDate.toString("<center> yyyy 年 M 月 dd 日 </center>"));
        EnableForm();
    }
}

void MainWindow::on_actionSave_triggered()
{
    if( saveForm() == 0 ){
        showInStatusBar("Saved !");
    }else{
        showInStatusBar("Failed to save");
        QMessageBox::about(0,"Failed to save",dbQuery->lastError().text());
    }
}

void MainWindow::showInStatusBar(QString message){
    statusBar()->showMessage(message, 2000);
}
