#-------------------------------------------------
#
# Project created by QtCreator 2018-05-05T20:41:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = KirbiDSMx64-OPS
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS


# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainhome.cpp \
    adder.cpp \
    addressconverter.cpp \
    enteraddress.cpp \
    expression.cpp \
    hexdump1.cpp \
    hexdumpsecond.cpp \
    hexdumpthird.cpp \
    importadder.cpp \
    importstable.cpp \
    memorymap.cpp \
    protectionanalyzer.cpp \
    relocationadder.cpp \
    relocations.cpp \
    sectionsadder.cpp \
    selectsection.cpp \
    settings.cpp \
    strings.cpp \
    Zydis/ZydisAPI.cpp \
    Zydis/ZydisInstructionDecoder.cpp \
    Zydis/ZydisInstructionFormatter.cpp \
    Zydis/ZydisOpcodeTable.cpp \
    Zydis/ZydisSymbolResolver.cpp \
    Zydis/ZydisUtils.cpp \
    pe_lib/entropy.cpp \
    pe_lib/file_version_info.cpp \
    pe_lib/message_table.cpp \
    pe_lib/pe_base.cpp \
    pe_lib/pe_bound_import.cpp \
    pe_lib/pe_checksum.cpp \
    pe_lib/pe_debug.cpp \
    pe_lib/pe_directory.cpp \
    pe_lib/pe_dotnet.cpp \
    pe_lib/pe_exception.cpp \
    pe_lib/pe_exception_directory.cpp \
    pe_lib/pe_exports.cpp \
    pe_lib/pe_factory.cpp \
    pe_lib/pe_imports.cpp \
    pe_lib/pe_properties.cpp \
    pe_lib/pe_properties_generic.cpp \
    pe_lib/pe_rebuilder.cpp \
    pe_lib/pe_relocations.cpp \
    pe_lib/pe_resource_manager.cpp \
    pe_lib/pe_resource_viewer.cpp \
    pe_lib/pe_resources.cpp \
    pe_lib/pe_rich_data.cpp \
    pe_lib/pe_section.cpp \
    pe_lib/pe_tls.cpp \
    pe_lib/resource_bitmap_reader.cpp \
    pe_lib/resource_bitmap_writer.cpp \
    pe_lib/resource_cursor_icon_reader.cpp \
    pe_lib/resource_cursor_icon_writer.cpp \
    pe_lib/resource_data_info.cpp \
    pe_lib/resource_message_list_reader.cpp \
    pe_lib/resource_string_table_reader.cpp \
    pe_lib/resource_version_info_reader.cpp \
    pe_lib/resource_version_info_writer.cpp \
    pe_lib/utils.cpp \
    pe_lib/version_info_editor.cpp \
    pe_lib/version_info_viewer.cpp \
    libpe/htable.cpp \
    libpe/libpe.cpp \
    libpe/llist.cpp \
    include/decoder.c \
    include/distorm.c \
    include/instructions.c \
    include/insts.c \
    include/mnemonics.c \
    include/operands.c \
    include/prefix.c \
    include/textdefs.c \
    include/wstring.c \
    exporttable.cpp \
    libudis86/decode.c \
    libudis86/itab.c \
    libudis86/syn.c \
    libudis86/syn-att.c \
    libudis86/syn-intel.c \
    libudis86/udis86.c

HEADERS += \
        mainhome.h \
    adder.h \
    addressconverter.h \
    enteraddress.h \
    expression.h \
    hexdump1.h \
    hexdumpsecond.h \
    hexdumpthird.h \
    importadder.h \
    importstable.h \
    memorymap.h \
    relocationadder.h \
    sectionsadder.h \
    selectsection.h \
    settings.h \
    strings.h \
    protectionanalyzer.h \
    relocations.h \
    exporttable.h

FORMS += \
        mainhome.ui \
    adder.ui \
    addressconverter.ui \
    enteraddress.ui \
    expression.ui \
    hexdump1.ui \
    hexdumpsecond.ui \
    hexdumpthird.ui \
    importadder.ui \
    importstable.ui \
    mainhome.ui \
    memorymap.ui \
    protectionanalyzer.ui \
    relocationadder.ui \
    relocations.ui \
    sectionsadder.ui \
    selectsection.ui \
    settings.ui \
    strings.ui \
    exporttable.ui

RESOURCES += \
    icons.qrc


RC_ICONS = 46-512.ico
