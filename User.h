#ifndef USER
#define USER

#include <iostream>

using namespace std;

class User
{
    int userId;
    string login;
    string name;
    string surname;
    string password;

public:
    void setUserId(int newId);
    void setLogin(string newLogin);
    void setName(string newName);
    void setSurname(string newSurname);
    void setPassword(string newPassword);

    int getUserId();
    string getLogin();
    string getName();
    string getSurname();
    string getPassword();
};

#endif // USER
