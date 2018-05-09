#ifndef ADDER_H
#define ADDER_H

#include <QDialog>
#include <QAbstractButton>
namespace Ui {
class Adder;
}

class Adder : public QDialog
{
    Q_OBJECT

public:
    explicit Adder(QWidget *parent = 0);
    ~Adder();

private slots:
    void on_checkBox_clicked();

    void on_checkBox_2_clicked();

    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::Adder *ui;

public:

    QString filedat;

    QString gtfil(QString targ) {

        filedat = targ;
        return filedat;
    }
};

#endif // ADDER_H
