#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlTableModel>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(int age, QString experinces, QString position, QWidget *parent = 0);
    ~Dialog();
    void get_values();


private slots:
    void on_change_Button_clicked();
    void on_close_Button_clicked();

private:
    Ui::Dialog *ui;
    QSqlDatabase db;
    QSqlQuery query;
    QString experinces, position;
    int age;

};

#endif // DIALOG_H
