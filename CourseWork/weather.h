#ifndef WEATHER_H
#define WEATHER_H
#include <QString>
//using namespace std;

class Weather
{


public:
    Weather();//коструктор без параметрів
    Weather(int y, int m, int d, double t, double p, double h, std::string wd);//конструктор з параметрами

    Weather(const Weather &copy);//конструктор копіювання

    ~Weather(){};//деструктор

    Weather& operator=(const Weather& other){//оператор присвоювання
        this->year=other.year;
        this->month=other.month;
        this->day=other.day;

        this->temperature=other.temperature;
        this->pressure=other.pressure;
        this->humidity=other.humidity;

        this->windDirection=other.windDirection;
        return *this;
    }

    bool operator<(const Weather &other) const;//оператор порівняння (потрібний для виклику функції sort у векторі)

    //                              GETERS
    int getYear(){return year;}
    int getMonth(){return month;}
    int getDay(){return day;}

    double getTemperature(){return temperature;}
    double getPressure(){ return pressure;}
    double getHumidity(){return humidity;}

    std::string getWindDirection(){return windDirection;}



    //                              FUNCTIONS
    int timeLineDay() const; //дозволяє дізнатись до розміщується цей день в часі
    QString convertMonthToQStr(); //повертає перетворений місяць з числа в слово
    QString dateToQStr();//повератє дати у вигляді [yyyy.mm.dd]
private:
    int year, month, day;
    double temperature, pressure, humidity;

    std::string windDirection;

};

#endif // WEATHER_H
