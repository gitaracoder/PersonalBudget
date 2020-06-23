#include "AuxiliaryMethods.h"

string AuxiliaryMethods::retrieveLine()
{
    string input = "";
    getline(cin, input);
    return input;
}

char AuxiliaryMethods::retrieveCharacter()
{
    string input = "";
    char character  = {0};

    while (true)
    {
        getline(cin, input);

        if (input.length() == 1)
        {
            character = input[0];
            break;
        }
        cout << "This is not a single character. Type in again." << endl;
    }
    return character;
}

float AuxiliaryMethods::retrieveFloatNumber()
{
    float number;
    bool correct;

    do
    {
        cin >> number;
        correct = cin.good();
        cin.clear();
        cin.sync();

        if(correct != true)
            cout << "Wrong input" << endl;
    }
    while(correct != true);
    return number;
}

int AuxiliaryMethods::convertStringToInt(string number)
{
    int intNumber;
    istringstream iss(number);
    iss >> intNumber;
    return intNumber;
}

string AuxiliaryMethods::convertIntToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}
