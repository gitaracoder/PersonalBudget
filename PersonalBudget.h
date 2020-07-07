#ifndef PERSONAL_BUDGET
#define PERSONAL_BUDGET

#include <iostream>
#include "BudgetManager.h"
#include "Income.h"
#include "UserManager.h"
#include "UserFile.h"
#include "DateManager.h"
#include "IncomeFile.h"
#include "ExpenseFile.h"

using namespace std;

class PersonalBudget
{
public:

    UserManager userManager;
    BudgetManager *budgetManager;

    PersonalBudget()
    {
        userManager.idOfSignedInUser = 0;
        budgetManager = NULL;
    };
    ~PersonalBudget()
    {
        delete budgetManager;
        budgetManager = NULL;
    };

    void userSignUp();
    void userSignIn();
    void changePassword();
    void userLogOut();
    void addIncome();
    void addExpense();
    void showBallanceFromCurrentMonth();
    void showBallanceFromPreviousMonth();
    void showBallanceFromCustomPeriod();
    int getIdOfLoggedInUser();
    char displayUserMenu();
    char displyMainMenu();
};

#endif // PERSONAL_BUDGET
