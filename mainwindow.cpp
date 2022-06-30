#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("\"TurManage\" Workstation");

    sWindow = new ShowInfoWindow();
    aWindow = new AddInfoWindow();
    cWindow = new ChangeInfoWindow();
    rWindow = new RemoveInfoWindow();

    connect(sWindow, &ShowInfoWindow::mainWindow, this, &MainWindow::show);
    connect(aWindow, &AddInfoWindow::mainWindow, this, &MainWindow::show);
    connect(cWindow, &ChangeInfoWindow::mainWindow, this, &MainWindow::show);
    connect(rWindow, &RemoveInfoWindow::mainWindow, this, &MainWindow::show);
    connect(this, &MainWindow::sendFPath, sWindow, &ShowInfoWindow::tWUpdater);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete sWindow;
    delete aWindow;
    delete rWindow;
}

void MainWindow::on_pushButton_clicked()
{
    sWindow->show();
    this->close();
    getPath();
    ui->statusbar->showMessage("");
}


void MainWindow::on_pushButton_2_clicked()
{
    aWindow->show();
    this->close();
    ui->statusbar->showMessage("");
}


void MainWindow::on_pushButton_4_clicked()
{
    rWindow->show();
    this->close();
    ui->statusbar->showMessage("");
}

void MainWindow::getPath(){

    QFile file("fPath.tmp");
    if ( !file.open(QFile::ReadOnly | QFile::Text) ) {
            QMessageBox::warning(this, "File access error", "Нет доступа к файлу или файл не существует");
    } else {
        QTextStream in(&file);
        QString fPath = in.readLine();
        file.close();
        emit sendFPath(fPath);
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    QString fPath = QFileDialog::getOpenFileName(this, tr("Выберите файл"), "/table", tr("Images (*.csv)"));
    QFile file("fPath.tmp");
    if ( !file.open(QFile::WriteOnly | QFile::Text) ) {
            QMessageBox::warning(this, "File access error", "Нет доступа к файлу или файл не существует");
    } else {
        QTextStream out(&file);
        out << fPath;
        file.close();
        ui->statusbar->showMessage("Файл добавлен");
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    cWindow->show();
    this->close();
    ui->statusbar->showMessage("");
}

