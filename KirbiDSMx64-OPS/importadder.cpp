#include "importadder.h"
#include "ui_importadder.h"
#include <QScrollBar>
#include <QString>
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
#include <QMessageBox>
#include <numeric>
#include <vector>
#include <QPalette>
#include "pe_lib/pe_bliss.h"
#include <QFileDialog>
#include <QPushButton>
using namespace pe_bliss;

ImportAdder::ImportAdder(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ImportAdder)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
}

bool readablet = false;
bool writeablet = false;
ImportAdder::~ImportAdder()
{
    delete ui;
}

void ImportAdder::on_ImportAdder_windowTitleChanged(const QString &title)
{

}

void ImportAdder::on_checkBox_clicked()
{
    if(ui->checkBox->checkState() == true)
        readablet = true;
    else
        readablet = false;
}

void ImportAdder::on_checkBox_2_clicked()
{
    if(ui->checkBox_2->checkState() == true)
        writeablet = true;
    else
        writeablet = false;
}



void ImportAdder::on_toolButton_clicked()
{
    QString dll = QFileDialog::getOpenFileName(this, "Open the Dinamic library", "c:\\", "DLL (*.dll)");


    std::string printt = dll.toStdString();
    const size_t last_slash_idx = printt.find_last_of("\\/");
    if (std::string::npos != last_slash_idx)
    {
        printt.erase(0, last_slash_idx + 1);
    }
    ui->lineEdit->setText(QString::fromStdString(printt));
}

void ImportAdder::on_buttonBox_clicked(QAbstractButton *button)
{

}

void ImportAdder::on_pushButton_clicked()
{
    if((ui->lineEdit->text().length() > 0) && (ui->lineEdit_2->text().length() > 0) && (ui->lineEdit_3->text().length() > 0)) {

            std::ifstream pe_file(pthi.toStdString(), std::ios::in | std::ios::binary);
            if(!pe_file)
            {

                QMessageBox::critical(this, "KirbiDSMx64", "Couldn't load this PE!");

            }

            try
            {

                pe_base image(pe_factory::create_pe(pe_file));


                imported_functions_list imports(get_imported_functions(image));


                import_library new_lib;
                new_lib.set_name(ui->lineEdit->text().toStdString());


                imported_function func;
                func.set_name(ui->lineEdit_2->text().toStdString());
                func.set_iat_va(0x1);

                imported_function func2;
                func2.set_ordinal(5);
                func2.set_iat_va(0x2);


                new_lib.add_import(func);
                new_lib.add_import(func2);
                imports.push_back(new_lib);


                section new_imports;
                new_imports.get_raw_data().resize(1);
                new_imports.set_name(ui->lineEdit_3->text().toStdString());
                new_imports.readable(readablet).writeable(writeablet);
                section& attached_section = image.add_section(new_imports);


                import_rebuilder_settings settings(true, false);
                rebuild_imports(image, imports, attached_section, settings);


                std::string base_file_name(pthi.toStdString());
                std::string::size_type slash_pos;
                if((slash_pos = base_file_name.find_last_of("/\\")) != std::string::npos)
                    base_file_name = base_file_name.substr(slash_pos + 1);

                base_file_name = "new_" + base_file_name;
                std::ofstream new_pe_file(base_file_name.c_str(), std::ios::out | std::ios::binary | std::ios::trunc);
                if(!new_pe_file)
                {

                    QMessageBox::critical(this, "KirbiDSMx64", "Couldn't save the import.");

                }


                rebuild_pe(image, new_pe_file);


                QMessageBox::information(this, "KirbiDSMx64", "Import saved successfully. PE rebuilt");
            }
            catch(const pe_exception& e)
            {

                std::string about(e.what());
                QString fn = "Exception! " + QString::fromStdString(about);
                QMessageBox::critical(this, "KirbiDSMx64", fn);

            }
    }
    else {

        QMessageBox::warning(this, "KirbiDSMx64", "First enter other data!");

    }
}

void ImportAdder::on_pushButton_2_clicked()
{
    this->close();
}
