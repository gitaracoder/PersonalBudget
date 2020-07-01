#include "UserFile.h"

void UserFile::addUserToFile(User user)
{
    CMarkup xml;
    string sPath = "Users.xml";

    xml.Load(sPath);

// If the root element "USERS" does not exist, create it.
    if (!xml.FindElem("USERS"))
    {
        xml.AddElem(("USERS"));
    }

// Navigate into the root element.
    if (xml.IntoElem())
    {
        // AddElem() adds a new element at the end of the existing elements.
        if (xml.AddElem(("SINGLE_USER") ) && xml.IntoElem())
        {
            xml.AddElem("ID", AuxiliaryMethods::convertIntToString(user.getUserId()));
            xml.AddElem("LOGIN", user.getLogin());
            xml.AddElem("PASSWORD", user.getPassword());
            xml.AddElem("NAME", user.getName());
            xml.AddElem("SURNAME", user.getSurname());
            xml.OutOfElem();
        }

        // Since the file will be closed, you don't really have to navigate out
        // of the root here, but it is just good practice to always have a
        // matching IntoElem()/OutOfElem() pair.
        xml.OutOfElem();
    }

    xml.Save(sPath);
}

vector <User> UserFile::loadUsersFromFile()
{
    vector <User> users;
    User user;

    CMarkup xml;
    xml.Load("Users.xml");


    xml.FindElem(); // root ORDER element
    xml.IntoElem(); // inside ORDER
    while (xml.FindElem("SINGLE_USER"))
    {
        xml.IntoElem();

        xml.FindElem("ID");
        user.setUserId(AuxiliaryMethods::convertStringToInt(xml.GetData()));

        xml.FindElem("LOGIN");
        user.setLogin(xml.GetData());

        xml.FindElem("PASSWORD");
        user.setPassword(xml.GetData());

        xml.FindElem("NAME");
        user.setName(xml.GetData());

        xml.FindElem("SURNAME");
        user.setSurname(xml.GetData());

        xml.OutOfElem();

        users.push_back(user);
    }

    return users;
}

void UserFile::changePasswordInFile(int userId, string password)
{
    CMarkup xml;
    string sPath = "Users.xml";

    xml.Load(sPath);

    xml.FindElem(); // root ORDER element
    xml.IntoElem(); // inside ORDER
    while (xml.FindElem("SINGLE_USER"))
    {
        xml.IntoElem();
        xml.FindElem("ID");
        if(AuxiliaryMethods::convertStringToInt(xml.GetData()) == userId)
        {
            xml.FindElem("PASSWORD");
            xml.RemoveElem();
            xml.AddElem("PASSWORD", password);
        }
        xml.OutOfElem();
    }

    xml.Save(sPath);
}
