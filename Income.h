#ifndef INCOME
#define INCOME

#include <iostream>
#include "Expense.h"

using namespace std;

class Income : public Expense
{
    int incomeId;

public:
    void setIncomeId(int newId);
    int getIncomeId();
};

#endif // INCOME
