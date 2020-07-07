#include "DateManager.h"

bool DateManager::isLeapYear(int year)
{
    if(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
        return true;
    else
        return false;
}

void DateManager::currentDate()
{
    SYSTEMTIME st;
    GetSystemTime(&st);

    currentYear = st.wYear;
    currentMonth = st.wMonth;
    currentDay = st.wDay;
}

int DateManager::daysBetweenDateRange(int beginYear, int endYear, int beginMonth, int endMonth, int beginDay, int endDay)
{
    int sumOfDaysInFollowingMonths[12] = {31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
    int sumOfDaysInFollowingMonthsInLeapYear[12] = {31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366};

    int days = 0;

    for (int i = beginYear; i < endYear; i++)
    {
        if(isLeapYear(i))
            days += 366;
        else
            days += 365;
    }

    if(isLeapYear(beginYear))
        days -= (sumOfDaysInFollowingMonthsInLeapYear[beginMonth - 1]);
    else
        days -= sumOfDaysInFollowingMonths[beginMonth - 1];

    if(isLeapYear(endYear))
        days += (sumOfDaysInFollowingMonthsInLeapYear[endMonth - 1]);
    else
        days += sumOfDaysInFollowingMonths[endMonth - 1];

    days -= beginDay;
    days += endDay;

    return days;
}

int DateManager::currentMonthDays()
{
    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if(isLeapYear(currentYear) && currentMonth == 2)
        return daysInMonth[currentMonth - 1] + 1;
    else
        return daysInMonth[currentMonth - 1];
}

bool DateManager::isDateCorrect(string date)
{
    const int CORRECT_LENGTH_OF_DATE = 10;
    const int MINIMAL_YEAR = 2000;
    const int MINIMAL_MONTH = 1;
    const int MAXIMAL_MONTH = 12;
    const int MINIMAL_DAY = 1;
    const int MAXIMAL_DAY[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    string year, month, day;
    int intYear, intMonth, intDay;
    bool check = true;

    if (date.length() != CORRECT_LENGTH_OF_DATE)
        return false;

    for (int i = 0; i <= 3 ; i++)
    {
        if (!isdigit(date[i]))
            check = check && false;
        else
            year += date[i];
    }

    if (date[4] != '-')
        check = check && false;

    for (int i = 5; i <= 6 ; i++)
    {
        if (!isdigit(date[i]))
            check = check && false;
        else
            month += date[i];
    }

    if (date[7] != '-')
        check = check && false;

    for (int i = 8; i <= 9 ; i++)
    {
        if (!isdigit(date[i]))
            check = check && false;
        else
            day += date[i];
    }

    if (!check)
        return false;

    intYear = AuxiliaryMethods::convertStringToInt(year);
    intMonth = AuxiliaryMethods::convertStringToInt(month);
    intDay = AuxiliaryMethods::convertStringToInt(day);

    if (intYear < MINIMAL_YEAR || intYear > currentYear)
        check = check && false;

    if (intMonth < MINIMAL_MONTH || intMonth > MAXIMAL_MONTH)
        check = check && false;

    if (isLeapYear(intYear) && intMonth == 2)
    {
        if (intDay < MINIMAL_DAY || intDay > (MAXIMAL_DAY[intMonth - 1] + 1))
            check = check && false;
    }
    else
    {
        if (intDay < MINIMAL_DAY || intDay > MAXIMAL_DAY[intMonth - 1])
            check = check && false;
    }

    if (!check)
        return false;

    if ((intMonth < MINIMAL_MONTH || intMonth > currentMonth) && intYear == currentYear)
        check = check && false;

    if ((intDay < MINIMAL_DAY || intDay > currentDay) && intMonth == currentMonth)
        check = check && false;

    if (!check)
        return false;
    else
        return true;
}

int DateManager::convertFromLineWithDashToLine(string date)
{
    date.erase(date.begin() + 7);
    date.erase(date.begin() + 4);
    return AuxiliaryMethods::convertStringToInt(date);
}

string DateManager::convertDateFromSeparateToLineWithDashes(int year, int month, int day)
{
    string yearSTR, monthSTR, daySTR;

    yearSTR = AuxiliaryMethods::convertIntToString(year);

    if (month < 10)
        monthSTR = "0" + AuxiliaryMethods::convertIntToString(month);
    else
        monthSTR = AuxiliaryMethods::convertIntToString(month);

    if (day < 10)
        daySTR = "0" + AuxiliaryMethods::convertIntToString(day);
    else
        daySTR = AuxiliaryMethods::convertIntToString(day);

    return  yearSTR + "-" + monthSTR + "-" + daySTR;
}

string DateManager::convertFromLineToLineWithDash(int date)
{
    string dashDate;

    dashDate = AuxiliaryMethods::convertIntToString(date);
    dashDate.insert(6,"-");
    dashDate.insert(4,"-");
    return dashDate;
}

int DateManager::extractMonthFromLineWithDash(string date)
{
    date.erase(7,9);
    date.erase(0,5);

    return AuxiliaryMethods::convertStringToInt(date);
}

int DateManager::extractYearFromLineWithDash(string date)
{
    date.erase(4,9);

    return AuxiliaryMethods::convertStringToInt(date);
}

string DateManager::getDate()
{
    string date;

    while (true)
    {
        date = AuxiliaryMethods::retrieveLine();

        if (isDateCorrect(date))
        {
            break;
        }
        cout << "Wrong date. Try again: ";
    }

    return date;
}

DateManager::DateManager()
{
    DateManager::currentDate();
}
