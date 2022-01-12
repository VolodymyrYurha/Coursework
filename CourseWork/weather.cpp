#include "weather.h"

Weather::Weather()
{
    year=0;
    month=0;
    day=0;

    temperature = 0;
    pressure=0;
    humidity=0;

    windDirection="none";
}

Weather::Weather(int y, int m, int d, double t, double p, double h, std::string wd)
{
    this->year=y;
    this->month=m;
    this->day=d;

    this->temperature = t;
    this->pressure=p;
    this->humidity=h;

    this->windDirection=wd;
}


Weather::Weather(const Weather& other)
{
    this->year=other.year;
    this->month=other.month;
    this->day=other.day;

    this->humidity=other.humidity;
    this->pressure=other.pressure;
    this->temperature=other.temperature;

    this->windDirection=other.windDirection;
}


QString Weather::convertMonthToQStr(){
    switch (month) {
        case 1: return "January";//31
        case 2: return "February";

        case 3: return "March";
        case 4: return "April";
        case 5: return "May";

        case 6: return "June";
        case 7: return "July";
        case 8: return "August";

        case 9: return "September";
        case 10: return "October";
        case 11: return "November";

        default: return "December";
    }
}

QString Weather::dateToQStr(){
    QString result = "["+QString::number(year) +"." + QString::number(month)+'.'+QString::number(day)+']';
    return result;
}

int Weather::timeLineDay() const{
    int monthDays;
    switch (month) {
    //кожен місяць буде повертати кількість днів від 1 січня до 1 дня цього місяця
    case 1: monthDays = 0; break;
    case 2: monthDays = 31; break;
    case 3: monthDays = 31+28; break;
    case 4: monthDays = 31+28+31; break;
    case 5: monthDays = 31+28+31+30; break;
    case 6: monthDays = 31+28+31+30+31; break;
    case 7: monthDays = 31+28+31+30+31+30; break;
    case 8: monthDays = 31+28+31+30+31+30+31; break;
    case 9: monthDays = 31+28+31+30+31+30+31+31; break;
    case 10: monthDays = 31+28+31+30+31+30+31+31+30; break;
    case 11: monthDays = 31+28+31+30+31+30+31+31+30+31; break;
    default: monthDays = 31+28+31+30+31+30+31+31+30+31+30; break;
    }
    return year*365 + monthDays + day;//кількість днів від початку Ери
}

//оператор порівняння на основі розміщення дня в часовій лінії
bool Weather::operator<(const Weather &other) const{
    return this->timeLineDay()<other.timeLineDay();
}
