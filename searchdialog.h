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
    void setDate(QDate *date);

private slots:
    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_lineEdit_editingFinished();

    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::SearchDialog *ui;
    QSqlDatabase *dbConn;
    QSqlQueryModel *model;
    QDate *selectedDate;
    void search();

signals:
    void done(int y, int m, int d);

};

#endif // SEARCHDIALOG_H
