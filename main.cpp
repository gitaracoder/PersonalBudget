#include <iostream>
#include "PersonalBudget.h"

using namespace std;

int main()
{
    PersonalBudget personalBudget;

    char choice;

    while (true)
    {
        if (personalBudget.getIdOfLoggedInUser() == 0)
        {
            choice = personalBudget.displyMainMenu();

            switch (choice)
            {
            case '1':
                personalBudget.userSignUp();
                break;
            case '2':
                personalBudget.userSignIn();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "No such option." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            choice = personalBudget.displayUserMenu();

            switch (choice)
            {
            case '1':
                personalBudget.addIncome();
                break;
            case '2':
                personalBudget.addExpense();
                break;
            case '3':
                personalBudget.showBallanceFromCurrentMonth();
                break;
            case '4':
                personalBudget.showBallanceFromPreviousMonth();
                break;
            case '5':
                personalBudget.showBallanceFromCustomPeriod();
                break;
            case '6':
                personalBudget.changePassword();
                break;
            case '9':
                personalBudget.userLogOut();
                break;
                default:
                cout << endl << "No such option." << endl << endl;
                system("pause");
                break;
            }
        }
    }






















    //UserManager userManager;
    //BudgetManager budgetManager;
    //DateManager dateManager;

    //ExpenseFile expenseFile;
    //IncomeFile incomeFile;

    //budgetManager.addIncome();


    //budgetManager.showBallanceFromSelectedPeriod();

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
