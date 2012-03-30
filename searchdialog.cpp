#include "searchdialog.h"
#include "ui_searchdialog.h"

SearchDialog::SearchDialog(QWidget *parent, QSqlQuery *dbConn) :
    QDialog(parent),
    ui(new Ui::SearchDialog)
{
    ui->setupUi(this);
    this->dbQuery = dbConn;
}

SearchDialog::~SearchDialog()
{
    delete ui;
}
