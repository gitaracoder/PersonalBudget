#ifndef BUDGET_MANAGER
#define BUDGET_MANAGER

#include <iostream>
#include <vector>
#include <algorithm>
#include "Income.h"
#include "Expense.h"
#include "AuxiliaryMethods.h"
#include "DateManager.h"
#include "UserManager.h"
#include "ExpenseFile.h"
#include "IncomeFile.h"

using namespace std;

class BudgetManager
{
public:
    DateManager dateManager;
    ExpenseFile expenseFile;
    IncomeFile incomeFile;

    const int ID_OF_LOGGED_IN_USER;

    vector <Income> incomes;
    vector <Expense> expenses;

    void sortExpensesAscendingByDate();
    void sortIncomesAscendingByDate();


    BudgetManager(int idOfLoggedInUser) : ID_OF_LOGGED_IN_USER(idOfLoggedInUser)
    {
        expenses = expenseFile.loadExpensesOfLoggedInUserFromFile(ID_OF_LOGGED_IN_USER);
        incomes = incomeFile.loadIncomesOfLoggedInUserFromFile(ID_OF_LOGGED_IN_USER);
        sortExpensesAscendingByDate();
        sortIncomesAscendingByDate();
    };


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

    int getIdOfNewIncome();
    int getIdOfNewExpense();

    void showBallanceFromCurrentMonth();
    void showBallangeFromPreviousMonth();
    void showBallanceFromSelectedPeriod();

    void showIncomes(Income income);
    void showExpenses(Expense expense);
};
#endif // BUDGET_MANAGER
