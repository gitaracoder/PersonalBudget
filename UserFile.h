#ifndef USER_FILE
#define USER_FILE

#include <iostream>
#include <vector>
#include "Markup.h"
#include "User.h"
#include "AuxiliaryMethods.h"

using namespace std;

class UserFile
{
public:

    const string USER_FILE_NAME;
    CMarkup xml;
    void addUserToFile(User user);
    vector <User> loadUsersFromFile();
    void changePasswordInFile(int userId, string password);
};

#endif // USER_FILE
