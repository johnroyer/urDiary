#ifndef SEARCHDIALOG_H
#define SEARCHDIALOG_H

#include <QDialog>
#include <QSqlQuery>

namespace Ui {
    class SearchDialog;
}

class SearchDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SearchDialog(QWidget *parent = 0, QSqlQuery *dbConn = NULL);
    ~SearchDialog();

private:
    Ui::SearchDialog *ui;
    QSqlQuery *dbQuery;
};

#endif // SEARCHDIALOG_H
