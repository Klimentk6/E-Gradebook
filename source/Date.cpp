#include "Date.h"

Date::Date()
{
    day = 0;
    month = 0;
    year = 0;
}
Date::Date(unsigned day, unsigned month, unsigned year)
{
    this->day = day;
    this->month = month;
    this->year = year;
}

void Date::printDate() const
{
    std::cout << (day < 10 ? "0" : "") << day << ".";
    std::cout << (month < 10 ? "0" : "") << month << ".";
    std::cout << year << std::endl;

}
bool Date::isToday() const 
{
    std::time_t now = std::time(nullptr);
    std::tm localTime;

    if (localtime_s(&localTime, &now) != 0) 
    {
        return false; 
    }

    unsigned currentDay = localTime.tm_mday;
    unsigned currentMonth = localTime.tm_mon + 1;
    unsigned currentYear = localTime.tm_year + 1900;

    return (day == currentDay) && (month == currentMonth) && (year == currentYear);
}
bool Date::isTodayBirthday() const
{
    std::time_t now = std::time(nullptr);
    std::tm localTime;

    if (localtime_s(&localTime, &now) != 0)
    {
        return false;
    }

    unsigned currentDay = localTime.tm_mday;
    unsigned currentMonth = localTime.tm_mon + 1;

    return (day == currentDay) && (month == currentMonth);
}

void Date::readFromBinaryFile(std::ifstream& ifs)
{
    ifs.read((char*)&day, sizeof(day));
    ifs.read((char*)&month, sizeof(month));
    ifs.read((char*)&year, sizeof(year));
}
void Date::writeToBinaryFile(std::ofstream& ofs) const
{
    ofs.write((const char*)&day, sizeof(day));
    ofs.write((const char*)&month, sizeof(month));
    ofs.write((const char*)&year, sizeof(year));
}

unsigned Date::getDay() const
{
    return day;
}
unsigned Date::getMonth() const
{
    return month;
}
unsigned Date::getYear() const
{
    return year;
}
void Date::setDate(unsigned day, unsigned month, unsigned year)
{
    this->day = day;
    this->month = month;
    this->year = year;
}
void Date::setToToday()
{
    std::time_t now = std::time(nullptr);
    std::tm localTime;

    if (localtime_s(&localTime, &now) != 0)
    {
        return;
    }

    day = localTime.tm_mday;
    month = localTime.tm_mon + 1;
    year = localTime.tm_year + 1900;
}

std::ostream& operator<<(std::ostream& os, const Date& date)
{
    os << (date.day < 10 ? "0" : "") << date.day << "."
        << (date.month < 10 ? "0" : "") << date.month << "."
        << date.year;
    return os;
}
std::istream& operator>>(std::istream& is, Date& date)
{
    unsigned d, m, y;
    char dot1, dot2;

    is >> d >> dot1 >> m >> dot2 >> y;

    if (!is || dot1 != '.' || dot2 != '.')
    {
        is.setstate(std::ios::failbit);
        return is;
    }

    date.setDate(d, m, y);
    return is;
}


