#ifndef ADDINFOWINDOW_H
#define ADDINFOWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QFile>
#include <QMessageBox>

using namespace std;
namespace Ui {
class AddInfoWindow;

}

class AddInfoWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddInfoWindow(QWidget *parent = nullptr);
    ~AddInfoWindow();

signals:
    void mainWindow();

private slots:

    void on_BackBtn_clicked();

    void on_OKBtn_clicked();

private:
    Ui::AddInfoWindow *ui;
    QStandardItemModel *csvModel;
};

#endif // ADDINFOWINDOW_H
