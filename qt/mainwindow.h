#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QtSql>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void on_recherche(const QString &arg1);
    void on_affiche_la_fiche(const QModelIndex &index, QModelIndex);
    void A_Propos();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QSqlQueryModel *model;
    QSortFilterProxyModel *proxyModel;
};

#endif // MAINWINDOW_H
