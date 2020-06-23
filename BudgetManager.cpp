#include "BudgetManager.h"

void BudgetManager::sortExpensesAscendingByDate()
{
    struct less_than_key
    {
        inline bool operator() (const Expense& struct1, const Expense& struct2)
        {
            return (struct1.date < struct2.date);
        }
    };
    sort(expenses.begin(), expenses.end(), less_than_key());
}

void BudgetManager::sortIncomesAscendingByDate()
{
    struct less_than_key
    {
        inline bool operator() (const Income& struct1, const Income& struct2)
        {
            return (struct1.date < struct2.date);
        }
    };
    sort(incomes.begin(), incomes.end(), less_than_key());
}

void BudgetManager::addIncome()
{
    Income income;
    DateManager dateManager;
    char selection;

    system("cls");
    cout << " >>> ADD NEW INCOME <<<" << endl << endl;

    cout << "1. Today income" << endl;
    cout << "2. Custom date income" << endl;
    cout << "9. Back" << endl;

    cout << "Selection: ";

    selection = AuxiliaryMethods::retrieveCharacter();

    switch (selection)
    {
    case '1':
        addIncomeWithTodayDate();
        break;
    case '2':
        addIncomeWithCustomDate();
        break;
    case '9':
        return;
        break;
    }
}

void BudgetManager::addIncomeWithTodayDate()
{
    Income income;
    DateManager dateManager;
    int todayDate;

    todayDate = dateManager.convertFromLineWithDashToLine(dateManager.convertDateFromSeparateToLineWithDashes(dateManager.currentYear, dateManager.currentMonth, dateManager.currentDay));

    income = getIncomeDetails(todayDate);
    incomes.push_back(income);
}

void BudgetManager::addIncomeWithCustomDate()
{
    Income income;
    DateManager dateManager;
    int customDate;
    string insertedDate;

    cout << "Type in date (yyyy-mm-dd): ";
    insertedDate = AuxiliaryMethods::retrieveLine();

    if(!dateManager.isDateCorrect(insertedDate))
    {
        cout << "Wrong date" << endl;
        return;
    }
    else
        customDate = dateManager.convertFromLineWithDashToLine(insertedDate);

    income = getIncomeDetails(customDate);
    incomes.push_back(income);
}

Income BudgetManager::getIncomeDetails(int date)
{
    Income income;
    string incomeDescription;
    float incomeAmount;

    system("cls");
    cout << " >>> ADD NEW INCOME <<<" << endl << endl;

    cout << "Income description: ";
    incomeDescription = AuxiliaryMethods::retrieveLine();

    cout << "Income amount: ";
    incomeAmount = AuxiliaryMethods::retrieveFloatNumber();

    income.date = date;
    income.item = incomeDescription;
    income.amount = incomeAmount;

    return income;
}

void BudgetManager::addExpense()
{
    Expense expense;
    DateManager dateManager;
    char selection;

    system("cls");
    cout << " >>> ADD NEW EXPENSE <<<" << endl << endl;

    cout << "1. Today expense" << endl;
    cout << "2. Custom date expense" << endl;
    cout << "9. Back" << endl;

    cout << "Selection: ";

    selection = AuxiliaryMethods::retrieveCharacter();

    switch (selection)
    {
    case '1':
        addExpenseWithTodayDate();
        break;
    case '2':
        addExpenseWithCustomDate();
        break;
    case '9':
        return;
        break;
    }
}

void BudgetManager::addExpenseWithTodayDate()
{
    Expense expense;
    DateManager dateManager;
    int todayDate;

    todayDate = dateManager.convertFromLineWithDashToLine(dateManager.convertDateFromSeparateToLineWithDashes(dateManager.currentYear, dateManager.currentMonth, dateManager.currentDay));

    expense = getExpenseDetails(todayDate);
    expenses.push_back(expense);
}

void BudgetManager::addExpenseWithCustomDate()
{
    Expense expense;
    DateManager dateManager;
    int customDate;
    string insertedDate;

    cout << "Type in date (yyyy-mm-dd): ";
    insertedDate = AuxiliaryMethods::retrieveLine();

    if(!dateManager.isDateCorrect(insertedDate))
    {
        cout << "Wrong date" << endl;
        return;
    }
    else
        customDate = dateManager.convertFromLineWithDashToLine(insertedDate);

    expense = getExpenseDetails(customDate);
    expenses.push_back(expense);
}

Expense BudgetManager::getExpenseDetails(int date)
{
    Expense expense;
    string expenseDescription;
    float expenseAmount;

    system("cls");
    cout << " >>> ADD NEW EXPENSE <<<" << endl << endl;

    cout << "Expense description: ";
    expenseDescription = AuxiliaryMethods::retrieveLine();

    cout << "Expense amount: ";
    expenseAmount = AuxiliaryMethods::retrieveFloatNumber();

    expense.date = date;
    expense.item = expenseDescription;
    expense.amount = expenseAmount;

    return expense;
}

void BudgetManager::showAllIncomes()
{
    for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++)
    {
        cout << "Date: " << dateManager.convertFromLineToLineWithDash(itr->date) << " Description: " << itr->item << " Amount: " << itr->amount << endl;
    }
}

void BudgetManager::showAllExpenses()
{
    for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++)
    {
        cout << "Date: " << dateManager.convertFromLineToLineWithDash(itr->date) << " Description: " << itr->item << " Amount: " << itr->amount << endl;
    }
}
