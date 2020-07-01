#ifndef USER_MANAGER
#define USER_MANAGER

#include <iostream>
#include <vector>
#include "User.h"
#include "AuxiliaryMethods.h"
#include "UserFile.h"

using namespace std;

class UserManager
{
public:
    vector <User> users;

    UserManager();

    int idOfSignedInUser;

    void userSignUp();
    User provideDetailsOfNewUser();
    int getIdOfNewUser();
    bool doesLoginExists(string login);
    void showAllUsers();
    int userSignIn();
    void changePassword();
    bool isUserSignedIn();

};
#endif // USER_MANAGER
