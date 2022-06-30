#include "removeinfowindow.h"
#include "ui_removeinfowindow.h"

RemoveInfoWindow::RemoveInfoWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RemoveInfoWindow)
{
    ui->setupUi(this);

    setWindowTitle("\"TurManage\" Workstation");
}

RemoveInfoWindow::~RemoveInfoWindow()
{
    delete ui;
}


void RemoveInfoWindow::on_pushButton_2_clicked()
{
    this->close();
    emit mainWindow();
    ui->statusbar->showMessage("");
    ui->lineEdit->clear();
}

void RemoveInfoWindow::on_pushButton_3_clicked()
{
    QFile pathfile("fPath.tmp");
    if ( !pathfile.open(QFile::ReadOnly | QFile::Text) ) {
            QMessageBox::warning(this, "File access error", "Нет доступа к файлу или файл не существует");
    } else {
        QTextStream in(&pathfile);
        QString fPath = in.readLine();
        pathfile.close();

        QFile file(fPath);
        if ( !file.open(QFile::WriteOnly | QFile::Text) ) {
            QMessageBox::warning(this, "File access error", "Нет доступа к файлу или файл не существует");
        } else {
            file.close();
            ui->statusbar->showMessage("Данные удалены");
        }
    }
}

void RemoveInfoWindow::on_pushButton_clicked()
{

    QFile pathfile("fPath.tmp");
    if ( !pathfile.open(QFile::ReadOnly | QFile::Text) ) {
            QMessageBox::warning(this, "File access error", "Нет доступа к файлу или файл не существует");
    } else {
        QTextStream in(&pathfile);
        QString fPath = in.readLine();
        pathfile.close();

        QFile file(fPath);
        if ( !file.open(QFile::ReadOnly | QFile::Text) ) {
            QMessageBox::warning(this, "File access error", "Нет доступа к файлу или файл не существует");
        } else {

        int removableLine = ui->lineEdit->text().toInt() - 1;
        QList<QString> lst;
        QTextStream in(&file);
        lst = in.readAll().split("\n");
        lst.remove(removableLine);
        file.close();

        QFile file(fPath);
        if ( !file.open(QFile::WriteOnly | QFile::Text) ) {
            QMessageBox::warning(this, "File access error", "Нет доступа к файлу или файл не существует");
        } else {

    QTextStream out(&file);
    QString result;
    for (int i = 0; i < lst.size(); ++i)
    {
        result += lst.at(i) + QString("\n");
    }
        result.chop(2);
            out << result << "\n";
            file.close();
            ui->statusbar->showMessage("Данные удалены");
}}}}
