#ifndef CHANGEINFOWINDOW_H
#define CHANGEINFOWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>

namespace Ui {
class ChangeInfoWindow;
}

class ChangeInfoWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChangeInfoWindow(QWidget *parent = nullptr);
    ~ChangeInfoWindow();

signals:
    void mainWindow();

private slots:
    void on_OKBtn_clicked();

    void on_BackBtn_clicked();

private:
    Ui::ChangeInfoWindow *ui;
    QStandardItemModel *csvModel;
};

#endif // CHANGEINFOWINDOW_H
