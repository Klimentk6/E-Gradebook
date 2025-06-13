#include "Utils.h"

namespace Utils
{
    bool isLeapYear(unsigned year)
    {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }
    bool isValidDate(unsigned day, unsigned month, unsigned year)
    {
        if (year < 1000 || month == 0 || month > 12 || day == 0)
        {
            return false;
        }

        const unsigned daysInMonth[12] =
        {
            31, 28 + isLeapYear(year), 31, 30, 31, 30,
            31, 31, 30, 31, 30, 31
        };

        return day <= daysInMonth[month - 1];
    }
    bool isValidDateString(const std::string& dateStr)
    {
        if (dateStr.length() != 10 || dateStr[2] != '.' || dateStr[5] != '.')
        {
            return false;
        }
        for (unsigned i : {0, 1, 3, 4, 6, 7, 8, 9})
        {
            if (!std::isdigit((unsigned char)dateStr[i]))
            {
                return false;
            }
        }

        unsigned day = std::stoi(dateStr.substr(0, 2));
        unsigned month = std::stoi(dateStr.substr(3, 2));
        unsigned year = std::stoi(dateStr.substr(6, 4));

        return isValidDate(day, month, year);
    }
    bool isValidFullName(const std::string& fullName)
    {
        int partCount = 0;
        unsigned i = 0;
        unsigned len = fullName.length();
        while (i < len)
        {
            if (fullName[i] == ' ' && (i == 0 || fullName[i - 1] == ' '))
            {
                return false;
            }
            unsigned start = i;
            while (i < len && fullName[i] != ' ')
            {
                char ch = fullName[i];
                if (!((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')))
                {
                    return false;
                }
                i++;
            }
            if (i == start)
            {
                return false;
            }
            partCount++;
            if (partCount < 3)
            {
                if (i >= len || fullName[i] != ' ')
                {
                    return false;
                }
                i++;
            }
        }
        return partCount == 3;
    }
    bool isStringUnsigned(const std::string& str)
    {
        if (str.empty()) return false;
        for (char c : str)
        {
            if (!isdigit((unsigned char)c))
            {
                return false;
            }
        }
        return true;
    }
    std::vector<std::string> split(const std::string& str, char delimiter)
    {
        std::vector<std::string> parts;
        std::stringstream ss(str);
        std::string part;
        while (std::getline(ss, part, delimiter))
        {
            parts.push_back(part);
        }
        return parts;
    }
}

