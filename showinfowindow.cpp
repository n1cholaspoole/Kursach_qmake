#include "showinfowindow.h"
#include "ui_showinfowindow.h"


ShowInfoWindow::ShowInfoWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ShowInfoWindow)
{
    ui->setupUi(this);

    setWindowTitle("\"TurManage\" Workstation");

    csvModel = new QStandardItemModel(this);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setSortingEnabled(true);
    ui->tableView->setModel(csvModel);
}

void ShowInfoWindow::tWUpdater(QString fPath){
     getData(csvModel, fPath);
}

ShowInfoWindow::~ShowInfoWindow()
{
    delete ui;
    delete csvModel;
}


void ShowInfoWindow::on_pushButton_clicked()
{
    this->close();
    emit mainWindow();
    ui->statusbar->showMessage("");
}
