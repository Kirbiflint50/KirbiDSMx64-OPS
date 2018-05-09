#include "addressconverter.h"
#include "ui_addressconverter.h"
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
#include <iomanip>
#include<math.h>
#include <regex>
#include <bitset>
AddressConverter::AddressConverter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddressConverter)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
}

AddressConverter::~AddressConverter()
{
    delete ui;
}

void AddressConverter::on_AddressConverter_windowTitleChanged(const QString &title)
{
    if(locfl == "") {

        ui->lineEdit_4->setEnabled(false);
        ui->lineEdit_5->setEnabled(false);
        ui->pushButton_4->setEnabled(false);
        ui->pushButton_5->setEnabled(false);
    }
}


void AddressConverter::on_lineEdit_textChanged(const QString &arg1)
{


    if(ui->lineEdit->text().length() > 0) {


        ui->lineEdit_2->setText("");
        ui->lineEdit_3->setText("");








    }
}

void AddressConverter::on_lineEdit_2_textChanged(const QString &arg1)
{
    if(ui->lineEdit_2->text().length() > 0) {


        ui->lineEdit->setText("");
        ui->lineEdit_3->setText("");








    }

}

void AddressConverter::on_lineEdit_3_textChanged(const QString &arg1)
{
    if(ui->lineEdit_3->text().length() > 0) {


        ui->lineEdit->setText("");
        ui->lineEdit_2->setText("");








    }
}

void AddressConverter::on_pushButton_clicked()
{
    if((ui->lineEdit_3->text().length() == 0) && (ui->lineEdit_2->text() == 0)) {




        QMessageBox::critical(this, "KirbiDSMx64", "First enter something to convert!");

    }
    else {

        if(ui->lineEdit->text().length() == 0) {



            if(ui->lineEdit_3->text().length() > 0) {


                std::string data = ui->lineEdit_3->text().toStdString();
                std::regex binright("^(.*0.*0.*1.*)|(.*0.*1.*0.*)|(.*1.*0.*0.*)$");

                if (std::regex_search(data, binright))
                {
                    std::stringstream sstream(data);
                    std::stringstream outascii;
                    std::string output;
                    while (sstream.good())
                    {
                           std::bitset<8> bits;
                           sstream >> bits;
                           char c = char(bits.to_ulong());
                           output += c;
                     }

                      outascii << output;
                      std::string outputinstring = outascii.str();
                      ui->lineEdit->setText(QString::fromStdString(outputinstring));
                      ui->lineEdit_3->setText("");

                }
                else {

                    QMessageBox::critical(this, "KirbiDSMx64", "Invalid Binary String.");
                }
            }
            else if(ui->lineEdit_2->text().length() > 0) {

                std::string hexstr = ui->lineEdit_2->text().toStdString();
                std::regex findhex("(?:0[xX])?[0-9a-fA-F]+");

                if (std::regex_search(hexstr, findhex)) {

                    const char* hex_str = (const char*)hexstr.c_str();

                    std::string result_string;
                    unsigned int ch;
                    for (; std::sscanf(hex_str, "%2x", &ch) == 1; hex_str += 2)
                    {
                         result_string += ch;
                    }
                    ui->lineEdit->setText(QString::fromStdString(result_string));
                    ui->lineEdit_2->setText("");
                }
            }
        }




    }
}

char *TextToHex(char *text) {
            char *retnhex = (char*)"";
            if (!text) return 0;

            int len = strlen(text);


            char *buffer = new char[2 * len] + 1;
            char end[1024] = { 0 };
            if (!buffer) return 0;

            for (int i = 0; i < len; i++) {
                sprintf(buffer + 2 * i, "%02x", (unsigned int)text[i]);
            }
            retnhex = buffer;
            return retnhex;


            ///return buffer;
        }

void AddressConverter::on_pushButton_2_clicked()
{
    if((ui->lineEdit->text().length() == 0) && (ui->lineEdit_3->text() == 0)) {

        QMessageBox::critical(this, "Kirbix64", "First enter something to convert!");
    }
    else {

        if(ui->lineEdit_2->text().length() == 0) {


            if(ui->lineEdit_3->text().length() > 0) {

                std::string data = ui->lineEdit_3->text().toStdString();
                std::regex searchbin("^(.*0.*0.*1.*)|(.*0.*1.*0.*)|(.*1.*0.*0.*)$");

                if (std::regex_search(data, searchbin))
                {
                    std::stringstream sstream(data);
                    std::stringstream outascii;
                    std::string output;
                    while (sstream.good())
                    {
                        std::bitset<8> bits;
                        sstream >> bits;
                        char c = char(bits.to_ulong());
                        output += c;
                    }

                    outascii << output;
                    std::string outputinstring = outascii.str();


                    char *hexiwanna = TextToHex((char*)outputinstring.c_str());
                    std::string fin(hexiwanna);
                    ///String^ thehex = gcnew String(hexiwanna);
                    ui->lineEdit_2->setText(QString::fromStdString(fin));
                    ui->lineEdit_3->setText("");
                                    ///textBox5->Text = "";

               }
               else {

                    QMessageBox::critical(this, "KirbiDSMx64", "Invalid Binary String.");

                }
            }
            else if(ui->lineEdit->text().length() > 0) {

                std::string ascidata = ui->lineEdit->text().toStdString();
                char *finalhexachars = TextToHex((char*)ascidata.c_str());
                std::string finale(finalhexachars);
                ui->lineEdit_2->setText(QString::fromStdString(finale));
                ui->lineEdit->setText("");
            }
        }
    }
}

const char* hex_char_to_bin(char c)
{
             // TODO handle default / error
        switch (toupper(c))
        {
             case '0': return "0000";
             case '1': return "0001";
             case '2': return "0010";
             case '3': return "0011";
             case '4': return "0100";
             case '5': return "0101";
             case '6': return "0110";
             case '7': return "0111";
             case '8': return "1000";
             case '9': return "1001";
             case 'A': return "1010";
             case 'B': return "1011";
             case 'C': return "1100";
             case 'D': return "1101";
             case 'E': return "1110";
             case 'F': return "1111";
        }
}
std::string hex_str_to_bin_str(const std::string& hex)
{

             std::string binary;
             for (unsigned i = 0; i != hex.length(); ++i)
                 binary += hex_char_to_bin(hex[i]);
             return binary;
}
void AddressConverter::on_pushButton_3_clicked()
{
    if((ui->lineEdit->text().length() == 0) && (ui->lineEdit_2->text().length() == 0)) {

        QMessageBox::critical(this, "Kirbix64", "First enter something to convert!");
    }
    else {

        if(ui->lineEdit_3->text().length() == 0)
        {

            if(ui->lineEdit_2->text().length() > 0) {


                std::string hexdata = ui->lineEdit_2->text().toStdString();
                std::regex findhex("(?:0[xX])?[0-9a-fA-F]+");
                if (std::regex_search(hexdata, findhex))
                {


                    std::string bindata = hex_str_to_bin_str(hexdata);
                    ui->lineEdit_3->setText(QString::fromStdString(bindata));
                    ui->lineEdit_2->setText("");


                }
            else {

                QMessageBox::critical(this, "KirbiDSMx64", "Invalid Hex String");

            }
        }
        else if(ui->lineEdit->text().length() > 0) {

                std::string asc = ui->lineEdit->text().toStdString();
                char *gethexforbin = TextToHex((char*)asc.c_str());
                std::string hex(gethexforbin);
                std::string thebinary = hex_str_to_bin_str(hex);
                ui->lineEdit_3->setText(QString::fromStdString(thebinary));
                ui->lineEdit->setText("");


       }
    }
  }
}

void AddressConverter::on_lineEdit_4_textChanged(const QString &arg1)
{
    if(ui->lineEdit_4->text().length() > 0) {

        ui->lineEdit_5->setText("");
    }
}

void AddressConverter::on_pushButton_4_clicked()
{
    if(ui->lineEdit_4->text().length() == 0) {

        ui->lineEdit_4->setText("Enter an address!");
    }
    else {

        char res[1024] = { 0 };
        std::stringstream rs;
                ///msclr::interop::marshal_context conti;
         std::string imput = ui->lineEdit_4->text().toStdString();
         std::regex hex("(?:0[xX])?[0-9a-fA-F]+");

         if (std::regex_search(imput, hex)) {


             LONG64 output = strtol(imput.c_str(), 0, 0);
             LONG64 address = output;


             LONG64 resul = address + imgbs;

             sprintf(res, "0x%x", resul);
             rs << res;
             ui->lineEdit_5->setText(QString::fromStdString(rs.str()));


         }
         else {

             QMessageBox::critical(this, "KirbiDSMx64", "Invalid hex address!");
         }
    }
}

void AddressConverter::on_pushButton_5_clicked()
{

    if(ui->lineEdit_4->text().length() == 0) {

        ui->lineEdit_4->setText("Enter an address!");
    }
    else {

        char res[1024] = { 0 };
        std::stringstream rs;
                ///msclr::interop::marshal_context conti;
         std::string imput = ui->lineEdit_4->text().toStdString();
         std::regex hex("(?:0[xX])?[0-9a-fA-F]+");

         if (std::regex_search(imput, hex)) {


             LONG64 output = strtol(imput.c_str(), 0, 0);
             LONG64 address = output;


             LONG64 resul = address - imgbs;

             sprintf(res, "0x%x", resul);
             rs << res;
             ui->lineEdit_5->setText(QString::fromStdString(rs.str()));


         }
         else {

             QMessageBox::critical(this, "KirbiDSMx64", "Invalid hex address!");
         }
    }
}
