#ifndef EXPENSE_FILE
#define EXPENSE_FILE

#include <iostream>
#include "Markup.h"
#include "Expense.h"
#include "AuxiliaryMethods.h"
#include <vector>

using namespace std;

class ExpenseFile
{
public:

    CMarkup xml;
    void addExpenseToFile(Expense expense);
    vector <Expense> loadExpensesOfLoggedInUserFromFile(int userID);
    int getLastExpenseId();
};

#endif // EXPENSE_FILE
