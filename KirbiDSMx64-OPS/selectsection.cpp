#include "selectsection.h"
#include "ui_selectsection.h"
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
#include <QComboBox>
#include <QPalette>
#include "Zydis/Zydis.hpp"
#include "include/distorm.h"
#include "mainhome.h"
#define MAX_INSTRUCTIONS (1000)
SelectSection::SelectSection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectSection)
{
    ui->setupUi(this);
}

PIMAGE_NT_HEADERS64 nthr;
PIMAGE_SECTION_HEADER scs;
LONG64 rawadd;
LONG64 rawsize;
LPVOID map;
SelectSection::~SelectSection()
{
    delete ui;
}

void SelectSection::on_SelectSection_windowTitleChanged(const QString &title)
{
    int i = 0;
    HANDLE hMapObject, hFile;                        //File Mapping Object
    LPVOID lpBase;                                          //Pointer to the base memory of mapped file
    PIMAGE_DOS_HEADER dosHeader;            //Pointer to DOS Header
    PIMAGE_NT_HEADERS64 ntHeader;                     //Pointer to NT Header
    IMAGE_FILE_HEADER header;                       //Pointer to image file header of NT Header
    IMAGE_OPTIONAL_HEADER opHeader;         //Optional Header of PE files present in NT Header structure
    PIMAGE_SECTION_HEADER pSecHeader;
     ///std::string pthf = path.toStdString();
    std::string secnm;

    hFile = CreateFileA((char*)fli.toStdString().c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
    HANDLE hMap = CreateFileMapping(hFile, 0, PAGE_READONLY, 0, 0, 0);
    lpBase = MapViewOfFile(hMap, FILE_MAP_READ, 0, 0, 0);
    dosHeader = (PIMAGE_DOS_HEADER)lpBase;
    ntHeader = (PIMAGE_NT_HEADERS64)((LONG64)(dosHeader)+(dosHeader->e_lfanew));
    pSecHeader = (PIMAGE_SECTION_HEADER)((LONG64)ntHeader + sizeof(IMAGE_NT_HEADERS64));
    nthr = ntHeader;
    scs = pSecHeader;
    map = lpBase;
    for(int m = 0; m < ntHeader->FileHeader.NumberOfSections; m++) {

        secnm = (char*)pSecHeader->Name;

        ui->comboBox->addItem(QString::fromStdString(secnm));
        pSecHeader++;
    }
}

void SelectSection::on_comboBox_activated(const QString &arg1)
{

}

QString dism() {


        QString val = "";
        char arrdis[1024] = { 0 };
        std::stringstream disstr;
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
        res = distorm_decode(offset, (unsigned char*)map + rawadd, rawsize, dt, decodedInstructions, MAX_INSTRUCTIONS, &decodedInstructionsCount);
        if (res > 0) {
            ////ui->plainTextEdit_4->appendPlainText("-Disassemblying complete.\n");
            for (i = 0; i < decodedInstructionsCount; i++) {

                sprintf(arrdis, " %0*I64x\t(%02d) %-24s\t%s%s%s\n", dt != Decode64Bits ? 8 : 16, decodedInstructions[i].offset, decodedInstructions[i].size, (char*)decodedInstructions[i].instructionHex.p, (char*)decodedInstructions[i].mnemonic.p, decodedInstructions[i].operands.length != 0 ? " " : "", (char*)decodedInstructions[i].operands.p);

                ///sprintf(arrdis, " %08x\t(%02d) %-24s\t%s%s%s\n", decodedInstructions[i].offset, decodedInstructions[i].size, (char*)decodedInstructions[i].instructionHex.p, (char*)decodedInstructions[i].mnemonic.p, decodedInstructions[i].operands.length != 0 ? " " : "", (char*)decodedInstructions[i].operands.p);
                disstr << arrdis;
            }

            val = QString::fromStdString(disstr.str());
            ///std::string ass = disstr.str();
           /// QScrollBar* vScrollBar = ui->plainTextEdit->verticalScrollBar();


        }


    return val;
}
void SelectSection::on_pushButton_clicked()
{
    std::string sect = ui->comboBox->currentText().toStdString();
    for(int g = 0; g < nthr->FileHeader.NumberOfSections; g++) {

        if(sect == (char*)scs->Name) {

            rawadd = scs->PointerToRawData;
            rawsize = scs->SizeOfRawData;
            break;
        }
        scs++;
    }
    QString assembly = dism();
    MainHome *ma = new MainHome();
    ma->ui->plainTextEdit->appendPlainText(assembly);
    //ma->ui->plainTextEdit_3->appendPlainText(rgs);
    ///ma->ui->plainTextEdit_4->appendPlainText(stack);

    ma->setWindowTitle("KirbiDSMx64 - " + fli);
    ma->show();
    QScrollBar *scrollup = ma->ui->plainTextEdit->verticalScrollBar();
    scrollup->triggerAction(QSlider::SliderToMinimum);
    this->close();
}
