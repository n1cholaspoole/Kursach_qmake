#ifndef SHOWINFOWINDOW_H
#define SHOWINFOWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QFile>
#include <QSortFilterProxyModel>
#include <QMessageBox>

namespace Ui {
class ShowInfoWindow;
}

class ShowInfoWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ShowInfoWindow(QWidget *parent = nullptr);
    ~ShowInfoWindow();

    void tWUpdater(QString fPath);

    void getData(QStandardItemModel *csvModel, QString fPath){
        csvModel->clear();
        csvModel->setHorizontalHeaderLabels(QStringList() << "Фамилия" << "Дата" << "Время" << "Трансфер" << "Кол-во дней" << "Цена");
        QFile file(fPath);
        if ( !file.open(QFile::ReadOnly | QFile::Text) ) {
            QMessageBox::warning(this, "File access error", "Нет доступа к файлу или файл не существует");
        } else {
            QTextStream in(&file);
            while (!in.atEnd())
            {
                QString line = in.readLine();
                QList<QStandardItem *> textData;
                for (QString item : line.split(",")) {
                    textData.append(new QStandardItem(item));
                }
                csvModel->insertRow(csvModel->rowCount(), textData);
            }

            file.close();
        }
}

signals:
    void mainWindow();

private slots:

    void on_pushButton_clicked();

private:
    Ui::ShowInfoWindow *ui;
    QStandardItemModel *csvModel;
};

#endif // SHOWINFOWINDOW_H
