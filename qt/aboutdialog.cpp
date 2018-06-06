#include "aboutdialog.h"
#include "ui_aboutdialog.h"

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);
    ui->blablabla->setOpenExternalLinks(true);
    ui->blablabla->setHtml("<center><p><h3>Médocs</h3></b>\
<p>Pour en savoir plus sur cette application et rechercher des mises-à-jours de la base de données:\
<center><a href=\"http://medocs.drx.tn\" target=\"_blank\">http://medocs.drx.tn</a></center></p>");
}
