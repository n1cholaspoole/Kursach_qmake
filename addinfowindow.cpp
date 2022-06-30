#include "addinfowindow.h"
#include "ui_addinfowindow.h"

AddInfoWindow::AddInfoWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddInfoWindow)
{
    ui->setupUi(this);

    setWindowTitle("\"TurManage\" Workstation");


    csvModel = new QStandardItemModel(1, 6, this);
    csvModel->setHorizontalHeaderLabels(QStringList() << "Фамилия" << "Дата" << "Время" << "Трансфер" << "Кол-во дней" << "Цена");
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setModel(csvModel);
}

AddInfoWindow::~AddInfoWindow()
{
    delete ui;
    delete csvModel;
}


void AddInfoWindow::on_BackBtn_clicked()
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


void AddInfoWindow::on_OKBtn_clicked()
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
        textData += "\n";
    }

    QFile pathfile("fPath.tmp");
    if ( !pathfile.open(QFile::ReadOnly | QFile::Text) ) {
            QMessageBox::warning(this, "File access error", "Нет доступа к файлу или файл не существует");
    } else {
        QTextStream in(&pathfile);
        QString fPath = in.readLine();
        pathfile.close();

        QFile file(fPath);
        if ( !file.open(QFile::WriteOnly | QFile::Text | QIODevice::Append) ) {
            QMessageBox::warning(this, "File access error", "Нет доступа к файлу или файл не существует");
        } else {
            QTextStream out(&file);
            out << textData;
            file.close();
            ui->statusbar->showMessage("Данные добавлены");
        }
    }
}
