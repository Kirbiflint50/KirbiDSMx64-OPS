#include "sectionsadder.h"
#include "ui_sectionsadder.h"
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
#include "adder.h"
using namespace pe_bliss;
SectionsAdder::SectionsAdder(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SectionsAdder)
{
    ui->setupUi(this);
}

SectionsAdder::~SectionsAdder()
{
    delete ui;
}

void SectionsAdder::on_SectionsAdder_windowTitleChanged(const QString &title)
{
    QPalette palete;
    std::stringstream datread;
    QString dascrivere2 = "BackColor default;";
    QString dascrivere3 = "Font default;";
    QString dascrivere4 = "UpperCase NO;";
    QString dascrivere5 = "FontColor default;";
    char ch;
    FILE *reader = NULL;

    reader = fopen("Settings.ini", "rt");

    if(reader > 0) {


        while((ch = fgetc(reader)) != EOF) {

            datread << ch;
        }
        fclose(reader);
        //ui->plainTextEdit_4->appendPlainText("-Settings loaded successfully.\n");



    }
    else  {

        ///ui->plainTextEdit_4->appendPlainText("-Settings load FALIED.\n");
        QMessageBox::critical(this, "KirbiDSMx64", "Sorry, couldn't read settings.");
        fclose(reader);
        //goto ahead;


    }
   std::string rd = datread.str();
    QString dts = QString::fromStdString(rd);

                if (dts.contains(dascrivere2))
                {
                    //QPalette backgrd;
                    palete.setColor(QPalette::Base, QColor(Qt::black));
                    ui->plainTextEdit->setPalette(palete);

                    ////richTextBox1->Font = gcnew System::Drawing::Font(richTextBox1->Font->FontFamily, 8);
                    /// ui->plainTextEdit_4->appendPlainText("-Background default setted.\n");


                    //richTextBox1->ForeColor = System::Drawing::Color::Red;
                    /*textBox1->ForeColor = System::Drawing::Color::Black;
                    label2->ForeColor = System::Drawing::Color::Black;
                    label1->ForeColor = System::Drawing::Color::Black;*/

                    //break;


                }
                //mine:
                if (dts.contains(dascrivere3))
                {

                    ui->plainTextEdit->setFont(QFont("Lucida Console", 8));


                }

                if (dts.contains(dascrivere5))
                {


                    ///QPalette fontcl;
                    palete.setColor(QPalette::Text, QColor(Qt::red));
                    ui->plainTextEdit->setPalette(palete);


                }
                if (dts.contains("BackColor red;"))
                {
                   // QPalette bkgry;
                    palete.setColor(QPalette::Base, QColor(Qt::red));
                    ui->plainTextEdit->setPalette(palete);



                }
                if (dts.contains("BackColor blue;"))
                {

                    palete.setColor(QPalette::Base, QColor(Qt::blue));
                    ui->plainTextEdit->setPalette(palete);


                }
                if (dts.contains("BackColor white;"))
                {
                    ///QPalette bkgr;
                    palete.setColor(QPalette::Base, QColor(Qt::white));
                    ui->plainTextEdit->setPalette(palete);

                }
                if (dts.contains("BackColor black;"))
                {
                    //QPalette bkgr;
                    palete.setColor(QPalette::Base, QColor(Qt::black));
                    ui->plainTextEdit->setPalette(palete);


                }
                if (dts.contains("Font medium;"))
                {
                    ui->plainTextEdit->setFont(QFont("Lucida Console", 12));

                }
                if (dts.contains("Font big;"))
                {

                    ui->plainTextEdit->setFont(QFont("Lucida Console", 15));

                }
                if (dts.contains("FontColor blue;"))
                {

                    ////QPalette fontcl;
                    palete.setColor(QPalette::Text, QColor(Qt::blue));
                    ui->plainTextEdit->setPalette(palete);


                }
                if (dts.contains("FontColor red;"))
                {
                    //QPalette fontcl;
                    palete.setColor(QPalette::Text, QColor(Qt::red));
                    ui->plainTextEdit->setPalette(palete);

                }
                if (dts.contains("FontColor green;"))
                {
                    //QPalette fontcl;
                    palete.setColor(QPalette::Text, QColor(Qt::green));
                    ui->plainTextEdit->setPalette(palete);

                }
                if (dts.contains("FontColor yellow;"))
                {
                   // QPalette fontcl;
                    palete.setColor(QPalette::Text, QColor(Qt::yellow));
                    ui->plainTextEdit->setPalette(palete);

                }
    std::stringstream sects;

    std::ifstream pe_file(target.toStdString(), std::ios::in | std::ios::binary);
    if (!pe_file) {
        QMessageBox::critical(this, "KirbiDSMx64", "Couldn't read the file.");


    }

    try {

        pe_base image(pe_factory::create_pe(pe_file));


        sects << "Reading PE sections..." << std::hex << std::showbase << std::endl
                  << std::endl;
        const section_list sections(image.get_image_sections());


        for (section_list::const_iterator it = sections.begin(); it != sections.end(); ++it) {
            const section& s = *it; //Секция
            sects << "Section [" << s.get_name() << "]" << std::endl
                      << "Characteristics: " << s.get_characteristics() << std::endl
                      << "Size of raw data: " << s.get_size_of_raw_data() << std::endl
                      << "Virtual address: " << s.get_virtual_address() << std::endl
                      << "Virtual size: " << s.get_virtual_size() << std::endl
                      << std::endl;
        }
    }
    catch (const pe_exception& e) {

        std::string info(e.what());
        QString infos = "Exception! " + QString::fromStdString(info);
        QMessageBox::critical(this, "KirbiDSMx64", infos);

    }
    ui->plainTextEdit->appendPlainText(QString::fromStdString(sects.str()));

}

void SectionsAdder::on_pushButton_clicked()
{
    Adder addsec;
    addsec.setModal(true);
    addsec.gtfil(target);
    addsec.setWindowTitle("Add a Section");
    addsec.exec();
}
