#include "expression.h"
#include "ui_expression.h"
#include <QPushButton>
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
#include <regex>
#include "mainhome.h"
#include "include/distorm.h"
#include "Zydis/Zydis.hpp"
#include <iomanip>
#define MAX_INSTRUCTIONS (1000)
Expression::Expression(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Expression)
{
    ui->setupUi(this);
    this->setSizeGripEnabled(false);

    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
    QPalette pal;
    pal.setColor(QPalette::WindowText, Qt::blue);
    ui->label->setPalette(pal);
    this->setFixedSize(this->size());


}
PIMAGE_NT_HEADERS n;
PIMAGE_SECTION_HEADER s;
std::string hexaddress = "";
std::regex hex("(?:0[xX])?[0-9a-fA-F]+");
LONG64 hexaddr;
LONG64 outrva;
LONG64 cmp;
bool valid = false;
std::stringstream entry;
std::string entstr = "";
size_t length = 0;
int eng = 0;
LONG64 offsetad;
LPVOID based;
LONG64 fine;
Expression::~Expression()
{
    delete ui;
}

bool isvalidaddress(LONG64 vaddress, PIMAGE_SECTION_HEADER sec, PIMAGE_NT_HEADERS nth) {

    bool add = false;
    for (int i = 0; i < nth->FileHeader.NumberOfSections; i++)
    {
        if ((sec->VirtualAddress <= vaddress) && (vaddress < (sec->VirtualAddress + sec->Misc.VirtualSize))) {

            add = true;

            ///endi = (pSecHeader->PointerToRawData) + (pSecHeader->SizeOfRawData) - oepoffi;


            break;

        }

        sec++;
    }
    return add;

}



void Expression::on_lineEdit_textChanged(const QString &arg1)
{
    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);

    hexaddress = ui->lineEdit->text().toStdString();
    entry << std::hex << n->OptionalHeader.AddressOfEntryPoint;
    entstr = entry.str();
    length = entstr.size();
    /*strtoimax(hexadec.c_str(), 0, 16);*/
    if (hexaddress.length() > 0) {

        if(ui->lineEdit->text().length() <= 16) {

            if (std::regex_search(hexaddress, hex)) {

                if (ui->lineEdit->text().contains("00007FFA39A")) {

                    hexaddress = hexaddress.substr(11, length);
                    hexaddr = strtoimax(hexaddress.c_str(), 0, 16);
                    ///outrva = (hexaddr - n->OptionalHeader.ImageBase);
                    valid = isvalidaddress(hexaddr, s, n);
                    if (valid == true) {

                        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
                        ui->label->setText("Correct expression!");
                        QPalette palete;
                        palete.setColor(QPalette::WindowText, Qt::green);
                        ui->label->setPalette(palete);
                        hexaddress = "";
                        eng = 2;

                        for (int i = 0; i < n->FileHeader.NumberOfSections; i++)
                        {
                            if ((s->VirtualAddress <= hexaddr) && (hexaddr < (s->VirtualAddress + s->Misc.VirtualSize))) {

                                offsetad = (hexaddr - s->VirtualAddress + s->PointerToRawData);
                                fine = (s->PointerToRawData + s->SizeOfRawData - offsetad);

                                ///endi = (pSecHeader->PointerToRawData) + (pSecHeader->SizeOfRawData) - oepoffi;


                                break;

                            }

                            s++;
                        }
                    }
                    else {

                        QPalette palit;
                        palit.setColor(QPalette::WindowText, Qt::red);
                        ui->label->setText("Invalid expression!");
                        ui->label->setPalette(palit);
                    }
                }
                else {
                    hexaddr = strtoimax(hexaddress.c_str(), 0, 16);
                    outrva = (hexaddr - n->OptionalHeader.ImageBase);
                    valid = isvalidaddress(outrva, s, n);
                    if (valid == true) {

                        if ((hexaddr & n->OptionalHeader.ImageBase)) {

                            ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
                            ui->label->setText("Correct expression!");
                            QPalette palete;
                            palete.setColor(QPalette::WindowText, Qt::green);
                            ui->label->setPalette(palete);
                            hexaddress = "";
                            eng = 1;

                            for (int i = 0; i < n->FileHeader.NumberOfSections; i++)
                            {
                                if ((s->VirtualAddress <= outrva) && (outrva < (s->VirtualAddress + s->Misc.VirtualSize))) {

                                    offsetad = (outrva - s->VirtualAddress + s->PointerToRawData);
                                    fine = (s->PointerToRawData + s->SizeOfRawData - offsetad);

                                    ///endi = (pSecHeader->PointerToRawData) + (pSecHeader->SizeOfRawData) - oepoffi;


                                    break;

                                }

                                s++;
                            }
                        }
                        else {

                            QPalette palii;
                            palii.setColor(QPalette::WindowText, Qt::red);
                            ui->label->setText("Invalid expression!");
                            ui->label->setPalette(palii);
                        }
                    }
                    else {

                        QPalette palit;
                        palit.setColor(QPalette::WindowText, Qt::red);
                        ui->label->setText("Invalid expression!");
                        ui->label->setPalette(palit);
                    }
                }
            }
            else {

                QPalette pali;
                pali.setColor(QPalette::WindowText, Qt::red);
                ui->label->setText("Invalid expression!");
                ui->label->setPalette(pali);
            }
        }
        else {

            QPalette pali;
            pali.setColor(QPalette::WindowText, Qt::red);
            ui->label->setText("Invalid expression!");
            ui->label->setPalette(pali);
        }
    }
}

QString getd() {

    QString dataz = "";
    ///ui->plainTextEdit->clear();
    if(eng == 2) {



        std::stringstream add;
        Zydis::InstructionInfo info;
        Zydis::InstructionDecoder decoder;
        Zydis::IntelInstructionFormatter formatter;
        Zydis::MemoryInput input64((unsigned char*)based + offsetad, fine);
        //Zydis::MemoryInput input64(&data64[0], sizeof(data64));
        char formt[1024] = { 0 };
        std::stringstream disi;
        /*0x00007FFA39A81930ull*/
        LONG64 entry = n->OptionalHeader.AddressOfEntryPoint;
        LONG64 addresses = 0x00007FFA39A;
        std::stringstream ad;
        ///uint64_t res;
        ad << "0x0000" << std::hex << std::uppercase << addresses << outrva;
        std::string hexadec(ad.str());

        strcpy(formt, (char*)hexadec.c_str());
        uint64_t formatting = strtoimax(hexadec.c_str(), 0, 16);

        decoder.setDisassemblerMode(Zydis::DisassemblerMode::M64BIT);
        decoder.setDataSource(&input64);
        decoder.setInstructionPointer(formatting);
        /*info.instrAddress*/
        while (decoder.decodeInstruction(info)) {
            disi << std::hex << std::setw(16) << std::setfill('0') << std::uppercase
                << info.instrAddress << "\t\t\t";
            if (info.flags & Zydis::IF_ERROR_MASK) {
                disi << "db " << std::setw(2) << static_cast<int>(info.data[0]) << std::endl;
            }
            else {
                disi << formatter.formatInstruction(info) << std::endl;
            }
        }
        dataz = QString::fromStdString(disi.str());

    }
    else if(eng == 1) {

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
        res = distorm_decode(offset, (unsigned char*)based + offsetad, fine, dt, decodedInstructions, MAX_INSTRUCTIONS, &decodedInstructionsCount);
        if (res > 0) {
            ////ui->plainTextEdit_4->appendPlainText("-Disassemblying complete.\n");
            for (i = 0; i < decodedInstructionsCount; i++) {

                sprintf(arrdis, " %0*I64x\t(%02d) %-24s\t%s%s%s\n", dt != Decode64Bits ? 8 : 16, decodedInstructions[i].offset, decodedInstructions[i].size, (char*)decodedInstructions[i].instructionHex.p, (char*)decodedInstructions[i].mnemonic.p, decodedInstructions[i].operands.length != 0 ? " " : "", (char*)decodedInstructions[i].operands.p);

                ///sprintf(arrdis, " %08x\t(%02d) %-24s\t%s%s%s\n", decodedInstructions[i].offset, decodedInstructions[i].size, (char*)decodedInstructions[i].instructionHex.p, (char*)decodedInstructions[i].mnemonic.p, decodedInstructions[i].operands.length != 0 ? " " : "", (char*)decodedInstructions[i].operands.p);
                disstr << arrdis;
            }

            dataz = QString::fromStdString(disstr.str());
            ///std::string ass = disstr.str();
           /// QScrollBar* vScrollBar = ui->plainTextEdit->verticalScrollBar();


        }
    }

    return dataz;




















}

void Expression::on_Expression_windowTitleChanged(const QString &title)
{

    std::string express = expfil.toStdString();
    int i = 0;
    HANDLE hMapObject, hFile;                        //File Mapping Object
    LPVOID lpBase;                                          //Pointer to the base memory of mapped file
    PIMAGE_DOS_HEADER dosHeader;            //Pointer to DOS Header
    PIMAGE_NT_HEADERS64 ntHeader;                     //Pointer to NT Header
    IMAGE_FILE_HEADER header;                       //Pointer to image file header of NT Header
    IMAGE_OPTIONAL_HEADER opHeader;         //Optional Header of PE files present in NT Header structure
    PIMAGE_SECTION_HEADER pSecHeader;
    hFile = CreateFileA((char*)express.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
    HANDLE hMap = CreateFileMapping(hFile, 0, PAGE_READONLY, 0, 0, 0);
    lpBase = MapViewOfFile(hMap, FILE_MAP_READ, 0, 0, 0);
    dosHeader = (PIMAGE_DOS_HEADER)lpBase;

    ntHeader = (PIMAGE_NT_HEADERS64)((LONG64)(dosHeader)+(dosHeader->e_lfanew));
    pSecHeader = (PIMAGE_SECTION_HEADER)((LONG64)ntHeader + sizeof(IMAGE_NT_HEADERS64));
    n = ntHeader;
    s = pSecHeader;
    based = lpBase;
}



void Expression::on_buttonBox_clicked(QAbstractButton *button)
{

    MainHome *m = new MainHome();
    if(button == ui->buttonBox->button(QDialogButtonBox::Ok) ) {

        ///dsmadd = getd();
        ////MainHome mainadd;



         m->show();
         m->setWindowTitle("KirbiDSMx64 - " + expfil);
         m->ui->plainTextEdit->clear();
         m->ui->plainTextEdit_3->clear();
         m->ui->plainTextEdit->appendPlainText(getd());

         QScrollBar* vScrollBar = m->ui->plainTextEdit->verticalScrollBar();

         //QScrollBar *vScrollBarhex = ui->plainTextEdit_2->verticalScrollBar();
         vScrollBar->triggerAction(QScrollBar::SliderToMinimum);

         m->ui->plainTextEdit_3->appendPlainText("RAX = 0000000000000000\n");
         m->ui->plainTextEdit_3->appendPlainText("RBX = 0000000000000000\n");
         m->ui->plainTextEdit_3->appendPlainText("RCX = 0000000000000000\n");
         m->ui->plainTextEdit_3->appendPlainText("RDX = 0000000000000000\n");
         m->ui->plainTextEdit_3->appendPlainText("RBP = 0000000000000000\n");
         m->ui->plainTextEdit_3->appendPlainText("RSP = 0000000000000000\n");
         m->ui->plainTextEdit_3->appendPlainText("RSI = 0000000000000000\n");
         m->ui->plainTextEdit_3->appendPlainText("RDI = 0000000000000000\n\n");
         m->ui->plainTextEdit_3->appendPlainText("R8 = 0000000000000000\n");
         m->ui->plainTextEdit_3->appendPlainText("R9 = 0000000000000000\n");
         m->ui->plainTextEdit_3->appendPlainText("R10 = 0000000000000000\n");
         m->ui->plainTextEdit_3->appendPlainText("R11 = 0000000000000000\n");
         m->ui->plainTextEdit_3->appendPlainText("R12 = 0000000000000000\n");
         m->ui->plainTextEdit_3->appendPlainText("R13 = 0000000000000000\n");
         m->ui->plainTextEdit_3->appendPlainText("R14 = 0000000000000000\n");
         m->ui->plainTextEdit_3->appendPlainText("R15 = 0000000000000000\n");
        /*mainadd.ui->plainTextEdit->clear();
        mainadd.ui->plainTextEdit->appendPlainText(getd());

        QScrollBar* vScrollBar = mainadd.ui->plainTextEdit->verticalScrollBar();
        //QScrollBar *vScrollBarhex = ui->plainTextEdit_2->verticalScrollBar();
        vScrollBar->triggerAction(QScrollBar::SliderToMinimum);*/
        this->close();
    }
    else if(button == ui->buttonBox->button(QDialogButtonBox::Cancel)) {

        this->close();
        m->ui->plainTextEdit->appendPlainText(disdata);
        m->ui->plainTextEdit_3->appendPlainText(regis);
        m->ui->plainTextEdit_4->appendPlainText(infos);
        m->setWindowTitle("KirbiDSMx64 - " + expfil);
        m->show();
        QScrollBar* vScrollBar1 = m->ui->plainTextEdit->verticalScrollBar();
        vScrollBar1->triggerAction(QScrollBar::SliderToMinimum);
    }
}
