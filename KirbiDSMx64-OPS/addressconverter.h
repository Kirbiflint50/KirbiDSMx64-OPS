#ifndef ADDRESSCONVERTER_H
#define ADDRESSCONVERTER_H

#include <QDialog>
#include <Windows.h>
#include <inttypes.h>
#include <stdio.h>
#include <ctime>
#include<windows.h>
#include<time.h>
#include <string.h>
#include<tchar.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
namespace Ui {
class AddressConverter;
}

class AddressConverter : public QDialog
{
    Q_OBJECT

public:
    explicit AddressConverter(QWidget *parent = 0);
    ~AddressConverter();

private slots:
    void on_AddressConverter_windowTitleChanged(const QString &title);

    void on_lineEdit_textChanged(const QString &arg1);

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_lineEdit_3_textChanged(const QString &arg1);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_lineEdit_4_textChanged(const QString &arg1);

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::AddressConverter *ui;

public:
    QString locfl;

    QString getloc(QString pth) {


        locfl = pth;
        return locfl;
    }
    LONG64 imgbs;

    LONG64 getimage(LONG64 data) {

        imgbs = data;
        return imgbs;
    }
};

#endif // ADDRESSCONVERTER_H
