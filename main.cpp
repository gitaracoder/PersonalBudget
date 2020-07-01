#include <iostream>
#include "BudgetManager.h"
#include "Income.h"
#include "UserManager.h"
#include "UserFile.h"
#include "DateManager.h"

using namespace std;

int main()
{
    UserManager userManager;
    BudgetManager budgetManager;
    DateManager dateManager;

    budgetManager.showBallanceFromSelectedPeriod();

    //budgetManager.showBallanceFromCurrentMonth();
    //budgetManager.showBallangeFromPreviousMonth();

    //budgetManager.showAllExpenses();
    //budgetManager.showAllIncomes();

    //UserFile userFile;

    //userManager.userSignUp();

    //userManager.showAllUsers();

    //userManager.userSignIn();

    //cout << userManager.idOfSignedInUser;

    //userManager.changePassword();

/*

    for (int i=0; i<3; i++)
    {
        budgetManager.addExpense();
        budgetManager.addIncome();
    }


    budgetManager.showAllExpenses();
    budgetManager.showAllIncomes();

*/
    return 0;
}
