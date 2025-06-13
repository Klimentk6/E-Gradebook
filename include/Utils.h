#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

namespace Utils
{
	bool isLeapYear(unsigned year);
	bool isValidDate(unsigned day, unsigned month, unsigned year);
	bool isValidDateString(const std::string& dateStr);
	bool isValidFullName(const std::string& fullName);
	bool isStringUnsigned(const std::string& str);

	std::vector<std::string> split(const std::string& str, char delimiter);
};

