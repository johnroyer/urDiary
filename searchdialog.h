#ifndef SEARCHDIALOG_H
#define SEARCHDIALOG_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQueryModel>

namespace Ui {
    class SearchDialog;
}

class SearchDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SearchDialog(QWidget *parent = 0, QSqlDatabase *dbConn = NULL);
    ~SearchDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::SearchDialog *ui;
    QSqlDatabase *dbConn;
    QSqlQueryModel *model;
};

#endif // SEARCHDIALOG_H
