#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "aboutwindow.h"
#include "searchdialog.h"
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
    currDate = QDate::currentDate();
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

void MainWindow::setDb(QSqlDatabase *conn, QSqlQuery *query){
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

void MainWindow::enableForm(){
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
        dbQuery->exec("select * from diary where date = " + currDate.toString("yyyyMMdd") );
        if( dbQuery->next() == true ){
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
            enableForm();
            ui->pushButton->setText(dbQuery->value(16).toString());
            ui->pushButton->setDisabled(true);
        }else{
            if( currDate > QDate::currentDate() ){
                // Can not edit diary in the future
                ui->plainTextEdit->setPlainText("");
                ui->plainTextEdit_2->setPlainText("");
                ui->plainTextEdit_3->setPlainText("");
                ui->plainTextEdit_4->setPlainText("");
                ui->plainTextEdit_5->setPlainText("");
                ui->plainTextEdit_6->setPlainText("");
                ui->plainTextEdit_7->setPlainText("");
                ui->plainTextEdit_8->setPlainText("");
                ui->lineEdit_anniversary->setText("");
                ui->lineEdit_birth->setText("");
                ui->lineEdit_fate->setText("");
                ui->lineEdit_meet->setText("");
                ui->lineEdit_specialDate->setText("");
                ui->lineEdit_weather->setText("");
                disableForm();
                ui->pushButton->setText("我起床了");
                ui->pushButton->setDisabled(true);
            }else{
                ui->plainTextEdit->setPlainText("");
                ui->plainTextEdit_2->setPlainText("");
                ui->plainTextEdit_3->setPlainText("");
                ui->plainTextEdit_4->setPlainText("");
                ui->plainTextEdit_5->setPlainText("");
                ui->plainTextEdit_6->setPlainText("");
                ui->plainTextEdit_7->setPlainText("");
                ui->plainTextEdit_8->setPlainText("");
                ui->lineEdit_anniversary->setText("");
                ui->lineEdit_birth->setText("");
                ui->lineEdit_fate->setText("");
                ui->lineEdit_meet->setText("");
                ui->lineEdit_specialDate->setText("");
                ui->lineEdit_weather->setText("");
                disableForm();
                ui->pushButton->setText("我起床了");
                ui->pushButton->setEnabled(true);
            }
        }
    }
    ui->label_currDate->setText(currDate.toString("<center> yyyy 年 M 月 dd 日 </center>"));
}

int MainWindow::saveForm(){
    dbQuery->prepare("update diary set "
                  " field1 = :field1, "
                  " field2 = :field2, "
                  " field3 = :field3, "
                  " field4 = :field4, "
                  " field5 = :field5, "
                  " field6 = :field6, "
                  " field7 = :field7, "
                  " field8 = :field8, "
                  " anniversary = :anniversary, "
                  " birth = :birth, "
                  " fate = :fate, "
                  " meet = :meet, "
                  " specialDate = :specialDate, "
                  " weather = :weather "
                  " where date = :date ");
    dbQuery->bindValue(":field1", ui->plainTextEdit->toPlainText() );
    dbQuery->bindValue(":field2", ui->plainTextEdit_2->toPlainText() );
    dbQuery->bindValue(":field3", ui->plainTextEdit_3->toPlainText() );
    dbQuery->bindValue(":field4", ui->plainTextEdit_4->toPlainText() );
    dbQuery->bindValue(":field5", ui->plainTextEdit_5->toPlainText() );
    dbQuery->bindValue(":field6", ui->plainTextEdit_6->toPlainText() );
    dbQuery->bindValue(":field7", ui->plainTextEdit_7->toPlainText() );
    dbQuery->bindValue(":field8", ui->plainTextEdit_8->toPlainText() );
    dbQuery->bindValue(":anniversary", ui->lineEdit_anniversary->text() );
    dbQuery->bindValue(":birth", ui->lineEdit_birth->text() );
    dbQuery->bindValue(":fate", ui->lineEdit_fate->text() );
    dbQuery->bindValue(":meet", ui->lineEdit_meet->text() );
    dbQuery->bindValue(":specialDate", ui->lineEdit_specialDate->text() );
    dbQuery->bindValue(":weather", ui->lineEdit_weather->text() );
    dbQuery->bindValue(":date", currDate.toString("yyyyMMdd") );
    bool stat = dbQuery->exec();
    if( stat == false){
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
    if( res == true ){
        ui->pushButton->setDisabled(true);
        ui->pushButton->setText(currTime);
        currDate = QDate::currentDate();
        ui->label_currDate->setText(currDate.toString("<center> yyyy 年 M 月 dd 日 </center>"));
        enableForm();
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

void MainWindow::on_pushButton_Today_clicked()
{
    currDate = QDate::currentDate();
    initForm();
}

void MainWindow::on_pushButton_nextDay_clicked()
{
    currDate = currDate.addDays(1);
    initForm();
}

void MainWindow::on_pushButton_PrevDay_clicked()
{
    currDate = currDate.addDays(-1);
    initForm();
}

void MainWindow::on_pushButton_PrevMonth_clicked()
{
    currDate = currDate.addMonths(-1);
    initForm();
}

void MainWindow::on_pushButton_prevYear_clicked()
{
    currDate = currDate.addYears(-1);
    initForm();
}

void MainWindow::on_pushButton_nextMonth_clicked()
{
    currDate = currDate.addMonths(1);
    initForm();
}

void MainWindow::on_pushButton_nextYear_clicked()
{
    currDate = currDate.addYears(1);
    initForm();
}

void MainWindow::on_action_triggered()
{
    SearchDialog *search = new SearchDialog(this, this->dbConn);
    search->show();
    connect(search, SIGNAL(done(int,int,int)), this, SLOT(renewForm(int,int,int)) );
}

void MainWindow::renewForm(int y, int m, int d)
{
    currDate = QDate(y,m,d);
    initForm();
}
