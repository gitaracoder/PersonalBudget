#ifndef INCOME_FILE
#define INCOME_FILE

#include <iostream>
#include "Markup.h"
#include "Income.h"
#include "AuxiliaryMethods.h"
#include <vector>

using namespace std;

class IncomeFile
{
public:

    CMarkup xml;
    void addIncomeToFile(Income income);
    vector <Income> loadIncomesOfLoggedInUserFromFile(int userID);
    int getLastIncomeId();
};

#endif // INCOME_FILE
