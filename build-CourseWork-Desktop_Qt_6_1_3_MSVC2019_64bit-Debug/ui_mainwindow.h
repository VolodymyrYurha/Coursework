/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionSort;
    QAction *actionReverse;
    QAction *actionSave_to_file;
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QTableWidget *tableWidget;
    QToolBox *toolBox;
    QWidget *page;
    QPushButton *pushButton_task1;
    QSpinBox *spinBox_year1;
    QSpinBox *spinBox_month1;
    QLabel *label;
    QLabel *label_2;
    QPlainTextEdit *plainTextEdit_task1result;
    QWidget *page_2;
    QPlainTextEdit *plainTextEdit_task2result;
    QPushButton *pushButton_task2;
    QWidget *page_3;
    QPushButton *pushButton_task3;
    QPlainTextEdit *plainTextEdit_task3result;
    QWidget *page_4;
    QLabel *label_3;
    QLabel *label_4;
    QSpinBox *spinBox_from4;
    QSpinBox *spinBox_to4;
    QLabel *label_5;
    QPlainTextEdit *plainTextEdit_temperature4;
    QPlainTextEdit *plainTextEdit_humidity4;
    QPushButton *pushButton_find4;
    QWidget *page_5;
    QLabel *label_6;
    QLabel *label_7;
    QDoubleSpinBox *doubleSpinBox_pressure5;
    QDoubleSpinBox *doubleSpinBox_temperature5;
    QPlainTextEdit *plainTextEdit_task5result;
    QPushButton *pushButton_find5;
    QWidget *page_6;
    QLabel *label_10;
    QPushButton *pushButton_draw6;
    QSpinBox *spinBox_year6;
    QLabel *label_18;
    QWidget *page_7;
    QSpinBox *spinBox_month7;
    QLabel *label_8;
    QLabel *label_9;
    QSpinBox *spinBox_year7;
    QPushButton *pushButton_find7;
    QPlainTextEdit *plainTextEdit_task7result;
    QWidget *tab_2;
    QCustomPlot *plotTemperature;
    QCustomPlot *plotPressure;
    QCustomPlot *plotHumidity;
    QWidget *tab_3;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QSpinBox *spinBox_yearCreate;
    QSpinBox *spinBox_monthCreate;
    QSpinBox *spinBox_dayCreate;
    QDoubleSpinBox *doubleSpinBox_temperatureCreate;
    QDoubleSpinBox *doubleSpinBox_pressureCreate;
    QDoubleSpinBox *doubleSpinBox_humidityCreate;
    QLabel *label_17;
    QPlainTextEdit *plainTextEdit_windCreate;
    QPushButton *pushButton_create;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(947, 700);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionSort = new QAction(MainWindow);
        actionSort->setObjectName(QString::fromUtf8("actionSort"));
        actionReverse = new QAction(MainWindow);
        actionReverse->setObjectName(QString::fromUtf8("actionReverse"));
        actionSave_to_file = new QAction(MainWindow);
        actionSave_to_file->setObjectName(QString::fromUtf8("actionSave_to_file"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 20, 881, 631));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tab->setAutoFillBackground(false);
        tableWidget = new QTableWidget(tab);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 9, 571, 550));
        toolBox = new QToolBox(tab);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        toolBox->setGeometry(QRect(590, 10, 271, 541));
        toolBox->setMouseTracking(true);
        toolBox->setTabletTracking(true);
        toolBox->setAcceptDrops(true);
        toolBox->setToolTipDuration(1);
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setGeometry(QRect(0, 0, 271, 338));
        page->setMouseTracking(true);
        page->setTabletTracking(true);
        page->setContextMenuPolicy(Qt::CustomContextMenu);
        page->setAcceptDrops(true);
#if QT_CONFIG(tooltip)
        page->setToolTip(QString::fromUtf8(""));
#endif // QT_CONFIG(tooltip)
        page->setToolTipDuration(1);
        page->setStyleSheet(QString::fromUtf8(""));
        page->setInputMethodHints(Qt::ImhNone);
        pushButton_task1 = new QPushButton(page);
        pushButton_task1->setObjectName(QString::fromUtf8("pushButton_task1"));
        pushButton_task1->setGeometry(QRect(0, 120, 261, 61));
        spinBox_year1 = new QSpinBox(page);
        spinBox_year1->setObjectName(QString::fromUtf8("spinBox_year1"));
        spinBox_year1->setGeometry(QRect(130, 20, 131, 41));
        spinBox_year1->setMinimum(2000);
        spinBox_year1->setMaximum(2021);
        spinBox_year1->setValue(2021);
        spinBox_month1 = new QSpinBox(page);
        spinBox_month1->setObjectName(QString::fromUtf8("spinBox_month1"));
        spinBox_month1->setGeometry(QRect(130, 70, 131, 41));
        spinBox_month1->setMinimum(1);
        spinBox_month1->setMaximum(12);
        label = new QLabel(page);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 101, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Calibri")});
        font.setPointSize(14);
        font.setItalic(true);
        label->setFont(font);
        label_2 = new QLabel(page);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 70, 111, 41));
        label_2->setFont(font);
        plainTextEdit_task1result = new QPlainTextEdit(page);
        plainTextEdit_task1result->setObjectName(QString::fromUtf8("plainTextEdit_task1result"));
        plainTextEdit_task1result->setGeometry(QRect(0, 190, 261, 41));
        toolBox->addItem(page, QString::fromUtf8("Task 1"));
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        page_2->setGeometry(QRect(0, 0, 271, 338));
        plainTextEdit_task2result = new QPlainTextEdit(page_2);
        plainTextEdit_task2result->setObjectName(QString::fromUtf8("plainTextEdit_task2result"));
        plainTextEdit_task2result->setGeometry(QRect(0, 0, 271, 241));
        pushButton_task2 = new QPushButton(page_2);
        pushButton_task2->setObjectName(QString::fromUtf8("pushButton_task2"));
        pushButton_task2->setGeometry(QRect(0, 250, 271, 51));
        toolBox->addItem(page_2, QString::fromUtf8("Task 2"));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        page_3->setGeometry(QRect(0, 0, 271, 338));
        pushButton_task3 = new QPushButton(page_3);
        pushButton_task3->setObjectName(QString::fromUtf8("pushButton_task3"));
        pushButton_task3->setGeometry(QRect(0, 250, 271, 51));
        plainTextEdit_task3result = new QPlainTextEdit(page_3);
        plainTextEdit_task3result->setObjectName(QString::fromUtf8("plainTextEdit_task3result"));
        plainTextEdit_task3result->setGeometry(QRect(0, 0, 271, 241));
        toolBox->addItem(page_3, QString::fromUtf8("Task 3"));
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        page_4->setGeometry(QRect(0, 0, 271, 338));
        label_3 = new QLabel(page_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 30, 141, 51));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Calibri")});
        font1.setPointSize(10);
        font1.setItalic(true);
        label_3->setFont(font1);
        label_4 = new QLabel(page_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 90, 111, 51));
        label_4->setFont(font1);
        spinBox_from4 = new QSpinBox(page_4);
        spinBox_from4->setObjectName(QString::fromUtf8("spinBox_from4"));
        spinBox_from4->setGeometry(QRect(180, 40, 71, 41));
        spinBox_from4->setMinimum(1);
        spinBox_to4 = new QSpinBox(page_4);
        spinBox_to4->setObjectName(QString::fromUtf8("spinBox_to4"));
        spinBox_to4->setGeometry(QRect(180, 100, 71, 41));
        spinBox_to4->setMinimum(1);
        spinBox_to4->setValue(2);
        label_5 = new QLabel(page_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(100, -10, 61, 51));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Calibri")});
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setItalic(false);
        label_5->setFont(font2);
        plainTextEdit_temperature4 = new QPlainTextEdit(page_4);
        plainTextEdit_temperature4->setObjectName(QString::fromUtf8("plainTextEdit_temperature4"));
        plainTextEdit_temperature4->setGeometry(QRect(10, 160, 241, 31));
        plainTextEdit_humidity4 = new QPlainTextEdit(page_4);
        plainTextEdit_humidity4->setObjectName(QString::fromUtf8("plainTextEdit_humidity4"));
        plainTextEdit_humidity4->setGeometry(QRect(10, 210, 241, 85));
        pushButton_find4 = new QPushButton(page_4);
        pushButton_find4->setObjectName(QString::fromUtf8("pushButton_find4"));
        pushButton_find4->setGeometry(QRect(10, 304, 241, 31));
        toolBox->addItem(page_4, QString::fromUtf8("Task 4"));
        page_5 = new QWidget();
        page_5->setObjectName(QString::fromUtf8("page_5"));
        page_5->setGeometry(QRect(0, 0, 271, 338));
        label_6 = new QLabel(page_5);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 10, 141, 41));
        label_6->setFont(font1);
        label_7 = new QLabel(page_5);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 60, 141, 41));
        label_7->setFont(font1);
        doubleSpinBox_pressure5 = new QDoubleSpinBox(page_5);
        doubleSpinBox_pressure5->setObjectName(QString::fromUtf8("doubleSpinBox_pressure5"));
        doubleSpinBox_pressure5->setGeometry(QRect(180, 10, 71, 41));
        doubleSpinBox_pressure5->setValue(1.430000000000000);
        doubleSpinBox_temperature5 = new QDoubleSpinBox(page_5);
        doubleSpinBox_temperature5->setObjectName(QString::fromUtf8("doubleSpinBox_temperature5"));
        doubleSpinBox_temperature5->setGeometry(QRect(180, 60, 71, 41));
        doubleSpinBox_temperature5->setDecimals(3);
        doubleSpinBox_temperature5->setValue(5.673000000000000);
        plainTextEdit_task5result = new QPlainTextEdit(page_5);
        plainTextEdit_task5result->setObjectName(QString::fromUtf8("plainTextEdit_task5result"));
        plainTextEdit_task5result->setGeometry(QRect(10, 120, 241, 141));
        pushButton_find5 = new QPushButton(page_5);
        pushButton_find5->setObjectName(QString::fromUtf8("pushButton_find5"));
        pushButton_find5->setGeometry(QRect(10, 270, 241, 51));
        toolBox->addItem(page_5, QString::fromUtf8("Task 5"));
        page_6 = new QWidget();
        page_6->setObjectName(QString::fromUtf8("page_6"));
        page_6->setGeometry(QRect(0, 0, 271, 338));
        label_10 = new QLabel(page_6);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(20, 20, 61, 41));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Calibri")});
        font3.setPointSize(10);
        font3.setBold(false);
        font3.setItalic(true);
        label_10->setFont(font3);
        pushButton_draw6 = new QPushButton(page_6);
        pushButton_draw6->setObjectName(QString::fromUtf8("pushButton_draw6"));
        pushButton_draw6->setGeometry(QRect(10, 90, 241, 51));
        spinBox_year6 = new QSpinBox(page_6);
        spinBox_year6->setObjectName(QString::fromUtf8("spinBox_year6"));
        spinBox_year6->setGeometry(QRect(170, 20, 81, 41));
        spinBox_year6->setMinimum(2000);
        spinBox_year6->setMaximum(2021);
        spinBox_year6->setValue(2021);
        label_18 = new QLabel(page_6);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(120, 150, 131, 21));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Calibri")});
        font4.setPointSize(8);
        font4.setBold(false);
        font4.setItalic(false);
        label_18->setFont(font4);
        toolBox->addItem(page_6, QString::fromUtf8("Task 6"));
        page_7 = new QWidget();
        page_7->setObjectName(QString::fromUtf8("page_7"));
        page_7->setGeometry(QRect(0, 0, 271, 338));
        spinBox_month7 = new QSpinBox(page_7);
        spinBox_month7->setObjectName(QString::fromUtf8("spinBox_month7"));
        spinBox_month7->setGeometry(QRect(190, 80, 71, 31));
        spinBox_month7->setMinimum(1);
        spinBox_month7->setMaximum(12);
        label_8 = new QLabel(page_7);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 10, 171, 51));
        label_8->setFont(font1);
        label_9 = new QLabel(page_7);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 70, 151, 51));
        label_9->setFont(font1);
        spinBox_year7 = new QSpinBox(page_7);
        spinBox_year7->setObjectName(QString::fromUtf8("spinBox_year7"));
        spinBox_year7->setGeometry(QRect(190, 20, 71, 31));
        spinBox_year7->setMinimum(2000);
        spinBox_year7->setMaximum(2021);
        spinBox_year7->setValue(2021);
        pushButton_find7 = new QPushButton(page_7);
        pushButton_find7->setObjectName(QString::fromUtf8("pushButton_find7"));
        pushButton_find7->setGeometry(QRect(10, 280, 251, 51));
        plainTextEdit_task7result = new QPlainTextEdit(page_7);
        plainTextEdit_task7result->setObjectName(QString::fromUtf8("plainTextEdit_task7result"));
        plainTextEdit_task7result->setGeometry(QRect(10, 140, 251, 131));
        toolBox->addItem(page_7, QString::fromUtf8("Task 7"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        plotTemperature = new QCustomPlot(tab_2);
        plotTemperature->setObjectName(QString::fromUtf8("plotTemperature"));
        plotTemperature->setGeometry(QRect(20, 20, 840, 180));
        plotTemperature->setLocale(QLocale(QLocale::Ukrainian, QLocale::Ukraine));
        plotPressure = new QCustomPlot(tab_2);
        plotPressure->setObjectName(QString::fromUtf8("plotPressure"));
        plotPressure->setGeometry(QRect(20, 210, 840, 180));
        plotHumidity = new QCustomPlot(tab_2);
        plotHumidity->setObjectName(QString::fromUtf8("plotHumidity"));
        plotHumidity->setGeometry(QRect(20, 400, 841, 180));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        label_11 = new QLabel(tab_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(10, 40, 121, 41));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Calibri")});
        font5.setPointSize(12);
        font5.setBold(true);
        font5.setItalic(true);
        label_11->setFont(font5);
        label_12 = new QLabel(tab_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(330, 40, 121, 41));
        label_12->setFont(font5);
        label_13 = new QLabel(tab_3);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(630, 40, 121, 41));
        label_13->setFont(font5);
        label_14 = new QLabel(tab_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(330, 100, 141, 61));
        label_14->setFont(font5);
        label_15 = new QLabel(tab_3);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(10, 100, 151, 61));
        label_15->setFont(font5);
        label_16 = new QLabel(tab_3);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(630, 100, 121, 61));
        label_16->setFont(font5);
        spinBox_yearCreate = new QSpinBox(tab_3);
        spinBox_yearCreate->setObjectName(QString::fromUtf8("spinBox_yearCreate"));
        spinBox_yearCreate->setGeometry(QRect(190, 40, 91, 41));
        spinBox_yearCreate->setMinimum(2000);
        spinBox_yearCreate->setMaximum(2021);
        spinBox_yearCreate->setValue(2021);
        spinBox_monthCreate = new QSpinBox(tab_3);
        spinBox_monthCreate->setObjectName(QString::fromUtf8("spinBox_monthCreate"));
        spinBox_monthCreate->setGeometry(QRect(500, 40, 91, 41));
        spinBox_monthCreate->setMinimum(1);
        spinBox_monthCreate->setMaximum(12);
        spinBox_dayCreate = new QSpinBox(tab_3);
        spinBox_dayCreate->setObjectName(QString::fromUtf8("spinBox_dayCreate"));
        spinBox_dayCreate->setGeometry(QRect(760, 40, 91, 41));
        spinBox_dayCreate->setMinimum(1);
        spinBox_dayCreate->setMaximum(31);
        doubleSpinBox_temperatureCreate = new QDoubleSpinBox(tab_3);
        doubleSpinBox_temperatureCreate->setObjectName(QString::fromUtf8("doubleSpinBox_temperatureCreate"));
        doubleSpinBox_temperatureCreate->setGeometry(QRect(190, 110, 91, 41));
        doubleSpinBox_temperatureCreate->setMinimum(-20.000000000000000);
        doubleSpinBox_temperatureCreate->setMaximum(40.000000000000000);
        doubleSpinBox_temperatureCreate->setValue(10.000000000000000);
        doubleSpinBox_pressureCreate = new QDoubleSpinBox(tab_3);
        doubleSpinBox_pressureCreate->setObjectName(QString::fromUtf8("doubleSpinBox_pressureCreate"));
        doubleSpinBox_pressureCreate->setGeometry(QRect(500, 110, 91, 41));
        doubleSpinBox_pressureCreate->setMaximum(1500.000000000000000);
        doubleSpinBox_pressureCreate->setValue(1013.000000000000000);
        doubleSpinBox_humidityCreate = new QDoubleSpinBox(tab_3);
        doubleSpinBox_humidityCreate->setObjectName(QString::fromUtf8("doubleSpinBox_humidityCreate"));
        doubleSpinBox_humidityCreate->setGeometry(QRect(760, 110, 91, 41));
        doubleSpinBox_humidityCreate->setMaximum(100.000000000000000);
        doubleSpinBox_humidityCreate->setValue(60.000000000000000);
        label_17 = new QLabel(tab_3);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(10, 190, 141, 51));
        label_17->setFont(font5);
        plainTextEdit_windCreate = new QPlainTextEdit(tab_3);
        plainTextEdit_windCreate->setObjectName(QString::fromUtf8("plainTextEdit_windCreate"));
        plainTextEdit_windCreate->setGeometry(QRect(190, 200, 131, 41));
        pushButton_create = new QPushButton(tab_3);
        pushButton_create->setObjectName(QString::fromUtf8("pushButton_create"));
        pushButton_create->setGeometry(QRect(560, 260, 291, 71));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Calibri")});
        font6.setPointSize(12);
        font6.setBold(true);
        pushButton_create->setFont(font6);
        tabWidget->addTab(tab_3, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 947, 25));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave_to_file);
        menuEdit->addAction(actionSort);
        menuEdit->addAction(actionReverse);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        toolBox->setCurrentIndex(0);
        toolBox->layout()->setSpacing(5);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Sinoptik", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        actionSort->setText(QCoreApplication::translate("MainWindow", "Sort", nullptr));
#if QT_CONFIG(tooltip)
        actionSort->setToolTip(QCoreApplication::translate("MainWindow", "Sort", nullptr));
#endif // QT_CONFIG(tooltip)
        actionReverse->setText(QCoreApplication::translate("MainWindow", "Reverse", nullptr));
#if QT_CONFIG(tooltip)
        actionReverse->setToolTip(QCoreApplication::translate("MainWindow", "Reverse", nullptr));
#endif // QT_CONFIG(tooltip)
        actionSave_to_file->setText(QCoreApplication::translate("MainWindow", "Save to file", nullptr));
#if QT_CONFIG(tooltip)
        toolBox->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        toolBox->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(whatsthis)
        toolBox->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        pushButton_task1->setText(QCoreApplication::translate("MainWindow", "Find average humidity", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Year:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Month:", nullptr));
        toolBox->setItemText(toolBox->indexOf(page), QCoreApplication::translate("MainWindow", "Task 1", nullptr));
#if QT_CONFIG(tooltip)
        toolBox->setItemToolTip(toolBox->indexOf(page), QCoreApplication::translate("MainWindow", "Finding average humidity", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        page_2->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        pushButton_task2->setText(QCoreApplication::translate("MainWindow", "Find", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_2), QCoreApplication::translate("MainWindow", "Task 2", nullptr));
#if QT_CONFIG(tooltip)
        toolBox->setItemToolTip(toolBox->indexOf(page_2), QCoreApplication::translate("MainWindow", "Finding the hottest and wettest days at the same time", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_task3->setText(QCoreApplication::translate("MainWindow", "Find", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_3), QCoreApplication::translate("MainWindow", "Task 3", nullptr));
#if QT_CONFIG(tooltip)
        toolBox->setItemToolTip(toolBox->indexOf(page_3), QCoreApplication::translate("MainWindow", "Finding period when wind directions doesn't change", nullptr));
#endif // QT_CONFIG(tooltip)
        label_3->setText(QCoreApplication::translate("MainWindow", "From this position:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "To this position:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Period:", nullptr));
        plainTextEdit_temperature4->setPlainText(QCoreApplication::translate("MainWindow", "Average temperature:", nullptr));
        plainTextEdit_humidity4->setPlainText(QCoreApplication::translate("MainWindow", "Wettest days:", nullptr));
        pushButton_find4->setText(QCoreApplication::translate("MainWindow", "Find", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_4), QCoreApplication::translate("MainWindow", "Task 4", nullptr));
#if QT_CONFIG(tooltip)
        toolBox->setItemToolTip(toolBox->indexOf(page_4), QCoreApplication::translate("MainWindow", "In entered period finds average temperature and wettest days", nullptr));
#endif // QT_CONFIG(tooltip)
        label_6->setText(QCoreApplication::translate("MainWindow", "Pressure +-%", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Temperature +-%", nullptr));
        plainTextEdit_task5result->setPlainText(QCoreApplication::translate("MainWindow", "Period", nullptr));
        pushButton_find5->setText(QCoreApplication::translate("MainWindow", "Find", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_5), QCoreApplication::translate("MainWindow", "Task 5", nullptr));
#if QT_CONFIG(tooltip)
        toolBox->setItemToolTip(toolBox->indexOf(page_5), QCoreApplication::translate("MainWindow", "Finding period when pressure and temperature changed in some range", nullptr));
#endif // QT_CONFIG(tooltip)
        label_10->setText(QCoreApplication::translate("MainWindow", "Year:", nullptr));
        pushButton_draw6->setText(QCoreApplication::translate("MainWindow", "Draw plot", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "*plots are in plots tab.", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_6), QCoreApplication::translate("MainWindow", "Task 6", nullptr));
#if QT_CONFIG(tooltip)
        toolBox->setItemToolTip(toolBox->indexOf(page_6), QCoreApplication::translate("MainWindow", "drawing Temperature, Pressure and Humidity plots (plots are in Plots tab)", nullptr));
#endif // QT_CONFIG(tooltip)
        label_8->setText(QCoreApplication::translate("MainWindow", "Year", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Previous month", nullptr));
        pushButton_find7->setText(QCoreApplication::translate("MainWindow", "Forecast weather", nullptr));
        plainTextEdit_task7result->setPlainText(QCoreApplication::translate("MainWindow", "Forecast\n"
"", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_7), QCoreApplication::translate("MainWindow", "Task 7", nullptr));
#if QT_CONFIG(tooltip)
        toolBox->setItemToolTip(toolBox->indexOf(page_7), QCoreApplication::translate("MainWindow", "Forecast the weather for the next month taking into account the change of the season of the year.", nullptr));
#endif // QT_CONFIG(tooltip)
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Table and tasks", nullptr));
#if QT_CONFIG(tooltip)
        tabWidget->setTabToolTip(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "main table and necessary functions", nullptr));
#endif // QT_CONFIG(tooltip)
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Plots", nullptr));
#if QT_CONFIG(tooltip)
        tabWidget->setTabToolTip(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "plots drawing tab", nullptr));
#endif // QT_CONFIG(tooltip)
        label_11->setText(QCoreApplication::translate("MainWindow", "Year:", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Month:", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Day:", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Pressure hPA:", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Temperature \302\260C:", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Humidity %:", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "Wind direction:", nullptr));
        plainTextEdit_windCreate->setPlainText(QCoreApplication::translate("MainWindow", "NorthEast", nullptr));
        pushButton_create->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "Create", nullptr));
#if QT_CONFIG(tooltip)
        tabWidget->setTabToolTip(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "Creating a new weather item", nullptr));
#endif // QT_CONFIG(tooltip)
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
