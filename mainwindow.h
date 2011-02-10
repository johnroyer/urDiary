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
    void setDbQuery(QSqlQuery *query);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QSqlQuery *dbQuery;
    QDate diaryDate;
    void disableForm();
    void EnableForm();
    int currId;

private slots:
    void on_pushButton_clicked();
    void on_actionClose_triggered();
    void on_actionUrDiary_triggered();
};

#endif // MAINWINDOW_H
