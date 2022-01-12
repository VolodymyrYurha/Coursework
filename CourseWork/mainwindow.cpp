#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "weather.h"
#include <iostream>
#include <stdio.h>
#include <QString>
#include <string.h>
#include <fstream>
#include <sstream>

#include <QMessageBox>

#include <QFileDialog>
//#include <fileapi.h>
//#include <stringstream>
//#include <system>
//#include <vector>

//using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(COLUMNCOUNT);
    //ui->tableWidget->setRowCount(1);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Year" << "Mounth" << "Day" << "Temperature" << "Pressure" << "Humidity" << "Wind dir.");
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

std::vector<Weather> weatherVector;
bool isSortedVector = false;


//Перевизначені оператори зчитування з та запису у файл
void operator>>(std::string filePath, std::vector<Weather>&weatherVec){
        std::ifstream file;

        file.exceptions(std::ifstream::badbit | std::ifstream::failbit);
        bool isOpen=false;

        try{
        file.open(filePath);
        isOpen=true;


        while(!file.eof()){
            //Subscription mySubscription;
            //Person person;
            //std::string subscriptionType;

            std::string line;
            std::getline(file, line);
            if(line == ""){
                continue;
            }
            std::stringstream strstream(line);
            std::vector<std::string> tokenVect;
            std::string token;
            while(std::getline(strstream, token, ' ')){
                //RemoveSpaces(token);
                tokenVect.push_back(token);

            }
//            if(tokenVect.size() != 5){
//                throw std::runtime_error("The input data isn't correct!");
//                return;
//            }
//            if(!tokenVect.empty()){
//                if(tokenVect[4].size() > 10 || tokenVect[4].size() < 8 || tokenVect[4].size() == 9){
//                    throw std::runtime_error("The duration is incorrect!");
//                    return;
//                }
//            }
            Weather wthItem(stoi(tokenVect[0]),stoi(tokenVect[1]),stoi(tokenVect[2]),stod(tokenVect[3]),stod(tokenVect[4]),stod(tokenVect[5]),tokenVect[6]);
            //string str ="hi";
            //Weather wthItem(1,2,3,4.0,5.0,6.0,str);
            weatherVec.push_back(wthItem);
        }
        }
        catch(const std::ifstream::failure & ex){
            if(!isOpen) QMessageBox::warning(NULL,"File", "Problem with file opening!\n"+QString::fromStdString(ex.what()));
        }
        catch(...){
            QMessageBox::critical(NULL,"File", "Problem with file data!");
            weatherVector.clear();


        }
}


void operator<<(std::string filePath, std::vector<Weather>&weatherVector){

    QFile file(filePath.c_str());
          if(file.open(QIODevice::WriteOnly | QIODevice::Text))
          {
                QTextStream stream(&file);
              QString strYear, strMonth, strDay, strTemperature, strPressure, strHumidity, strWind;
              for(int i=0; i<weatherVector.size(); i++){


                  strYear=QString::number(weatherVector[i].getYear());
                  strMonth=QString::number(weatherVector[i].getMonth());
                  strDay=QString::number(weatherVector[i].getDay());

                  strTemperature=QString::number(weatherVector[i].getTemperature());
                  strPressure=QString::number(weatherVector[i].getPressure());
                  strHumidity=QString::number(weatherVector[i].getHumidity());

                  strWind=QString::fromStdString(weatherVector[i].getWindDirection());
                  stream<<strYear+' '+strMonth+' '+strDay+' '+strTemperature+' '+strPressure+' '+strHumidity+' '+strWind+'\n';
            }
              file.close();
          }


}

MainWindow::~MainWindow()
{
    delete ui;
}

//кнопка відкриття файлу
void MainWindow::on_actionOpen_triggered()
{
    weatherVector.clear();

    std::string filePath = (QFileDialog::getOpenFileName(this,"Open file to read", "D://QT//Projects//ASD//CourseWork//weatherData")).toStdString();

    filePath>>weatherVector;

    int row=weatherVector.size();
    ui->tableWidget->setRowCount(row);

    for(int i=0; i<row; i++){
        QTableWidgetItem *item = new QTableWidgetItem(QString::number(weatherVector[i].getYear()));//YEAR
        ui->tableWidget->setItem(i,0,item);

        //item = new QTableWidgetItem(QString::number(weatherVector[i].getMonth()));//MONTH
        item = new QTableWidgetItem(weatherVector[i].convertMonthToQStr());
        ui->tableWidget->setItem(i,1,item);

        item = new QTableWidgetItem(QString::number(weatherVector[i].getDay()));//DAY
        ui->tableWidget->setItem(i,2,item);

        item = new QTableWidgetItem(QString::number(weatherVector[i].getTemperature()) + " °C");//TEMPERATURE
        ui->tableWidget->setItem(i,3,item);

        item = new QTableWidgetItem(QString::number(weatherVector[i].getPressure()) + " hPA");//PRESSURE
        ui->tableWidget->setItem(i,4,item);

        item = new QTableWidgetItem(QString::number(weatherVector[i].getHumidity()) + " %");//HUMIDITY
        ui->tableWidget->setItem(i,5,item);

        item = new QTableWidgetItem(QString::fromStdString(weatherVector[i].getWindDirection()));//WIND DIRECTION
        ui->tableWidget->setItem(i,6,item);
    }
}

//кнопка зберігання у файл
void MainWindow::on_actionSave_to_file_triggered()
{

    //try{
    std::string filePath = (QFileDialog::getOpenFileName(this,"Open file to save", "D://QT//Projects//ASD//CourseWork//weatherData")).toStdString();
    //QFile file(file_name);
    //file.open(QIODevice::ReadOnly);

    filePath<<weatherVector;

    QMessageBox::information(this,"Saving", "Saved successfully!");
}



void MainWindow::on_pushButton_task1_clicked()//Пощук середньої вологості
{
    int tYear=ui->spinBox_year1->value();
    int tMonth=ui->spinBox_month1->value();

    double Sum=0;
    int count=0;
    bool exist=false;
    for(int i=0; i<weatherVector.size(); i++){
        //якщо потрібний місяць та рік то додаємо температуру до суми і збільшуємо лічильник
        if( (weatherVector[i].getYear() == tYear) && (weatherVector[i].getMonth() == tMonth) ){
            Sum+=weatherVector[i].getHumidity();
            count++;
            if(!exist) exist = true;
        }
    }

    if(exist) ui->plainTextEdit_task1result->setPlainText("Finded:\t" + QString::number(Sum/count) + " %");
    else ui->plainTextEdit_task1result->setPlainText("There are no data for this month");
}


void MainWindow::on_actionSort_triggered()//кнопка сортування
{
    sort(weatherVector.begin(), weatherVector.end());
    isSortedVector=true;

    //обновленя таблиці
    for(int i=0; i<weatherVector.size(); i++){
        QTableWidgetItem *item = new QTableWidgetItem(QString::number(weatherVector[i].getYear()));//YEAR
        ui->tableWidget->setItem(i,0,item);

        item = new QTableWidgetItem(weatherVector[i].convertMonthToQStr());
        ui->tableWidget->setItem(i,1,item);

        item = new QTableWidgetItem(QString::number(weatherVector[i].getDay()));//DAY
        ui->tableWidget->setItem(i,2,item);

        item = new QTableWidgetItem(QString::number(weatherVector[i].getTemperature()) + " °C");//TEMPERATURE
        ui->tableWidget->setItem(i,3,item);

        item = new QTableWidgetItem(QString::number(weatherVector[i].getPressure()) + " hPA");//PRESSURE
        ui->tableWidget->setItem(i,4,item);

        item = new QTableWidgetItem(QString::number(weatherVector[i].getHumidity()) + " %");//HUMIDITY
        ui->tableWidget->setItem(i,5,item);

        item = new QTableWidgetItem(QString::fromStdString(weatherVector[i].getWindDirection()));//WIND DIRECTION
        ui->tableWidget->setItem(i,6,item);
    }

    //weatherVector.
}



void MainWindow::on_actionReverse_triggered()//кнопка розвертання таблиці
{
    reverse(weatherVector.begin(), weatherVector.end());
    if(isSortedVector) isSortedVector=false;
    else isSortedVector=true;

    for(int i=0; i<weatherVector.size(); i++){
        QTableWidgetItem *item = new QTableWidgetItem(QString::number(weatherVector[i].getYear()));//YEAR
        ui->tableWidget->setItem(i,0,item);

        //item = new QTableWidgetItem(QString::number(weatherVector[i].getMonth()));//MONTH
        item = new QTableWidgetItem(weatherVector[i].convertMonthToQStr());
        ui->tableWidget->setItem(i,1,item);

        item = new QTableWidgetItem(QString::number(weatherVector[i].getDay()));//DAY
        ui->tableWidget->setItem(i,2,item);

        item = new QTableWidgetItem(QString::number(weatherVector[i].getTemperature()) + " °C");//TEMPERATURE
        ui->tableWidget->setItem(i,3,item);

        item = new QTableWidgetItem(QString::number(weatherVector[i].getPressure()) + " hPA");//PRESSURE
        ui->tableWidget->setItem(i,4,item);

        item = new QTableWidgetItem(QString::number(weatherVector[i].getHumidity()) + " %");//HUMIDITY
        ui->tableWidget->setItem(i,5,item);

        item = new QTableWidgetItem(QString::fromStdString(weatherVector[i].getWindDirection()));//WIND DIRECTION
        ui->tableWidget->setItem(i,6,item);
    }
}


void MainWindow::on_pushButton_task2_clicked()//пошук дня з максимальною температурою та мінімальним тиском
{
    double temperatureMax = weatherVector[0].getTemperature();
    double pressureMin=weatherVector[0].getPressure();

    //Finding numbers

    for(int i=0; i<weatherVector.size(); i++){
        if(weatherVector[i].getTemperature()>temperatureMax) temperatureMax = weatherVector[i].getTemperature();
        if(weatherVector[i].getPressure()<pressureMin) pressureMin = weatherVector[i].getPressure();
    }

    ui->plainTextEdit_task2result->setPlainText("Max. temperature:\t" + QString::number(temperatureMax) + " °C\nMin. pressure:\t\t" + QString::number(pressureMin) + " hPA\n");
    ui->plainTextEdit_task2result->moveCursor(QTextCursor::End);
    //Finding this days
    bool findedOnce = false;
    for(int i=0; i<weatherVector.size(); i++){
        if(weatherVector[i].getTemperature()==temperatureMax && weatherVector[i].getPressure()==pressureMin){
            if(!findedOnce){
                ui->plainTextEdit_task2result->insertPlainText("Existing date:\n");
                findedOnce=true;
            }
            ui->plainTextEdit_task2result->insertPlainText("[" + QString::number(weatherVector[i].getYear())+'.'+QString::number(weatherVector[i].getMonth())+'.'+QString::number(weatherVector[i].getDay())+"]\n");
            ui->plainTextEdit_task2result->moveCursor(QTextCursor::End);
        }
    }
    if(!findedOnce) ui->plainTextEdit_task2result->insertPlainText("There are no date with Max. temperature and Min. pressure");
}


void MainWindow::on_pushButton_task3_clicked()//пошук періоду коли вітер не міняв напрямок
{
    if(isSortedVector){
    //ui->plainTextEdit_task3result
    ui->plainTextEdit_task3result->clear();
    int nowDay = 0;
    bool existConsistentDays=false;
    bool existNeedDays=false;
    for(int i=1; i<weatherVector.size(); i++){
        if(weatherVector[i].timeLineDay()==weatherVector[i-1].timeLineDay()+1){//перевіряєм чи два дні послідовні
            existConsistentDays=true;
            if(weatherVector[i].getWindDirection()==weatherVector[i-1].getWindDirection()){//перевіряємо чи ці дні мають однаковий напрям вітру
                if(!existNeedDays){
                    existNeedDays=true;
                    ui->plainTextEdit_task3result->insertPlainText("Finded same wind! ("+ QString::fromStdString(weatherVector[i-1].getWindDirection())+ ")\nThis date:\n[" + QString::number(weatherVector[i-1].getYear())+'.'+QString::number(weatherVector[i-1].getMonth())+'.'+QString::number(weatherVector[i-1].getDay())+"]\n");
                    ui->plainTextEdit_task3result->moveCursor(QTextCursor::End);
                }
                ui->plainTextEdit_task3result->insertPlainText("[" + QString::number(weatherVector[i].getYear())+'.'+QString::number(weatherVector[i].getMonth())+'.'+QString::number(weatherVector[i].getDay())+"]\n");
                ui->plainTextEdit_task3result->moveCursor(QTextCursor::End);
            }
        }
    }
    if(!existNeedDays) ui->plainTextEdit_task3result->setPlainText("There are no one same winds");
    if(!existConsistentDays) ui->plainTextEdit_task3result->setPlainText("There are no cosistent days");
    }
    else ui->plainTextEdit_task3result->setPlainText("This task need a sorted input vector.\nPlease sort by date!\n");
}


void MainWindow::on_pushButton_find4_clicked()//пошук середньої температури та днів з максимальною вологістю
{
    int pos_from, pos_to;
    pos_from=ui->spinBox_from4->value()-1;
    pos_to=ui->spinBox_to4->value()-1;

    double tempSum=0, maxHumidity=0;
    int tempCount=pos_to-pos_from+1;
    for(int i=pos_from; i<pos_to; i++){
        tempSum+=weatherVector[i].getTemperature();
        //tempCount++;
        if(weatherVector[i].getHumidity()>maxHumidity) maxHumidity=weatherVector[i].getHumidity();
    }

    ui->plainTextEdit_temperature4->setPlainText("Finded av. Temperature: " + QString::number(tempSum/tempCount) + " °C");
    //пошук УСІХ днів з максимальною вологістю
    ui->plainTextEdit_humidity4->setPlainText("Finded, date:\n");
    for(int i=pos_from; i<pos_to; i++){
        if(weatherVector[i].getHumidity()==maxHumidity){
            ui->plainTextEdit_humidity4->moveCursor(QTextCursor::End);
            ui->plainTextEdit_humidity4->insertPlainText(weatherVector[i].dateToQStr()+" with:\t" + QString::number(maxHumidity) + " %;\n");
        }
    }
}


void MainWindow::on_pushButton_find5_clicked()//пошук періоду коли тиск та температура мінялись на певну кількість відсотків
{
    int findedPeriod=false;

    double perPressure, perTemperature;
    perPressure=ui->doubleSpinBox_pressure5->value()/100;
    perTemperature=ui->doubleSpinBox_temperature5->value()/100;

    double prevPressure, prevTemperature;
    prevPressure=weatherVector[0].getPressure();
    prevTemperature=weatherVector[0].getTemperature();

    for(int i=1; i<weatherVector.size(); i++){
        int curPressure, curTemperature;
        curPressure = weatherVector[i].getPressure();
        curTemperature=weatherVector[i].getTemperature();
        //Необхідна умова
        if( (curPressure>(1-perPressure)*prevPressure && curPressure<(1+perPressure)*prevPressure) && (curTemperature>(1-perTemperature )*prevTemperature && curTemperature<(1+perTemperature)*prevTemperature) && (weatherVector[i-1].timeLineDay()==weatherVector[i].timeLineDay()-1)){
            if(!findedPeriod){
                findedPeriod=true;
                ui->plainTextEdit_task5result->setPlainText("Finded period!\nDate:\n" + weatherVector[i-1].dateToQStr() + ";\n");
            }
            ui->plainTextEdit_task5result->moveCursor(QTextCursor::End);
            ui->plainTextEdit_task5result->insertPlainText(weatherVector[i].dateToQStr() + ";\n");

        }

            prevPressure=curPressure;
            prevTemperature=curTemperature;
     }
    if(!findedPeriod) ui->plainTextEdit_task5result->setPlainText("There are not this period in table");
}

//прогноз погоди
//якщо місяць від серпня до січня то температура зменшується на 4.3 градуси, тиск збільшується на 1% а вологість на 10%
//якщо ж місяць в інших межах то температура буде збільшуватись на 5 градусів, а тиск та вологість зменшуватись на 2% та 20% відповідно
void MainWindow::on_pushButton_find7_clicked()
{
    bool exist=false;

    int yearToFind,monthToFind;
    yearToFind=ui->spinBox_year7->value();
    monthToFind=ui->spinBox_month7->value();

    for(int i=0; i<weatherVector.size(); i++){
        if(weatherVector[i].getMonth()==monthToFind && weatherVector[i].getYear()==yearToFind){
            if(!exist) exist=true;
            ui->plainTextEdit_task7result->setPlainText("Finded!\n");
            //month from Sep to March
            if(monthToFind>7||monthToFind<2){
                ui->plainTextEdit_task7result->moveCursor(QTextCursor::End);
                ui->plainTextEdit_task7result->insertPlainText("Forecast for month №"+QString::number(weatherVector[i].getMonth()+1)+"\n");
                ui->plainTextEdit_task7result->moveCursor(QTextCursor::End);
                // v1 ui->plainTextEdit_task7result->insertPlainText("Temperature:\t"+QString::number(weatherVector[i].getTemperature()*0.65)+" °C\n");
                ui->plainTextEdit_task7result->insertPlainText("Temperature:\t"+QString::number(weatherVector[i].getTemperature()-4.3)+" °C\n");
                ui->plainTextEdit_task7result->moveCursor(QTextCursor::End);
                ui->plainTextEdit_task7result->insertPlainText("Pressure:\t"+QString::number(weatherVector[i].getPressure()*1.01)+" hPA\n");
                ui->plainTextEdit_task7result->moveCursor(QTextCursor::End);
                ui->plainTextEdit_task7result->insertPlainText("Humidity:\t"+QString::number(weatherVector[i].getHumidity()*1.1)+" %\n");
            }
            else{
                ui->plainTextEdit_task7result->moveCursor(QTextCursor::End);
                ui->plainTextEdit_task7result->insertPlainText("Forecast for month №"+QString::number(weatherVector[i].getMonth()+1)+"\n");
                ui->plainTextEdit_task7result->moveCursor(QTextCursor::End);
                //ui->plainTextEdit_task7result->insertPlainText("Temperature:\t"+QString::number(weatherVector[i].getTemperature()*1.4)+" °C\n");
                ui->plainTextEdit_task7result->insertPlainText("Temperature:\t"+QString::number(weatherVector[i].getTemperature()+5)+" °C\n");
                ui->plainTextEdit_task7result->moveCursor(QTextCursor::End);
                ui->plainTextEdit_task7result->insertPlainText("Pressure:\t"+QString::number(weatherVector[i].getPressure()*0.98)+" hPA\n");
                ui->plainTextEdit_task7result->moveCursor(QTextCursor::End);
                ui->plainTextEdit_task7result->insertPlainText("Humidity:\t"+QString::number(weatherVector[i].getHumidity()*0.8)+" %\n");
            }

            break;
        }

    }
    if(!exist) ui->plainTextEdit_task7result->setPlainText("This month doesn't exist");
}



bool createdRow=false;
//кнопка для малювання графіків
void MainWindow::on_pushButton_draw6_clicked()
{

    QVector<double> y1,y2,y3;
    QVector<double> x;

    ui->plotTemperature->clearItems();
    ui->plotPressure->clearItems();
    ui->plotHumidity->clearItems();

    ui->plotTemperature->xAxis->setRange(1,12);
    ui->plotPressure->xAxis->setRange(1,12);
    ui->plotHumidity->xAxis->setRange(1,12);

    double minP,maxP,minT,maxT,minH,maxH;
    minP=weatherVector[0].getPressure();
    minT=weatherVector[0].getTemperature();
    minH=weatherVector[0].getHumidity();

    maxP=minP;
    maxT=minT;
    maxH=minH;


    //ui->plotTemperature->yAxis->setRange(0,100);

    //ui->plotTemperature->plotLayout()->clear();
    if(!createdRow){
        createdRow=true;
        ui->plotTemperature->plotLayout()->insertRow(0);
        ui->plotHumidity->plotLayout()->insertRow(0);
        ui->plotPressure->plotLayout()->insertRow(0);

        ui->plotTemperature->plotLayout()->addElement(0, 0, new QCPTextElement(ui->plotTemperature, "Temperature", QFont("sans", 12, QFont::Bold)));
        ui->plotHumidity->plotLayout()->addElement(0, 0, new QCPTextElement(ui->plotHumidity, "Humidity", QFont("sans", 12, QFont::Bold)));
        ui->plotPressure->plotLayout()->addElement(0, 0, new QCPTextElement(ui->plotPressure, "Pressure", QFont("sans", 12, QFont::Bold)));
    }


    ui->plotTemperature->xAxis->setLabel("Month (number)");
    ui->plotTemperature->yAxis->setLabel("Temperature (°C)");

    ui->plotPressure->xAxis->setLabel("Month (number)");
    ui->plotPressure->yAxis->setLabel("Temperature (hPA)");

    ui->plotHumidity->xAxis->setLabel("Month (number)");
    ui->plotHumidity->yAxis->setLabel("Temperature (%)");
    //ui->plotTemperature->xAxis->set


    int needYear=ui->spinBox_year6->value();

    for(int i=0; i<weatherVector.size(); i++){
        if(weatherVector[i].getYear()==needYear){
            y1.push_back(weatherVector[i].getTemperature());
            y2.push_back(weatherVector[i].getPressure());
            y3.push_back(weatherVector[i].getHumidity());
            x.push_back(weatherVector[i].getMonth() + 1/(365/12.0)*weatherVector[i].getDay());

            if(weatherVector[i].getHumidity()>maxH) maxH=weatherVector[i].getHumidity();
            if(weatherVector[i].getHumidity()<minH) minH=weatherVector[i].getHumidity();

            if(weatherVector[i].getTemperature()>maxT) maxT=weatherVector[i].getTemperature();
            if(weatherVector[i].getTemperature()<minT) minT=weatherVector[i].getTemperature();

            if(weatherVector[i].getPressure()>maxP) maxP=weatherVector[i].getPressure();
            if(weatherVector[i].getPressure()<minP) minP=weatherVector[i].getPressure();
        }
    }

    ui->plotTemperature->yAxis->setRange(minT-abs(minT*0.1),maxT+abs(maxT*0.1));
    ui->plotPressure->yAxis->setRange(minP-abs(minP*0.1),maxP+abs(maxP*0.1));
    ui->plotHumidity->yAxis->setRange(minH-abs(minH*0.1),maxH+abs(maxH*0.1));



    ui->plotTemperature->addGraph();
    ui->plotTemperature->graph(0)->setData(x,y1);
    ui->plotTemperature->replot();

    ui->plotPressure->addGraph();
    ui->plotPressure->graph(0)->setData(x,y2);
    ui->plotPressure->replot();

    ui->plotHumidity->addGraph();
    ui->plotHumidity->graph(0)->setData(x,y3);
    ui->plotHumidity->replot();


    //ui->plotTemperature->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
}


//функція для перевірки коректності даних для створення (присутня перевірка на 30 лютого)
bool checkCreatingData(int month, int day, std::string windDirection){
    if(month==1||month==3||month==5||month==7||month==8||month==10||month==12){
        if(day>31){
            throw std::exception("incorrect day (>31)!");
            return false;
        }
    }
    else if(month == 2 && day>28){
        throw std::exception("incorrect day on Fabruary! (only 28 days)");
        return false;
    }
    else if((month==4||month==6||month==9||month==11)&& (day>30)){
        throw std::exception("incorrect day (only 30 days exist in this month)");
        return false;
    }

    if( !(windDirection=="North" || windDirection=="NorthEast" || windDirection=="NorthWest" || windDirection=="South" || windDirection=="SouthEast" || windDirection=="SouthWest" ||windDirection=="West" || windDirection=="East")){
        throw std::exception("incorrect wind directions");
        return false;
    }
    return true;
}

//кнопка створення нового обєкту погоди
void MainWindow::on_pushButton_create_clicked()
{
    int year,month,day;
    double temperature, pressure, humidity;
    std::string windDir;

    year=ui->spinBox_yearCreate->value();
    month=ui->spinBox_monthCreate->value();
    day=ui->spinBox_dayCreate->value();

    temperature=ui->doubleSpinBox_temperatureCreate->value();
    pressure=ui->doubleSpinBox_pressureCreate->value();
    humidity=ui->doubleSpinBox_humidityCreate->value();

    windDir= ui->plainTextEdit_windCreate->toPlainText().toStdString();

    bool isOk=false;
    try {
        isOk = checkCreatingData(month,day,windDir);
    }  catch (const std::exception &ex) {
        QMessageBox::critical(this,"Data", QString::fromStdString( ex.what() ));
    }

    if(isOk){
        Weather newWeather(year, month, day, temperature, pressure, humidity, windDir);
        weatherVector.push_back(newWeather);

        ui->tableWidget->setRowCount(weatherVector.size());

        int i = weatherVector.size()-1;

        QTableWidgetItem *item = new QTableWidgetItem(QString::number(weatherVector[i].getYear()));//YEAR
        ui->tableWidget->setItem(i,0,item);

        //item = new QTableWidgetItem(QString::number(weatherVector[i].getMonth()));//MONTH
        item = new QTableWidgetItem(weatherVector[i].convertMonthToQStr());
        ui->tableWidget->setItem(i,1,item);

        item = new QTableWidgetItem(QString::number(weatherVector[i].getDay()));//DAY
        ui->tableWidget->setItem(i,2,item);

        item = new QTableWidgetItem(QString::number(weatherVector[i].getTemperature()) + " °C");//TEMPERATURE
        ui->tableWidget->setItem(i,3,item);

        item = new QTableWidgetItem(QString::number(weatherVector[i].getPressure()) + " hPA");//PRESSURE
        ui->tableWidget->setItem(i,4,item);

        item = new QTableWidgetItem(QString::number(weatherVector[i].getHumidity()) + " %");//HUMIDITY
        ui->tableWidget->setItem(i,5,item);

        item = new QTableWidgetItem(QString::fromStdString(weatherVector[i].getWindDirection()));//WIND DIRECTION
        ui->tableWidget->setItem(i,6,item);

        QMessageBox::information(this,"Data", "New weather item created successfully!");
    }

}


