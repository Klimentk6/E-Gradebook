#pragma once
#include <iostream>
#include <fstream>
#include <ctime>

class Date
{
public:
	Date();
	Date(unsigned day, unsigned month, unsigned year);

	void printDate() const;
	bool isToday() const;
	bool isTodayBirthday() const;

	void readFromBinaryFile(std::ifstream& ifs);
	void writeToBinaryFile(std::ofstream& ofs) const;

	unsigned getDay() const; 
	unsigned getMonth() const;
	unsigned getYear() const;
	void setDate(unsigned day, unsigned month, unsigned year);
	void setToToday();

	friend std::ostream& operator<<(std::ostream& os, const Date& date);
	friend std::istream& operator>>(std::istream& is, Date& date);

private:
	unsigned day;
	unsigned month;
	unsigned year;
};

