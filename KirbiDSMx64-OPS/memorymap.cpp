#include "memorymap.h"
#include "ui_memorymap.h"
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
MemoryMap::MemoryMap(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MemoryMap)
{
    ui->setupUi(this);


}

MemoryMap::~MemoryMap()
{
    delete ui;

}



char *Oepnamesec(LONG64 address, PIMAGE_SECTION_HEADER sects, PIMAGE_NT_HEADERS64 ntheader) {

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

LONG64 RVAtooff(LONG64 address, PIMAGE_SECTION_HEADER sects, PIMAGE_NT_HEADERS64 ntheader) {

    LONG64 off;
    for (int i = 0; i < ntheader->FileHeader.NumberOfSections; i++)
    {
        if ((sects->VirtualAddress <= address) && (address < (sects->VirtualAddress + sects->Misc.VirtualSize))) {

            off = (address) - (sects->VirtualAddress) + (sects->PointerToRawData);

            ///endi = (pSecHeader->PointerToRawData) + (pSecHeader->SizeOfRawData) - oepoffi;


            break;

        }

        sects++;
    }

    return off;

}

bool IsdotNetApp(const char* szPath)
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

void MemoryMap::on_MemoryMap_accepted()
{


}

void MemoryMap::on_MemoryMap_windowTitleChanged(const QString &title)
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

    std::string pthf = dir.toStdString();
    int i = 0;
    HANDLE hMapObject, hFile;                        //File Mapping Object
    LPVOID lpBase;                                          //Pointer to the base memory of mapped file
    PIMAGE_DOS_HEADER dosHeader;            //Pointer to DOS Header
    PIMAGE_NT_HEADERS64 ntHeader;                     //Pointer to NT Header
    IMAGE_FILE_HEADER header;                       //Pointer to image file header of NT Header
    IMAGE_OPTIONAL_HEADER opHeader;         //Optional Header of PE files present in NT Header structure
    PIMAGE_SECTION_HEADER pSecHeader;
     ///std::string pthf = path.toStdString();


    hFile = CreateFileA((char*)pthf.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
    HANDLE hMap = CreateFileMapping(hFile, 0, PAGE_READONLY, 0, 0, 0);
    lpBase = MapViewOfFile(hMap, FILE_MAP_READ, 0, 0, 0);
    dosHeader = (PIMAGE_DOS_HEADER)lpBase;
    ntHeader = (PIMAGE_NT_HEADERS64)((LONG64)(dosHeader)+(dosHeader->e_lfanew));
    char filesize[1024] = { 0 };
    char datalength[1024] = { 0 };
    struct stat info;
    char *filename = (char*)pthf.c_str();
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

    char *secoep = Oepnamesec(ntHeader->OptionalHeader.AddressOfEntryPoint, pSecHeader, ntHeader);
    LONG64 Realoepoff = RVAtooff(ntHeader->OptionalHeader.AddressOfEntryPoint, pSecHeader, ntHeader);

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

    if(IsdotNetApp(dir.toStdString().c_str())) {

         infos << "AddressOfEntryPoint: " << OEP << " VA " << "00000000" << " Offset " << "0x" << "00000000" << " (In " << "Unknown" << ")" << "\n\n";
    }
    else {

        infos << "AddressOfEntryPoint: " << OEP << " VA " << oepva << " Offset " << "0x" << std::hex << Realoepoff << " (In " << secoep << ")" << "\n\n";

    }
    //infos << "AddressOfEntryPoint: " << OEP << " VA " << oepva << " Offset " << "0x" << std::hex << Realoepoff << " (In " << secoep << ")" << "\n";

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


    this->ui->plainTextEdit->appendPlainText(QString::fromStdString(infos.str()));


}

void MemoryMap::on_pushButton_clicked()
{

}

void MemoryMap::on_plainTextEdit_textChanged()
{

}
