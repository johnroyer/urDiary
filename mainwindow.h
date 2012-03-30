#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDate>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void setDb(QSqlDatabase *conn, QSqlQuery *query);
    void disableForm();
    void enableForm();
    void initForm();
    int saveForm();
    bool formModified;
    void showInStatusBar(QString message);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QSqlDatabase *dbConn;
    QSqlQuery *dbQuery;
    QDate currDate;
    int currId;

private slots:
    void on_pushButton_nextYear_clicked();
    void on_pushButton_nextMonth_clicked();
    void on_pushButton_prevYear_clicked();
    void on_pushButton_PrevMonth_clicked();
    void on_pushButton_PrevDay_clicked();
    void on_pushButton_nextDay_clicked();
    void on_pushButton_Today_clicked();
    void on_actionSave_triggered();
    void on_pushButton_clicked();
    void on_actionClose_triggered();
    void on_actionUrDiary_triggered();
    void on_action_triggered();
};

#endif // MAINWINDOW_H
