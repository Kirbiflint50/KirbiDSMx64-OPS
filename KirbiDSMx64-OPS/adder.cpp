#include "adder.h"
#include "ui_adder.h"
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
#include <QPalette>
#include "pe_lib/pe_bliss.h"
#include <QPushButton>
#include <QAbstractButton>
#include <regex>
using namespace pe_bliss;
Adder::Adder(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Adder)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
}
bool readable = false;
bool writeable = false;
Adder::~Adder()
{
    delete ui;
}

void Adder::on_checkBox_clicked()
{
    if(ui->checkBox->checkState() == true)
        writeable = true;
    else
        writeable = false;

}

void Adder::on_checkBox_2_clicked()
{
    if(ui->checkBox_2->checkState() == true)
        readable = true;
    else
        readable = false;
}

void Adder::on_buttonBox_clicked(QAbstractButton *button)
{
    if (button == ui->buttonBox->button(QDialogButtonBox::Ok)) {
        if (ui->lineEdit->text().length() > 0) {

            std::regex hx("(?:0[xX])?[0-9a-fA-F]+");

            if (std::regex_search(ui->lineEdit->text().toStdString(), hx)) {
                std::ifstream pe_file(filedat.toStdString(), std::ios::in | std::ios::binary);
                if (!pe_file) {
                    QMessageBox::critical(this, "KirbiDSMx64", "Couldn't open.");
                }

                try {

                    pe_base image(pe_factory::create_pe(pe_file));

                    section new_section;
                    new_section.readable(readable).writeable(writeable);
                    new_section.set_name(ui->comboBox->currentText().toStdString());
                    new_section.set_raw_data("Kirbiflint");

                    section& added_section = image.add_section(new_section);

                    image.set_section_virtual_size(added_section, strtoimax(ui->lineEdit->text().toStdString().c_str(), 0, 16));

                    std::string base_file_name(filedat.toStdString());
                    std::string::size_type slash_pos;
                    if ((slash_pos = base_file_name.find_last_of("/\\")) != std::string::npos)
                        base_file_name = base_file_name.substr(slash_pos + 1);

                    base_file_name = "new_" + base_file_name;
                    std::ofstream new_pe_file(base_file_name.c_str(), std::ios::out | std::ios::binary | std::ios::trunc);
                    if (!new_pe_file) {

                        QMessageBox::critical(this, "KirbiDSMx64", "Couldn't add the section");
                    }

                    rebuild_pe(image, new_pe_file);

                    QMessageBox::information(this, "KirbiDSMx64", "Section added successfully. PE rebuilt.");
                }
                catch (const pe_exception& e) {

                    std::string info(e.what());
                    QString exc = "Exception! " + QString::fromStdString(info);
                    QMessageBox::critical(this, "KirbiDSMx64", exc);
                }


            }
            else {

                QMessageBox::warning(this, "KirbiDSMx64", "First enter a valid Virtual Size!");
            }
        }
        else
        {

            QMessageBox::warning(this, "KirbiDSMx64", "First enter a name!");
        }

    }
}
