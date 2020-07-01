#include "BudgetManager.h"

void BudgetManager::sortExpensesAscendingByDate()
{
    /*
    struct less_than_key
    {
        inline bool operator() ( Expense& struct1,  Expense& struct2)
        {
            return ( struct1.getDate() <  struct2.getDate());
        }
    };
    sort(expenses.begin(), expenses.end(), less_than_key());
    */
}

void BudgetManager::sortIncomesAscendingByDate()
{
    /*
    struct less_than_key
    {
        inline bool operator() ( Income& struct1,  Income& struct2)
        {
            return (struct1.getDate() < struct2.getDate());
        }
    };
    sort(incomes.begin(), incomes.end(), less_than_key());
    */
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
    incomeFile.addIncomeToFile(income);
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
    incomeFile.addIncomeToFile(income);
}

Income BudgetManager::getIncomeDetails(int date)
{
    Income income;
    UserManager userManager;
    string incomeDescription;
    float incomeAmount;

    system("cls");
    cout << " >>> ADD NEW INCOME <<<" << endl << endl;

    cout << "Income description: ";
    incomeDescription = AuxiliaryMethods::retrieveLine();

    cout << "Income amount: ";
    incomeAmount = AuxiliaryMethods::retrieveFloatNumber();

    income.setUserId(userManager.idOfSignedInUser);
    income.setIncomeId(getIdOfNewIncome());
    income.setDate(date);
    income.setItem(incomeDescription);
    income.setAmount(incomeAmount);

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
    expenseFile.addExpenseToFile(expense);
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
    expenseFile.addExpenseToFile(expense);
}

Expense BudgetManager::getExpenseDetails(int date)
{
    Expense expense;
    UserManager userManager;
    string expenseDescription;
    float expenseAmount;

    system("cls");
    cout << " >>> ADD NEW EXPENSE <<<" << endl << endl;

    cout << "Expense description: ";
    expenseDescription = AuxiliaryMethods::retrieveLine();

    cout << "Expense amount: ";
    expenseAmount = AuxiliaryMethods::retrieveFloatNumber();

    expense.setUserId(userManager.idOfSignedInUser);
    expense.setExpenseId(getIdOfNewExpense());
    expense.setDate(date);
    expense.setItem(expenseDescription);
    expense.setAmount(expenseAmount);

    return expense;
}

void BudgetManager::showAllIncomes()
{
    for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++)
    {
        showIncomes(*itr);
    }
}

void BudgetManager::showAllExpenses()
{
    for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++)
    {
        showExpenses(*itr);
    }
}

int BudgetManager::getIdOfNewIncome()
{
    if (incomes.empty() == true)
        return 1;
    else
        return incomes.back().getIncomeId() + 1;
}

int BudgetManager::getIdOfNewExpense()
{
    if (expenses.empty() == true)
        return 1;
    else
        return expenses.back().getExpenseId() + 1;
}

void BudgetManager::showBallanceFromCurrentMonth()
{
    float sumOfIncomes = 0;
    float sumOfExpenses = 0;

    cout << "Incomes: " << endl;

    for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++)
    {
        if ((dateManager.extractMonthFromLineWithDash(dateManager.convertFromLineToLineWithDash(itr->getDate())) == dateManager.currentMonth) && (dateManager.extractYearFromLineWithDash(dateManager.convertFromLineToLineWithDash(itr->getDate())) == dateManager.currentYear) )
        {
            showIncomes(*itr);
            sumOfIncomes += itr->getAmount();
        }
    }

    cout << endl << "Expenses: " << endl;

    for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++)
    {
        if ((dateManager.extractMonthFromLineWithDash(dateManager.convertFromLineToLineWithDash(itr->getDate())) == dateManager.currentMonth) && (dateManager.extractYearFromLineWithDash(dateManager.convertFromLineToLineWithDash(itr->getDate())) == dateManager.currentYear) )
        {
            showExpenses(*itr);
            sumOfExpenses += itr->getAmount();
        }
    }

    cout << endl << "Sum of incomes: " << sumOfIncomes << endl;
    cout << "Sum of expenses: " << sumOfExpenses << endl;
    cout << "Ballance: " << sumOfIncomes - sumOfExpenses << endl;
}

void BudgetManager::showBallangeFromPreviousMonth()
{
    float sumOfIncomes = 0;
    float sumOfExpenses = 0;

    cout << "Incomes: " << endl;

    for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++)
    {
        if ((dateManager.extractMonthFromLineWithDash(dateManager.convertFromLineToLineWithDash(itr->getDate())) == dateManager.currentMonth - 1) && (dateManager.extractYearFromLineWithDash(dateManager.convertFromLineToLineWithDash(itr->getDate())) == dateManager.currentYear) )
        {
            showIncomes(*itr);
            sumOfIncomes += itr->getAmount();
        }
    }

    cout << endl << "Expenses: " << endl;

    for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++)
    {
        if ((dateManager.extractMonthFromLineWithDash(dateManager.convertFromLineToLineWithDash(itr->getDate())) == dateManager.currentMonth - 1) && (dateManager.extractYearFromLineWithDash(dateManager.convertFromLineToLineWithDash(itr->getDate())) == dateManager.currentYear) )
        {
            showExpenses(*itr);
            sumOfExpenses += itr->getAmount();
        }
    }

    cout << endl << "Sum of incomes: " << sumOfIncomes << endl;
    cout << "Sum of expenses: " << sumOfExpenses << endl;
    cout << "Ballance: " << sumOfIncomes - sumOfExpenses << endl;
}

void BudgetManager::showBallanceFromSelectedPeriod()
{
    string beginDate, endDate;

    cout << "Begin date: ";
    beginDate = AuxiliaryMethods::retrieveLine();
    if (!dateManager.isDateCorrect(beginDate))
        cout << "Wrong date";

    cout << "End date: ";
    endDate = AuxiliaryMethods::retrieveLine();
    if (!dateManager.isDateCorrect(endDate))
        cout << "Wrong date";

    float sumOfIncomes = 0;
    float sumOfExpenses = 0;

    cout << "Incomes: " << endl;

    for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++)
    {
        if ((itr->getDate() >= dateManager.convertFromLineWithDashToLine(beginDate)) && (itr->getDate() <= dateManager.convertFromLineWithDashToLine(endDate)))
        {
            showIncomes(*itr);
            sumOfIncomes += itr->getAmount();
        }
    }

    cout << endl << "Expenses: " << endl;

    for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++)
    {
        if ((itr->getDate() >= dateManager.convertFromLineWithDashToLine(beginDate)) && (itr->getDate() <= dateManager.convertFromLineWithDashToLine(endDate)))
        {
            showExpenses(*itr);
            sumOfExpenses += itr->getAmount();
        }
    }

    cout << endl << "Sum of incomes: " << sumOfIncomes << endl;
    cout << "Sum of expenses: " << sumOfExpenses << endl;
    cout << "Ballance: " << sumOfIncomes - sumOfExpenses << endl;
}

void BudgetManager::showIncomes(Income income)
{
    cout << "userID: " << income.getUserId() << " incID: " << income.getIncomeId() <<
         " Date: " << dateManager.convertFromLineToLineWithDash(income.getDate()) <<
         " Description: " << income.getItem() << " Amount: " << income.getAmount() << endl;
}

void BudgetManager::showExpenses(Expense expense)
{
    cout << "userID: " << expense.getUserId() << " expID: " << expense.getExpenseId() <<
         " Date: " << dateManager.convertFromLineToLineWithDash(expense.getDate()) <<
         " Description: " << expense.getItem() << " Amount: " << expense.getAmount() << endl;
}

BudgetManager::BudgetManager()
{
    expenses = expenseFile.loadExpensesOfLoggedInUserFromFile(1);
    incomes = incomeFile.loadIncomesOfLoggedInUserFromFile(1);
}
