#include "mainwindow.h"
#include "aboutdialog.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionA_Propos, &QAction::triggered, this, &MainWindow::A_Propos);
    connect(ui->actionQuitter, &QAction::triggered, this, &MainWindow::close);
    QString dpmBase = QCoreApplication::applicationDirPath()+QDir::separator()+"dpm.db";
    if(!QFile::exists(dpmBase)){
        QMessageBox::critical(this, "Erreur", "Le fichier dpm.db n'a pas été retrouvé dans le dossier de l'application.");
    } else {
        if (!QSqlDatabase::drivers().contains("QSQLITE")) {
            QMessageBox::critical(this, "Erreur", "Le driver SQLite n'a pas été retrouvé.");
        } else {
            db = QSqlDatabase::addDatabase("QSQLITE");
            db.setDatabaseName(dpmBase);
            if (!db.open()) {
                QMessageBox::critical(this, "Erreur", "Erreur lors de l'ouverture de la base de données.");
            } else {
                model = new QSqlQueryModel(this);
                model->setQuery(QString("SELECT (specialite || \" \" || dosage || \" \" || forme || \" \" || presentation) \
AS Spécialité, dci as DCI, dosage, (classe || \": \" || sousclasse) AS Classe, tableau, indication, laboratoire, amm, dateamm, \
conditionnement, specification, conservation from medocs"), db);
                if (model->lastError().isValid()) {
                    QMessageBox::critical(this, "Erreur", "Erreur lors de la lecture de la base de données.");
                } else {
                    while(model->canFetchMore()) model->fetchMore();
                    proxyModel = new QSortFilterProxyModel(this);
                    proxyModel->setSourceModel(model);
                    proxyModel->sort(0, Qt::AscendingOrder);
                    proxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
                    proxyModel->setFilterKeyColumn(-1);
                    ui->listeTable->setModel(proxyModel);
                    connect(ui->searchEdit, &QLineEdit::textChanged, this, &MainWindow::on_recherche);
                    connect(ui->listeTable->selectionModel(), &QItemSelectionModel::currentChanged, this, &MainWindow::on_affiche_la_fiche);
                    for (int i=4; i< ui->listeTable->model()->columnCount(); i++) ui->listeTable->setColumnHidden(i, true);
                    ui->listeTable->show();
                }
            }
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_recherche(const QString &medoc)
{
    proxyModel->setFilterFixedString(medoc);
}

void MainWindow::on_affiche_la_fiche(const QModelIndex &index, QModelIndex)
{
    if (index.isValid()) {
        int row = index.row();
        ui->ficheHTML->setHtml(\
        "<p><b>Spécialité:</b> "\
        +index.sibling(row, 0).data().toString()+"</p>"\
        "<p><b>DCI:</b> "\
        +index.sibling(row, 1).data().toString()+"</p>"\
        "<p><b>Dosage:</b> "\
        +index.sibling(row, 2).data().toString()+"</p>"\
        "<p><b>Classe Thérapeutique:</b> "\
        +index.sibling(row, 3).data().toString()+"</p>"\
        "<p><b>Tableau:</b> "\
        +index.sibling(row, 4).data().toString()+"</p>"\
        "<p><b>Indication:</b> "\
        +index.sibling(row, 5).data().toString()+"</p>"\
        "<p><b>Laboratoire:</b> "\
        +index.sibling(row, 6).data().toString()+\
        "<p><b>AMM:</b> "\
        +index.sibling(row, 7).data().toString()+\
        "<p><b>Date de l'AMM:</b> "\
        +index.sibling(row, 8).data().toString()+"</p>"\
        "<p><b>Conditionnement:</b> "\
        +index.sibling(row, 9).data().toString()+\
        "<p><b>Specification:</b> "\
        +index.sibling(row, 10).data().toString()+\
        "<p><b>Conservation:</b> "\
        +index.sibling(row, 11).data().toString()+"</p>"\
        );
    }
}

void MainWindow::A_Propos()
{
    AboutDialog *aboutDialog = new AboutDialog(this);
    aboutDialog->show();
}
