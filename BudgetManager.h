#ifndef BUDGET_MANAGER
#define BUDGET_MANAGER

#include <iostream>
#include <vector>
#include <algorithm>
#include "Income.h"
#include "Expense.h"
#include "AuxiliaryMethods.h"
#include "DateManager.h"

using namespace std;

class BudgetManager
{
public:
    DateManager dateManager;

    vector <Income> incomes;
    vector <Expense> expenses;

    void sortExpensesAscendingByDate();
    void sortIncomesAscendingByDate();

    void addIncome();
    void addIncomeWithTodayDate();
    void addIncomeWithCustomDate();
    Income getIncomeDetails(int date);

    void addExpense();
    void addExpenseWithTodayDate();
    void addExpenseWithCustomDate();
    Expense getExpenseDetails(int date);

    void showAllIncomes();
    void showAllExpenses();
};
#endif // BUDGET_MANAGER
