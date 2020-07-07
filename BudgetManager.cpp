#include "BudgetManager.h"

void BudgetManager::sortExpensesAscendingByDate()
{

    struct less_than_key
    {
        inline bool operator() ( Expense& struct1,  Expense& struct2)
        {
            return ( struct1.getDate() <  struct2.getDate());
        }
    };
    sort(expenses.begin(), expenses.end(), less_than_key());

}

void BudgetManager::sortIncomesAscendingByDate()
{

    struct less_than_key
    {
        inline bool operator() ( Income& struct1,  Income& struct2)
        {
            return (struct1.getDate() < struct2.getDate());
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

    cout << endl << "Choice: ";

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
    default:
        cout << "No such option.";
        system("pause");
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

    cout << endl << "Income added." << endl;
    system("pause");
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
        system("pause");
        return;
    }
    else
        customDate = dateManager.convertFromLineWithDashToLine(insertedDate);

    income = getIncomeDetails(customDate);
    incomes.push_back(income);
    incomeFile.addIncomeToFile(income);

    cout << endl << "Income added." << endl;
    system("pause");
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

    income.setUserId(ID_OF_LOGGED_IN_USER);
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

    cout << endl << "Choice: ";

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
    default:
        cout << "No such option.";
        system("pause");
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

    cout << endl << "Expense added." << endl;
    system("pause");
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
        system("pause");
        return;
    }
    else
        customDate = dateManager.convertFromLineWithDashToLine(insertedDate);

    expense = getExpenseDetails(customDate);
    expenses.push_back(expense);
    expenseFile.addExpenseToFile(expense);

    cout << endl << "Expense added." << endl;
    system("pause");
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

    expense.setUserId(ID_OF_LOGGED_IN_USER);
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
    return incomeFile.getLastIncomeId() + 1;
}

int BudgetManager::getIdOfNewExpense()
{
    return expenseFile.getLastExpenseId() + 1;
}

void BudgetManager::showBallanceFromCurrentMonth()
{
    float sumOfIncomes = 0;
    float sumOfExpenses = 0;

    cout << endl << "Incomes: " << endl;

    for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++)
    {
        if ((dateManager.extractMonthFromLineWithDash(dateManager.convertFromLineToLineWithDash(itr->getDate())) == dateManager.currentMonth) && (dateManager.extractYearFromLineWithDash(dateManager.convertFromLineToLineWithDash(itr->getDate())) == dateManager.currentYear) )
        {
            showIncomes(*itr);
            sumOfIncomes += itr->getAmount();
        }
    }

    if (sumOfIncomes == 0)
        cout << "No incomes in selected period." << endl;

    cout << endl << "Expenses: " << endl;

    for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++)
    {
        if ((dateManager.extractMonthFromLineWithDash(dateManager.convertFromLineToLineWithDash(itr->getDate())) == dateManager.currentMonth) && (dateManager.extractYearFromLineWithDash(dateManager.convertFromLineToLineWithDash(itr->getDate())) == dateManager.currentYear) )
        {
            showExpenses(*itr);
            sumOfExpenses += itr->getAmount();
        }
    }

    if (sumOfExpenses == 0)
        cout << "No expenses in selected period." << endl << endl;

    if (sumOfIncomes != 0)
        cout << endl << "Sum of incomes: " << sumOfIncomes << endl;

    if (sumOfExpenses != 0)
        cout << "Sum of expenses: " << sumOfExpenses << endl << endl;

    if ((sumOfIncomes != 0)&&(sumOfExpenses != 0))
        cout << "Ballance: " << sumOfIncomes - sumOfExpenses << endl << endl;

    system("pause");
}

void BudgetManager::showBallangeFromPreviousMonth()
{

    float sumOfIncomes = 0;
    float sumOfExpenses = 0;

    cout << endl << "Incomes: " << endl;

    for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++)
    {
        if ((dateManager.extractMonthFromLineWithDash(dateManager.convertFromLineToLineWithDash(itr->getDate())) == dateManager.currentMonth - 1) && (dateManager.extractYearFromLineWithDash(dateManager.convertFromLineToLineWithDash(itr->getDate())) == dateManager.currentYear) )
        {
            showIncomes(*itr);
            sumOfIncomes += itr->getAmount();
        }
    }

    if (sumOfIncomes == 0)
        cout << "No incomes in selected period." << endl;

    cout << endl << "Expenses: " << endl;

    for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++)
    {
        if ((dateManager.extractMonthFromLineWithDash(dateManager.convertFromLineToLineWithDash(itr->getDate())) == dateManager.currentMonth - 1) && (dateManager.extractYearFromLineWithDash(dateManager.convertFromLineToLineWithDash(itr->getDate())) == dateManager.currentYear) )
        {
            showExpenses(*itr);
            sumOfExpenses += itr->getAmount();
        }
    }

    if (sumOfExpenses == 0)
        cout << "No expenses in selected period." << endl << endl;

    if (sumOfIncomes != 0)
        cout << endl << "Sum of incomes: " << sumOfIncomes << endl;

    if (sumOfExpenses != 0)
        cout << "Sum of expenses: " << sumOfExpenses << endl << endl;

    if ((sumOfIncomes != 0)&&(sumOfExpenses != 0))
        cout << "Ballance: " << sumOfIncomes - sumOfExpenses << endl << endl;

    system("pause");
}

void BudgetManager::showBallanceFromSelectedPeriod()
{
    string beginDate, endDate;

    cout << endl << "Begin date: ";
    beginDate = dateManager.getDate();

    cout << "End date: ";
    endDate = dateManager.getDate();

    float sumOfIncomes = 0;
    float sumOfExpenses = 0;

    cout << endl << "Incomes: " << endl;

    for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++)
    {
        if ((itr->getDate() >= dateManager.convertFromLineWithDashToLine(beginDate)) && (itr->getDate() <= dateManager.convertFromLineWithDashToLine(endDate)))
        {
            showIncomes(*itr);
            sumOfIncomes += itr->getAmount();
        }
    }

    if (sumOfIncomes == 0)
        cout << "No incomes in selected period." << endl;

    cout << endl << "Expenses: " << endl;

    for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++)
    {
        if ((itr->getDate() >= dateManager.convertFromLineWithDashToLine(beginDate)) && (itr->getDate() <= dateManager.convertFromLineWithDashToLine(endDate)))
        {
            showExpenses(*itr);
            sumOfExpenses += itr->getAmount();
        }
    }

    if (sumOfExpenses == 0)
        cout << "No expenses in selected period." << endl << endl;

    if (sumOfIncomes != 0)
        cout << endl << "Sum of incomes: " << sumOfIncomes << endl;

    if (sumOfExpenses != 0)
        cout << "Sum of expenses: " << sumOfExpenses << endl << endl;

    if ((sumOfIncomes != 0)&&(sumOfExpenses != 0))
        cout << "Ballance: " << sumOfIncomes - sumOfExpenses << endl << endl;

    system("pause");
}

void BudgetManager::showIncomes(Income income)
{
    cout << "Income ID: " << income.getIncomeId() << " Date: " << dateManager.convertFromLineToLineWithDash(income.getDate()) << " Amount: " << income.getAmount() << " Description: " << income.getItem()  << endl;
}

void BudgetManager::showExpenses(Expense expense)
{
    cout << "Expense ID: " << expense.getExpenseId() << " Date: " << dateManager.convertFromLineToLineWithDash(expense.getDate()) << " Amount: " << expense.getAmount() << " Description: " << expense.getItem()  << endl;
}
