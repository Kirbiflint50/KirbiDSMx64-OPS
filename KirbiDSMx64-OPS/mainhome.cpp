#include "mainhome.h"
#include "ui_mainhome.h"
#include <QString>
#include <QMessageBox>
#include <QFileDialog>
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
#include <inttypes.h>
#include <string>
#include "pe_lib/pe_bliss.h"
#include <iomanip>
#include "include/distorm.h"
#include "memorymap.h"
#include "hexdump1.h"
#include "hexdumpsecond.h"
#include "hexdumpthird.h"
#include "protectionanalyzer.h"
#include <string>
#include <QScrollBar>
#include <QIcon>
#include <QPalette>
#include <QFile>
#include <QTextStream>
#include <QDragEnterEvent>
#include <QUrl>
#include <QDropEvent>
#include <QTextDocument>
#include <QFont>
#include <QDialog>
#include <QKeySequence>
#include "addressconverter.h"
#include <QKeyEvent>
#include "relocations.h"
#include "strings.h"
#include "importstable.h"
#include "exporttable.h"
#include <expression.h>
#include "settings.h"
#include <QHBoxLayout>
//#include "searchpattern.h"
#include <QClipboard>
#include <QTextCursor>
#include <QMimeData>
#include <QList>
#include <string>
#include "Zydis/Zydis.hpp"
#include <QProcess>
#include <QPushButton>
#include <QWidget>
#include "decompiler.h"
#include <QTextCursor>
#include "relocationadder.h"
#include "libudis86/udis86.h"
#include "sectionsadder.h"
#include "importadder.h"
#include "selectsection.h"
#include <stdlib.h>
#include <inttypes.h>
#include <thread>
#define MAX_INSTRUCTIONS (1000)
#define HEX_OFFSET    1
#define ASCII_OFFSET 51
#define NUM_CHARS    16


using namespace std;
using namespace pe_bliss;
MainHome::MainHome(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainHome)
{
    ui->setupUi(this);

    std::stringstream stackreport;

    stackreport << "------------------------------------------------------------------------------------------------------------------------------------KirbiDSMx64------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";

    stackreport << "\n\n";
    this->setAcceptDrops(true);
    //stackreport << "\n\n";
    QPalette palete;
    palete.setColor(QPalette::Text, Qt::red);
    ui->plainTextEdit_4->setPalette(palete);
    ui->plainTextEdit_4->appendPlainText(QString::fromStdString(stackreport.str()));
    QString settingsdir = "Settings.ini";
    std::string fileini = settingsdir.toStdString();
    DWORD ftyp = GetFileAttributesA(fileini.c_str());

    if (ftyp == INVALID_FILE_ATTRIBUTES) {

        std::string dascrivere2 = "BackColor default;";
        std::string dascrivere3 = "Font default;";
        std::string dascrivere4 = "UpperCase NO;";
        std::string dascrivere5 = "FontColor default;";
        char c = ' ';
        FILE *writesttes = fopen(fileini.c_str(), "w");
        FILE *readsetts = NULL;
        if(writesttes > 0) {
        fprintf(writesttes, "%s\n", (char*)dascrivere2.c_str());
        fprintf(writesttes, "%s\n", (char*)dascrivere3.c_str());
        fprintf(writesttes, "%s\n", (char*)dascrivere4.c_str());
        fprintf(writesttes, "%s\n", (char*)dascrivere5.c_str());

        fclose(writesttes);
        QPalette palette;
        palette.setColor(QPalette::Text, Qt::red);
        ui->plainTextEdit_4->setPalette(palette);
        ui->plainTextEdit_4->appendPlainText("-Settings file successfully created, waiting for reading...\n");
    }
     else if (writesttes == NULL){
        QPalette palette;
        palette.setColor(QPalette::Text, Qt::red);
        ui->plainTextEdit_4->setPalette(palette);
        ui->plainTextEdit_4->appendPlainText("-Write settings file settings FALIED.\n");
        fclose(writesttes);
        QMessageBox::critical(this, "KirbiDSMx64", "Sorry, couldn't create the settings file.");


        QApplication::quit();
       /// goto ahead;



        }
        readsetts = fopen(fileini.c_str(), "rt");
        std::stringstream dates;
        if (readsetts > 0) {
            while ((c = fgetc(readsetts)) != EOF) {

                dates << c;
            }
            fclose(readsetts);
            QPalette palette;
            palette.setColor(QPalette::Text, Qt::red);
            ui->plainTextEdit_4->setPalette(palette);
            ui->plainTextEdit_4->appendPlainText("-Settings readed successfully, waiting for reading...\n");
        }
        else if(readsetts == NULL){

            fclose(readsetts);
            QMessageBox::critical(this, "KirbiDSMx64", "Sorry, couldn't read the settings data from the configuration file.");

            QApplication::quit();
            ///goto ahead;
        }




         std::string ouput = dates.str();
         QString infos = QString::fromStdString(ouput);

         if(infos.contains(QString::fromStdString(dascrivere2)) + infos.contains(QString::fromStdString(dascrivere3)) + infos.contains(QString::fromStdString(dascrivere4)) + infos.contains(QString::fromStdString(dascrivere5))) {

             ///QPalette palette;
             palete.setColor(QPalette::Base, QColor(Qt::black));
             palete.setColor(QPalette::Text, Qt::red);
             ui->plainTextEdit->setPalette(palete);
             ui->plainTextEdit->setFont(QFont("Lucida Console", 9));
             ui->plainTextEdit_3->setPalette(palete);
             ui->plainTextEdit_3->setFont(QFont("Lucida Console", 9));
             ui->plainTextEdit_4->setPalette(palete);
             ui->plainTextEdit_4->setFont(QFont("Lucida Console", 9));
             ui->plainTextEdit_4->appendPlainText("-Font color default setted.\n");
             ui->plainTextEdit_4->appendPlainText("-Backcolor default setted.\n");
             ui->plainTextEdit_4->appendPlainText("-Font size default setted.\n");










         }













































    }
    else {



         std::stringstream datread;
         QString dascrivere2 = "BackColor default;";
         QString dascrivere3 = "Font default;";
         QString dascrivere4 = "UpperCase NO;";
         QString dascrivere5 = "FontColor default;";
         char ch;
         FILE *reader = NULL;

         reader = fopen(fileini.c_str(), "rt");

         if(reader > 0) {


             while((ch = fgetc(reader)) != EOF) {

                 datread << ch;
             }
             fclose(reader);
             ui->plainTextEdit_4->appendPlainText("-Settings loaded successfully.\n");



         }
         else  {

             ui->plainTextEdit_4->appendPlainText("-Settings load FALIED.\n");
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
                         ui->plainTextEdit_3->setPalette(palete);
                         ui->plainTextEdit_4->setPalette(palete);
                         ////richTextBox1->Font = gcnew System::Drawing::Font(richTextBox1->Font->FontFamily, 8);
                          ui->plainTextEdit_4->appendPlainText("-Background default setted.\n");


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
                         ui->plainTextEdit_3->setPalette(palete);
                         ui->plainTextEdit_4->setPalette(palete);
                         ui->plainTextEdit_4->appendPlainText("-Font color default setted.\n");

                     }
                     if (dts.contains("BackColor red;"))
                     {
                        // QPalette bkgry;
                         palete.setColor(QPalette::Base, QColor(Qt::red));
                         ui->plainTextEdit->setPalette(palete);
                         ui->plainTextEdit_3->setPalette(palete);
                         ui->plainTextEdit_4->setPalette(palete);
                         ui->plainTextEdit_4->appendPlainText("-Background color red setted.\n");


                     }
                     if (dts.contains("BackColor blue;"))
                     {

                         palete.setColor(QPalette::Base, QColor(Qt::blue));
                         ui->plainTextEdit->setPalette(palete);
                         ui->plainTextEdit_3->setPalette(palete);
                         ui->plainTextEdit_4->setPalette(palete);
                         ui->plainTextEdit_4->appendPlainText("-Background blue setted.\n");

                     }
                     if (dts.contains("BackColor white;"))
                     {
                         ///QPalette bkgr;
                         palete.setColor(QPalette::Base, QColor(Qt::white));
                         ui->plainTextEdit->setPalette(palete);
                         ui->plainTextEdit_3->setPalette(palete);
                         ui->plainTextEdit_4->setPalette(palete);
                         ui->plainTextEdit_4->appendPlainText("-Background white setted.\n");
                     }
                     if (dts.contains("BackColor black;"))
                     {
                         //QPalette bkgr;
                         palete.setColor(QPalette::Base, QColor(Qt::black));
                         ui->plainTextEdit->setPalette(palete);
                         ui->plainTextEdit_3->setPalette(palete);
                         ui->plainTextEdit_4->setPalette(palete);
                         ui->plainTextEdit_4->appendPlainText("-Background black setted.\n");

                     }
                     if (dts.contains("Font medium;"))
                     {
                         ui->plainTextEdit->setFont(QFont("Courier", 12));
                         ui->plainTextEdit_3->setFont(QFont("Courier", 12));
                         ui->plainTextEdit_4->setFont(QFont("Courier", 12));
                         ui->plainTextEdit_4->appendPlainText("-Font medium setted.\n");
                     }
                     if (dts.contains("Font big;"))
                     {

                         ui->plainTextEdit->setFont(QFont("Courier", 15));
                         ui->plainTextEdit_3->setFont(QFont("Courier", 15));
                         ui->plainTextEdit_4->setFont(QFont("Courier", 15));
                         ui->plainTextEdit_4->appendPlainText("-Font big setted.\n");
                     }
                     if (dts.contains("FontColor blue;"))
                     {

                         ////QPalette fontcl;
                         palete.setColor(QPalette::Text, QColor(Qt::blue));
                         ui->plainTextEdit->setPalette(palete);
                         ui->plainTextEdit_3->setPalette(palete);
                         ui->plainTextEdit_4->setPalette(palete);
                         ui->plainTextEdit_4->appendPlainText("-Font color blue setted.\n");

                     }
                     if (dts.contains("FontColor red;"))
                     {
                         //QPalette fontcl;
                         palete.setColor(QPalette::Text, QColor(Qt::red));
                         ui->plainTextEdit->setPalette(palete);
                         ui->plainTextEdit_3->setPalette(palete);
                         ui->plainTextEdit_4->setPalette(palete);
                         ui->plainTextEdit_4->appendPlainText("-Font color red setted.\n");
                     }
                     if (dts.contains("FontColor green;"))
                     {
                         //QPalette fontcl;
                         palete.setColor(QPalette::Text, QColor(Qt::green));
                         ui->plainTextEdit->setPalette(palete);
                         ui->plainTextEdit_3->setPalette(palete);
                         ui->plainTextEdit_4->setPalette(palete);
                         ui->plainTextEdit_4->appendPlainText("-Font color green setted.\n");
                     }
                     if (dts.contains("FontColor yellow;"))
                     {
                        // QPalette fontcl;
                         palete.setColor(QPalette::Text, QColor(Qt::yellow));
                         ui->plainTextEdit->setPalette(palete);
                         ui->plainTextEdit_3->setPalette(palete);
                         ui->plainTextEdit_4->setPalette(palete);
                         ui->plainTextEdit_4->appendPlainText("-Font color yellow setted.\n");
                     }

                      /// return;
























    }

}
QString flnm = "";
QString sections;
int f = 0;
int result = 0;
//int fontsize;
//int backcolor;
//int fontcolor;
int upper;
int lblfont = 12;
int pedonecode;
int infoupper;
LONG64 oepoffi;
LONG64 endi;
int engine = 0;
        ////System::String^ codedsm;
        ///System::String^ anassembi;
LONG64 imgbase;
LONG64 addressofentrypoint;
LONG64 offsetaddress;
LONG64 endsection;
LPVOID base;
PIMAGE_SECTION_HEADER sc;
PIMAGE_NT_HEADERS64 nt;
MainHome::~MainHome()
{
    delete ui;
}

uint64_t to_uint64(std::string const & in) {
  static_assert(sizeof(unsigned long long) == sizeof(uint64_t), "ull not large enough");
  unsigned long long val = 0;
  std::istringstream stream(in);
  stream >> val;
  return val;
}

LONG64 Rvatooff(LONG64 address, PIMAGE_SECTION_HEADER sects, PIMAGE_NT_HEADERS64 ntheader) {

    LONG64 offset;
    for (int i = 0; i < ntheader->FileHeader.NumberOfSections; i++)
    {
        if ((sects->VirtualAddress <= address) && (address < (sects->VirtualAddress + sects->Misc.VirtualSize))) {

            offset = (address)-(sects->VirtualAddress) + (sects->PointerToRawData);

            ///endi = (pSecHeader->PointerToRawData) + (pSecHeader->SizeOfRawData) - oepoffi;


            break;

        }

        sects++;
    }

    return offset;

}

char *Oepnamesecc(LONG64 address, PIMAGE_SECTION_HEADER sects, PIMAGE_NT_HEADERS64 ntheader) {

    char *name;
    for (int i = 0; i < ntheader->FileHeader.NumberOfSections; i++)
    {
        if ((sects->VirtualAddress <= address) && (address < (sects->VirtualAddress + sects->Misc.VirtualSize))) {

            name = (char*)sects->Name;

            ///endi = (pSecHeader->PointerToRawData) + (pSecHeader->SizeOfRawData) - oepoffi;


            break;

        }

        sects++;
    }

    return name;

}

bool IsDotNetApp(const char* szPath)
{
    HANDLE hFile = CreateFileA(szPath, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);
    if (INVALID_HANDLE_VALUE == hFile)
        return false;

    DWORD temp;

    IMAGE_DOS_HEADER IMAGE_DOS_HEADER_;
    ReadFile(hFile, &IMAGE_DOS_HEADER_, sizeof(IMAGE_DOS_HEADER_), &temp, NULL);

    SetFilePointer(hFile, IMAGE_DOS_HEADER_.e_lfanew, NULL, FILE_BEGIN);

    const int nNtHeaderMaxSize = sizeof(IMAGE_NT_HEADERS64);
    BYTE NT_HEADERS[nNtHeaderMaxSize];
    ReadFile(hFile, NT_HEADERS, nNtHeaderMaxSize, &temp, NULL);

    PIMAGE_NT_HEADERS pNT_HEADERS = (PIMAGE_NT_HEADERS)NT_HEADERS;
    bool bRes;
    if (pNT_HEADERS->OptionalHeader.Magic == IMAGE_NT_OPTIONAL_HDR64_MAGIC)
    {
        bRes = 0 != ((PIMAGE_NT_HEADERS64)NT_HEADERS)->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_COM_DESCRIPTOR].VirtualAddress;
    }
    else
    {
        // Unknown header type
        bRes = false;
    }

    CloseHandle(hFile);

    return bRes;
}

const char* resolve(struct ud *u, uint64_t addr, int64_t *offset)
{
  *offset = addr - 0x15;
  return "target";
}

QString dis_loop(struct ud *ud_obj)
{
    QString udisdsm;
    std::stringstream dis;
    char arraydsm[1024] = {0};
  while (ud_disassemble(ud_obj) != 0) {
    sprintf(arraydsm, "%016llx\t%-16s\t%s\n", ud_insn_off(ud_obj),
                                 ud_insn_hex(ud_obj),
                                 ud_insn_asm(ud_obj));
    dis << arraydsm;
  }
  udisdsm = QString::fromStdString(dis.str());
  return udisdsm;
}



std::string hexdumpm(const char *path) {
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

long getFileSizemain(FILE *file)
{
    long lCurPos, lEndPos;
    lCurPos = ftell(file);
    fseek(file, 0, 2);
    lEndPos = ftell(file);
    fseek(file, lCurPos, 0);
    return lEndPos;
}

void clear_lined(char *line, int size)
{
    int count;

    for (count = 0; count < size; line[count] = ' ', count++);
}

char * asciid(char *position, int c)
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

char * hexd(char *position, int c)
{
    int offset = 3;

    sprintf(position, "%02X ", (unsigned char)c);

    *(position + offset) = ' ';   /* Remove the '/0' created by 'sprint'  */

    return (position + offset);
}
void MainHome::on_actionOpen_triggered()
{

    QString filepath = QFileDialog::getOpenFileName(this, tr("Open your exe!"), "c:\\", tr("Executable files (*.exe *.ax *.cpl *.dll *.drv *.efi *.mui *.ocx *.scr *.sys *.tsp)"));

    if (filepath.length() > 0) {
        std::string pthstd = filepath.toStdString();
        flnm = filepath;
        this->setWindowTitle("KirbiDSMx64 - " + filepath);

        int i = 0;
        HANDLE hMapObject, hFile; //File Mapping Object
        LPVOID lpBase; //Pointer to the base memory of mapped file
        PIMAGE_DOS_HEADER dosHeader; //Pointer to DOS Header
        PIMAGE_NT_HEADERS64 ntHeader; //Pointer to NT Header
        IMAGE_FILE_HEADER header; //Pointer to image file header of NT Header
        IMAGE_OPTIONAL_HEADER opHeader; //Optional Header of PE files present in NT Header structure
        PIMAGE_SECTION_HEADER pSecHeader;

        hFile = CreateFileA((char*)pthstd.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);

        if (hFile == INVALID_HANDLE_VALUE) {
            ui->plainTextEdit_4->appendPlainText("-File read FALIED.\n");
            this->setWindowTitle("KirbiDSMx64");
            QMessageBox::critical(this, tr("KirbiDSMx64"), tr("Error reading the file."));
            flnm = "";
            return;
        }
        ui->plainTextEdit_4->appendPlainText("-File read successfully complete, waiting for mapping.\n");
        HANDLE hMap = CreateFileMapping(hFile, 0, PAGE_READONLY, 0, 0, 0);
        if (hMap == NULL) {
            ui->plainTextEdit_4->appendPlainText("-Create File mapping FALIED.\n");
            this->setWindowTitle("KirbiDSMx64");
            QMessageBox::critical(this, tr("KirbiDSMx64"), tr("Error mapping the file."));
            flnm = "";
            return;
        }
        ui->plainTextEdit_4->appendPlainText("-Map file created successfully, waiting for read.\n");
        lpBase = MapViewOfFile(hMap, FILE_MAP_READ, 0, 0, 0);
        base = lpBase;
        if (lpBase == NULL) {
            ui->plainTextEdit_4->appendPlainText("-Map reading FALIED.\n");
            this->setWindowTitle("KirbiDSMx64");
            QMessageBox::critical(this, tr("KirbiDSMx64"), tr("Error reading the bytes."));
            flnm = "";
            return;
        }
        ui->plainTextEdit_4->appendPlainText("-Map reading successfully complete.\n");
        dosHeader = (PIMAGE_DOS_HEADER)lpBase;

        ntHeader = (PIMAGE_NT_HEADERS64)((LONG64)(dosHeader) + (dosHeader->e_lfanew));
        if (ntHeader->Signature != IMAGE_NT_SIGNATURE) {
            this->setWindowTitle("KirbiDSMx64");
            QMessageBox::critical(this, tr("KirbiDSMx64"), tr("Invalid PE file!"));
            flnm = "";
            return;
        }
        pSecHeader = (PIMAGE_SECTION_HEADER)((LONG64)ntHeader + sizeof(IMAGE_NT_HEADERS64));
        if (flnm.contains(".dll")) {
            ui->plainTextEdit_4->appendPlainText("-PE type DLL\n");
        }
        if(IsDotNetApp(flnm.toStdString().c_str())) {

            ui->plainTextEdit_4->appendPlainText("-PE type .NET\n");
        }
        if (((ntHeader->OptionalHeader.Magic & IMAGE_NT_OPTIONAL_HDR32_MAGIC) == IMAGE_NT_OPTIONAL_HDR32_MAGIC) && ((ntHeader->FileHeader.Characteristics & IMAGE_FILE_32BIT_MACHINE) == IMAGE_FILE_32BIT_MACHINE)) {

            QMessageBox::warning(this, tr("KirbiDSMx64"), tr("This PE is 32 bit, to disasseble it use KirbiDSM."));
            this->setWindowTitle("KirbiDSMx64");
            flnm = "";
        }

        else {
            std::stringstream secstresm;
            ui->plainTextEdit_4->appendPlainText("-PE32+ (64)\n");
            sc = pSecHeader;
            nt = ntHeader;
            for (int i = 0; i < ntHeader->FileHeader.NumberOfSections; i++) {
                if ((pSecHeader->VirtualAddress <= ntHeader->OptionalHeader.AddressOfEntryPoint) && (ntHeader->OptionalHeader.AddressOfEntryPoint < (pSecHeader->VirtualAddress + pSecHeader->Misc.VirtualSize))) {

                    oepoffi = (ntHeader->OptionalHeader.AddressOfEntryPoint) - (pSecHeader->VirtualAddress) + (pSecHeader->PointerToRawData);

                    endi = (pSecHeader->PointerToRawData) + (pSecHeader->SizeOfRawData) - oepoffi;

                    break;
                }

                pSecHeader++;
            }
            pSecHeader = (PIMAGE_SECTION_HEADER)((LONG64)ntHeader + sizeof(IMAGE_NT_HEADERS64));
            int m;
            for (pSecHeader = IMAGE_FIRST_SECTION(ntHeader), m = 0; m < ntHeader->FileHeader.NumberOfSections; m++, pSecHeader++) {

                secstresm << (char*)pSecHeader->Name << "\n";
            }

            sections = QString::fromStdString(secstresm.str());
            pSecHeader = (PIMAGE_SECTION_HEADER)((LONG64)ntHeader + sizeof(IMAGE_NT_HEADERS64));
            if (oepoffi == 0) {

                QMessageBox::StandardButton ques;

                ques = QMessageBox::warning(this, "KirbiDSMx64", "Falied to get EntryPoint offset. Do you want to disassemble the executable section?",
                    QMessageBox::Yes | QMessageBox::No);

                if (ques == QMessageBox::Yes) {

                    oepoffi = pSecHeader->PointerToRawData;
                    endi = pSecHeader->SizeOfRawData;
                }
                else
                    return;
            }

            ui->plainTextEdit->clear();
            //ui->plainTextEdit_2->clear();
            ui->plainTextEdit_3->clear();
            ///ui->plainTextEdit_4->clear();
            char arrdis[1024] = { 0 };
            std::stringstream disstr;
            ui->plainTextEdit_4->appendPlainText("-Disassembling bytes...\n");
            imgbase = (ntHeader->OptionalHeader.ImageBase);
            QMessageBox::StandardButton s;

            s = QMessageBox::question(this, "KirbiDSMx64", "Which engine you want to use? [Yes]Distorm, [No]Zydis, [Cancel]Udis86", QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
            if (s == QMessageBox::Yes) {

                engine = 1;

                unsigned long dver = 0;
                // Holds the result of the decoding.
                _DecodeResult res;
                // Decoded instruction information.
                _DecodedInst decodedInstructions[MAX_INSTRUCTIONS];
                // next is used for instruction's offset synchronization.
                // decodedInstructionsCount holds the count of filled instructions' array by the decoder.
                unsigned int decodedInstructionsCount = 0, i, next;

                // Default decoding mode is 32 bits, could be set by command line.
                _DecodeType dt = Decode64Bits;

                // Default offset for buffer is 0, could be set in command line.
                _OffsetType offset = 0;
                char* errch = NULL;

                // Index to file name in argv.
                int param = 1;

                ////ui->plainTextEdit_4->appendPlainText("-Falied to get the OEP offset.\n");

                // If you get an unresolved external symbol linker error for the following line,
                // change the SUPPORT_64BIT_OFFSET in distorm.h.
                res = distorm_decode(offset, (unsigned char*)lpBase + oepoffi, endi, dt, decodedInstructions, MAX_INSTRUCTIONS, &decodedInstructionsCount);
                if (res > 0) {
                    ui->plainTextEdit_4->appendPlainText("-Disassemblying complete.\n");
                    for (i = 0; i < decodedInstructionsCount; i++) {

                        sprintf(arrdis, " %0*I64x\t(%02d) %-24s\t%s%s%s\n", dt != Decode64Bits ? 8 : 16, decodedInstructions[i].offset, decodedInstructions[i].size, (char*)decodedInstructions[i].instructionHex.p, (char*)decodedInstructions[i].mnemonic.p, decodedInstructions[i].operands.length != 0 ? " " : "", (char*)decodedInstructions[i].operands.p);

                        ///sprintf(arrdis, " %08x\t(%02d) %-24s\t%s%s%s\n", decodedInstructions[i].offset, decodedInstructions[i].size, (char*)decodedInstructions[i].instructionHex.p, (char*)decodedInstructions[i].mnemonic.p, decodedInstructions[i].operands.length != 0 ? " " : "", (char*)decodedInstructions[i].operands.p);
                        disstr << arrdis;
                    }

                    ui->plainTextEdit->appendPlainText(QString::fromStdString(disstr.str()));

                    QScrollBar* vScrollBar = ui->plainTextEdit->verticalScrollBar();

                    //QScrollBar *vScrollBarhex = ui->plainTextEdit_2->verticalScrollBar();
                    vScrollBar->triggerAction(QScrollBar::SliderToMinimum);
                    //pal->triggerAction(QScrollBar::SliderToMinimum);
                    ui->plainTextEdit_3->appendPlainText("RAX = 0000000000000000\n");
                    ui->plainTextEdit_3->appendPlainText("RBX = 0000000000000000\n");
                    ui->plainTextEdit_3->appendPlainText("RCX = 0000000000000000\n");
                    ui->plainTextEdit_3->appendPlainText("RDX = 0000000000000000\n");
                    ui->plainTextEdit_3->appendPlainText("RBP = 0000000000000000\n");
                    ui->plainTextEdit_3->appendPlainText("RSP = 0000000000000000\n");
                    ui->plainTextEdit_3->appendPlainText("RSI = 0000000000000000\n");
                    ui->plainTextEdit_3->appendPlainText("RDI = 0000000000000000\n\n");
                    ui->plainTextEdit_3->appendPlainText("R8 = 0000000000000000\n");
                    ui->plainTextEdit_3->appendPlainText("R9 = 0000000000000000\n");
                    ui->plainTextEdit_3->appendPlainText("R10 = 0000000000000000\n");
                    ui->plainTextEdit_3->appendPlainText("R11 = 0000000000000000\n");
                    ui->plainTextEdit_3->appendPlainText("R12 = 0000000000000000\n");
                    ui->plainTextEdit_3->appendPlainText("R13 = 0000000000000000\n");
                    ui->plainTextEdit_3->appendPlainText("R14 = 0000000000000000\n");
                    ui->plainTextEdit_3->appendPlainText("R15 = 0000000000000000\n");
                    QScrollBar* pal = ui->plainTextEdit_3->verticalScrollBar();
                    pal->triggerAction(QScrollBar::SliderToMinimum);
                    // vScrollBarhex->triggerAction(QScrollBar::SliderToMinimum);
                }
                else {

                    ui->plainTextEdit_4->appendPlainText("-Disassemblying bytes FALIED.\n");
                    QMessageBox::critical(this, "KirbiDSMx64", "Couln't disassemble this file sorry.");
                    UnmapViewOfFile(lpBase);
                    CloseHandle(hFile);
                    CloseHandle(hMap);
                    flnm = "";
                }
            }

             if(s == QMessageBox::No){

                engine = 2;

                std::stringstream add;
                Zydis::InstructionInfo info;
                Zydis::InstructionDecoder decoder;
                Zydis::IntelInstructionFormatter formatter;
                Zydis::MemoryInput input64((unsigned char*)lpBase + oepoffi, endi);
                //Zydis::MemoryInput input64(&data64[0], sizeof(data64));
                char formt[1024] = { 0 };
                std::stringstream dis;
                /*0x00007FFA39A81930ull*/
                LONG64 entry = ntHeader->OptionalHeader.AddressOfEntryPoint;
                LONG64 addresses = 0x00007FFA39A;
                std::stringstream ad;
                ///uint64_t res;
                ad << "0x0000" << std::hex << std::uppercase << addresses << entry;
                std::string hexadec(ad.str());

                strcpy(formt, (char*)hexadec.c_str());
                uint64_t formatting = strtoimax(hexadec.c_str(), 0, 16);

                decoder.setDisassemblerMode(Zydis::DisassemblerMode::M64BIT);
                decoder.setDataSource(&input64);
                decoder.setInstructionPointer(formatting);
                /*info.instrAddress*/
                while (decoder.decodeInstruction(info)) {
                    dis << std::hex << std::setw(16) << std::setfill('0') << std::uppercase
                        << info.instrAddress << "\t\t\t";
                    if (info.flags & Zydis::IF_ERROR_MASK) {
                        dis << "db " << std::setw(2) << static_cast<int>(info.data[0]) << std::endl;
                    }
                    else {
                        dis << formatter.formatInstruction(info) << std::endl;
                    }
                }
                ui->plainTextEdit->appendPlainText(QString::fromStdString(dis.str()));
                QScrollBar* vScrollBar = ui->plainTextEdit->verticalScrollBar();
                //QScrollBar *vScrollBarhex = ui->plainTextEdit_2->verticalScrollBar();
                vScrollBar->triggerAction(QScrollBar::SliderToMinimum);

                ui->plainTextEdit_3->appendPlainText("RAX = 0000000000000000\n");
                ui->plainTextEdit_3->appendPlainText("RBX = 0000000000000000\n");
                ui->plainTextEdit_3->appendPlainText("RCX = 0000000000000000\n");
                ui->plainTextEdit_3->appendPlainText("RDX = 0000000000000000\n");
                ui->plainTextEdit_3->appendPlainText("RBP = 0000000000000000\n");
                ui->plainTextEdit_3->appendPlainText("RSP = 0000000000000000\n");
                ui->plainTextEdit_3->appendPlainText("RSI = 0000000000000000\n");
                ui->plainTextEdit_3->appendPlainText("RDI = 0000000000000000\n\n");
                ui->plainTextEdit_3->appendPlainText("R8 = 0000000000000000\n");
                ui->plainTextEdit_3->appendPlainText("R9 = 0000000000000000\n");
                ui->plainTextEdit_3->appendPlainText("R10 = 0000000000000000\n");
                ui->plainTextEdit_3->appendPlainText("R11 = 0000000000000000\n");
                ui->plainTextEdit_3->appendPlainText("R12 = 0000000000000000\n");
                ui->plainTextEdit_3->appendPlainText("R13 = 0000000000000000\n");
                ui->plainTextEdit_3->appendPlainText("R14 = 0000000000000000\n");
                ui->plainTextEdit_3->appendPlainText("R15 = 0000000000000000\n");

                QScrollBar* pal = ui->plainTextEdit_3->verticalScrollBar();
                pal->triggerAction(QScrollBar::SliderToMinimum);
            }

             if(s == QMessageBox::Cancel) {





                  ud_t ud_obj;
                    ud_init(&ud_obj);
                    ud_set_mode(&ud_obj, 64);
                    ud_set_input_buffer(&ud_obj, (unsigned char*)lpBase + oepoffi, endi);
                    ud_set_syntax(&ud_obj, UD_SYN_INTEL);

                    ////printf("==> Without Symbol Resolution\n");


                    /*printf("==> With Symbol Resolution\n");
                    ud_set_pc(&ud_obj, 0);
                    ud_set_input_buffer(&ud_obj, bin, sizeof(bin));
                    ud_set_sym_resolver(&ud_obj, &resolve);
                    dis_loop(&ud_obj);*/


                ui->plainTextEdit->appendPlainText(dis_loop(&ud_obj));
                QScrollBar* vScrollBar = ui->plainTextEdit->verticalScrollBar();
                //QScrollBar *vScrollBarhex = ui->plainTextEdit_2->verticalScrollBar();
                vScrollBar->triggerAction(QScrollBar::SliderToMinimum);

                ui->plainTextEdit_3->appendPlainText("RAX = 0000000000000000\n");
                ui->plainTextEdit_3->appendPlainText("RBX = 0000000000000000\n");
                ui->plainTextEdit_3->appendPlainText("RCX = 0000000000000000\n");
                ui->plainTextEdit_3->appendPlainText("RDX = 0000000000000000\n");
                ui->plainTextEdit_3->appendPlainText("RBP = 0000000000000000\n");
                ui->plainTextEdit_3->appendPlainText("RSP = 0000000000000000\n");
                ui->plainTextEdit_3->appendPlainText("RSI = 0000000000000000\n");
                ui->plainTextEdit_3->appendPlainText("RDI = 0000000000000000\n\n");
                ui->plainTextEdit_3->appendPlainText("R8 = 0000000000000000\n");
                ui->plainTextEdit_3->appendPlainText("R9 = 0000000000000000\n");
                ui->plainTextEdit_3->appendPlainText("R10 = 0000000000000000\n");
                ui->plainTextEdit_3->appendPlainText("R11 = 0000000000000000\n");
                ui->plainTextEdit_3->appendPlainText("R12 = 0000000000000000\n");
                ui->plainTextEdit_3->appendPlainText("R13 = 0000000000000000\n");
                ui->plainTextEdit_3->appendPlainText("R14 = 0000000000000000\n");
                ui->plainTextEdit_3->appendPlainText("R15 = 0000000000000000\n");

                QScrollBar* pal = ui->plainTextEdit_3->verticalScrollBar();
                pal->triggerAction(QScrollBar::SliderToMinimum);

             }
        }
    }

}
void MainHome::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainHome::on_actionPE_Infos_Memory_Map_View_triggered()
{
    if(flnm == "")
        QMessageBox::critical(this, "KirbiDSMx64", "File not opened.");
    else {


        MemoryMap mem;
        mem.setModal(true);
        mem.dumpmem(flnm);
        mem.setWindowTitle("MemoryMap");


        mem.exec();


    }

}

void MainHome::on_actionDump_1_Not_all_the_file_triggered()
{
    if(flnm == "")
        QMessageBox::critical(this, "KirbiDSMx64", "File not opened.");
    else {





        HexDump1 hex;
        hex.setModal(true);
        hex.gethex(flnm);
        hex.setWindowTitle("HexDump1");


        hex.exec();

    }
}

void MainHome::on_actionDump_2_Not_all_the_file_triggered()
{
    if(flnm == "") {
        QMessageBox::critical(this, "KirbiDSMx64", "File not opened.");
    }
    else {

        HexDumpSecond hexsec;
        hexsec.setModal(true);
        hexsec.filepath(flnm);
        hexsec.setWindowTitle("HexDumpSecond");
        hexsec.exec();
    }

}

void MainHome::on_actionDump_3_Complete_triggered()
{
    if(flnm == "") {
        QMessageBox::critical(this, "KirbiDSMx64", "File not opened.");
    }
    else {

        HexDumpThird hexthird;
        hexthird.setModal(true);
        hexthird.getpath(flnm);
        hexthird.setWindowTitle("HexDumpThird");
        hexthird.exec();
    }
}

void MainHome::on_actionProtection_analyzer_triggered()
{
    if(flnm == "") {
        QMessageBox::critical(this, "KirbiDSMx64", "File not opened.");
    }
    else {

        ProtectionAnalyzer pro;
        pro.setModal(true);
        pro.getSections(sections);
        pro.setWindowTitle("ProtectionAnalayzer");
        pro.exec();
    }
}

void MainHome::on_MainHome_windowTitleChanged(const QString &title)
{





}

void MainHome::on_MainHome_windowIconChanged(const QIcon &icon)
{

}

void MainHome::on_actionAddressConverter_values_converter_triggered()
{
    if(flnm == "") {



        QMessageBox::StandardButton info;

        info = QMessageBox::question(this, "KirbiDSMx64", "The file is not opened, do you want to open the addressconverter without using the addressconverter?",

                                     QMessageBox::Yes|QMessageBox::No);

        if (info == QMessageBox::Yes) {


            AddressConverter address;
            address.setModal(true);
            address.getloc(flnm);
            address.setWindowTitle("AddressConverter");
            address.exec();



        }







    }
    else {


        AddressConverter addressv;
        addressv.setModal(true);
        addressv.getloc(flnm);
        addressv.getimage(imgbase);
        addressv.setWindowTitle("AddressConverter");
        addressv.exec();







    }
}

void MainHome::on_actionImports_table_View_triggered()
{
    if(flnm == "") {

        QMessageBox::critical(this, "KirbiDSMx64", "File not opened.");
    }
    else {

        std::ifstream pe_file(flnm.toStdString(), std::ios::in | std::ios::binary);

        pe_base image(pe_factory::create_pe(pe_file));

        //Проверим, есть ли импорты у файла
        if(!image.has_imports())
        {

            QMessageBox::warning(this, "KirbiDSMx64", "This PE has not Imports.");

        }
        else {

            ImportsTable table;
            table.setModal(true);
            table.gthloc(flnm);
            table.setWindowTitle("Imports");
            table.exec();
        }


    }
}

void MainHome::on_actionExports_table_View_triggered()
{
    if(flnm == "") {

        QMessageBox::critical(this, "KirbiDSMx64", "File not opened.");
    }
    else {
        std::ifstream pe_file(flnm.toStdString(), std::ios::in | std::ios::binary);

        pe_base image(pe_factory::create_pe(pe_file));


        if(!image.has_exports())
        {

            QMessageBox::warning(this, "KirbiDSMx64", "This PE has not Exports.");


        }
        else {

          ExportTable extable;
          extable.setModal(true);
          extable.getex(flnm);
          extable.setWindowTitle("Exports");
          extable.exec();
        }


    }

}

void MainHome::on_actionRelocations_Viewer_triggered()
{
    if(flnm == "") {

        QMessageBox::critical(this, "KirbiDSMx64", "File not opened.");
    }
    else {

        std::ifstream pe_file(flnm.toStdString(), std::ios::in | std::ios::binary);

        pe_base image(pe_factory::create_pe(pe_file));

        //Проверим, есть ли релокации у файла
        if(!image.has_reloc())
        {
            QMessageBox::warning(this, "KirbiDSMx64", "This PE has not Relocations");
        }
        else {

        Relocations reloc;
        reloc.setModal(true);
        reloc.reloc(flnm);
        reloc.setWindowTitle("Relocations");
        reloc.exec();
        }
    }

}

void MainHome::on_actionAll_Strings_triggered()
{
    if(flnm == "") {

        QMessageBox::critical(this, "KirbiDSMx64", "File not opened.");
    }
    else {

        ///ui->plainTextEdit_4->appendPlainText("Loading Strings...\n");
        Strings strs;
        strs.setModal(true);
        strs.location(flnm);
        strs.setWindowTitle("Strings");
        strs.exec();
        ///ui->plainTextEdit_4->appendPlainText("Strings loaded!\n");

    }
}

void MainHome::on_actionAddress_VA_triggered()
{
    if((ui->plainTextEdit->textCursor().selectedText().length() > 0) && (ui->plainTextEdit->toPlainText().length() > 0)) {
    QClipboard *clipboard = QApplication::clipboard();
    if(engine == 1) {

    std::string address = ui->plainTextEdit->textCursor().selectedText().toStdString();
    address = address.substr(0, 16);
    clipboard->setText(QString::fromStdString(address));
    if(clipboard->text().length() > 0)
        ui->plainTextEdit_4->appendPlainText("VA Copied to clipboard.\n");
  }
    else if(engine == 2) {

        std::string addressva = ui->plainTextEdit->textCursor().selectedText().toStdString();
        addressva = addressva.substr(0, 16);
        clipboard->setText(QString::fromStdString(addressva));
        if(clipboard->text().length() > 0)
            ui->plainTextEdit_4->appendPlainText("VA Copied to clipboard.\n");

    }
}
}

void MainHome::on_plainTextEdit_selectionChanged()
{

}

void MainHome::on_actionRVA_triggered()
{
    if((ui->plainTextEdit->textCursor().selectedText().length() > 0) && (ui->plainTextEdit->toPlainText().length() > 0)) {
    QClipboard *clipboard = QApplication::clipboard();
    if(engine == 1) {

    std::string address = ui->plainTextEdit->textCursor().selectedText().toStdString();
    std::stringstream en;
    en << std::hex << nt->OptionalHeader.AddressOfEntryPoint;
    size_t length = en.str().size();
    address = address.substr(0, length);
    clipboard->setText(QString::fromStdString(address));

    if(clipboard->text().length() > 0)
        ui->plainTextEdit_4->appendPlainText("RVA Copied to clipboard.\n");
  }
    else if(engine == 2) {

        std::string addressva = ui->plainTextEdit->textCursor().selectedText().toStdString();
        addressva = addressva.substr(11, 5);
        clipboard->setText(QString::fromStdString(addressva));
        if(clipboard->text().length() > 0)
            ui->plainTextEdit_4->appendPlainText("RVA Copied to clipboard.\n");

    }
  }
}

void MainHome::on_actionOffset_triggered()
{
    if((ui->plainTextEdit->textCursor().selectedText().length() > 0) && (ui->plainTextEdit->toPlainText().length() > 0)) {
    QClipboard *clipboard = QApplication::clipboard();
    std::stringstream out;

    if(engine == 2) {

        std::string address = ui->plainTextEdit->textCursor().selectedText().toStdString();
        address = address.substr(11, 5);

        LONG64 addressoff = strtoimax(address.c_str(), 0, 16);

        LONG64 offs = Rvatooff(addressoff, sc, nt);

        out << std::hex << std::uppercase << offs;
        clipboard->setText(QString::fromStdString(out.str()));
        if(clipboard->text().length() > 0)
            ui->plainTextEdit_4->appendPlainText("Offset Copied to clipboard.\n");


    }
    else {

        QMessageBox::warning(this, "KirbiDSMx64", "Couldn't copy File offset in Distorm engine.");
    }

    }
}

void MainHome::on_actionSelected_lines_triggered()
{
    if((ui->plainTextEdit->textCursor().selectedText().length() > 0) && (ui->plainTextEdit->toPlainText().length() > 0)) {
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(ui->plainTextEdit->textCursor().selectedText());
    if(clipboard->text().length() > 0)
        ui->plainTextEdit_4->appendPlainText("Selected lines Copied to clipboard.\n");

    }
}

void MainHome::on_actionPattern_triggered() {






}

void MainHome::keyPressEvent(QKeyEvent *event)
{

    if(event->type() == QEvent::KeyPress) {

        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);

        if (keyEvent->key() == Qt::Modifier::CTRL || keyEvent->key() == Qt::Key_G)
        {
        //do something
            if((flnm.length() > 0) && (ui->plainTextEdit->toPlainText().length() > 0)) {

                Expression *exp = new Expression();
                exp->setModal(true);
                exp->location(flnm, this->ui->plainTextEdit->toPlainText(), this->ui->plainTextEdit_4->toPlainText(), this->ui->plainTextEdit_3->toPlainText());
                exp->setWindowTitle("Expression");
                this->hide();
                exp->show();
               /// this->ui->plainTextEdit->appendPlainText(exp.dsmadd);

            }

        }

        if(keyEvent->key() == Qt::Modifier::CTRL || keyEvent->key() == Qt::Key_O) {

            QString filepath = QFileDialog::getOpenFileName(this, tr("Open your exe!"), "c:\\", tr("Executable files (*.exe *.ax *.cpl *.dll *.drv *.efi *.mui *.ocx *.scr *.sys *.tsp)"));

            if (filepath.length() > 0) {
                std::string pthstd = filepath.toStdString();
                flnm = filepath;
                this->setWindowTitle("KirbiDSMx64 - " + filepath);

                int i = 0;
                HANDLE hMapObject, hFile; //File Mapping Object
                LPVOID lpBase; //Pointer to the base memory of mapped file
                PIMAGE_DOS_HEADER dosHeader; //Pointer to DOS Header
                PIMAGE_NT_HEADERS64 ntHeader; //Pointer to NT Header
                IMAGE_FILE_HEADER header; //Pointer to image file header of NT Header
                IMAGE_OPTIONAL_HEADER opHeader; //Optional Header of PE files present in NT Header structure
                PIMAGE_SECTION_HEADER pSecHeader;

                hFile = CreateFileA((char*)pthstd.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);

                if (hFile == INVALID_HANDLE_VALUE) {
                    ui->plainTextEdit_4->appendPlainText("-File read FALIED.\n");
                    this->setWindowTitle("KirbiDSMx64");
                    QMessageBox::critical(this, tr("KirbiDSMx64"), tr("Error reading the file."));
                    flnm = "";
                    return;
                }
                ui->plainTextEdit_4->appendPlainText("-File read successfully complete, waiting for mapping.\n");
                HANDLE hMap = CreateFileMapping(hFile, 0, PAGE_READONLY, 0, 0, 0);
                if (hMap == NULL) {
                    ui->plainTextEdit_4->appendPlainText("-Create File mapping FALIED.\n");
                    this->setWindowTitle("KirbiDSMx64");
                    QMessageBox::critical(this, tr("KirbiDSMx64"), tr("Error mapping the file."));
                    flnm = "";
                    return;
                }
                ui->plainTextEdit_4->appendPlainText("-Map file created successfully, waiting for read.\n");
                lpBase = MapViewOfFile(hMap, FILE_MAP_READ, 0, 0, 0);
                base = lpBase;
                if (lpBase == NULL) {
                    ui->plainTextEdit_4->appendPlainText("-Map reading FALIED.\n");
                    this->setWindowTitle("KirbiDSMx64");
                    QMessageBox::critical(this, tr("KirbiDSMx64"), tr("Error reading the bytes."));
                    flnm = "";
                    return;
                }
                ui->plainTextEdit_4->appendPlainText("-Map reading successfully complete.\n");
                dosHeader = (PIMAGE_DOS_HEADER)lpBase;

                ntHeader = (PIMAGE_NT_HEADERS64)((LONG64)(dosHeader) + (dosHeader->e_lfanew));
                if (ntHeader->Signature != IMAGE_NT_SIGNATURE) {
                    this->setWindowTitle("KirbiDSMx64");
                    QMessageBox::critical(this, tr("KirbiDSMx64"), tr("Invalid PE file!"));
                    flnm = "";
                    return;
                }
                pSecHeader = (PIMAGE_SECTION_HEADER)((LONG64)ntHeader + sizeof(IMAGE_NT_HEADERS64));
                if (flnm.contains(".dll")) {
                    ui->plainTextEdit_4->appendPlainText("-PE type DLL\n");
                }
                if(IsDotNetApp(flnm.toStdString().c_str())) {

                    ui->plainTextEdit_4->appendPlainText("-PE type .NET\n");
                }
                if (((ntHeader->OptionalHeader.Magic & IMAGE_NT_OPTIONAL_HDR32_MAGIC) == IMAGE_NT_OPTIONAL_HDR32_MAGIC) && ((ntHeader->FileHeader.Characteristics & IMAGE_FILE_32BIT_MACHINE) == IMAGE_FILE_32BIT_MACHINE)) {

                    QMessageBox::warning(this, tr("KirbiDSMx64"), tr("This PE is 32 bit, to disasseble it use KirbiDSM."));
                    this->setWindowTitle("KirbiDSMx64");
                    flnm = "";
                }

                else {
                    std::stringstream secstresm;
                    ui->plainTextEdit_4->appendPlainText("-PE32+ (64)\n");
                    sc = pSecHeader;
                    nt = ntHeader;
                    for (int i = 0; i < ntHeader->FileHeader.NumberOfSections; i++) {
                        if ((pSecHeader->VirtualAddress <= ntHeader->OptionalHeader.AddressOfEntryPoint) && (ntHeader->OptionalHeader.AddressOfEntryPoint < (pSecHeader->VirtualAddress + pSecHeader->Misc.VirtualSize))) {

                            oepoffi = (ntHeader->OptionalHeader.AddressOfEntryPoint) - (pSecHeader->VirtualAddress) + (pSecHeader->PointerToRawData);

                            endi = (pSecHeader->PointerToRawData) + (pSecHeader->SizeOfRawData) - oepoffi;

                            break;
                        }

                        pSecHeader++;
                    }
                    pSecHeader = (PIMAGE_SECTION_HEADER)((LONG64)ntHeader + sizeof(IMAGE_NT_HEADERS64));
                    int m;
                    for (pSecHeader = IMAGE_FIRST_SECTION(ntHeader), m = 0; m < ntHeader->FileHeader.NumberOfSections; m++, pSecHeader++) {

                        secstresm << (char*)pSecHeader->Name << "\n";
                    }

                    sections = QString::fromStdString(secstresm.str());
                    pSecHeader = (PIMAGE_SECTION_HEADER)((LONG64)ntHeader + sizeof(IMAGE_NT_HEADERS64));
                    if (oepoffi == 0) {

                        QMessageBox::StandardButton ques;

                        ques = QMessageBox::warning(this, "KirbiDSMx64", "Falied to get EntryPoint offset. Do you want to disassemble the executable section?",
                            QMessageBox::Yes | QMessageBox::No);

                        if (ques == QMessageBox::Yes) {

                            oepoffi = pSecHeader->PointerToRawData;
                            endi = pSecHeader->SizeOfRawData;
                        }
                        else
                            return;
                    }

                    ui->plainTextEdit->clear();
                    //ui->plainTextEdit_2->clear();
                    ui->plainTextEdit_3->clear();
                    ///ui->plainTextEdit_4->clear();
                    char arrdis[1024] = { 0 };
                    std::stringstream disstr;
                    ui->plainTextEdit_4->appendPlainText("-Disassembling bytes...\n");
                    imgbase = (ntHeader->OptionalHeader.ImageBase);
                    QMessageBox::StandardButton s;

                    s = QMessageBox::question(this, "KirbiDSMx64", "Which engine you want to use? [Yes]Distorm, [No]Zydis, [Cancel]Udis86", QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
                    if (s == QMessageBox::Yes) {

                        engine = 1;

                        unsigned long dver = 0;
                        // Holds the result of the decoding.
                        _DecodeResult res;
                        // Decoded instruction information.
                        _DecodedInst decodedInstructions[MAX_INSTRUCTIONS];
                        // next is used for instruction's offset synchronization.
                        // decodedInstructionsCount holds the count of filled instructions' array by the decoder.
                        unsigned int decodedInstructionsCount = 0, i, next;

                        // Default decoding mode is 32 bits, could be set by command line.
                        _DecodeType dt = Decode64Bits;

                        // Default offset for buffer is 0, could be set in command line.
                        _OffsetType offset = 0;
                        char* errch = NULL;

                        // Index to file name in argv.
                        int param = 1;

                        ////ui->plainTextEdit_4->appendPlainText("-Falied to get the OEP offset.\n");

                        // If you get an unresolved external symbol linker error for the following line,
                        // change the SUPPORT_64BIT_OFFSET in distorm.h.
                        res = distorm_decode(offset, (unsigned char*)lpBase + oepoffi, endi, dt, decodedInstructions, MAX_INSTRUCTIONS, &decodedInstructionsCount);
                        if (res > 0) {
                            ui->plainTextEdit_4->appendPlainText("-Disassemblying complete.\n");
                            for (i = 0; i < decodedInstructionsCount; i++) {

                                sprintf(arrdis, " %0*I64x\t(%02d) %-24s\t%s%s%s\n", dt != Decode64Bits ? 8 : 16, decodedInstructions[i].offset, decodedInstructions[i].size, (char*)decodedInstructions[i].instructionHex.p, (char*)decodedInstructions[i].mnemonic.p, decodedInstructions[i].operands.length != 0 ? " " : "", (char*)decodedInstructions[i].operands.p);

                                ///sprintf(arrdis, " %08x\t(%02d) %-24s\t%s%s%s\n", decodedInstructions[i].offset, decodedInstructions[i].size, (char*)decodedInstructions[i].instructionHex.p, (char*)decodedInstructions[i].mnemonic.p, decodedInstructions[i].operands.length != 0 ? " " : "", (char*)decodedInstructions[i].operands.p);
                                disstr << arrdis;
                            }

                            ui->plainTextEdit->appendPlainText(QString::fromStdString(disstr.str()));

                            QScrollBar* vScrollBar = ui->plainTextEdit->verticalScrollBar();

                            //QScrollBar *vScrollBarhex = ui->plainTextEdit_2->verticalScrollBar();
                            vScrollBar->triggerAction(QScrollBar::SliderToMinimum);
                            //pal->triggerAction(QScrollBar::SliderToMinimum);
                            ui->plainTextEdit_3->appendPlainText("RAX = 0000000000000000\n");
                            ui->plainTextEdit_3->appendPlainText("RBX = 0000000000000000\n");
                            ui->plainTextEdit_3->appendPlainText("RCX = 0000000000000000\n");
                            ui->plainTextEdit_3->appendPlainText("RDX = 0000000000000000\n");
                            ui->plainTextEdit_3->appendPlainText("RBP = 0000000000000000\n");
                            ui->plainTextEdit_3->appendPlainText("RSP = 0000000000000000\n");
                            ui->plainTextEdit_3->appendPlainText("RSI = 0000000000000000\n");
                            ui->plainTextEdit_3->appendPlainText("RDI = 0000000000000000\n\n");
                            ui->plainTextEdit_3->appendPlainText("R8 = 0000000000000000\n");
                            ui->plainTextEdit_3->appendPlainText("R9 = 0000000000000000\n");
                            ui->plainTextEdit_3->appendPlainText("R10 = 0000000000000000\n");
                            ui->plainTextEdit_3->appendPlainText("R11 = 0000000000000000\n");
                            ui->plainTextEdit_3->appendPlainText("R12 = 0000000000000000\n");
                            ui->plainTextEdit_3->appendPlainText("R13 = 0000000000000000\n");
                            ui->plainTextEdit_3->appendPlainText("R14 = 0000000000000000\n");
                            ui->plainTextEdit_3->appendPlainText("R15 = 0000000000000000\n");
                            QScrollBar* pal = ui->plainTextEdit_3->verticalScrollBar();
                            pal->triggerAction(QScrollBar::SliderToMinimum);
                            // vScrollBarhex->triggerAction(QScrollBar::SliderToMinimum);
                        }
                        else {

                            ui->plainTextEdit_4->appendPlainText("-Disassemblying bytes FALIED.\n");
                            QMessageBox::critical(this, "KirbiDSMx64", "Couln't disassemble this file sorry.");
                            UnmapViewOfFile(lpBase);
                            CloseHandle(hFile);
                            CloseHandle(hMap);
                            flnm = "";
                        }
                    }

                     if(s == QMessageBox::No){

                        engine = 2;

                        std::stringstream add;
                        Zydis::InstructionInfo info;
                        Zydis::InstructionDecoder decoder;
                        Zydis::IntelInstructionFormatter formatter;
                        Zydis::MemoryInput input64((unsigned char*)lpBase + oepoffi, endi);
                        //Zydis::MemoryInput input64(&data64[0], sizeof(data64));
                        char formt[1024] = { 0 };
                        std::stringstream dis;
                        /*0x00007FFA39A81930ull*/
                        LONG64 entry = ntHeader->OptionalHeader.AddressOfEntryPoint;
                        LONG64 addresses = 0x00007FFA39A;
                        std::stringstream ad;
                        ///uint64_t res;
                        ad << "0x0000" << std::hex << std::uppercase << addresses << entry;
                        std::string hexadec(ad.str());

                        strcpy(formt, (char*)hexadec.c_str());
                        uint64_t formatting = strtoimax(hexadec.c_str(), 0, 16);

                        decoder.setDisassemblerMode(Zydis::DisassemblerMode::M64BIT);
                        decoder.setDataSource(&input64);
                        decoder.setInstructionPointer(formatting);
                        /*info.instrAddress*/
                        while (decoder.decodeInstruction(info)) {
                            dis << std::hex << std::setw(16) << std::setfill('0') << std::uppercase
                                << info.instrAddress << "\t\t\t";
                            if (info.flags & Zydis::IF_ERROR_MASK) {
                                dis << "db " << std::setw(2) << static_cast<int>(info.data[0]) << std::endl;
                            }
                            else {
                                dis << formatter.formatInstruction(info) << std::endl;
                            }
                        }
                        ui->plainTextEdit->appendPlainText(QString::fromStdString(dis.str()));
                        QScrollBar* vScrollBar = ui->plainTextEdit->verticalScrollBar();
                        //QScrollBar *vScrollBarhex = ui->plainTextEdit_2->verticalScrollBar();
                        vScrollBar->triggerAction(QScrollBar::SliderToMinimum);

                        ui->plainTextEdit_3->appendPlainText("RAX = 0000000000000000\n");
                        ui->plainTextEdit_3->appendPlainText("RBX = 0000000000000000\n");
                        ui->plainTextEdit_3->appendPlainText("RCX = 0000000000000000\n");
                        ui->plainTextEdit_3->appendPlainText("RDX = 0000000000000000\n");
                        ui->plainTextEdit_3->appendPlainText("RBP = 0000000000000000\n");
                        ui->plainTextEdit_3->appendPlainText("RSP = 0000000000000000\n");
                        ui->plainTextEdit_3->appendPlainText("RSI = 0000000000000000\n");
                        ui->plainTextEdit_3->appendPlainText("RDI = 0000000000000000\n\n");
                        ui->plainTextEdit_3->appendPlainText("R8 = 0000000000000000\n");
                        ui->plainTextEdit_3->appendPlainText("R9 = 0000000000000000\n");
                        ui->plainTextEdit_3->appendPlainText("R10 = 0000000000000000\n");
                        ui->plainTextEdit_3->appendPlainText("R11 = 0000000000000000\n");
                        ui->plainTextEdit_3->appendPlainText("R12 = 0000000000000000\n");
                        ui->plainTextEdit_3->appendPlainText("R13 = 0000000000000000\n");
                        ui->plainTextEdit_3->appendPlainText("R14 = 0000000000000000\n");
                        ui->plainTextEdit_3->appendPlainText("R15 = 0000000000000000\n");

                        QScrollBar* pal = ui->plainTextEdit_3->verticalScrollBar();
                        pal->triggerAction(QScrollBar::SliderToMinimum);
                    }

                     if(s == QMessageBox::Cancel) {





                          ud_t ud_obj;
                            ud_init(&ud_obj);
                            ud_set_mode(&ud_obj, 64);
                            ud_set_input_buffer(&ud_obj, (unsigned char*)lpBase + oepoffi, endi);
                            ud_set_syntax(&ud_obj, UD_SYN_INTEL);

                            ////printf("==> Without Symbol Resolution\n");


                            /*printf("==> With Symbol Resolution\n");
                            ud_set_pc(&ud_obj, 0);
                            ud_set_input_buffer(&ud_obj, bin, sizeof(bin));
                            ud_set_sym_resolver(&ud_obj, &resolve);
                            dis_loop(&ud_obj);*/


                        ui->plainTextEdit->appendPlainText(dis_loop(&ud_obj));
                        QScrollBar* vScrollBar = ui->plainTextEdit->verticalScrollBar();
                        //QScrollBar *vScrollBarhex = ui->plainTextEdit_2->verticalScrollBar();
                        vScrollBar->triggerAction(QScrollBar::SliderToMinimum);

                        ui->plainTextEdit_3->appendPlainText("RAX = 0000000000000000\n");
                        ui->plainTextEdit_3->appendPlainText("RBX = 0000000000000000\n");
                        ui->plainTextEdit_3->appendPlainText("RCX = 0000000000000000\n");
                        ui->plainTextEdit_3->appendPlainText("RDX = 0000000000000000\n");
                        ui->plainTextEdit_3->appendPlainText("RBP = 0000000000000000\n");
                        ui->plainTextEdit_3->appendPlainText("RSP = 0000000000000000\n");
                        ui->plainTextEdit_3->appendPlainText("RSI = 0000000000000000\n");
                        ui->plainTextEdit_3->appendPlainText("RDI = 0000000000000000\n\n");
                        ui->plainTextEdit_3->appendPlainText("R8 = 0000000000000000\n");
                        ui->plainTextEdit_3->appendPlainText("R9 = 0000000000000000\n");
                        ui->plainTextEdit_3->appendPlainText("R10 = 0000000000000000\n");
                        ui->plainTextEdit_3->appendPlainText("R11 = 0000000000000000\n");
                        ui->plainTextEdit_3->appendPlainText("R12 = 0000000000000000\n");
                        ui->plainTextEdit_3->appendPlainText("R13 = 0000000000000000\n");
                        ui->plainTextEdit_3->appendPlainText("R14 = 0000000000000000\n");
                        ui->plainTextEdit_3->appendPlainText("R15 = 0000000000000000\n");

                        QScrollBar* pal = ui->plainTextEdit_3->verticalScrollBar();
                        pal->triggerAction(QScrollBar::SliderToMinimum);

                     }
                }
            }

        }

        if(event->key() == Qt::Key_F1) {

            QApplication::quit();
        }

        if(keyEvent->key() == Qt::Modifier::ALT || keyEvent->key() == Qt::Key_H || keyEvent->key() == Qt::Key_1) {

            if(flnm == "")
                QMessageBox::critical(this, "KirbiDSMx64", "File not opened.");
            else {





                HexDump1 hex;
                hex.setModal(true);
                hex.gethex(flnm);
                hex.setWindowTitle("HexDump1");


                hex.exec();

            }

        }
        if(keyEvent->key() == Qt::Modifier::ALT || keyEvent->key() == Qt::Key_H || keyEvent->key() == Qt::Key_2) {

            if(flnm == "") {
                QMessageBox::critical(this, "KirbiDSMx64", "File not opened.");
            }
            else {

                HexDumpSecond hexsec;
                hexsec.setModal(true);
                hexsec.filepath(flnm);
                hexsec.setWindowTitle("HexDumpSecond");
                hexsec.exec();
            }

        }
        if(keyEvent->key() == Qt::Modifier::ALT || keyEvent->key() == Qt::Key_H || keyEvent->key() == Qt::Key_3) {

            if(flnm == "") {
                QMessageBox::critical(this, "KirbiDSMx64", "File not opened.");
            }
            else {

                HexDumpThird hexthird;
                hexthird.setModal(true);
                hexthird.getpath(flnm);
                hexthird.setWindowTitle("HexDumpThird");
                hexthird.exec();
            }
        }

        if(keyEvent->key() == Qt::Modifier::ALT || keyEvent->key() == Qt::Key_Z) {

            ui->plainTextEdit->undo();
            ui->plainTextEdit_3->undo();
            ui->plainTextEdit_4->undo();
        }

        if(keyEvent->key() == Qt::Modifier::ALT || keyEvent->key() == Qt::Key_X) {

            ui->plainTextEdit->redo();
            ui->plainTextEdit_3->redo();
            ui->plainTextEdit_4->redo();
        }
        if(keyEvent->key() == Qt::Modifier::ALT || keyEvent->key() == Qt::Key_M) {

            if(flnm == "")
                QMessageBox::critical(this, "KirbiDSMx64", "File not opened.");
            else {


                MemoryMap mem;
                mem.setModal(true);
                mem.dumpmem(flnm);
                mem.setWindowTitle("MemoryMap");


                mem.exec();


            }
        }
        if(keyEvent->key() == Qt::Modifier::ALT || keyEvent->key() == Qt::Key_P) {

            if(flnm == "") {
                QMessageBox::critical(this, "KirbiDSMx64", "File not opened.");
            }
            else {

                ProtectionAnalyzer pro;
                pro.setModal(true);
                pro.getSections(sections);
                pro.setWindowTitle("ProtectionAnalayzer");
                pro.exec();
            }
        }
        if(keyEvent->key() == Qt::Modifier::ALT || keyEvent->key() == Qt::Key_A) {

            if(flnm == "") {



                QMessageBox::StandardButton info;

                info = QMessageBox::question(this, "KirbiDSMx64", "The file is not opened, do you want to open the addressconverter without using the addressconverter?",

                                             QMessageBox::Yes|QMessageBox::No);

                if (info == QMessageBox::Yes) {


                    AddressConverter address;
                    address.setModal(true);
                    address.getloc(flnm);
                    address.setWindowTitle("AddressConverter");
                    address.exec();



                }







            }
            else {


                AddressConverter addressv;
                addressv.setModal(true);
                addressv.getloc(flnm);
                addressv.getimage(imgbase);
                addressv.setWindowTitle("AddressConverter");
                addressv.exec();







            }
        }
        if(keyEvent->key() == Qt::Modifier::ALT || keyEvent->key() == Qt::Key_U) {

            if(flnm == "") {

                QMessageBox::critical(this, "KirbiDSMx64", "File not opened.");
            }
            else {

                std::ifstream pe_file(flnm.toStdString(), std::ios::in | std::ios::binary);

                pe_base image(pe_factory::create_pe(pe_file));

                //Проверим, есть ли импорты у файла
                if(!image.has_imports())
                {

                    QMessageBox::warning(this, "KirbiDSMx64", "This PE has not Imports.");

                }
                else {

                    ImportsTable table;
                    table.setModal(true);
                    table.gthloc(flnm);
                    table.setWindowTitle("Imports");
                    table.exec();
                }


            }

        }
        if(keyEvent->key() == Qt::Modifier::ALT || keyEvent->key() == Qt::Key_E) {

            if(flnm == "") {

                QMessageBox::critical(this, "KirbiDSMx64", "File not opened.");
            }
            else {
                std::ifstream pe_file(flnm.toStdString(), std::ios::in | std::ios::binary);

                pe_base image(pe_factory::create_pe(pe_file));


                if(!image.has_exports())
                {

                    QMessageBox::warning(this, "KirbiDSMx64", "This PE has not Exports.");


                }
                else {

                ExportTable extable;
                extable.setModal(true);
                extable.getex(flnm);
                extable.setWindowTitle("Exports");
                extable.exec();
                }


            }

        }
        if(keyEvent->key() == Qt::Modifier::ALT || keyEvent->key() == Qt::Key_R) {

            if(flnm == "") {

                QMessageBox::critical(this, "KirbiDSMx64", "File not opened.");
            }
            else {

                std::ifstream pe_file(flnm.toStdString(), std::ios::in | std::ios::binary);

                pe_base image(pe_factory::create_pe(pe_file));

                //Проверим, есть ли релокации у файла
                if(!image.has_reloc())
                {
                    QMessageBox::warning(this, "KirbiDSMx64", "This PE has not Relocations");
                }
                else {

                Relocations reloc;
                reloc.setModal(true);
                reloc.reloc(flnm);
                reloc.setWindowTitle("Relocations");
                reloc.exec();
                }
            }

        }
        if(keyEvent->key() == Qt::Modifier::CTRL || keyEvent->key() == Qt::Key_S) {

            if(flnm == "") {

                QMessageBox::critical(this, "KirbiDSMx64", "File not opened.");
            }
            else {

                ///ui->plainTextEdit_4->appendPlainText("Loading Strings...\n");
                Strings strs;
                strs.setModal(true);
                strs.location(flnm);
                strs.setWindowTitle("Strings");
                strs.exec();
                ///ui->plainTextEdit_4->appendPlainText("Strings loaded!\n");

            }

        }
        if(keyEvent->key() == Qt::Modifier::SHIFT || keyEvent->key() == Qt::Key_A) {


            if((ui->plainTextEdit->textCursor().selectedText().length() > 0) && (ui->plainTextEdit->toPlainText().length() > 0)) {
            QClipboard *clipboard = QApplication::clipboard();
            if(engine == 1) {

            std::string address = ui->plainTextEdit->textCursor().selectedText().toStdString();
            address = address.substr(0, 16);
            clipboard->setText(QString::fromStdString(address));
            if(clipboard->text().length() > 0)
                ui->plainTextEdit_4->appendPlainText("VA Copied to clipboard.\n");
          }
            else if(engine == 2) {

                std::string addressva = ui->plainTextEdit->textCursor().selectedText().toStdString();
                addressva = addressva.substr(0, 16);
                clipboard->setText(QString::fromStdString(addressva));
                if(clipboard->text().length() > 0)
                    ui->plainTextEdit_4->appendPlainText("VA Copied to clipboard.\n");

            }
        }


        }
        if(keyEvent->key() == Qt::Modifier::SHIFT || keyEvent->key() == Qt::Key_R) {

            if((ui->plainTextEdit->textCursor().selectedText().length() > 0) && (ui->plainTextEdit->toPlainText().length() > 0)) {
            QClipboard *clipboard = QApplication::clipboard();
            if(engine == 1) {

            std::string address = ui->plainTextEdit->textCursor().selectedText().toStdString();
            std::stringstream en;
            en << std::hex << nt->OptionalHeader.AddressOfEntryPoint;
            size_t length = en.str().size();
            address = address.substr(0, length);
            clipboard->setText(QString::fromStdString(address));

            if(clipboard->text().length() > 0)
                ui->plainTextEdit_4->appendPlainText("RVA Copied to clipboard.\n");
          }
            else if(engine == 2) {

                std::string addressva = ui->plainTextEdit->textCursor().selectedText().toStdString();
                addressva = addressva.substr(11, 5);
                clipboard->setText(QString::fromStdString(addressva));
                if(clipboard->text().length() > 0)
                    ui->plainTextEdit_4->appendPlainText("RVA Copied to clipboard.\n");

            }
          }
        }

        if(keyEvent->key() == Qt::Modifier::SHIFT || keyEvent->key() == Qt::Key_O) {

            if((ui->plainTextEdit->textCursor().selectedText().length() > 0) && (ui->plainTextEdit->toPlainText().length() > 0)) {
            QClipboard *clipboard = QApplication::clipboard();
            std::stringstream out;

            if(engine == 2) {

                std::string address = ui->plainTextEdit->textCursor().selectedText().toStdString();
                address = address.substr(11, 5);

                LONG64 addressoff = strtoimax(address.c_str(), 0, 16);

                LONG64 offs = Rvatooff(addressoff, sc, nt);

                out << std::hex << std::uppercase << offs;
                clipboard->setText(QString::fromStdString(out.str()));
                if(clipboard->text().length() > 0)
                    ui->plainTextEdit_4->appendPlainText("Offset Copied to clipboard.\n");


            }
            else {

                QMessageBox::warning(this, "KirbiDSMx64", "Couldn't copy File offset in Distorm engine.");
            }

            }

        }

        if(keyEvent->key() == Qt::Modifier::SHIFT || keyEvent->key() == Qt::Key_S) {


            if((ui->plainTextEdit->textCursor().selectedText().length() > 0) && (ui->plainTextEdit->toPlainText().length() > 0)) {
            QClipboard *clipboard = QApplication::clipboard();
            clipboard->setText(ui->plainTextEdit->textCursor().selectedText());
            if(clipboard->text().length() > 0)
                ui->plainTextEdit_4->appendPlainText("Selected lines Copied to clipboard.\n");

            }

        }
        if(keyEvent->key() == Qt::Modifier::SHIFT || keyEvent->key() == Qt::Modifier::ALT || keyEvent->key() == Qt::Key_E) {

            Settings sts;
            sts.setModal(true);
            sts.setWindowTitle("Settings");
            sts.exec();

        }
        if(keyEvent->key() == Qt::Modifier::SHIFT || keyEvent->key() == Qt::Modifier::ALT || keyEvent->key() == Qt::Key_A) {

            if(flnm == "") {

                QMessageBox::critical(this, "KirbiDSMx64", "File not opened.");
            }
            else {

                SectionsAdder sects;
                sects.setModal(true);
                sects.getterg(flnm);
                sects.setWindowTitle("Add section");
                sects.exec();
            }
        }
        if(keyEvent->key() == Qt::Modifier::SHIFT || keyEvent->key() == Qt::Modifier::ALT || keyEvent->key() == Qt::Key_I) {

            if(flnm == "") {

                QMessageBox::critical(this, "KirbiDSMx64", "File not opened.");
            }
            else {

                ImportAdder impa;
                impa.setModal(true);
                impa.datetarg(flnm);
                impa.setWindowTitle("ImportAdder");
                impa.exec();
            }
        }
        if(keyEvent->key() == Qt::Modifier::SHIFT || keyEvent->key() == Qt::Modifier::ALT || keyEvent->key() == Qt::Key_T) {

            if(flnm == "") {

                QMessageBox::critical(this, "KirbiDSMx64", "File not opened.");
            }
            else {

                RelocationAdder rlcadd;
                rlcadd.setModal(true);
                rlcadd.opn(flnm);
                rlcadd.setWindowTitle("RelocationAdder");
                rlcadd.exec();
            }

        }
        if(keyEvent->key() == Qt::Key_F2) {

            qApp->quit();
            QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
        }
        if(keyEvent->key() == Qt::Key_F3) {

            ui->plainTextEdit->clear();
            ui->plainTextEdit_3->clear();
            flnm = "";
        }
    }


}



/*void MainHome::gotoaddress(LONG64 addr, LONG64 endt, int enginead)
{


}*/





void MainHome::on_actionExpression_triggered()
{
    if(flnm == "") {

        QMessageBox::critical(this, "KirbiDSMx64", "File not opened.");
    }
    else {

        Expression *exp = new Expression();
        exp->setModal(true);
        exp->location(flnm, this->ui->plainTextEdit->toPlainText(), this->ui->plainTextEdit_4->toPlainText(), this->ui->plainTextEdit_3->toPlainText());
        exp->setWindowTitle("Expression");
        this->hide();
        exp->show();

    }

}

void MainHome::on_actionUndo_triggered()
{
    ui->plainTextEdit->undo();
    ui->plainTextEdit_3->undo();
    ui->plainTextEdit_4->undo();
}

void MainHome::on_actionRedo_triggered()
{
    ui->plainTextEdit->redo();
    ui->plainTextEdit_3->redo();
    ui->plainTextEdit_4->redo();
}

void MainHome::on_actionBinary_triggered()
{

}

void MainHome::on_actionSettings_triggered()
{
    Settings sts;
    sts.setModal(true);
    sts.setWindowTitle("Settings");
    sts.exec();
}

void MainHome::on_actionSection_adder_triggered()
{
    if(flnm == "") {

        QMessageBox::critical(this, "KirbiDSMx64", "File not opened.");
    }
    else {

        SectionsAdder sects;
        sects.setModal(true);
        sects.getterg(flnm);
        sects.setWindowTitle("Add section");
        sects.exec();
    }
}

void MainHome::on_actionImport_adder_triggered()
{
    if(flnm == "") {

        QMessageBox::critical(this, "KirbiDSMx64", "File not opened.");
    }
    else {

        ImportAdder impa;
        impa.setModal(true);
        impa.datetarg(flnm);
        impa.setWindowTitle("ImportAdder");
        impa.exec();
    }
}

void MainHome::on_actionRelocation_adder_triggered()
{
    if(flnm == "") {

        QMessageBox::critical(this, "KirbiDSMx64", "File not opened.");
    }
    else {

        RelocationAdder rlcadd;
        rlcadd.setModal(true);
        rlcadd.opn(flnm);
        rlcadd.setWindowTitle("RelocationAdder");
        rlcadd.exec();
    }
}

void MainHome::on_actionDisassemble_a_section_triggered()
{
    if(flnm == "") {

        QMessageBox::critical(this, "KirbiDSMx64", "File not opened.");
    }
    else {

        SelectSection slcsc;
        slcsc.setModal(true);
        slcsc.pth(flnm, engine, ui->plainTextEdit_4->toPlainText(), ui->plainTextEdit_3->toPlainText(), ui->plainTextEdit->toPlainText());
        slcsc.setWindowTitle("SelectSection");
        this->hide();
        slcsc.exec();

    }
}

void MainHome::on_actionDump_1_Complete_triggered()
{
    if (flnm == "") {

        QMessageBox::StandardButton question;

        question = QMessageBox::question(this, "KirbiDSMx64", "File is not opened, do you want to open it?", QMessageBox::Yes | QMessageBox::No);

        if (question == QMessageBox::Yes) {

            QString pathprov = QFileDialog::getOpenFileName(this, tr("Open your exe!"), "c:\\",
                tr("Executable files (*.exe *.ax *.cpl *.dll *.drv *.efi *.mui *.ocx *.scr *.sys *.tsp)"));

            if(pathprov == "") {

                return;
            }

            Sleep(2000);

            QString savefl = QFileDialog::getSaveFileName(this, "Save Hex Dump", "", ".txt");

            if(savefl == "") {

                return;
            }

            FILE* savehex = fopen(savefl.toStdString().c_str(), "w");

            std::string directory = pathprov.toStdString();

            FILE* f;
            unsigned char c[10];
            BYTE* filebuff;

            char dump[1024] = { 0 };
            std::stringstream dats;
            f = fopen(directory.c_str(), "rb");
            if (f > 0) {
                ////fseek(f, 0, SEEK_SET);

                long fsize = getFileSizemain(f);
                filebuff = new BYTE[fsize];

                char* provvio = new char;
                //lsize = ftell(f);
                rewind(f);
                std::string lngthdmp;
                int bytesread = 0;
                long ret = 0;

                fread(filebuff, fsize, 1, f);
                for (int i = 0; i < fsize; i++) {

                    fprintf(savehex, "%02x ", filebuff[i]);
                }

                fclose(f);
                fclose(savehex);
                flnm = "";
                QMessageBox::information(this, "KirbiDSMx64", "Hex Dump successfully saved.");
            }
        }
    }
    else {

        QString savefl = QFileDialog::getSaveFileName(this, "Save Hex Dump", "", ".txt");

        if(savefl == "") {

            return;
        }
        FILE* savehex = fopen(savefl.toStdString().c_str(), "w");

        std::string directory = flnm.toStdString();

        FILE* f;
        unsigned char c[10];
        BYTE* filebuff;

        char dump[1024] = { 0 };
        std::stringstream dats;
        f = fopen(directory.c_str(), "rb");
        if (f > 0) {
            ////fseek(f, 0, SEEK_SET);

            long fsize = getFileSizemain(f);
            filebuff = new BYTE[fsize];

            char* provvio = new char;
            //lsize = ftell(f);
            rewind(f);
            std::string lngthdmp;
            int bytesread = 0;
            long ret = 0;

            fread(filebuff, fsize, 1, f);
            for (int i = 0; i < fsize; i++) {

                fprintf(savehex, "%02x ", filebuff[i]);
            }
            fclose(savehex);
            fclose(f);

            QMessageBox::information(this, "KirbiDSMx64", "Hex Dump successfully saved.");
        }
    }
}

void MainHome::on_actionDump_2_Complete_triggered()
{
    if (flnm == "") {

        QMessageBox::StandardButton question;

        question = QMessageBox::question(this, "KirbiDSMx64", "File is not opened, do you want to open it?", QMessageBox::Yes | QMessageBox::No);

        if (question == QMessageBox::Yes) {

            QString pathprov = QFileDialog::getOpenFileName(this, tr("Open your exe!"), "c:\\",
                tr("Executable files (*.exe *.ax *.cpl *.dll *.drv *.efi *.mui *.ocx *.scr *.sys *.tsp)"));

            if(pathprov == "") {

                return;
            }

            Sleep(2000);

            QString savefl = QFileDialog::getSaveFileName(this, "Save Hex Dump", "", ".txt");

            if(savefl == "") {

                return;
            }
            FILE *sv = fopen(savefl.toStdString().c_str(), "w");

            int c = ' ';
            char * hex_offset;

            std::stringstream hexdmp;
            char * ascii_offset;

            char line[81];

            std::string flm = pathprov.toStdString();
            int i;

            FILE* fp = fopen(flm.c_str(), "rb");
            if (fp > 0) {

                while (c != EOF)
                {
                    clear_lined(line, sizeof line);
                    hex_offset = line + HEX_OFFSET;
                    ascii_offset = line + ASCII_OFFSET;
                    while (ascii_offset < line + ASCII_OFFSET + NUM_CHARS
                        && (c = fgetc(fp)) != EOF) {
                        hex_offset = hexd(hex_offset, c);

                        /* Build the Ascii part of
                        * the line.      */
                        ascii_offset = asciid(ascii_offset, c);

                    }
                    ///printf(" %02x", line);
                    fprintf(sv, " %s\n", line);

                }




            }

            fclose(fp);
            fclose(sv);
            QMessageBox::information(this, "KirbiDSMx64", "Hex Dump successfully saved.");











        }
    }
    else {


        QString savefl = QFileDialog::getSaveFileName(this, "Save Hex Dump", "", ".txt");

        if(savefl == "") {

            return;
        }
        FILE *sv = fopen(savefl.toStdString().c_str(), "w");

        int c = ' ';
        char * hex_offset;

        std::stringstream hexdmp;
        char * ascii_offset;

        char line[81];

        std::string flm = flnm.toStdString();
        int i;

        FILE* fp = fopen(flm.c_str(), "rb");
        if (fp > 0) {

            while (c != EOF)
            {
                clear_lined(line, sizeof line);
                hex_offset = line + HEX_OFFSET;
                ascii_offset = line + ASCII_OFFSET;
                while (ascii_offset < line + ASCII_OFFSET + NUM_CHARS
                    && (c = fgetc(fp)) != EOF) {
                    hex_offset = hexd(hex_offset, c);

                    /* Build the Ascii part of
                    * the line.      */
                    ascii_offset = asciid(ascii_offset, c);

                }
                ///printf(" %02x", line);
                fprintf(sv, " %s\n", line);

            }




        }

        fclose(fp);
        fclose(sv);
        QMessageBox::information(this, "KirbiDSMx64", "Hex Dump successfully saved.");


    }
}


void MainHome::on_actionDump_3_Complete_2_triggered()
{
    if (flnm == "") {

        QMessageBox::StandardButton question;

        question = QMessageBox::question(this, "KirbiDSMx64", "File is not opened, do you want to open it?", QMessageBox::Yes | QMessageBox::No);

        if (question == QMessageBox::Yes) {

            QString pathprov = QFileDialog::getOpenFileName(this, tr("Open your exe!"), "c:\\",
                tr("Executable files (*.exe *.ax *.cpl *.dll *.drv *.efi *.mui *.ocx *.scr *.sys *.tsp)"));

            if(pathprov == "") {

                return;
            }

            Sleep(2000);

            QString savefl = QFileDialog::getSaveFileName(this, "Save Hex Dump", "", ".txt");
            if(savefl == "") {

                return;
            }
            FILE *sv = fopen(savefl.toStdString().c_str(), "w");

            fprintf(sv, "%s\n", (char*)hexdumpm(pathprov.toStdString().c_str()).c_str());
            fclose(sv);
            QMessageBox::information(this, "KirbiDSMx64", "Hex Dump successfully saved.");

        }
    }
    else {



        QString savefl = QFileDialog::getSaveFileName(this, "Save Hex Dump", "", ".txt");
        if(savefl == "") {

            return;
        }
        FILE *sv = fopen(savefl.toStdString().c_str(), "w");

        fprintf(sv, "%s\n", (char*)hexdumpm(flnm.toStdString().c_str()).c_str());
        fclose(sv);
        QMessageBox::information(this, "KirbiDSMx64", "Hex Dump successfully saved.");


    }
}

void MainHome::on_actionSave_disassembly_triggered()
{
    if (flnm.length() > 0) {



            QString savefl = QFileDialog::getSaveFileName(this, "Save Disassembly", "", ".txt");

            if(savefl == "") {

                return;
            }
            FILE *sv = fopen(savefl.toStdString().c_str(), "w");
            fprintf(sv, "%s\n", (char*)this->ui->plainTextEdit->toPlainText().toStdString().c_str());
            fclose(sv);
            QMessageBox::information(this, "KirbiDSMx64", "Disassembly successfully saved.");



    }
    else {

        QMessageBox::critical(this, "KirbiDSMx64", "First open a file.");
    }
}

void MainHome::on_actionSave_memory_map_triggered()
{
    if (flnm == "") {

        QMessageBox::StandardButton question;

        question = QMessageBox::question(this, "KirbiDSMx64", "File is not opened, do you want to open it?", QMessageBox::Yes | QMessageBox::No);

        if (question == QMessageBox::Yes) {

            QString pathprov = QFileDialog::getOpenFileName(this, tr("Open your exe!"), "c:\\",
                tr("Executable files (*.exe *.ax *.cpl *.dll *.drv *.efi *.mui *.ocx *.scr *.sys *.tsp)"));

            if(pathprov == "") {

                return;
            }

            Sleep(2000);

            QString savefl = QFileDialog::getSaveFileName(this, "Save Memory map", "", ".txt");

            if(savefl == "") {

                return;
            }
            FILE *sv = fopen(savefl.toStdString().c_str(), "w");

            ///std::string pthf = dir.toStdString();
                int i = 0;
                HANDLE hMapObject, hFile;                        //File Mapping Object
                LPVOID lpBase;                                          //Pointer to the base memory of mapped file
                PIMAGE_DOS_HEADER dosHeader;            //Pointer to DOS Header
                PIMAGE_NT_HEADERS64 ntHeader;                     //Pointer to NT Header
                IMAGE_FILE_HEADER header;                       //Pointer to image file header of NT Header
                IMAGE_OPTIONAL_HEADER opHeader;         //Optional Header of PE files present in NT Header structure
                PIMAGE_SECTION_HEADER pSecHeader;
                 ///std::string pthf = path.toStdString();


                hFile = CreateFileA((char*)pathprov.toStdString().c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
                HANDLE hMap = CreateFileMapping(hFile, 0, PAGE_READONLY, 0, 0, 0);
                lpBase = MapViewOfFile(hMap, FILE_MAP_READ, 0, 0, 0);
                dosHeader = (PIMAGE_DOS_HEADER)lpBase;
                ntHeader = (PIMAGE_NT_HEADERS64)((LONG64)(dosHeader)+(dosHeader->e_lfanew));
                char filesize[1024] = { 0 };
                char datalength[1024] = { 0 };
                struct stat info;
                char *filename = (char*)pathprov.toStdString().c_str();
                if (stat(filename, &info) != 0) {
                    /* error handling*/
                }
                sprintf(filesize, "FILE SIZE: %lu\n", (unsigned long)info.st_size);

                char *content = (char*)malloc(info.st_size);
                if (content == NULL) {
                    /* error handling */
                }
                FILE *fp = fopen(filename, "rb");
                if (fp == NULL) {
                    /* error handling */
                }
                /* Try to read a single block of info.st_size bytes */
                size_t blocks_read = fread(content, info.st_size, 1, fp);
                if (blocks_read != 1) {
                    /* error handling */
                }
                ///fclose(fp);

                /*
                * If nothing went wrong, content now contains the
                * data read from the file.
                */

                sprintf(datalength, "DATA LENGTH: %lu\n", (unsigned long)info.st_size);

                char mine[1024] = { 0 };
                char OEP[1024] = { 0 };
                char mio[1024] = { 0 };
                //char yno[1024] = { 0 };
                char bhj[1024] = { 0 };
                char sec[1024] = { 0 };
                char secnumber[1024] = { 0 };
                char test[1024] = { 0 };
                char virsize[1024] = { 0 };
                char viraddress[1024] = { 0 };
                char sizeofraw[1024] = { 0 };
                char pofrawdata[1024] = { 0 };
                char ptoreloc[1024] = { 0 };
                char ptolinenumbers[1024] = { 0 };
                char nofreloc[1024] = { 0 };
                char noflinenumbers[1024] = { 0 };
                char vaaddva[1024] = { 0 };
                char oepva[1024] = { 0 };
                char oepoffset[1024] = { 0 };
                char Vaoffset[1024] = { 0 };
                char symbols[1024] = { 0 };
                char opsize[1024] = { 0 };
                char imagbs[1024] = { 0 };
                char uigraphic[1024] = { 0 };
                char typearch[1024] = { 0 };
                char szofcode[1024] = { 0 };
                char basecode[1024] = { 0 };
                char indata[1024] = { 0 };
                char basedata[1024] = { 0 };
                char sctallignment[1024] = { 0 };
                char minor[1024] = { 0 };
                char major[1024] = { 0 };
                char magicsign[1024] = { 0 };
                char bytes[1024] = { 0 };
                char pagefiles[1024] = { 0 };
                char reloc[1024] = { 0 };
                char sizeofheaderinp[1024] = { 0 };
                char miniextrapd[1024] = { 0 };
                char maxextrapn[1024] = { 0 };
                char inrlssval[1024] = { 0 };
                char initspval[1024] = { 0 };
                char checksum[1024] = { 0 };
                char initialipval[1024] = { 0 };
                char initialrlcsval[1024] = { 0 };
                char fileaddressrelctable[1024] = { 0 };
                char Overlaynumb[1024] = { 0 };
                char OEMID[1024] = { 0 };
                char oemide_mid[1024] = { 0 };
                char RVAAddressofpeheader[1024] = { 0 };
                char themachinearch[1024] = { 0 };
                //char timedatestamp[1024] = { 0 };
                char sgnhex[1024] = { 0 };
                char a[1024] = { 0 };
                char s[1024] = { 0 };
                char charcex[1024] = {0};
                /*char sizeofraw[1024] = { 0 };
                char sizeofraw[1024] = { 0 };*/
                //unsigned int hg;
                sprintf(OEP, "0x%x", ntHeader->OptionalHeader.AddressOfEntryPoint);
                pSecHeader = (PIMAGE_SECTION_HEADER)((LONG64)ntHeader + sizeof(IMAGE_NT_HEADERS64));


                sprintf(bhj, "%s", pSecHeader->Name);
                sprintf(sgnhex, "0x%x", dosHeader->e_magic);
                time_t creationTime = ntHeader->FileHeader.TimeDateStamp;

                tm* Time = localtime(&creationTime);
                strftime(s, sizeof(s), "%a %Y-%m-%d %H:%M:%S %Z", Time);
                sprintf(a, "%s", s);



                if (dosHeader->e_magic == IMAGE_DOS_SIGNATURE) {
                    //Dump the Dos Header info
                    sprintf(magicsign, "\n%-36s%s ", "Magic number : ", dosHeader->e_magic == 0x5a4d ? "MZ (detected)" : "-");
                    sprintf(bytes, "\n%-36s%#x", "Bytes on last page of file :", dosHeader->e_cblp);
                    sprintf(pagefiles, "\n%-36s%#x", "Pages in file : ", dosHeader->e_cp);
                    sprintf(reloc, "\n%-36s%#x", "Relocation : ", dosHeader->e_crlc);
                    sprintf(sizeofheaderinp, "\n%-36s%#x", "Size of header in paragraphs : ", dosHeader->e_cparhdr);
                    sprintf(miniextrapd, "\n%-36s%#x", "Minimum extra paragraphs needed : ", dosHeader->e_minalloc);
                    sprintf(maxextrapn, "\n%-36s%#x", "Maximum extra paragraphs needed : ", dosHeader->e_maxalloc);
                    sprintf(inrlssval, "\n%-36s%#x", "Initial (relative) SS value : ", dosHeader->e_ss);
                    sprintf(initspval, "\n%-36s%#x", "Initial SP value : ", dosHeader->e_sp);
                    sprintf(checksum, "\n%-36s%#x", "Checksum : ", dosHeader->e_csum);
                    sprintf(initialipval, "\n%-36s%#x", "Initial IP value : ", dosHeader->e_ip);
                    sprintf(initialrlcsval, "\n%-36s%#x", "Initial (relative) CS value : ", dosHeader->e_cs);
                    sprintf(fileaddressrelctable, "\n%-36s%#x", "File address of relocation table : ", dosHeader->e_lfarlc);
                    sprintf(Overlaynumb, "\n%-36s%#x", "Overlay number : ", dosHeader->e_ovno);
                    sprintf(OEMID, "\n%-36s%#x", "OEM identifier : ", dosHeader->e_oemid);
                    sprintf(oemide_mid, "\n%-36s%#x", "OEM information(e_oemid specific) :", dosHeader->e_oeminfo);
                    sprintf(RVAAddressofpeheader, "\n%-36s%#x", "RVA address of PE header : ", dosHeader->e_lfanew);

                }
                else {
                    ///MessageBox::Show("Dos header not valid.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
                    QMessageBox::critical(this, "KirbiDSMx64", "Invalid DosHeader.");
                    this->close();


                    //goto end;
                }


                switch (ntHeader->FileHeader.Machine) { //Only few are determined (for remaining refer to the above specification)
                case 0x0:        sprintf(themachinearch, "All "); break;
                case 0x14d:  sprintf(themachinearch, "Intel i860"); break;
                case 0x14c:  sprintf(themachinearch, "Intel i386,i486,i586"); break;
                case 0x200:  sprintf(themachinearch, "Intel Itanium processor"); break;
                case 0x8664: sprintf(themachinearch, "AMD x64"); break;
                case 0x162:  sprintf(themachinearch, "MIPS R3000"); break;
                case 0x166:  sprintf(themachinearch, "MIPS R4000"); break;
                case 0x183:  sprintf(themachinearch, "DEC Alpha AXP"); break;
                default:         sprintf(themachinearch, "It seems not found"); break;
                }




                std::stringstream sectstream;
                std::stringstream buffinf;

            ///			std::stringstream test;

                sectstream << "Address                     Raw Size                     Raw Address                                 Name                                 Contains" << "\n\n";
                sectstream << "------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
                for (i = 0; i < ntHeader->FileHeader.NumberOfSections;i++, pSecHeader++)
                {





                   /// if ((pSecHeader->Characteristics & IMAGE_SCN_MEM_READ) == IMAGE_SCN_MEM_READ)
                    ///sprintf(charcex,"can be read.\n");
                    ///if ((pSecHeader->Characteristics & IMAGE_SCN_MEM_WRITE) == IMAGE_SCN_MEM_WRITE)
                    //sprintf(charcex,"can be written to.\n");
                    DWORD vava = (pSecHeader->VirtualAddress) + (ntHeader->OptionalHeader.ImageBase);
                    //	sprintf(yno, "\n\nSection Info (%d of %d)", i + 1, ntHeader->FileHeader.NumberOfSections);
                    DWORD vaoepva = (pSecHeader->VirtualAddress) + (pSecHeader->PointerToRawData) - (pSecHeader->VirtualAddress);
                    DWORD RVARAWADD = (pSecHeader->VirtualAddress);
                    //strcat(sec, (char*)pSecHeader->Name);

                    sectstream  << " " << "0x" << std::hex << pSecHeader->VirtualAddress << " ------------------->   " << "0x" << std::hex << pSecHeader->SizeOfRawData << " ------------------->   " << "0x" << std::hex << pSecHeader->PointerToRawData << " ------------------->   "  << (char*)pSecHeader->Name;
                    ///test << pSecHeader->Name << std::endl;
                    sectstream<< " ------------------->   ";
                    if((pSecHeader->Characteristics & IMAGE_SCN_CNT_CODE) == IMAGE_SCN_CNT_CODE) {

                        sectstream << "executable code ";
                    }

                    if((pSecHeader->Characteristics & IMAGE_SCN_CNT_INITIALIZED_DATA) == IMAGE_SCN_CNT_INITIALIZED_DATA) {

                        sectstream << "initialized data ";
                    }

                    if((pSecHeader->Characteristics & IMAGE_SCN_CNT_UNINITIALIZED_DATA) == IMAGE_SCN_CNT_UNINITIALIZED_DATA) {

                        sectstream << "uninitialized data ";
                    }

                    if((pSecHeader->Characteristics & IMAGE_SCN_LNK_INFO) == IMAGE_SCN_LNK_INFO) {

                        sectstream << "comments or other information ";
                    }


                    sectstream << "\n";

                    buffinf << "Section: " << (char*)pSecHeader->Name << "\n";
                    sprintf(virsize, "\n%-36s%#x", "Size of code or data:", pSecHeader->Misc.VirtualSize);
                    buffinf << virsize << "\n";
                    sprintf(viraddress, "\n%-36s%#x", "(RVA)Virtual Address :", pSecHeader->VirtualAddress);
                    buffinf << viraddress << "\n";
                    //////printf("\n%-36s%#x", "Virtual Address(RVA) :", pSecHeader->VirtualAddress);
                    sprintf(sizeofraw, "\n%-36s%#x", "Size of raw data (rounded to FA) : ", pSecHeader->SizeOfRawData);
                    buffinf << sizeofraw << "\n";
                    sprintf(pofrawdata, "\n%-36s%#x", "Pointer to Raw Data : ", pSecHeader->PointerToRawData);
                    buffinf << pofrawdata << "\n";
                    sprintf(ptoreloc, "\n%-36s%#x", "Pointer to Relocations : ", pSecHeader->PointerToRelocations);
                    buffinf << ptoreloc << "\n";
                    sprintf(ptolinenumbers, "\n%-36s%#x", "Pointer to Line numbers : ", pSecHeader->PointerToLinenumbers);
                    buffinf << ptolinenumbers << "\n";
                    sprintf(nofreloc, "\n%-36s%#x", "Number of relocations : ", pSecHeader->NumberOfRelocations);
                    buffinf << nofreloc << "\n";
                    sprintf(noflinenumbers, "\n%-36s%#x", "Number of line numbers : ", pSecHeader->NumberOfLinenumbers);
                    buffinf << noflinenumbers << "\n\n";
                    sprintf(mine, "(%d of %d)", i + 1, ntHeader->FileHeader.NumberOfSections);
                    sprintf(vaaddva, "0x%x", vava);
                    sprintf(Vaoffset, "0x%x", vaoepva);


                    //System::String ^othersections = gcnew String(sec);
                    ///sprintf(mine, "%s", pSecHeader->Name);
                //	richTextBox1->Text = othersections;
                    //richTextBox1->Text += Environment::NewLine;
                    //richTextBox1->Text += othenomi;

                }


                /*for (int i = 1; i < ntHeader->FileHeader.NumberOfSections; i++)
                {


                    pSecHeader = (PIMAGE_SECTION_HEADER)((DWORD)pSecHeader + sizeof(IMAGE_SECTION_HEADER));

                    DWORD testva = (pSecHeader[i].VirtualAddress);
                    sprintf(sec, "%s", testva);
                }*/

                ////header = ntHeader->FileHeader;
                pSecHeader = (PIMAGE_SECTION_HEADER)((LONG64)ntHeader + sizeof(IMAGE_NT_HEADERS64));

                char *secoep = Oepnamesecc(ntHeader->OptionalHeader.AddressOfEntryPoint, pSecHeader, ntHeader);
                LONG64 Realoepoff = Rvatooff(ntHeader->OptionalHeader.AddressOfEntryPoint, pSecHeader, ntHeader);

                DWORD variable = (pSecHeader->VirtualAddress);
                ///hg = ntHeader->FileHeader.NumberOfSections;
                LONG64 imagem = (ntHeader->OptionalHeader.ImageBase);

                ///DWORD offset = (ntHeader->OptionalHeader.AddressOfEntryPoint) - variable + (pSecHeader->PointerToRawData);
                ///DWORD retAddr = (ntHeader->OptionalHeader.AddressOfEntryPoint) - (pSecHeader->VirtualAddress) + (pSecHeader->PointerToRawData);
                ////DWORD vaoep = offset - (pSecHeader->PointerToRawData) + (pSecHeader->VirtualAddress) + (ntHeader->OptionalHeader.ImageBase);
                DWORD vaoep = (ntHeader->OptionalHeader.AddressOfEntryPoint) + (ntHeader->OptionalHeader.ImageBase);
                DWORD off = vaoep - (ntHeader->OptionalHeader.ImageBase) - (pSecHeader->VirtualAddress) + (pSecHeader->PointerToRawData);
                DWORD RVAOEP = vaoep - (ntHeader->OptionalHeader.ImageBase);
                DWORD check = (ntHeader->OptionalHeader.AddressOfEntryPoint) - (pSecHeader->VirtualAddress) + (pSecHeader->PointerToRawData);

                sprintf(oepva, "0x%x", vaoep);
                sprintf(oepoffset, "0x%x", off);
                sprintf(symbols, "\n%-36s%d", "No.entries in symbol table :", ntHeader->FileHeader.NumberOfSymbols);
                sprintf(opsize, "\n%-36s%d", "Size of optional header :", ntHeader->FileHeader.SizeOfOptionalHeader);
                sprintf(imagbs, "\n%-36s%#x", "ImageBase : ", imagem);
                sprintf(uigraphic, "\n%-36s%s", "SubSystem type (UI) : ",
                    ntHeader->OptionalHeader.Subsystem == 1 ? "Device Driver(Native windows Process)" :
                    ntHeader->OptionalHeader.Subsystem == 2 ? "Windows GUI" :
                    ntHeader->OptionalHeader.Subsystem == 3 ? "Windows CLI" :
                    ntHeader->OptionalHeader.Subsystem == 9 ? "Windows CE GUI" :
                    "Unknown");
                sprintf(typearch, "\n%-36s%s", "Type : ", ntHeader->OptionalHeader.Magic == 0x20b ? "PE32+(64)" : "PE32");
                sprintf(szofcode, "\n%-36s%d", "Size of code segment(.text) : ", ntHeader->OptionalHeader.SizeOfCode);
                sprintf(basecode, "\n%-36s%#x", "(RVA)Base address of code segment :", ntHeader->OptionalHeader.BaseOfCode);
                sprintf(indata, "\n%-36s%d", "Size of Initialized data : ", ntHeader->OptionalHeader.SizeOfInitializedData);
                ////sprintf(basedata, "\n%-36s%#x", "(RVA)Base address of data segment :", ntHeader->OptionalHeader.BaseOfData);
                sprintf(sctallignment, "\n%-36s%#x", "Section Alignment :", ntHeader->OptionalHeader.SectionAlignment);
                sprintf(major, "\n%-36s%d", "Major Linker Version : ", ntHeader->OptionalHeader.MajorLinkerVersion);
                sprintf(minor, "\n%-36s%d", "Minor Linker Version : ", ntHeader->OptionalHeader.MinorLinkerVersion);


                std::stringstream infos;
                std::string sections = sectstream.str();
                std::string ssectin = buffinf.str();

                infos << "                                            Sections:                 " << "\n\n\n";

                infos << sections << "\n";
                infos << filesize << "\n";
                infos << datalength << "\n\n\n";
                infos << "                                            DosHeader:       " << "\n\n";
                infos << magicsign << " " << "in Hex " << sgnhex << "\n";

                infos << bytes << "\n";
                infos << pagefiles << "\n";
                infos << reloc << "\n";
                infos << sizeofheaderinp << "\n\n";
                infos << miniextrapd << "\n";
                infos << maxextrapn << "\n";
                infos << inrlssval << std::endl;
                infos << initspval << "\n";
                infos << checksum << "\n";
                infos << initialipval << "\n";
                infos << initialrlcsval << "\n";
                infos << fileaddressrelctable << "\n";
                infos << Overlaynumb << "\n";
                infos << OEMID << "\n";
                infos << oemide_mid << "\n";
                infos << RVAAddressofpeheader << "\n\n\n";

                infos << "------------------------------" << "\n\n";
                infos << "                                            FileHeader:       " << "\n\n\n";
                infos << themachinearch << "\n\n";
                infos << "TimeDateStamp: " << a << "\n\n\n";
                infos << "------------------------------" << "\n\n";
                infos << "                                            General info:       " << "\n\n\n";
                infos << "NumberOfSections: " << mine << "\n";
                infos << opsize << "\n";
                infos << symbols << "\n";
                infos << typearch << "\n\n\n";
                infos << "------------------------------" << "\n\n";
                infos << "                                            Optional Header:       " << "\n\n\n";
                infos << "AddressOfEntryPoint: " << OEP << " VA " << oepva << " Offset " << "0x" << std::hex << Realoepoff << " (In " << secoep << ")" << "\n";
                infos << imagbs << "\n";
                infos << uigraphic << "\n";
                infos << szofcode << "\n";
                infos << basecode << "\n";
                infos << basedata << "\n";
                infos << sctallignment << "\n";
                infos << major << "\n";
                infos << minor << "\n\n\n";
                infos << "-----------------------------" << "\n\n";
                infos << "                                  Sections (details):      " << "\n\n\n";
                infos << ssectin << "\n";


                fprintf(sv, "%s\n", (char*)infos.str().c_str());
                ///fclose(sv);
                QMessageBox::information(this, "KirbiDSMx64", "Memory map successfully saved.");

        }
    }
    else {

        QString savefl = QFileDialog::getSaveFileName(this, "Save Memory map", "", ".txt");

        if(savefl == "") {

            return;
        }
        FILE *sv = fopen(savefl.toStdString().c_str(), "w");

        ///std::string pthf = dir.toStdString();
            int i = 0;
            HANDLE hMapObject, hFile;                        //File Mapping Object
            LPVOID lpBase;                                          //Pointer to the base memory of mapped file
            PIMAGE_DOS_HEADER dosHeader;            //Pointer to DOS Header
            PIMAGE_NT_HEADERS64 ntHeader;                     //Pointer to NT Header
            IMAGE_FILE_HEADER header;                       //Pointer to image file header of NT Header
            IMAGE_OPTIONAL_HEADER opHeader;         //Optional Header of PE files present in NT Header structure
            PIMAGE_SECTION_HEADER pSecHeader;
             ///std::string pthf = path.toStdString();


            hFile = CreateFileA((char*)flnm.toStdString().c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
            HANDLE hMap = CreateFileMapping(hFile, 0, PAGE_READONLY, 0, 0, 0);
            lpBase = MapViewOfFile(hMap, FILE_MAP_READ, 0, 0, 0);
            dosHeader = (PIMAGE_DOS_HEADER)lpBase;
            ntHeader = (PIMAGE_NT_HEADERS64)((LONG64)(dosHeader)+(dosHeader->e_lfanew));
            char filesize[1024] = { 0 };
            char datalength[1024] = { 0 };
            struct stat info;
            char *filename = (char*)flnm.toStdString().c_str();
            if (stat(filename, &info) != 0) {
                /* error handling*/
            }
            sprintf(filesize, "FILE SIZE: %lu\n", (unsigned long)info.st_size);

            char *content = (char*)malloc(info.st_size);
            if (content == NULL) {
                /* error handling */
            }
            FILE *fp = fopen(filename, "rb");
            if (fp == NULL) {
                /* error handling */
            }
            /* Try to read a single block of info.st_size bytes */
            size_t blocks_read = fread(content, info.st_size, 1, fp);
            if (blocks_read != 1) {
                /* error handling */
            }
            fclose(fp);

            /*
            * If nothing went wrong, content now contains the
            * data read from the file.
            */

            sprintf(datalength, "DATA LENGTH: %lu\n", (unsigned long)info.st_size);

            char mine[1024] = { 0 };
            char OEP[1024] = { 0 };
            char mio[1024] = { 0 };
            //char yno[1024] = { 0 };
            char bhj[1024] = { 0 };
            char sec[1024] = { 0 };
            char secnumber[1024] = { 0 };
            char test[1024] = { 0 };
            char virsize[1024] = { 0 };
            char viraddress[1024] = { 0 };
            char sizeofraw[1024] = { 0 };
            char pofrawdata[1024] = { 0 };
            char ptoreloc[1024] = { 0 };
            char ptolinenumbers[1024] = { 0 };
            char nofreloc[1024] = { 0 };
            char noflinenumbers[1024] = { 0 };
            char vaaddva[1024] = { 0 };
            char oepva[1024] = { 0 };
            char oepoffset[1024] = { 0 };
            char Vaoffset[1024] = { 0 };
            char symbols[1024] = { 0 };
            char opsize[1024] = { 0 };
            char imagbs[1024] = { 0 };
            char uigraphic[1024] = { 0 };
            char typearch[1024] = { 0 };
            char szofcode[1024] = { 0 };
            char basecode[1024] = { 0 };
            char indata[1024] = { 0 };
            char basedata[1024] = { 0 };
            char sctallignment[1024] = { 0 };
            char minor[1024] = { 0 };
            char major[1024] = { 0 };
            char magicsign[1024] = { 0 };
            char bytes[1024] = { 0 };
            char pagefiles[1024] = { 0 };
            char reloc[1024] = { 0 };
            char sizeofheaderinp[1024] = { 0 };
            char miniextrapd[1024] = { 0 };
            char maxextrapn[1024] = { 0 };
            char inrlssval[1024] = { 0 };
            char initspval[1024] = { 0 };
            char checksum[1024] = { 0 };
            char initialipval[1024] = { 0 };
            char initialrlcsval[1024] = { 0 };
            char fileaddressrelctable[1024] = { 0 };
            char Overlaynumb[1024] = { 0 };
            char OEMID[1024] = { 0 };
            char oemide_mid[1024] = { 0 };
            char RVAAddressofpeheader[1024] = { 0 };
            char themachinearch[1024] = { 0 };
            //char timedatestamp[1024] = { 0 };
            char sgnhex[1024] = { 0 };
            char a[1024] = { 0 };
            char s[1024] = { 0 };
            char charcex[1024] = {0};
            /*char sizeofraw[1024] = { 0 };
            char sizeofraw[1024] = { 0 };*/
            //unsigned int hg;
            sprintf(OEP, "0x%x", ntHeader->OptionalHeader.AddressOfEntryPoint);
            pSecHeader = (PIMAGE_SECTION_HEADER)((LONG64)ntHeader + sizeof(IMAGE_NT_HEADERS64));


            sprintf(bhj, "%s", pSecHeader->Name);
            sprintf(sgnhex, "0x%x", dosHeader->e_magic);
            time_t creationTime = ntHeader->FileHeader.TimeDateStamp;

            tm* Time = localtime(&creationTime);
            strftime(s, sizeof(s), "%a %Y-%m-%d %H:%M:%S %Z", Time);
            sprintf(a, "%s", s);



            if (dosHeader->e_magic == IMAGE_DOS_SIGNATURE) {
                //Dump the Dos Header info
                sprintf(magicsign, "\n%-36s%s ", "Magic number : ", dosHeader->e_magic == 0x5a4d ? "MZ (detected)" : "-");
                sprintf(bytes, "\n%-36s%#x", "Bytes on last page of file :", dosHeader->e_cblp);
                sprintf(pagefiles, "\n%-36s%#x", "Pages in file : ", dosHeader->e_cp);
                sprintf(reloc, "\n%-36s%#x", "Relocation : ", dosHeader->e_crlc);
                sprintf(sizeofheaderinp, "\n%-36s%#x", "Size of header in paragraphs : ", dosHeader->e_cparhdr);
                sprintf(miniextrapd, "\n%-36s%#x", "Minimum extra paragraphs needed : ", dosHeader->e_minalloc);
                sprintf(maxextrapn, "\n%-36s%#x", "Maximum extra paragraphs needed : ", dosHeader->e_maxalloc);
                sprintf(inrlssval, "\n%-36s%#x", "Initial (relative) SS value : ", dosHeader->e_ss);
                sprintf(initspval, "\n%-36s%#x", "Initial SP value : ", dosHeader->e_sp);
                sprintf(checksum, "\n%-36s%#x", "Checksum : ", dosHeader->e_csum);
                sprintf(initialipval, "\n%-36s%#x", "Initial IP value : ", dosHeader->e_ip);
                sprintf(initialrlcsval, "\n%-36s%#x", "Initial (relative) CS value : ", dosHeader->e_cs);
                sprintf(fileaddressrelctable, "\n%-36s%#x", "File address of relocation table : ", dosHeader->e_lfarlc);
                sprintf(Overlaynumb, "\n%-36s%#x", "Overlay number : ", dosHeader->e_ovno);
                sprintf(OEMID, "\n%-36s%#x", "OEM identifier : ", dosHeader->e_oemid);
                sprintf(oemide_mid, "\n%-36s%#x", "OEM information(e_oemid specific) :", dosHeader->e_oeminfo);
                sprintf(RVAAddressofpeheader, "\n%-36s%#x", "RVA address of PE header : ", dosHeader->e_lfanew);

            }
            else {
                ///MessageBox::Show("Dos header not valid.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
                QMessageBox::critical(this, "KirbiDSMx64", "Invalid DosHeader.");
                this->close();


                //goto end;
            }


            switch (ntHeader->FileHeader.Machine) { //Only few are determined (for remaining refer to the above specification)
            case 0x0:        sprintf(themachinearch, "All "); break;
            case 0x14d:  sprintf(themachinearch, "Intel i860"); break;
            case 0x14c:  sprintf(themachinearch, "Intel i386,i486,i586"); break;
            case 0x200:  sprintf(themachinearch, "Intel Itanium processor"); break;
            case 0x8664: sprintf(themachinearch, "AMD x64"); break;
            case 0x162:  sprintf(themachinearch, "MIPS R3000"); break;
            case 0x166:  sprintf(themachinearch, "MIPS R4000"); break;
            case 0x183:  sprintf(themachinearch, "DEC Alpha AXP"); break;
            default:         sprintf(themachinearch, "It seems not found"); break;
            }




            std::stringstream sectstream;
            std::stringstream buffinf;

        ///			std::stringstream test;

            sectstream << "Address                     Raw Size                     Raw Address                                 Name                                 Contains" << "\n\n";
            sectstream << "------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
            for (i = 0; i < ntHeader->FileHeader.NumberOfSections;i++, pSecHeader++)
            {





               /// if ((pSecHeader->Characteristics & IMAGE_SCN_MEM_READ) == IMAGE_SCN_MEM_READ)
                ///sprintf(charcex,"can be read.\n");
                ///if ((pSecHeader->Characteristics & IMAGE_SCN_MEM_WRITE) == IMAGE_SCN_MEM_WRITE)
                //sprintf(charcex,"can be written to.\n");
                DWORD vava = (pSecHeader->VirtualAddress) + (ntHeader->OptionalHeader.ImageBase);
                //	sprintf(yno, "\n\nSection Info (%d of %d)", i + 1, ntHeader->FileHeader.NumberOfSections);
                DWORD vaoepva = (pSecHeader->VirtualAddress) + (pSecHeader->PointerToRawData) - (pSecHeader->VirtualAddress);
                DWORD RVARAWADD = (pSecHeader->VirtualAddress);
                //strcat(sec, (char*)pSecHeader->Name);

                sectstream  << " " << "0x" << std::hex << pSecHeader->VirtualAddress << " ------------------->   " << "0x" << std::hex << pSecHeader->SizeOfRawData << " ------------------->   " << "0x" << std::hex << pSecHeader->PointerToRawData << " ------------------->   "  << (char*)pSecHeader->Name;
                ///test << pSecHeader->Name << std::endl;
                sectstream<< " ------------------->   ";
                if((pSecHeader->Characteristics & IMAGE_SCN_CNT_CODE) == IMAGE_SCN_CNT_CODE) {

                    sectstream << "executable code ";
                }

                if((pSecHeader->Characteristics & IMAGE_SCN_CNT_INITIALIZED_DATA) == IMAGE_SCN_CNT_INITIALIZED_DATA) {

                    sectstream << "initialized data ";
                }

                if((pSecHeader->Characteristics & IMAGE_SCN_CNT_UNINITIALIZED_DATA) == IMAGE_SCN_CNT_UNINITIALIZED_DATA) {

                    sectstream << "uninitialized data ";
                }

                if((pSecHeader->Characteristics & IMAGE_SCN_LNK_INFO) == IMAGE_SCN_LNK_INFO) {

                    sectstream << "comments or other information ";
                }


                sectstream << "\n";

                buffinf << "Section: " << (char*)pSecHeader->Name << "\n";
                sprintf(virsize, "\n%-36s%#x", "Size of code or data:", pSecHeader->Misc.VirtualSize);
                buffinf << virsize << "\n";
                sprintf(viraddress, "\n%-36s%#x", "(RVA)Virtual Address :", pSecHeader->VirtualAddress);
                buffinf << viraddress << "\n";
                //////printf("\n%-36s%#x", "Virtual Address(RVA) :", pSecHeader->VirtualAddress);
                sprintf(sizeofraw, "\n%-36s%#x", "Size of raw data (rounded to FA) : ", pSecHeader->SizeOfRawData);
                buffinf << sizeofraw << "\n";
                sprintf(pofrawdata, "\n%-36s%#x", "Pointer to Raw Data : ", pSecHeader->PointerToRawData);
                buffinf << pofrawdata << "\n";
                sprintf(ptoreloc, "\n%-36s%#x", "Pointer to Relocations : ", pSecHeader->PointerToRelocations);
                buffinf << ptoreloc << "\n";
                sprintf(ptolinenumbers, "\n%-36s%#x", "Pointer to Line numbers : ", pSecHeader->PointerToLinenumbers);
                buffinf << ptolinenumbers << "\n";
                sprintf(nofreloc, "\n%-36s%#x", "Number of relocations : ", pSecHeader->NumberOfRelocations);
                buffinf << nofreloc << "\n";
                sprintf(noflinenumbers, "\n%-36s%#x", "Number of line numbers : ", pSecHeader->NumberOfLinenumbers);
                buffinf << noflinenumbers << "\n\n";
                sprintf(mine, "(%d of %d)", i + 1, ntHeader->FileHeader.NumberOfSections);
                sprintf(vaaddva, "0x%x", vava);
                sprintf(Vaoffset, "0x%x", vaoepva);


                //System::String ^othersections = gcnew String(sec);
                ///sprintf(mine, "%s", pSecHeader->Name);
            //	richTextBox1->Text = othersections;
                //richTextBox1->Text += Environment::NewLine;
                //richTextBox1->Text += othenomi;

            }


            /*for (int i = 1; i < ntHeader->FileHeader.NumberOfSections; i++)
            {


                pSecHeader = (PIMAGE_SECTION_HEADER)((DWORD)pSecHeader + sizeof(IMAGE_SECTION_HEADER));

                DWORD testva = (pSecHeader[i].VirtualAddress);
                sprintf(sec, "%s", testva);
            }*/

            ////header = ntHeader->FileHeader;
            pSecHeader = (PIMAGE_SECTION_HEADER)((LONG64)ntHeader + sizeof(IMAGE_NT_HEADERS64));

            char *secoep = Oepnamesecc(ntHeader->OptionalHeader.AddressOfEntryPoint, pSecHeader, ntHeader);
            LONG64 Realoepoff = Rvatooff(ntHeader->OptionalHeader.AddressOfEntryPoint, pSecHeader, ntHeader);

            DWORD variable = (pSecHeader->VirtualAddress);
            ///hg = ntHeader->FileHeader.NumberOfSections;
            LONG64 imagem = (ntHeader->OptionalHeader.ImageBase);

            ///DWORD offset = (ntHeader->OptionalHeader.AddressOfEntryPoint) - variable + (pSecHeader->PointerToRawData);
            ///DWORD retAddr = (ntHeader->OptionalHeader.AddressOfEntryPoint) - (pSecHeader->VirtualAddress) + (pSecHeader->PointerToRawData);
            ////DWORD vaoep = offset - (pSecHeader->PointerToRawData) + (pSecHeader->VirtualAddress) + (ntHeader->OptionalHeader.ImageBase);
            DWORD vaoep = (ntHeader->OptionalHeader.AddressOfEntryPoint) + (ntHeader->OptionalHeader.ImageBase);
            DWORD off = vaoep - (ntHeader->OptionalHeader.ImageBase) - (pSecHeader->VirtualAddress) + (pSecHeader->PointerToRawData);
            DWORD RVAOEP = vaoep - (ntHeader->OptionalHeader.ImageBase);
            DWORD check = (ntHeader->OptionalHeader.AddressOfEntryPoint) - (pSecHeader->VirtualAddress) + (pSecHeader->PointerToRawData);

            sprintf(oepva, "0x%x", vaoep);
            sprintf(oepoffset, "0x%x", off);
            sprintf(symbols, "\n%-36s%d", "No.entries in symbol table :", ntHeader->FileHeader.NumberOfSymbols);
            sprintf(opsize, "\n%-36s%d", "Size of optional header :", ntHeader->FileHeader.SizeOfOptionalHeader);
            sprintf(imagbs, "\n%-36s%#x", "ImageBase : ", imagem);
            sprintf(uigraphic, "\n%-36s%s", "SubSystem type (UI) : ",
                ntHeader->OptionalHeader.Subsystem == 1 ? "Device Driver(Native windows Process)" :
                ntHeader->OptionalHeader.Subsystem == 2 ? "Windows GUI" :
                ntHeader->OptionalHeader.Subsystem == 3 ? "Windows CLI" :
                ntHeader->OptionalHeader.Subsystem == 9 ? "Windows CE GUI" :
                "Unknown");
            sprintf(typearch, "\n%-36s%s", "Type : ", ntHeader->OptionalHeader.Magic == 0x20b ? "PE32+(64)" : "PE32");
            sprintf(szofcode, "\n%-36s%d", "Size of code segment(.text) : ", ntHeader->OptionalHeader.SizeOfCode);
            sprintf(basecode, "\n%-36s%#x", "(RVA)Base address of code segment :", ntHeader->OptionalHeader.BaseOfCode);
            sprintf(indata, "\n%-36s%d", "Size of Initialized data : ", ntHeader->OptionalHeader.SizeOfInitializedData);
            ////sprintf(basedata, "\n%-36s%#x", "(RVA)Base address of data segment :", ntHeader->OptionalHeader.BaseOfData);
            sprintf(sctallignment, "\n%-36s%#x", "Section Alignment :", ntHeader->OptionalHeader.SectionAlignment);
            sprintf(major, "\n%-36s%d", "Major Linker Version : ", ntHeader->OptionalHeader.MajorLinkerVersion);
            sprintf(minor, "\n%-36s%d", "Minor Linker Version : ", ntHeader->OptionalHeader.MinorLinkerVersion);


            std::stringstream infos;
            std::string sections = sectstream.str();
            std::string ssectin = buffinf.str();

            infos << "                                            Sections:                 " << "\n\n\n";

            infos << sections << "\n";
            infos << filesize << "\n";
            infos << datalength << "\n\n\n";
            infos << "                                            DosHeader:       " << "\n\n";
            infos << magicsign << " " << "in Hex " << sgnhex << "\n";

            infos << bytes << "\n";
            infos << pagefiles << "\n";
            infos << reloc << "\n";
            infos << sizeofheaderinp << "\n\n";
            infos << miniextrapd << "\n";
            infos << maxextrapn << "\n";
            infos << inrlssval << std::endl;
            infos << initspval << "\n";
            infos << checksum << "\n";
            infos << initialipval << "\n";
            infos << initialrlcsval << "\n";
            infos << fileaddressrelctable << "\n";
            infos << Overlaynumb << "\n";
            infos << OEMID << "\n";
            infos << oemide_mid << "\n";
            infos << RVAAddressofpeheader << "\n\n\n";

            infos << "------------------------------" << "\n\n";
            infos << "                                            FileHeader:       " << "\n\n\n";
            infos << themachinearch << "\n\n";
            infos << "TimeDateStamp: " << a << "\n\n\n";
            infos << "------------------------------" << "\n\n";
            infos << "                                            General info:       " << "\n\n\n";
            infos << "NumberOfSections: " << mine << "\n";
            infos << opsize << "\n";
            infos << symbols << "\n";
            infos << typearch << "\n\n\n";
            infos << "------------------------------" << "\n\n";
            infos << "                                            Optional Header:       " << "\n\n\n";
            infos << "AddressOfEntryPoint: " << OEP << " VA " << oepva << " Offset " << "0x" << std::hex << Realoepoff << " (In " << secoep << ")" << "\n";
            infos << "ImageBase :                       " << "0x" << std::hex << ntHeader->OptionalHeader.ImageBase << "\n";
            infos << uigraphic << "\n";
            infos << szofcode << "\n";
            infos << basecode << "\n";
            infos << basedata << "\n";
            infos << sctallignment << "\n";
            infos << major << "\n";
            infos << minor << "\n\n\n";
            infos << "-----------------------------" << "\n\n";
            infos << "                                  Sections (details):      " << "\n\n\n";
            infos << ssectin << "\n";


            fprintf(sv, "%s\n", (char*)infos.str().c_str());
            ///fclose(sv);
            QMessageBox::information(this, "KirbiDSMx64", "Memory map successfully saved.");

    }
}

void MainHome::on_actionC_Decompiler_triggered()
{

}

void MainHome::on_actionC_code_triggered()
{

    if(flnm == "") {

        QMessageBox::critical(this, "KirbiDSMx64", "File not opened");
    }
    else {

        std::string decpth = ".NET Decompiler\\Decompiler.exe";
        DWORD ftyp = GetFileAttributesA(decpth.c_str());

        if (ftyp == INVALID_FILE_ATTRIBUTES) {

            QMessageBox::critical(this, "KirbiDSMx64", ".NET Decompiler not found!");
        }
        else {

            if(IsDotNetApp(flnm.toStdString().c_str())) {

                FILE *dc = fopen("File.txt", "w");
               /// std::string cmd;
                fprintf(dc, "%s", (char*)flnm.toStdString().c_str());
                fclose(dc);
                ShellExecuteA( NULL, NULL, ".NET Decompiler\\Decompiler.exe", NULL, NULL, SW_SHOW );

            }
            else {

                QMessageBox::critical(this, "KirbiDSMx64", "This PE is not .NET");
            }
        }





    }


}

void MainHome::on_actionSave_imports_triggered()
{
    if (flnm == "") {

        QMessageBox::StandardButton question;

        question = QMessageBox::question(this, "KirbiDSMx64", "File is not opened, do you want to open it?", QMessageBox::Yes | QMessageBox::No);

        if (question == QMessageBox::Yes) {

            QString pathprov = QFileDialog::getOpenFileName(this, tr("Open your exe!"), "c:\\",
                tr("Executable files (*.exe *.ax *.cpl *.dll *.drv *.efi *.mui *.ocx *.scr *.sys *.tsp)"));

            if(pathprov == "") {

                return;
            }

            Sleep(2000);

            QString savefl = QFileDialog::getSaveFileName(this, "Save Imports", "", ".txt");
            if(savefl == "") {

                return;
            }
            FILE *sv = fopen(savefl.toStdString().c_str(), "w");
            std::stringstream importes;
            std::ifstream pe_file(pathprov.toStdString(), std::ios::in | std::ios::binary);
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
                 //ui->plainTextEdit->appendPlainText(QString::fromStdString(importes.str()));
                 fprintf(sv, "%s\n", (char*)importes.str().c_str());

                 fclose(sv);
                 QMessageBox::information(this, "KirbiDSMx64", "Imports successfully saved.");

        }

    }
    else {

        QString savefl = QFileDialog::getSaveFileName(this, "Save Imports", "", ".txt");
        if(savefl == "") {

            return;
        }
        FILE *sv = fopen(savefl.toStdString().c_str(), "w");
        std::stringstream importes;
        std::ifstream pe_file(flnm.toStdString(), std::ios::in | std::ios::binary);
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
             //ui->plainTextEdit->appendPlainText(QString::fromStdString(importes.str()));
             fprintf(sv, "%s\n", (char*)importes.str().c_str());

             fclose(sv);
             QMessageBox::information(this, "KirbiDSMx64", "Imports successfully saved.");
    }
}

void MainHome::dragEnterEvent(QDragEnterEvent *e)
{
    if(e->mimeData()->hasUrls())
           e->acceptProposedAction();
       else e->ignore();

}

void MainHome::dropEvent(QDropEvent *ev)
{
    foreach (QUrl url, ev->mimeData()->urls()) {

            QString fileName = url.toLocalFile();

            flnm = fileName;


            std::string pthstd = flnm.toStdString();
            //flnm = filepath;
            this->setWindowTitle("KirbiDSMx64 - " + flnm);

            int i = 0;
            HANDLE hMapObject, hFile; //File Mapping Object
            LPVOID lpBase; //Pointer to the base memory of mapped file
            PIMAGE_DOS_HEADER dosHeader; //Pointer to DOS Header
            PIMAGE_NT_HEADERS64 ntHeader; //Pointer to NT Header
            IMAGE_FILE_HEADER header; //Pointer to image file header of NT Header
            IMAGE_OPTIONAL_HEADER opHeader; //Optional Header of PE files present in NT Header structure
            PIMAGE_SECTION_HEADER pSecHeader;

            hFile = CreateFileA((char*)pthstd.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);

            if (hFile == INVALID_HANDLE_VALUE) {
                ui->plainTextEdit_4->appendPlainText("-File read FALIED.\n");
                this->setWindowTitle("KirbiDSMx64");
                QMessageBox::critical(this, tr("KirbiDSMx64"), tr("Error reading the file."));
                flnm = "";
                return;
            }
            ui->plainTextEdit_4->appendPlainText("-File read successfully complete, waiting for mapping.\n");
            HANDLE hMap = CreateFileMapping(hFile, 0, PAGE_READONLY, 0, 0, 0);
            if (hMap == NULL) {
                ui->plainTextEdit_4->appendPlainText("-Create File mapping FALIED.\n");
                this->setWindowTitle("KirbiDSMx64");
                QMessageBox::critical(this, tr("KirbiDSMx64"), tr("Error mapping the file."));
                flnm = "";
                return;
            }
            ui->plainTextEdit_4->appendPlainText("-Map file created successfully, waiting for read.\n");
            lpBase = MapViewOfFile(hMap, FILE_MAP_READ, 0, 0, 0);
            base = lpBase;
            if (lpBase == NULL) {
                ui->plainTextEdit_4->appendPlainText("-Map reading FALIED.\n");
                this->setWindowTitle("KirbiDSMx64");
                QMessageBox::critical(this, tr("KirbiDSMx64"), tr("Error reading the bytes."));
                flnm = "";
                return;
            }
            ui->plainTextEdit_4->appendPlainText("-Map reading successfully complete.\n");
            dosHeader = (PIMAGE_DOS_HEADER)lpBase;

            ntHeader = (PIMAGE_NT_HEADERS64)((LONG64)(dosHeader) + (dosHeader->e_lfanew));
            if (ntHeader->Signature != IMAGE_NT_SIGNATURE) {
                this->setWindowTitle("KirbiDSMx64");
                QMessageBox::critical(this, tr("KirbiDSMx64"), tr("Invalid PE file!"));
                flnm = "";
                return;
            }
            pSecHeader = (PIMAGE_SECTION_HEADER)((LONG64)ntHeader + sizeof(IMAGE_NT_HEADERS64));
            if (flnm.contains(".dll")) {
                ui->plainTextEdit_4->appendPlainText("-PE type DLL\n");
            }
            if(IsDotNetApp(flnm.toStdString().c_str())) {

                ui->plainTextEdit_4->appendPlainText("-PE type .NET\n");
            }
            if (((ntHeader->OptionalHeader.Magic & IMAGE_NT_OPTIONAL_HDR32_MAGIC) == IMAGE_NT_OPTIONAL_HDR32_MAGIC) && ((ntHeader->FileHeader.Characteristics & IMAGE_FILE_32BIT_MACHINE) == IMAGE_FILE_32BIT_MACHINE)) {

                QMessageBox::warning(this, tr("KirbiDSMx64"), tr("This PE is 32 bit, to disasseble it use KirbiDSM."));
                this->setWindowTitle("KirbiDSMx64");
                flnm = "";
            }

            else {
                std::stringstream secstresm;
                ui->plainTextEdit_4->appendPlainText("-PE32+ (64)\n");
                sc = pSecHeader;
                nt = ntHeader;
                for (int i = 0; i < ntHeader->FileHeader.NumberOfSections; i++) {
                    if ((pSecHeader->VirtualAddress <= ntHeader->OptionalHeader.AddressOfEntryPoint) && (ntHeader->OptionalHeader.AddressOfEntryPoint < (pSecHeader->VirtualAddress + pSecHeader->Misc.VirtualSize))) {

                        oepoffi = (ntHeader->OptionalHeader.AddressOfEntryPoint) - (pSecHeader->VirtualAddress) + (pSecHeader->PointerToRawData);

                        endi = (pSecHeader->PointerToRawData) + (pSecHeader->SizeOfRawData) - oepoffi;

                        break;
                    }

                    pSecHeader++;
                }
                pSecHeader = (PIMAGE_SECTION_HEADER)((LONG64)ntHeader + sizeof(IMAGE_NT_HEADERS64));
                int m;
                for (pSecHeader = IMAGE_FIRST_SECTION(ntHeader), m = 0; m < ntHeader->FileHeader.NumberOfSections; m++, pSecHeader++) {

                    secstresm << (char*)pSecHeader->Name << "\n";
                }

                sections = QString::fromStdString(secstresm.str());
                pSecHeader = (PIMAGE_SECTION_HEADER)((LONG64)ntHeader + sizeof(IMAGE_NT_HEADERS64));
                if (oepoffi == 0) {

                    QMessageBox::StandardButton ques;

                    ques = QMessageBox::warning(this, "KirbiDSMx64", "Falied to get EntryPoint offset. Do you want to disassemble the executable section?",
                        QMessageBox::Yes | QMessageBox::No);

                    if (ques == QMessageBox::Yes) {

                        oepoffi = pSecHeader->PointerToRawData;
                        endi = pSecHeader->SizeOfRawData;
                    }
                    else
                        return;
                }

                ui->plainTextEdit->clear();
                //ui->plainTextEdit_2->clear();
                ui->plainTextEdit_3->clear();
                ///ui->plainTextEdit_4->clear();
                char arrdis[1024] = { 0 };
                std::stringstream disstr;
                ui->plainTextEdit_4->appendPlainText("-Disassembling bytes...\n");
                imgbase = (ntHeader->OptionalHeader.ImageBase);
                QMessageBox::StandardButton s;

                s = QMessageBox::question(this, "KirbiDSMx64", "Which engine you want to use? [Yes]Distorm, [No]Zydis, [Cancel]Udis86", QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
                if (s == QMessageBox::Yes) {

                    engine = 1;

                    unsigned long dver = 0;
                    // Holds the result of the decoding.
                    _DecodeResult res;
                    // Decoded instruction information.
                    _DecodedInst decodedInstructions[MAX_INSTRUCTIONS];
                    // next is used for instruction's offset synchronization.
                    // decodedInstructionsCount holds the count of filled instructions' array by the decoder.
                    unsigned int decodedInstructionsCount = 0, i, next;

                    // Default decoding mode is 32 bits, could be set by command line.
                    _DecodeType dt = Decode64Bits;

                    // Default offset for buffer is 0, could be set in command line.
                    _OffsetType offset = 0;
                    char* errch = NULL;

                    // Index to file name in argv.
                    int param = 1;

                    ////ui->plainTextEdit_4->appendPlainText("-Falied to get the OEP offset.\n");

                    // If you get an unresolved external symbol linker error for the following line,
                    // change the SUPPORT_64BIT_OFFSET in distorm.h.
                    res = distorm_decode(offset, (unsigned char*)lpBase + oepoffi, endi, dt, decodedInstructions, MAX_INSTRUCTIONS, &decodedInstructionsCount);
                    if (res > 0) {
                        ui->plainTextEdit_4->appendPlainText("-Disassemblying complete.\n");
                        for (i = 0; i < decodedInstructionsCount; i++) {

                            sprintf(arrdis, " %0*I64x\t(%02d) %-24s\t%s%s%s\n", dt != Decode64Bits ? 8 : 16, decodedInstructions[i].offset, decodedInstructions[i].size, (char*)decodedInstructions[i].instructionHex.p, (char*)decodedInstructions[i].mnemonic.p, decodedInstructions[i].operands.length != 0 ? " " : "", (char*)decodedInstructions[i].operands.p);

                            ///sprintf(arrdis, " %08x\t(%02d) %-24s\t%s%s%s\n", decodedInstructions[i].offset, decodedInstructions[i].size, (char*)decodedInstructions[i].instructionHex.p, (char*)decodedInstructions[i].mnemonic.p, decodedInstructions[i].operands.length != 0 ? " " : "", (char*)decodedInstructions[i].operands.p);
                            disstr << arrdis;
                        }

                        ui->plainTextEdit->appendPlainText(QString::fromStdString(disstr.str()));

                        QScrollBar* vScrollBar = ui->plainTextEdit->verticalScrollBar();

                        //QScrollBar *vScrollBarhex = ui->plainTextEdit_2->verticalScrollBar();
                        vScrollBar->triggerAction(QScrollBar::SliderToMinimum);
                        //pal->triggerAction(QScrollBar::SliderToMinimum);
                        ui->plainTextEdit_3->appendPlainText("RAX = 0000000000000000\n");
                        ui->plainTextEdit_3->appendPlainText("RBX = 0000000000000000\n");
                        ui->plainTextEdit_3->appendPlainText("RCX = 0000000000000000\n");
                        ui->plainTextEdit_3->appendPlainText("RDX = 0000000000000000\n");
                        ui->plainTextEdit_3->appendPlainText("RBP = 0000000000000000\n");
                        ui->plainTextEdit_3->appendPlainText("RSP = 0000000000000000\n");
                        ui->plainTextEdit_3->appendPlainText("RSI = 0000000000000000\n");
                        ui->plainTextEdit_3->appendPlainText("RDI = 0000000000000000\n\n");
                        ui->plainTextEdit_3->appendPlainText("R8 = 0000000000000000\n");
                        ui->plainTextEdit_3->appendPlainText("R9 = 0000000000000000\n");
                        ui->plainTextEdit_3->appendPlainText("R10 = 0000000000000000\n");
                        ui->plainTextEdit_3->appendPlainText("R11 = 0000000000000000\n");
                        ui->plainTextEdit_3->appendPlainText("R12 = 0000000000000000\n");
                        ui->plainTextEdit_3->appendPlainText("R13 = 0000000000000000\n");
                        ui->plainTextEdit_3->appendPlainText("R14 = 0000000000000000\n");
                        ui->plainTextEdit_3->appendPlainText("R15 = 0000000000000000\n");
                        QScrollBar* pal = ui->plainTextEdit_3->verticalScrollBar();
                        pal->triggerAction(QScrollBar::SliderToMinimum);
                        // vScrollBarhex->triggerAction(QScrollBar::SliderToMinimum);
                    }
                    else {

                        ui->plainTextEdit_4->appendPlainText("-Disassemblying bytes FALIED.\n");
                        QMessageBox::critical(this, "KirbiDSMx64", "Couln't disassemble this file sorry.");
                        UnmapViewOfFile(lpBase);
                        CloseHandle(hFile);
                        CloseHandle(hMap);
                        flnm = "";
                    }
                }

                 if(s == QMessageBox::No){

                    engine = 2;

                    std::stringstream add;
                    Zydis::InstructionInfo info;
                    Zydis::InstructionDecoder decoder;
                    Zydis::IntelInstructionFormatter formatter;
                    Zydis::MemoryInput input64((unsigned char*)lpBase + oepoffi, endi);
                    //Zydis::MemoryInput input64(&data64[0], sizeof(data64));
                    char formt[1024] = { 0 };
                    std::stringstream dis;
                    /*0x00007FFA39A81930ull*/
                    LONG64 entry = ntHeader->OptionalHeader.AddressOfEntryPoint;
                    LONG64 addresses = 0x00007FFA39A;
                    std::stringstream ad;
                    ///uint64_t res;
                    ad << "0x0000" << std::hex << std::uppercase << addresses << entry;
                    std::string hexadec(ad.str());

                    strcpy(formt, (char*)hexadec.c_str());
                    uint64_t formatting = strtoimax(hexadec.c_str(), 0, 16);

                    decoder.setDisassemblerMode(Zydis::DisassemblerMode::M64BIT);
                    decoder.setDataSource(&input64);
                    decoder.setInstructionPointer(formatting);
                    /*info.instrAddress*/
                    while (decoder.decodeInstruction(info)) {
                        dis << std::hex << std::setw(16) << std::setfill('0') << std::uppercase
                            << info.instrAddress << "\t\t\t";
                        if (info.flags & Zydis::IF_ERROR_MASK) {
                            dis << "db " << std::setw(2) << static_cast<int>(info.data[0]) << std::endl;
                        }
                        else {
                            dis << formatter.formatInstruction(info) << std::endl;
                        }
                    }
                    ui->plainTextEdit->appendPlainText(QString::fromStdString(dis.str()));
                    QScrollBar* vScrollBar = ui->plainTextEdit->verticalScrollBar();
                    //QScrollBar *vScrollBarhex = ui->plainTextEdit_2->verticalScrollBar();
                    vScrollBar->triggerAction(QScrollBar::SliderToMinimum);

                    ui->plainTextEdit_3->appendPlainText("RAX = 0000000000000000\n");
                    ui->plainTextEdit_3->appendPlainText("RBX = 0000000000000000\n");
                    ui->plainTextEdit_3->appendPlainText("RCX = 0000000000000000\n");
                    ui->plainTextEdit_3->appendPlainText("RDX = 0000000000000000\n");
                    ui->plainTextEdit_3->appendPlainText("RBP = 0000000000000000\n");
                    ui->plainTextEdit_3->appendPlainText("RSP = 0000000000000000\n");
                    ui->plainTextEdit_3->appendPlainText("RSI = 0000000000000000\n");
                    ui->plainTextEdit_3->appendPlainText("RDI = 0000000000000000\n\n");
                    ui->plainTextEdit_3->appendPlainText("R8 = 0000000000000000\n");
                    ui->plainTextEdit_3->appendPlainText("R9 = 0000000000000000\n");
                    ui->plainTextEdit_3->appendPlainText("R10 = 0000000000000000\n");
                    ui->plainTextEdit_3->appendPlainText("R11 = 0000000000000000\n");
                    ui->plainTextEdit_3->appendPlainText("R12 = 0000000000000000\n");
                    ui->plainTextEdit_3->appendPlainText("R13 = 0000000000000000\n");
                    ui->plainTextEdit_3->appendPlainText("R14 = 0000000000000000\n");
                    ui->plainTextEdit_3->appendPlainText("R15 = 0000000000000000\n");

                    QScrollBar* pal = ui->plainTextEdit_3->verticalScrollBar();
                    pal->triggerAction(QScrollBar::SliderToMinimum);
                }

                 if(s == QMessageBox::Cancel) {





                      ud_t ud_obj;
                        ud_init(&ud_obj);
                        ud_set_mode(&ud_obj, 64);
                        ud_set_input_buffer(&ud_obj, (unsigned char*)lpBase + oepoffi, endi);
                        ud_set_syntax(&ud_obj, UD_SYN_INTEL);

                        ////printf("==> Without Symbol Resolution\n");


                        /*printf("==> With Symbol Resolution\n");
                        ud_set_pc(&ud_obj, 0);
                        ud_set_input_buffer(&ud_obj, bin, sizeof(bin));
                        ud_set_sym_resolver(&ud_obj, &resolve);
                        dis_loop(&ud_obj);*/


                    ui->plainTextEdit->appendPlainText(dis_loop(&ud_obj));
                    QScrollBar* vScrollBar = ui->plainTextEdit->verticalScrollBar();
                    //QScrollBar *vScrollBarhex = ui->plainTextEdit_2->verticalScrollBar();
                    vScrollBar->triggerAction(QScrollBar::SliderToMinimum);

                    ui->plainTextEdit_3->appendPlainText("RAX = 0000000000000000\n");
                    ui->plainTextEdit_3->appendPlainText("RBX = 0000000000000000\n");
                    ui->plainTextEdit_3->appendPlainText("RCX = 0000000000000000\n");
                    ui->plainTextEdit_3->appendPlainText("RDX = 0000000000000000\n");
                    ui->plainTextEdit_3->appendPlainText("RBP = 0000000000000000\n");
                    ui->plainTextEdit_3->appendPlainText("RSP = 0000000000000000\n");
                    ui->plainTextEdit_3->appendPlainText("RSI = 0000000000000000\n");
                    ui->plainTextEdit_3->appendPlainText("RDI = 0000000000000000\n\n");
                    ui->plainTextEdit_3->appendPlainText("R8 = 0000000000000000\n");
                    ui->plainTextEdit_3->appendPlainText("R9 = 0000000000000000\n");
                    ui->plainTextEdit_3->appendPlainText("R10 = 0000000000000000\n");
                    ui->plainTextEdit_3->appendPlainText("R11 = 0000000000000000\n");
                    ui->plainTextEdit_3->appendPlainText("R12 = 0000000000000000\n");
                    ui->plainTextEdit_3->appendPlainText("R13 = 0000000000000000\n");
                    ui->plainTextEdit_3->appendPlainText("R14 = 0000000000000000\n");
                    ui->plainTextEdit_3->appendPlainText("R15 = 0000000000000000\n");

                    QScrollBar* pal = ui->plainTextEdit_3->verticalScrollBar();
                    pal->triggerAction(QScrollBar::SliderToMinimum);

                 }
            }

        }

}

void MainHome::on_actionSave_exports_triggered()
{
    if (flnm == "") {

        QMessageBox::StandardButton question;

        question = QMessageBox::question(this, "KirbiDSMx64", "File is not opened, do you want to open it?", QMessageBox::Yes | QMessageBox::No);

        if (question == QMessageBox::Yes) {

            QString pathprov = QFileDialog::getOpenFileName(this, tr("Open your exe!"), "c:\\",
                tr("Executable files (*.exe *.ax *.cpl *.dll *.drv *.efi *.mui *.ocx *.scr *.sys *.tsp)"));

            if(pathprov == "") {

                return;
            }

            Sleep(2000);

            QString savefl = QFileDialog::getSaveFileName(this, "Save Exports", "", ".txt");
            if(savefl == "") {

                return;
            }
            FILE *sv = fopen(savefl.toStdString().c_str(), "w");
            std::stringstream ex;
            std::ifstream pe_file(pathprov.toStdString(), std::ios::in | std::ios::binary);
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

            //ui->plainTextEdit->appendPlainText(QString::fromStdString(ex.str()));
            fprintf(sv, "%s\n", (char*)ex.str().c_str());
            QMessageBox::information(this, "KirbiDSMx64", "Exports successfully saved.");

        }

    }
    else {




        QString savefl = QFileDialog::getSaveFileName(this, "Save Exports", "", ".txt");
        if(savefl == "") {

            return;
        }
        FILE *sv = fopen(savefl.toStdString().c_str(), "w");
        std::stringstream ex;
        std::ifstream pe_file(flnm.toStdString(), std::ios::in | std::ios::binary);
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

        //ui->plainTextEdit->appendPlainText(QString::fromStdString(ex.str()));
        fprintf(sv, "%s\n", (char*)ex.str().c_str());
        QMessageBox::information(this, "KirbiDSMx64", "Exports successfully saved.");









    }
}

void MainHome::on_actionSave_relocations_triggered()
{
    if (flnm == "") {

        QMessageBox::StandardButton question;

        question = QMessageBox::question(this, "KirbiDSMx64", "File is not opened, do you want to open it?", QMessageBox::Yes | QMessageBox::No);

        if (question == QMessageBox::Yes) {

            QString pathprov = QFileDialog::getOpenFileName(this, tr("Open your exe!"), "c:\\",
                tr("Executable files (*.exe *.ax *.cpl *.dll *.drv *.efi *.mui *.ocx *.scr *.sys *.tsp)"));

            if(pathprov == "") {

                return;
            }

            Sleep(2000);

            QString savefl = QFileDialog::getSaveFileName(this, "Save Exports", "", ".txt");

            if(savefl == "") {

                return;
            }
            FILE *sv = fopen(savefl.toStdString().c_str(), "w");
            std::stringstream relocat;

            std::ifstream pe_file(pathprov.toStdString(), std::ios::in | std::ios::binary);
            if(!pe_file)
            {
                QMessageBox::critical(this, "KirbiDSMx64", "Couldn't open this PE");
            }

            try
            {

                pe_base image(pe_factory::create_pe(pe_file));




                const relocation_table_list tables(get_relocations(image));


                for(relocation_table_list::const_iterator it = tables.begin(); it != tables.end(); ++it)
                {
                    const relocation_table& table = *it;
                    relocat << "RVA [" << table.get_rva() << "]" << std::endl
                        << "=========="
                        << std::endl;


                    const relocation_table::relocation_list& relocs = table.get_relocations();
                    for(relocation_table::relocation_list::const_iterator reloc_it = relocs.begin(); reloc_it != relocs.end(); ++reloc_it)
                    {
                        relocat << "[+] " << (*reloc_it).get_item() << std::endl;
                    }

                    relocat << std::endl;
                }
            }
            catch(const pe_exception& e)
            {

               QMessageBox::critical(this, "KirbiDSMx64", "Exception!");
            }

            fprintf(sv, "%s\n", (char*)relocat.str().c_str());

            QMessageBox::information(this, "KirbiDSMx64", "Relocations successfully saved.");
        }

    }
    else {

        QString savefl = QFileDialog::getSaveFileName(this, "Save Exports", "", ".txt");
        if(savefl == "") {

            return;
        }
        FILE *sv = fopen(savefl.toStdString().c_str(), "w");
        std::stringstream relocat;

        std::ifstream pe_file(flnm.toStdString(), std::ios::in | std::ios::binary);
        if(!pe_file)
        {
            QMessageBox::critical(this, "KirbiDSMx64", "Couldn't open this PE");
        }

        try
        {

            pe_base image(pe_factory::create_pe(pe_file));




            const relocation_table_list tables(get_relocations(image));


            for(relocation_table_list::const_iterator it = tables.begin(); it != tables.end(); ++it)
            {
                const relocation_table& table = *it;
                relocat << "RVA [" << table.get_rva() << "]" << std::endl
                    << "=========="
                    << std::endl;


                const relocation_table::relocation_list& relocs = table.get_relocations();
                for(relocation_table::relocation_list::const_iterator reloc_it = relocs.begin(); reloc_it != relocs.end(); ++reloc_it)
                {
                    relocat << "[+] " << (*reloc_it).get_item() << std::endl;
                }

                relocat << std::endl;
            }
        }
        catch(const pe_exception& e)
        {

           QMessageBox::critical(this, "KirbiDSMx64", "Exception!");
        }

        fprintf(sv, "%s\n", (char*)relocat.str().c_str());

        QMessageBox::information(this, "KirbiDSMx64", "Relocations successfully saved.");

    }
}

void MainHome::on_actionRestart_triggered()
{
    qApp->quit();
    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
}

void MainHome::on_actionClear_triggered()
{
    ui->plainTextEdit->clear();
    ui->plainTextEdit_3->clear();
    flnm = "";
}

void MainHome::on_actionAbout_triggered()
{
    std::stringstream msg;

    msg << "KirbiDSMx64-OPS is an Open Source 64 bit Disassembler for windows, it includes also a 'plugin' .NET Decompiler feature written in C#. KirbiDSMx64-OPS is written in C\C++ and the UI is made in Qt. It is also a new and little better than my previous one (KirbiDSM). The project KirbiDSM was started 14/02/2018 by Kirbiflint. it can read/editor PE. It was written in C++/CLI .NET. If you find any issue/bug, feel free to contact me at Discord. (Kirbiflint#3098). Enjoy!" << "\n\n";
    msg << "This disassembler uses some libraries:" << "\n\n";
    msg << "-Distorm" << "\n";
    msg << "-Udis86" << "\n";
    msg << "-Zydis" << "\n";
    msg << "-libpe" << "\n";
    msg << "-pe_bliss" << "\n";
    msg << "-IlSpy (.NET Decompiler)" << "\n\n";

    QMessageBox::information(this, "About KirbiDSMx64-OPS", QString::fromStdString(msg.str()));

}
