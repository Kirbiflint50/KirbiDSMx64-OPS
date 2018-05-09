#ifndef SELECTSECTION_H
#define SELECTSECTION_H

#include <QDialog>

namespace Ui {
class SelectSection;
}

class SelectSection : public QDialog
{
    Q_OBJECT

public:
    explicit SelectSection(QWidget *parent = 0);
    ~SelectSection();

private slots:
    void on_SelectSection_windowTitleChanged(const QString &title);

    void on_comboBox_activated(const QString &arg1);

    void on_pushButton_clicked();

private:
    Ui::SelectSection *ui;

public:

    int mode;
    QString fli;
    QString rgs;
    QString stack;
    QString dis;

    QString pth(QString targ, int type, QString infostck, QString registersdata, QString currentdsmtxt) {

        fli = targ;
        mode = type;
        stack = infostck;
        rgs = registersdata;
        dis = currentdsmtxt;
        return fli;
    }
};

#endif // SELECTSECTION_H
