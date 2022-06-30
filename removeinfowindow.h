#ifndef REMOVEINFOWINDOW_H
#define REMOVEINFOWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>

namespace Ui {
class RemoveInfoWindow;
}

class RemoveInfoWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit RemoveInfoWindow(QWidget *parent = nullptr);
    ~RemoveInfoWindow();

signals:
    void mainWindow();

private slots:

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

private:
    Ui::RemoveInfoWindow *ui;
};

#endif // REMOVEINFOWINDOW_H
