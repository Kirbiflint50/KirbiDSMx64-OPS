#ifndef RELOCATIONADDER_H
#define RELOCATIONADDER_H

#include <QDialog>
#include <QAbstractButton>
namespace Ui {
class RelocationAdder;
}

class RelocationAdder : public QDialog
{
    Q_OBJECT

public:
    explicit RelocationAdder(QWidget *parent = 0);
    ~RelocationAdder();

private slots:
    void on_checkBox_clicked();

    void on_buttonBox_clicked(QAbstractButton *button);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::RelocationAdder *ui;

public:

    QString pathrlc;

    QString opn(QString f) {

        pathrlc = f;
        return pathrlc;
    }
};

#endif // RELOCATIONADDER_H
