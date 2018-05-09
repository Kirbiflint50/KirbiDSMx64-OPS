#include "importstable.h"
#include "ui_importstable.h"
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

ImportsTable::ImportsTable(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ImportsTable)
{
    ui->setupUi(this);
}

ImportsTable::~ImportsTable()
{
    delete ui;
}

void ImportsTable::on_ImportsTable_windowTitleChanged(const QString &title)
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
    std::stringstream importes;

    std::ifstream pe_file(fileimp.toStdString(), std::ios::in | std::ios::binary);
        if(!pe_file)
        {

            QMessageBox::critical(this, "KirbiDSMx64", "Couln't load the imports!");
            this->close();

        }

        try
        {
            //Создаем экземпляр PE или PE+ класса с помощью фабрики
            pe_base image(pe_factory::create_pe(pe_file));

            //Проверим, есть ли импорты у файла




            //Получаем список импортируемых библиотек с функциями
            const imported_functions_list imports = get_imported_functions(image);

            //Перечисляем импортированные библиотеки и выводим информацию о них
            for(imported_functions_list::const_iterator it = imports.begin(); it != imports.end(); ++it)
            {
                const import_library& lib = *it; //Импортируемая библиотека
                importes << "Library [" << lib.get_name() << "]" << std::endl //Имя
                    << "Timestamp: " << lib.get_timestamp() << std::endl //Временная метка
                    << "RVA to IAT: " << lib.get_rva_to_iat() << std::endl //Относительный адрес к import address table
                    << "========" << std::endl;

                //Перечисляем импортированные функции для библиотеки
                const import_library::imported_list& functions = lib.get_imported_functions();
                for(import_library::imported_list::const_iterator func_it = functions.begin(); func_it != functions.end(); ++func_it)
                {
                    const imported_function& func = *func_it; //Импортированная функция
                    importes << "[+] ";
                    if(func.has_name()) //Если функция имеет имя - выведем его
                        importes << func.get_name();
                    else
                        importes << "#" << func.get_ordinal(); //Иначе она импортирована по ординалу

                    //Хинт
                    importes << " hint: " << func.get_hint() << std::endl;
                }

                importes << std::endl;
            }
        }
        catch(const pe_exception& e)
        {
            QMessageBox::critical(this, "KirbiDSMx64", "Exception!");
            this->close();
            //Если возникла ошибка
            //std::cout << "Error: " << e.what() << std::endl;

        }
         ui->plainTextEdit->appendPlainText(QString::fromStdString(importes.str()));
    /*UnmapViewOfFile(lpFile);
    CloseHandle(hFileMap);
    CloseHandle(hFile);*/

}

void ImportsTable::on_ImportsTable_windowIconChanged(const QIcon &icon)
{

}

void ImportsTable::on_ImportsTable_accepted()
{

}
