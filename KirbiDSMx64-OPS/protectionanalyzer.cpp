#include "protectionanalyzer.h"
#include "ui_protectionanalyzer.h"

ProtectionAnalyzer::ProtectionAnalyzer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProtectionAnalyzer)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
}

ProtectionAnalyzer::~ProtectionAnalyzer()
{
    delete ui;
}

void ProtectionAnalyzer::on_ProtectionAnalyzer_windowTitleChanged(const QString &title)
{
    ui->lineEdit->setText("Ready to scan!");
}

void ProtectionAnalyzer::on_pushButton_clicked()
{
    int contatore = 0;

            if (sections.contains(".bind"))
            {
                ui->lineEdit->setText("Steam Stub detected!");
                contatore = 1;
            }
            if (sections.contains(".aspack"))
            {
                ui->lineEdit->setText("Aspack detected!");
                contatore = 1;
            }
            if (sections.contains(".version"))
            {
                ui->lineEdit->setText("Steam CEG detected!");
                contatore = 1;
            }
            if (sections.contains(".adata"))
            {
                ui->lineEdit->setText("Aspack detected!");
                contatore = 1;
            }
            if (sections.contains(".ASPack"))
            {
                ui->lineEdit->setText("Aspack detected!");
                contatore = 1;
            }
            if (sections.contains(".boom"))
            {
                ui->lineEdit->setText("Boomerang List Builder detected!");
                contatore = 1;
            }
            if (sections.contains(".ccg"))
            {
                ui->lineEdit->setText("CCG Packer detected!");
                contatore = 1;
            }
            if (sections.contains("BitArts"))
            {
                ui->lineEdit->setText("Crunch 2.0 Packer detected!");
                contatore = 1;
            }
            if (sections.contains("DAStub"))
            {
                ui->lineEdit->setText("Dragon Armor detected!");
                contatore = 1;
            }
            if (sections.contains("!EPack"))
            {
                ui->lineEdit->setText("Epack packer detected!");
                contatore = 1;
            }
            if (sections.contains(".gentee"))
            {
                ui->lineEdit->setText("Gentee detected!");
                contatore = 1;
            }
            if (sections.contains("kkrunchy"))
            {
                ui->lineEdit->setText("kkrunchy Packer detected!");
                contatore = 1;
            }
            if (sections.contains(".MaskPE"))
            {
                ui->lineEdit->setText("MaskPE detected!");
                contatore = 1;
            }
            if (sections.contains("MEW"))
            {
                ui->lineEdit->setText("MEW detected!");
                contatore = 1;
            }
            if (sections.contains(".MPRESS1"))
            {
                ui->lineEdit->setText("MPRESS detected!");
                contatore = 1;
            }
            if (sections.contains(".MPRESS2"))
            {
                ui->lineEdit->setText("MPRESS detected!");
                contatore = 1;
            }
            if (sections.contains(".neolite"))
            {
                ui->lineEdit->setText("Neolite detected!");
                contatore = 1;
            }
            if (sections.contains(".neolit"))
            {
                ui->lineEdit->setText("Neolit detected!");
                contatore = 1;
            }
            if (sections.contains(".nsp1"))
            {
                ui->lineEdit->setText("NsPack detected!");
                contatore = 1;
            }
            if (sections.contains(".nsp0"))
            {
                ui->lineEdit->setText("NsPack detected!");
                contatore = 1;
            }
            if (sections.contains(".nsp2"))
            {
                ui->lineEdit->setText("NsPack detected!");
                contatore = 1;
            }
            if (sections.contains(".packed"))
            {
                ui->lineEdit->setText("RLPack detected!");
                contatore = 1;
            }
            if (sections.contains("pebundle"))
            {
                ui->lineEdit->setText("PEBundle detected!");
                contatore = 1;
            }
            if (sections.contains("PEBundle"))
            {
                ui->lineEdit->setText("PEBundle detected!");
                contatore = 1;
            }
            if (sections.contains("PEC2TO"))
            {
                ui->lineEdit->setText("PECompact detected!");
                contatore = 1;
            }
            if (sections.contains("PEC2"))
            {
                ui->lineEdit->setText("PECompact detected!");
                contatore = 1;
            }
            if (sections.contains("pec1"))
            {
                ui->lineEdit->setText("PECompact detected!");
                contatore = 1;
            }
            if (sections.contains("pec2"))
            {
                ui->lineEdit->setText("PECompact detected!");
                contatore = 1;
            }
            if (sections.contains("PEC2MO"))
            {
                ui->lineEdit->setText("PECompact detected!");
                contatore = 1;
            }
            if (sections.contains("PELOCKnt"))
            {
                ui->lineEdit->setText("PELock detected!");
                contatore = 1;
            }
            if (sections.contains(".perplex"))
            {
                ui->lineEdit->setText("Perplex PE Protector detected!");
                contatore = 1;
            }
            if (sections.contains("PESHiELD"))
            {
                ui->lineEdit->setText("PEShield detected!");
                contatore = 1;
            }
            if (sections.contains(".petite"))
            {
                ui->lineEdit->setText("Petite detected!");
                contatore = 1;
            }
            if (sections.contains("ProCrypt"))
            {
                ui->lineEdit->setText("ProCrypt detected!");
                contatore = 1;
            }
            if (sections.contains(".RLPack"))
            {
                ui->lineEdit->setText("RLPack detected!");
                contatore = 1;
            }
            if (sections.contains(".rmnet"))
            {
                ui->lineEdit->setText("Ramnit virus detected!");
                contatore = 1;
            }
            if (sections.contains("RCryptor"))
            {
                ui->lineEdit->setText("RPCrypt detected!");
                contatore = 1;
            }
            if (sections.contains(".RPCrypt"))
            {
                ui->lineEdit->setText("RPCrypt detected!");
                contatore = 1;
            }
            if (sections.contains(".seau"))
            {
                ui->lineEdit->setText("SeauSFX detected!");
                contatore = 1;
            }
            if (sections.contains(".sforce3"))
            {
                ui->lineEdit->setText("StarForce Protection detected!");
                contatore = 1;
            }
            if (sections.contains(".svkp"))
            {
                ui->lineEdit->setText("SVKP detected!");
                contatore = 1;
            }
            if (sections.contains("Themida"))
            {
                ui->lineEdit->setText("Themida detected!");
                contatore = 1;
            }
            if (sections.contains(".Themida"))
            {
                ui->lineEdit->setText("Themida detected!");
                contatore = 1;
            }
            if (sections.contains(".taz"))
            {
                ui->lineEdit->setText("PESpin detected!");
                contatore = 1;
            }
            if (sections.contains(".tsuarch"))
            {
                ui->lineEdit->setText("TSULoader detected!");
                contatore = 1;
            }
            if (sections.contains(".tsustub"))
            {
                ui->lineEdit->setText("TSULoader detected!");
                contatore = 1;
            }
            if (sections.contains(".packed"))
            {
                ui->lineEdit->setText("Unknown Packer!");
                contatore = 1;
            }
            if (sections.contains("PEPACK!!"))
            {
                ui->lineEdit->setText("Pepack detected!");
                contatore = 1;
            }
            if (sections.contains(".Upack"))
            {
                ui->lineEdit->setText("Upack detected!");
                contatore = 1;
            }
            if (sections.contains(".ByDwing"))
            {
                ui->lineEdit->setText("Upack detected!");
                contatore = 1;
            }
            if (sections.contains("UPX0"))
            {
                ui->lineEdit->setText("UPX detected!");
                contatore = 1;
            }
            if (sections.contains("UPX1"))
            {
                ui->lineEdit->setText("UPX detected!");
                contatore = 1;
            }
            if (sections.contains("UPX2"))
            {
                ui->lineEdit->setText("UPX detected!");
                contatore = 1;
            }
            if (sections.contains("UPX!"))
            {
                ui->lineEdit->setText("UPX detected!");
                contatore = 1;
            }
            if (sections.contains(".UPX0"))
            {
                ui->lineEdit->setText("UPX Packer!");
                contatore = 1;
            }
            if (sections.contains(".UPX1"))
            {
                ui->lineEdit->setText("UPX detected!");
                contatore = 1;
            }
            if (sections.contains(".UPX2"))
            {
                ui->lineEdit->setText("UPX detected!");
                contatore = 1;
            }
            if (sections.contains(".vmp0"))
            {
                ui->lineEdit->setText("VMProtect detected!");
                contatore = 1;
            }
            if (sections.contains(".vmp1"))
            {
                ui->lineEdit->setText("VMProtect detected!");
                contatore = 1;
            }
            if (sections.contains(".vmp2"))
            {
                ui->lineEdit->setText("VMProtect detected!");
                contatore = 1;
            }
            if (sections.contains("VProtect"))
            {
                ui->lineEdit->setText("Vprotect detected!");
                contatore = 1;
            }
            if (sections.contains("WinLicen"))
            {
                ui->lineEdit->setText("WinLicense (Themida) detected!");
                contatore = 1;
            }
            if (sections.contains("_winzip_"))
            {
                ui->lineEdit->setText("WinZip Self-Extractor Packer!");
                contatore = 1;
            }
            if (sections.contains(".WWPACK"))
            {
                ui->lineEdit->setText("WWPACK detected!");
                contatore = 1;
            }
            if (sections.contains(".yP"))
            {
                ui->lineEdit->setText("Y0da Protector detected!");
                contatore = 1;
            }
            if (sections.contains(".y0da"))
            {
                ui->lineEdit->setText("Y0da Protector detected");
                contatore = 1;
            }

            switch (contatore) {

            case 0:
                ui->lineEdit->setText("No protection found!");
                break;



            }
}
