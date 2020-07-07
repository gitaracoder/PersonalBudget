#include "ExpenseFile.h"

void ExpenseFile::addExpenseToFile(Expense expense)
{
    CMarkup xml;
    string sPath = "Expences.xml";
    xml.Load(sPath);

    if (!xml.FindElem("EXPENCES"))
    {
        xml.AddElem(("EXPENCES"));
    }

    if (xml.IntoElem())
    {
        if (xml.AddElem(("SINGLE_EXPENCE") ) && xml.IntoElem())
        {
            xml.AddElem("USER_ID", AuxiliaryMethods::convertIntToString(expense.getUserId()));
            xml.AddElem("EXP_ID", AuxiliaryMethods::convertIntToString(expense.getExpenseId()));
            xml.AddElem("DATE", AuxiliaryMethods::convertIntToString(expense.getDate()));
            xml.AddElem("ITEM", expense.getItem());
            xml.AddElem("AMOUNT", AuxiliaryMethods::convertFloatToString(expense.getAmount()));
            xml.OutOfElem();
        }

        xml.OutOfElem();
    }
    xml.Save(sPath);
}

vector <Expense> ExpenseFile::loadExpensesOfLoggedInUserFromFile(int userID)
{
    vector <Expense> expenses;
    Expense expense;

    CMarkup xml;
    xml.Load("Expences.xml");
    xml.FindElem();
    xml.IntoElem();
    while (xml.FindElem("SINGLE_EXPENCE"))
    {
        xml.IntoElem();

        xml.FindElem("USER_ID");
        if (AuxiliaryMethods::convertStringToInt(xml.GetData()) == userID)
        {
            xml.FindElem("USER_ID");
            expense.setUserId(AuxiliaryMethods::convertStringToInt(xml.GetData()));

            xml.FindElem("EXP_ID");
            expense.setExpenseId(AuxiliaryMethods::convertStringToInt(xml.GetData()));

            xml.FindElem("DATE");
            expense.setDate(AuxiliaryMethods::convertStringToInt(xml.GetData()));

            xml.FindElem("ITEM");
            expense.setItem(xml.GetData());

            xml.FindElem("AMOUNT");
            expense.setAmount(AuxiliaryMethods::convertStringToFloat(xml.GetData()));

            expenses.push_back(expense);
        }
        xml.OutOfElem();
    }

    return expenses;
}

int ExpenseFile::getLastExpenseId()
{
    int n = 0;
    CMarkup xml;
    xml.Load("Expences.xml");
    string lastExpenseId;
    xml.FindElem();
    xml.IntoElem();
    while (xml.FindElem("SINGLE_EXPENCE"))
    {
        xml.IntoElem();
        xml.FindElem("EXP_ID");
        lastExpenseId = xml.GetData();
        xml.OutOfElem();
        n++;
    }

    if (n == 0)
        return 0;
    else
        return AuxiliaryMethods::convertStringToInt(lastExpenseId);
}
