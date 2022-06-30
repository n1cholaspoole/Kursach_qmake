#include "changeinfowindow.h"
#include "ui_changeinfowindow.h"

ChangeInfoWindow::ChangeInfoWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChangeInfoWindow)
{
    ui->setupUi(this);

    setWindowTitle("\"TurManage\" Workstation");

    csvModel = new QStandardItemModel(1, 6, this);
    csvModel->setHorizontalHeaderLabels(QStringList() << "Фамилия" << "Дата" << "Время" << "Трансфер" << "Кол-во дней" << "Цена");
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setModel(csvModel);
}

ChangeInfoWindow::~ChangeInfoWindow()
{
    delete ui;
    delete csvModel;
}

void ChangeInfoWindow::on_OKBtn_clicked()
{
    QString textData;
    int rows = csvModel->rowCount();
    int columns = csvModel->columnCount();

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {

                textData += csvModel->data(csvModel->index(i,j)).toString();
                textData += ",";
        }
        textData.chop(1);
    }

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

        int changeableLine = ui->lineEdit->text().toInt() - 1;
        QList<QString> lst;
        QTextStream in(&file);
        lst = in.readAll().split("\n");
        lst[changeableLine] = textData;
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
            ui->statusbar->showMessage("Данные изменены");
}}}}


void ChangeInfoWindow::on_BackBtn_clicked()
{
    this->close();
    emit mainWindow();
    csvModel->clear();
    csvModel = new QStandardItemModel(1, 6, this);
    csvModel->setHorizontalHeaderLabels(QStringList() << "Фамилия" << "Дата" << "Время" << "Трансфер" << "Кол-во дней" << "Цена");
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setModel(csvModel);
    ui->statusbar->showMessage("");
}
