#ifndef MEMORYMAP_H
#define MEMORYMAP_H

#include <QDialog>
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
class MemoryMap;


}

class MemoryMap : public QDialog
{
    Q_OBJECT

public:
    explicit MemoryMap(QWidget *parent = 0);
    ~MemoryMap();

private:
    Ui::MemoryMap *ui;

public:
    QString dir;
    QString dumpmem(QString path){

                    dir = path;

                    return dir;































    }
private slots:
    void on_pushButton_clicked();




    void on_MemoryMap_accepted();
    void on_MemoryMap_windowTitleChanged(const QString &title);
    void on_plainTextEdit_textChanged();
};

#endif // MEMORYMAP_H

