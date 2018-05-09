#include "exporttable.h"
#include "ui_exporttable.h"
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

using namespace pe_bliss;

ExportTable::ExportTable(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExportTable)
{
    ui->setupUi(this);
}

ExportTable::~ExportTable()
{
    delete ui;
}

void ExportTable::on_ExportTable_windowTitleChanged(const QString &title)
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
            std::stringstream ex;
            std::ifstream pe_file(fileex.toStdString(), std::ios::in | std::ios::binary);
            if(!pe_file)
            {

                QMessageBox::critical(this, "KirbiDSMx64", "Couln't read exports!");
                this->close();

            }

            try
            {

                pe_base image(pe_factory::create_pe(pe_file));







                export_info info;
                const exported_functions_list exports = get_exported_functions(image, info);


                ex << "Export info" << std::endl
                    << "Library name: " << info.get_name() << std::endl
                    << "Timestamp: " << info.get_timestamp() << std::endl
                    << "Ordinal base: " << info.get_ordinal_base() << std::endl
                    << std::endl;


                for(exported_functions_list::const_iterator it = exports.begin(); it != exports.end(); ++it)
                {
                    const exported_function& func = *it;
                    ex << "[+] ";
                    if(func.has_name())
                        ex << func.get_name() << ", name ordinal: " << func.get_name_ordinal() << " ";


                    ex << "ORD: " << func.get_ordinal();


                    if(func.is_forwarded())
                        ex << std::endl << " -> " << func.get_forwarded_name();

                    ex << std::endl;
                }
            }
            catch(const pe_exception& e)
            {


                QMessageBox::critical(this, "KirbiDSMx64", "Exception!");
                this->close();
            }

            ui->plainTextEdit->appendPlainText(QString::fromStdString(ex.str()));
}
