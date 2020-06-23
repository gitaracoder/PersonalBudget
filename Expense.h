#ifndef EXPENSE
#define EXPENSE

#include <iostream>

using namespace std;

class Expense
{
public:
    int expenseId;
    int userId;
    int date;
    string item;
    float amount;
};

#endif // EXPENSE
