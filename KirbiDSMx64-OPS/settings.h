#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include <QAbstractButton>
namespace Ui {
class Settings;
}

class Settings : public QDialog
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = 0);
    ~Settings();

private slots:
    void on_checkBox_clicked();

    void on_checkBox_2_clicked();

    void on_checkBox_3_clicked();

    void on_checkBox_4_clicked();

    void on_checkBox_5_clicked();

    void on_checkBox_8_clicked();

    void on_checkBox_6_clicked();

    void on_checkBox_7_clicked();

    void on_checkBox_13_clicked();

    void on_checkBox_11_clicked();

    void on_checkBox_12_clicked();

    void on_checkBox_9_clicked();

    void on_checkBox_10_clicked();

    void on_buttonBox_clicked(QAbstractButton *button);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Settings *ui;
};

#endif // SETTINGS_H
