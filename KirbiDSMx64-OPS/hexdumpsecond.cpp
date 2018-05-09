#include "hexdumpsecond.h"
#include "ui_hexdumpsecond.h"
#include<stdio.h>
#include<windows.h>
#include<time.h>
#include <winbase.h>
#include <winnt.h>
#include <string.h>
#include<tchar.h>
#include <stdio.h>
#include <regex>
//#include "stdafx.h"
#include <string>
#include <cstdio>
#include <memory>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <clocale>
#include <cstdlib>
#include <QMessageBox>
#include <QScrollBar>
#define HEX_OFFSET    1
#define ASCII_OFFSET 51
#define NUM_CHARS    16
HexDumpSecond::HexDumpSecond(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HexDumpSecond)
{
    ui->setupUi(this);
}

HexDumpSecond::~HexDumpSecond()
{
    delete ui;
}

void clear_line(char *line, int size)
{
    int count;

    for (count = 0; count < size; line[count] = ' ', count++);
}

char * ascii(char *position, int c)
{
    /* If the character is NOT printable
    * replace it with a '.'  */
    if (!isprint(c)) c = '.';

    sprintf(position, "%c", c);    /* Put the character to the line
                                   * so it can be displayed later */

                                   /* Return the position of the next
                                   * ASCII character.   */
    return(++position);
}

char * hex(char *position, int c)
{
    int offset = 3;

    sprintf(position, "%02X ", (unsigned char)c);

    *(position + offset) = ' ';   /* Remove the '/0' created by 'sprint'  */

    return (position + offset);
}

void HexDumpSecond::on_HexDumpSecond_windowTitleChanged(const QString &title)
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
        int c = ' ';
        char * hex_offset;
        char hexdata[1024] = {0};
        std::stringstream hexdmp;
        char * ascii_offset;

        char line[81];

        std::string flm = filelocation.toStdString();
        int i;

        FILE* fp = fopen(flm.c_str(), "rb");
        if (fp > 0) {

            while (c != EOF)
            {
                clear_line(line, sizeof line);
                hex_offset = line + HEX_OFFSET;
                ascii_offset = line + ASCII_OFFSET;
                while (ascii_offset < line + ASCII_OFFSET + NUM_CHARS
                    && (c = fgetc(fp)) != EOF) {
                    hex_offset = hex(hex_offset, c);

                    /* Build the Ascii part of
                    * the line.      */
                    ascii_offset = ascii(ascii_offset, c);

                }
                ///printf(" %02x", line);
                sprintf(hexdata, " %s\n", line);
                hexdmp << hexdata;
            }
            ui->plainTextEdit->appendPlainText(QString::fromStdString(hexdmp.str()));



        }
        else {

            QMessageBox::critical(this, "KirbiDSMx64", "Couln't read file hex dump.");
            this->close();
        }
        fclose(fp);

}

void HexDumpSecond::on_plainTextEdit_textChanged()
{

}
