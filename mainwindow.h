#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

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

private slots:
    void on_actionClose_triggered();
    void on_actionUrDiary_triggered();
};

#endif // MAINWINDOW_H
