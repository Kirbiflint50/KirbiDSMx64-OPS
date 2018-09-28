# KirbiDSMx64-OPS
Open Source 64 bit disassembler for Windows 

KirbiDSMx64-OPS is re-made and the code is written in C\C++ and the UI is made in Qt. In this disassembler there are some more features which one of those is the .NET Decompiler plugin that is written in C#

The idea to make an 64 disassembler it comes me because my passion of coding is always more 
good and my knowledge It is always more better I think. Another reason that i decided to make this Disassembler, 
it is that i'm inspired of x64dbg since it is a very nice debugger, then i decided to make something my own. 

## Some Screenshots

![main ui](https://preview.ibb.co/m8htRp/Kirbi_DSMx64_OPS_screen1.jpg)

![hexdump](https://preview.ibb.co/jLaNmp/Kirbi_DSMx64_OPS_hexdump.jpg)

![memorymap](https://preview.ibb.co/c4tmCU/Kirbi_DSMx64_OPS_memorymap.jpg)


## Currently it supports

.NET executables

Executables 64 bit

DLLs and some more...


## Features

Disassembler: There are 3 engines, (Distorm, Zydis, and Udis86). Opening an executable, you will be able to choose which engine you would like to use.

Hex Dump: there are 3 types of them, the first one show only hex values, the second one too, and the third one can show the hex + ascii charcters.

Memory Map: the memory map can show the PE structures(DosHeader, FileHeader, OptionalHeader).

Protection Analyzer: Detect if the executable is packed and tell which packer is.

AddressConverter + values calculator: As said the name, this feature has 2 options, can convert an adress (example from RVA to VA or vice versa), the values calculator can convert binary, hex, ascii values.

Imports Table: Show the imports of a PE if detected.

Exports Table: Show the Exports of a PE if detected.

Relocations: Show the relocations of a PE if detected.

 

Then there's the tools which allow you to add sections, import, relocation.

It's possible to save The Memory map, Imports Table into a file.


## Build mini documentation

- Qt 4.5.1 required or higher. You can download [here](https://www.qt.io/download) you can also use Visual Studio 2017 with 
QT tools
- All required libraries are included to this project

## Download 

- Build available [here](https://www89.zippyshare.com/v/TMmTAt6Z/file.html) or in [Releases](https://github.com/Kirbiflint50/KirbiDSMx64-OPS/releases)

## Credits

- Disassembler engines made by [Zydis](https://github.com/zyantific/zydis), [Distorm](https://github.com/gdabah/distorm) and [Udis86](https://github.com/vmt/udis86)
- PE Parser library by [libpe](https://github.com/evilsocket/libpe) and [pe_bliss](https://code.google.com/archive/p/portable-executable-library/)
- .NET Decompiler by [IlSpy](https://github.com/icsharpcode/ILSpy)

## Developer

- [Kirbiflint](https://github.com/Kirbiflint50)

## Thanks to

- Everyone who supported this project!
-
