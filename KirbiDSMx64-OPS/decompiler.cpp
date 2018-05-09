#include "decompiler.h"
#include "ui_decompiler.h"
#include <nc/config.h>



Decompiler::Decompiler(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Decompiler)
{
    ui->setupUi(this);
}

Decompiler::~Decompiler()
{
    delete ui;
}





void Decompiler::on_Decompiler_windowTitleChanged(const QString &title)
{

}
