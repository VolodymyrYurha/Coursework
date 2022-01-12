#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include "weather.h"
//using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

//Головний інтерфейсний клас для вікна з основними функціями
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionOpen_triggered();

    void on_pushButton_task1_clicked();

    void on_actionSort_triggered();

    void on_actionReverse_triggered();

    void on_pushButton_task2_clicked();

    void on_pushButton_task3_clicked();

    void on_pushButton_find4_clicked();

    void on_pushButton_find5_clicked();

    void on_pushButton_find7_clicked();

    void on_pushButton_draw6_clicked();

    void on_pushButton_create_clicked();

    void on_actionSave_to_file_triggered();

private:
    Ui::MainWindow *ui;

    int COLUMNCOUNT = 7;

    std::vector<Weather> weatherVector;

//void operator>>(string filePath, vector<Weather>&myarr);

};
#endif // MAINWINDOW_H
