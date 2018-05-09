#include "relocationadder.h"
#include "ui_relocationadder.h"
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
RelocationAdder::RelocationAdder(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RelocationAdder)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
}
bool read = false;
RelocationAdder::~RelocationAdder()
{
    delete ui;
}

void RelocationAdder::on_checkBox_clicked()
{
    if(ui->checkBox->checkState() == true)
        read = true;
    else
        read = false;
}

void RelocationAdder::on_buttonBox_clicked(QAbstractButton *button)
{

}

void RelocationAdder::on_pushButton_clicked()
{
    if(ui->lineEdit->text().length() > 0) {

        std::ifstream pe_file(pathrlc.toStdString(), std::ios::in | std::ios::binary);
        if (!pe_file) {

            QMessageBox::critical(this, "KirbiDSMx64", "Couldn't load this PE.");
        }

        try {

            pe_base image(pe_factory::create_pe(pe_file));


            relocation_table_list tables(get_relocations(image));


            relocation_table new_table;
            new_table.set_rva(0x5678);

            new_table.add_relocation(relocation_entry(10, 3));

            tables.push_back(new_table);


            section new_relocs;
            new_relocs.get_raw_data().resize(1);
            new_relocs.set_name(ui->lineEdit->text().toStdString());
            new_relocs.readable(read);
            section& attached_section = image.add_section(new_relocs);

            rebuild_relocations(image, tables, attached_section);


            std::string base_file_name(pathrlc.toStdString());
            std::string::size_type slash_pos;
            if ((slash_pos = base_file_name.find_last_of("/\\")) != std::string::npos)
                base_file_name = base_file_name.substr(slash_pos + 1);

            base_file_name = "new_" + base_file_name;
            std::ofstream new_pe_file(base_file_name.c_str(), std::ios::out | std::ios::binary | std::ios::trunc);
            if (!new_pe_file) {

                QMessageBox::critical(this, "KirbiDSMx64", "Couldn't save the relocation.");

            }


            rebuild_pe(image, new_pe_file);


            QMessageBox::information(this, "KirbiDSMx64", "Relocation added successfully. PE rebuilt");
        }
        catch (const pe_exception& e) {

            std::string err(e.what());
            QString inf = "Exception! " + QString::fromStdString(err);

            QMessageBox::critical(this, "KirbiDSMx64", inf);

        }
    }
    else {

        QMessageBox::warning(this, "KirbiDSMx64", "First enter a name!");
    }

}

void RelocationAdder::on_pushButton_2_clicked()
{
    this->close();
}
