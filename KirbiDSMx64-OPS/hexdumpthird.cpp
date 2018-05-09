#include "hexdumpthird.h"
#include "ui_hexdumpthird.h"
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
#include <iomanip>
#include <QMessageBox>
using namespace std;
HexDumpThird::HexDumpThird(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HexDumpThird)
{
    ui->setupUi(this);
}

HexDumpThird::~HexDumpThird()
{
    delete ui;
}
std::string hexdump(char *path) {
    std::string output;
    std::stringstream in;
    char* Byte = new char;
        int   byteCount = 0;

        /*if (argc != 2) {
            cout << "Invocation: hexdump <binaryfilename>" << endl;
            return 1;
        }*/
        ifstream binFile(path, ios::in | ios::binary); // open input file in binary mode

        int c = ' ';
    //	cout << "Hex dump of file " << argv[1] << ":" << endl << endl;
        const string colHeader = "  00  01  02  03  04  05  06  07      08  09  0A  0B  0C  0D  0E  0F";
        const string Delimiter = "  ------------------------------------------------------------------";
        in << colHeader << endl;
        in << Delimiter << endl;
        char ascii[1024] = { 0 };
        binFile.read(Byte, 1);                   // grab first byte of file
        cout << setfill('0') << uppercase;       // set fill character to handle single-digit hex values
        int len = 0;
        char *asci;
        std::string imput;

        std::stringstream test;
        std::string bytesper1;
        std::string outascii;
        //     and display upper hex digits in upper-case
        while (binFile) {


            in << "  " << hex << setw(2) << (short(*Byte) & 0x00FF);




            byteCount++;
            if (byteCount % 8 == 0) {
                if (byteCount % 16 == 0) {
                    in << "\t\t" << endl;

                }

                else
                    in << "\t\t";
            }
            binFile.read(Byte, 1);                 // grab next byte of file
        }

        in << endl;
        in << Delimiter << endl;
        in << colHeader << endl;

        binFile.close();
        output = in.str();
        return output;
       // std::getchar();
}
void HexDumpThird::on_HexDumpThird_windowTitleChanged(const QString &title)
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
    std::string pthstd = pathret.toStdString();
    std::string hex = hexdump((char*)pthstd.c_str());
    ui->plainTextEdit->appendPlainText(QString::fromStdString(hex));
}
