#ifndef DATE_MANAGER
#define DATE_MANAGER

#include <iostream>
#include <windows.h>
#include <winbase.h>
#include "AuxiliaryMethods.h"

using namespace std;

class DateManager
{

public:
    DateManager();

    int currentDay;
    int currentMonth;
    int currentYear;

    string getDate();
    int currentMonthDays();
    int daysBetweenDateRange(int beginYear, int endYear, int beginMonth, int endMonth, int beginDay, int endDay);
    bool isLeapYear(int year);
    void currentDate();
    bool isDateCorrect(string date);
    int convertFromLineWithDashToLine(string date);
    string convertFromLineToLineWithDash(int date);
    string convertDateFromSeparateToLineWithDashes(int year, int month, int day);
    int extractMonthFromLineWithDash(string date);
    int extractYearFromLineWithDash(string date);
};
#endif // DATE_MANAGER
