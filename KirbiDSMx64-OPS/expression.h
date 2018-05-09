#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <QDialog>
#include <QAbstractButton>
//#include "mainhome.h"
namespace Ui {
class Expression;
}

class Expression : public QDialog
{
    Q_OBJECT

public:
    explicit Expression(QWidget *parent = 0);
    ~Expression();

private slots:
    void on_lineEdit_textChanged(const QString &arg1);

    void on_Expression_windowTitleChanged(const QString &title);

    //void on_buttonBox_clicked(QAbstractButton *button);

    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::Expression *ui;

public:

    QString expfil;
   /// QString ui1;
    QString disdata;
    QString infos;
    QString regis;
    //QString dsmadd;
    QString location(QString getpath, QString textdis, QString log, QString regs) {

        expfil = getpath;
        disdata = textdis;
        infos = log;
        regis = regs;
        return expfil;
    }

};

#endif // EXPRESSION_H
