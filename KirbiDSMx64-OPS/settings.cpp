#include "settings.h"
#include "ui_settings.h"
#include "QCheckBox"
#include <inttypes.h>
#include <stdio.h>
#include <ctime>
#include<windows.h>
#include<time.h>
#include <string.h>
#include<tchar.h>
#include <fstream>
#include <QAbstractButton>
#include <QPushButton>
#include <iterator>
#include <QMessageBox>
////#include <iostream>
#include <algorithm>
#include <QProcess>
#include <array>
Settings::Settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
}

Settings::~Settings()
{
    delete ui;
}
int fontcolor = 0;
int fontsize = 0;
int backcolor = 0;
void Settings::on_checkBox_clicked()
{
    ui->checkBox_2->setChecked(false);
    ui->checkBox_3->setChecked(false);
    ui->checkBox_4->setChecked(false);
    ui->checkBox_5->setChecked(false);
    fontcolor = 1;

}

void Settings::on_checkBox_2_clicked()
{
    ui->checkBox->setChecked(false);
    ui->checkBox_3->setChecked(false);
    ui->checkBox_4->setChecked(false);
    ui->checkBox_5->setChecked(false);
    fontcolor = 2;
}

void Settings::on_checkBox_3_clicked()
{
    ui->checkBox->setChecked(false);
    ui->checkBox_2->setChecked(false);
    ui->checkBox_4->setChecked(false);
    ui->checkBox_5->setChecked(false);
    fontcolor = 3;
}

void Settings::on_checkBox_4_clicked()
{
    ui->checkBox->setChecked(false);
    ui->checkBox_2->setChecked(false);
    ui->checkBox_3->setChecked(false);
    ui->checkBox_5->setChecked(false);
    fontcolor = 4;
}

void Settings::on_checkBox_5_clicked()
{
    ui->checkBox->setChecked(false);
    ui->checkBox_3->setChecked(false);
    ui->checkBox_2->setChecked(false);
    ui->checkBox_4->setChecked(false);
    fontcolor = 5;
}

void Settings::on_checkBox_8_clicked()
{
    ui->checkBox_6->setChecked(false);
    ui->checkBox_7->setChecked(false);
    fontsize = 1;
}

void Settings::on_checkBox_6_clicked()
{
    ui->checkBox_8->setChecked(false);
    ui->checkBox_7->setChecked(false);
    fontsize = 2;
}

void Settings::on_checkBox_7_clicked()
{
    ui->checkBox_8->setChecked(false);
    ui->checkBox_6->setChecked(false);
    fontsize = 3;
}

void Settings::on_checkBox_13_clicked()
{
    ui->checkBox_11->setChecked(false);
    ui->checkBox_12->setChecked(false);
    ui->checkBox_9->setChecked(false);
    ui->checkBox_10->setChecked(false);
    backcolor = 1;

}

void Settings::on_checkBox_11_clicked()
{
    ui->checkBox_13->setChecked(false);
    ui->checkBox_12->setChecked(false);
    ui->checkBox_9->setChecked(false);
    ui->checkBox_10->setChecked(false);
    backcolor = 2;
}

void Settings::on_checkBox_12_clicked()
{
    ui->checkBox_13->setChecked(false);
    ui->checkBox_11->setChecked(false);
    ui->checkBox_9->setChecked(false);
    ui->checkBox_10->setChecked(false);
    backcolor = 3;
}

void Settings::on_checkBox_9_clicked()
{
    ui->checkBox_13->setChecked(false);
    ui->checkBox_11->setChecked(false);
    ui->checkBox_12->setChecked(false);
    ui->checkBox_10->setChecked(false);
    backcolor = 4;
}

void Settings::on_checkBox_10_clicked()
{
    ui->checkBox_13->setChecked(false);
    ui->checkBox_11->setChecked(false);
    ui->checkBox_12->setChecked(false);
    ui->checkBox_9->setChecked(false);
    backcolor = 5;
}

void Settings::on_buttonBox_clicked(QAbstractButton *button)
{


        //	String^ dascrivere1 = "Color default;";

}

void Settings::on_pushButton_clicked()
{
    std::string dascrivere2 = "BackColor default;";
    std::string dascrivere3 = "Font default;";
    std::string dascrivere4 = "UpperCase NO;";
    std::string dascrivere5 = "FontColor default;";
    ////String^ dascrivere5 = "FontColor default;";
    //// msclr::interop::marshal_context conti;

    std::string readerer = "Settings.ini";
    std::wstring wFileName(readerer.begin(), readerer.end());
    auto res = DeleteFile(wFileName.c_str());
    /// StreamWriter ^ writer = gcnew StreamWriter("Settings.ini");
    std::string textowrite = "FontColor default;";
    FILE* writer = fopen("Settings.ini", "w");
    switch (fontcolor) {

    case 0:
        fclose(writer);
        goto insize;

        break;

    case 1:
        textowrite = "FontColor default;";
        /*String^ letto;
                    String^ strs;*/
        //conti.marshal_as<std::string>(textowrite);

        //remove("Settings.ini");

        //	writer->WriteLine(dascrivere1);
        fprintf(writer, "%s\n", (char*)dascrivere2.c_str());
        fprintf(writer, "%s\n", (char*)dascrivere3.c_str());
        fprintf(writer, "%s\n", (char*)dascrivere4.c_str());
        fprintf(writer, "%s\n", (char*)textowrite.c_str());

        fclose(writer);
        //MessageBox::Show("Done!")
        break;

    case 2:
        textowrite = "FontColor blue;";
        /*String^ letto;
                    String^ strs;*/
        //conti.marshal_as<std::string>(textowrite);

        //remove("Settings.ini");
        //StreamWriter^ writeri = gcnew StreamWriter("Settings.ini");
        //writer->WriteLine(dascrivere1);
        fprintf(writer, "%s\n", (char*)dascrivere2.c_str());
        fprintf(writer, "%s\n", (char*)dascrivere3.c_str());
        fprintf(writer, "%s\n", (char*)dascrivere4.c_str());
        fprintf(writer, "%s\n", (char*)textowrite.c_str());

        fclose(writer);
        break;

    case 3:
        textowrite = "FontColor red;";
        /*String^ letto;
                    String^ strs;*/
        //conti.marshal_as<std::string>(textowrite);

        //remove("Settings.ini");
        //StreamWriter^ writeri = gcnew StreamWriter("Settings.ini");
        //writer->WriteLine(dascrivere1);
        fprintf(writer, "%s\n", (char*)dascrivere2.c_str());
        fprintf(writer, "%s\n", (char*)dascrivere3.c_str());
        fprintf(writer, "%s\n", (char*)dascrivere4.c_str());
        fprintf(writer, "%s\n", (char*)textowrite.c_str());

        fclose(writer);
        break;

    case 4:
        textowrite = "FontColor green;";
        /*String^ letto;
                    String^ strs;*/
        //conti.marshal_as<std::string>(textowrite);

        //remove("Settings.ini");
        //StreamWriter^ writeri = gcnew StreamWriter("Settings.ini");
        ///writer->WriteLine(dascrivere1);
        fprintf(writer, "%s\n", (char*)dascrivere2.c_str());
        fprintf(writer, "%s\n", (char*)dascrivere3.c_str());
        fprintf(writer, "%s\n", (char*)dascrivere4.c_str());
        fprintf(writer, "%s\n", (char*)textowrite.c_str());

        fclose(writer);
        break;

    case 5:
        textowrite = "FontColor yellow;";
        /*String^ letto;
                    String^ strs;*/
        //conti.marshal_as<std::string>(textowrite);

        //remove("Settings.ini");
        //StreamWriter^ writeri = gcnew StreamWriter("Settings.ini");
        ///writer->WriteLine(dascrivere1);
        fprintf(writer, "%s\n", (char*)dascrivere2.c_str());
        fprintf(writer, "%s\n", (char*)dascrivere3.c_str());
        fprintf(writer, "%s\n", (char*)dascrivere4.c_str());
        fprintf(writer, "%s\n", (char*)textowrite.c_str());

        fclose(writer);
        break;
    }
    insize : std::string Size = "Font default;";
    std::string readererero = "Settings.ini";
    std::wstring wFileNameino(readererero.begin(), readererero.end());
    auto resino = DeleteFile(wFileNameino.c_str());
    FILE* again = fopen("Settings.ini", "w");

    switch (fontsize) {

    case 0:
        fclose(again);
        goto colore;

        break;

    case 1:
        Size = "Font default;";
        //again->WriteLine(dascrivere1);
        // again->WriteLine(dascrivere2);
        fprintf(again, "%s\n", (char*)dascrivere2.c_str());
        fprintf(again, "%s\n", (char*)Size.c_str());
        fprintf(again, "%s\n", (char*)dascrivere4.c_str());
        fprintf(again, "%s\n", (char*)textowrite.c_str());
        fclose(again);
        break;

    case 2:
        Size = "Font medium;";
        //again->WriteLine(dascrivere1);
        fprintf(again, "%s\n", (char*)dascrivere2.c_str());
        fprintf(again, "%s\n", (char*)Size.c_str());
        fprintf(again, "%s\n", (char*)dascrivere4.c_str());
        fprintf(again, "%s\n", (char*)textowrite.c_str());
        fclose(again);
        break;

    case 3:
        Size = "Font big;";
        //again->WriteLine(dascrivere1);
        fprintf(again, "%s\n", (char*)dascrivere2.c_str());
        fprintf(again, "%s\n", (char*)Size.c_str());
        fprintf(again, "%s\n", (char*)dascrivere4.c_str());
        fprintf(again, "%s\n", (char*)textowrite.c_str());
        fclose(again);
        break;
    }
    colore : std::string backcolori = "BackColor default;";
    std::string bkcolosets = "Settings.ini";
    std::wstring wFileNamebkcol(bkcolosets.begin(), bkcolosets.end());
    auto resto = DeleteFile(wFileNamebkcol.c_str());
    FILE* writebkcol = fopen("Settings.ini", "w");
    ///StreamWriter ^ writebkcol = gcnew StreamWriter("Settings.ini");

    switch (backcolor) {

    case 0:

        fclose(writebkcol);
        //goto ipper;

        break;

    case 1:
        backcolori = "BackColor default;";
        fprintf(writebkcol, "%s\n", (char*)backcolori.c_str());
        fprintf(writebkcol, "%s\n", (char*)dascrivere3.c_str());
        fprintf(writebkcol, "%s\n", (char*)dascrivere4.c_str());
        fprintf(writebkcol, "%s\n", (char*)textowrite.c_str());
        fclose(writebkcol);
        break;

    case 2:
        backcolori = "BackColor red;";
        fprintf(writebkcol, "%s\n", (char*)backcolori.c_str());
        fprintf(writebkcol, "%s\n", (char*)dascrivere3.c_str());
        fprintf(writebkcol, "%s\n", (char*)dascrivere4.c_str());
        fprintf(writebkcol, "%s\n", (char*)textowrite.c_str());
        fclose(writebkcol);
        break;

    case 3:
        backcolori = "BackColor blue;";
        fprintf(writebkcol, "%s\n", (char*)backcolori.c_str());
        fprintf(writebkcol, "%s\n", (char*)dascrivere3.c_str());
        fprintf(writebkcol, "%s\n", (char*)dascrivere4.c_str());
        fprintf(writebkcol, "%s\n", (char*)textowrite.c_str());
        fclose(writebkcol);
        break;

    case 4:
        backcolori = "BackColor white;";
        fprintf(writebkcol, "%s\n", (char*)backcolori.c_str());
        fprintf(writebkcol, "%s\n", (char*)dascrivere3.c_str());
        fprintf(writebkcol, "%s\n", (char*)dascrivere4.c_str());
        fprintf(writebkcol, "%s\n", (char*)textowrite.c_str());
        fclose(writebkcol);
        break;

    case 5:
        backcolori = "BackColor black;";
        fprintf(writebkcol, "%s\n", (char*)backcolori.c_str());
        fprintf(writebkcol, "%s\n", (char*)dascrivere3.c_str());
        fprintf(writebkcol, "%s\n", (char*)dascrivere4.c_str());
        fprintf(writebkcol, "%s\n", (char*)textowrite.c_str());
        fclose(writebkcol);
    }

    QMessageBox::StandardButton question;
    ///QApplication app;
    question = QMessageBox::information(this, "KirbiDSMx64", "Settings saved successfully. The Disassembler must be restarted, do you want to restart it now?",
                                        QMessageBox::Yes | QMessageBox::No);

    if (question == QMessageBox::Yes) {

        qApp->quit();
        QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
    }
}

void Settings::on_pushButton_2_clicked()
{
    this->close();
}
