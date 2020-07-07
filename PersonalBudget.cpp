#include "PersonalBudget.h"

void PersonalBudget::userSignUp()
{
    userManager.userSignUp();
}

void PersonalBudget::userSignIn()
{
    userManager.userSignIn();
    if (userManager.isUserSignedIn())
    {
        budgetManager = new BudgetManager(userManager.idOfSignedInUser);
    }
}

void PersonalBudget::changePassword()
{
    userManager.changePassword();
}

void PersonalBudget::userLogOut()
{
    userManager.idOfSignedInUser = 0;
}

void PersonalBudget::addIncome()
{
    budgetManager->addIncome();
}

void PersonalBudget::addExpense()
{
    budgetManager->addExpense();
}

void PersonalBudget::showBallanceFromCurrentMonth()
{
    budgetManager->showBallanceFromCurrentMonth();
}

void PersonalBudget::showBallanceFromPreviousMonth()
{
    budgetManager->showBallangeFromPreviousMonth();
}

void PersonalBudget::showBallanceFromCustomPeriod()
{
    budgetManager->showBallanceFromSelectedPeriod();
}

int PersonalBudget::getIdOfLoggedInUser()
{
    return userManager.idOfSignedInUser;
}

char PersonalBudget::displayUserMenu()
{
    char choice;

    system("cls");
    cout << " >>> USER MENU <<<" << endl;
    cout << "Welcome " << userManager.nameOfSignedInUser << " " << userManager.surnameOfSignedInUser << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add income" << endl;
    cout << "2. Add expense" << endl;
    cout << "3. Ballance from current month" << endl;
    cout << "4. Ballance from previous month" << endl;
    cout << "5. Ballance from custom period" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Change password" << endl;
    cout << "9. Log out" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = AuxiliaryMethods::retrieveCharacter();

    return choice;
}

char PersonalBudget::displyMainMenu()
{
    char choice;

    system("cls");
    cout << "    >>> MAIN MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Sign Up" << endl;
    cout << "2. Sign In" << endl;
    cout << "9. Exit" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = AuxiliaryMethods::retrieveCharacter();

    return choice;
}
