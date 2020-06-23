#ifndef AUXILIARY_METHODS
#define AUXILIARY_METHODS

#include <iostream>
#include <sstream>

using namespace std;

class AuxiliaryMethods
{
public:
    static string retrieveLine();
    static char retrieveCharacter();
    static float retrieveFloatNumber();
    static string convertIntToString(int number);
    static int convertStringToInt(string number);
};
#endif // AUXILIARY_METHODS
