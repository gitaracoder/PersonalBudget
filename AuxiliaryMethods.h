#ifndef AUXILIARY_METHODS
#define AUXILIARY_METHODS

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class AuxiliaryMethods
{
public:
    static string retrieveLine();
    static char retrieveCharacter();
    static float retrieveFloatNumber();
    static string convertIntToString(int number);
    static int convertStringToInt(string number);
    static string convertFloatToString(float number);
    static float convertStringToFloat(string number);
};
#endif // AUXILIARY_METHODS
