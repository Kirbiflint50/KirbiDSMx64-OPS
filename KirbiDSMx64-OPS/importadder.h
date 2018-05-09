#ifndef IMPORTADDER_H
#define IMPORTADDER_H

#include <QDialog>
#include <QAbstractButton>
namespace Ui {
class ImportAdder;
}

class ImportAdder : public QDialog
{
    Q_OBJECT

public:
    explicit ImportAdder(QWidget *parent = 0);
    ~ImportAdder();

private slots:
    void on_ImportAdder_windowTitleChanged(const QString &title);

    void on_checkBox_clicked();

    void on_checkBox_2_clicked();

    void on_toolButton_clicked();

    void on_buttonBox_clicked(QAbstractButton *button);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ImportAdder *ui;

public:

    QString pthi;

    QString datetarg(QString fileloc) {

        pthi = fileloc;
        return pthi;
    }
};

#endif // IMPORTADDER_H
