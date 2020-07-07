#include "UserManager.h"

void UserManager::userSignUp()
{
    UserFile userFile;
    User user = provideDetailsOfNewUser();
    users.push_back(user);

    userFile.addUserToFile(user);

    cout << endl << "Signed up successfully." << endl << endl;
    system("pause");
    cin.sync();
}

User UserManager::provideDetailsOfNewUser()
{
    User user;
    string login, password, name, surname;

    user.setUserId(getIdOfNewUser());

    do
    {
        cout << "Login: ";
        cin >> login;
        user.setLogin(login);
    }
    while (doesLoginExists(user.getLogin()) == true);

    cout << "Password: ";
    cin >> password;
    user.setPassword(password);

    cout << "Name: ";
    cin >> name;
    user.setName(name);

    cout << "Surname: ";
    cin >> surname;
    user.setSurname(surname);

    return user;
}

int UserManager:: getIdOfNewUser()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getUserId() + 1;
}

bool UserManager:: doesLoginExists(string login)
{
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].getLogin() == login)
        {
            cout << endl <<  "User with such login already exists." << endl;
            return true;
        }
    }
    return false;
}

void UserManager:: showAllUsers()
{
    for (int i = 0; i < users.size(); i++)
    {
        cout << users[i].getUserId() << endl;
        cout << users[i].getLogin() << endl;
        cout << users[i].getPassword() << endl;
        cout << users[i].getName() << endl;
        cout << users[i].getSurname() << endl;
    }
}

int UserManager::userSignIn()
{
    User user;
    string login = "", password = "";

    cout << endl << "Login: ";
    login = AuxiliaryMethods::retrieveLine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr -> getLogin() == login)
        {
            for (int triesCount = 3; triesCount > 0; triesCount--)
            {
                cout << "Password. Tries left " << triesCount << ": ";
                password = AuxiliaryMethods::retrieveLine();

                if (itr -> getPassword() == password)
                {
                    cout << endl << "Signed in successfully." << endl << endl;
                    system("pause");
                    idOfSignedInUser = itr -> getUserId();
                    nameOfSignedInUser = itr -> getName();
                    surnameOfSignedInUser = itr -> getSurname();
                    return 0;
                }
            }
            cout << "Password entered incorrectly 3 times." << endl;
            system("pause");
            return 0;
        }
        itr++;
    }
    cout << "There is no user with such login" << endl << endl;
    system("pause");

    return 0;
}

void UserManager::changePassword()
{
    UserFile userFile;

    string newPassword = "";
    cout << "New password: ";
    newPassword = AuxiliaryMethods::retrieveLine();

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
    {
        if (itr -> getUserId() == idOfSignedInUser)
        {
            itr -> setPassword(newPassword);
            cout << "Password changed successfully." << endl << endl;
            system("pause");
        }
    }
    userFile.changePasswordInFile(idOfSignedInUser, newPassword);
}

bool UserManager::isUserSignedIn()
{
    if (idOfSignedInUser > 0)
        return true;
    else
        return false;
}

UserManager::UserManager()
{
    UserFile userFile;
    users = userFile.loadUsersFromFile();
}
