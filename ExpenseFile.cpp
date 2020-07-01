#include "ExpenseFile.h"

void ExpenseFile::addExpenseToFile(Expense expense)
{
    CMarkup xml;
    string sPath = "Expences.xml";

    xml.Load(sPath);

// If the root element "EXPENCES" does not exist, create it.
    if (!xml.FindElem("EXPENCES"))
    {
        xml.AddElem(("EXPENCES"));
    }

// Navigate into the root element.
    if (xml.IntoElem())
    {
        // AddElem() adds a new element at the end of the existing elements.
        if (xml.AddElem(("SINGLE_EXPENCE") ) && xml.IntoElem())
        {
            xml.AddElem("USER_ID", AuxiliaryMethods::convertIntToString(expense.getUserId()));
            xml.AddElem("EXP_ID", AuxiliaryMethods::convertIntToString(expense.getExpenseId()));
            xml.AddElem("DATE", AuxiliaryMethods::convertIntToString(expense.getDate()));
            xml.AddElem("ITEM", expense.getItem());
            xml.AddElem("AMOUNT", AuxiliaryMethods::convertIntToString(expense.getAmount()));
            xml.OutOfElem();
        }

        // Since the file will be closed, you don't really have to navigate out
        // of the root here, but it is just good practice to always have a
        // matching IntoElem()/OutOfElem() pair.
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


    xml.FindElem(); // root ORDER element
    xml.IntoElem(); // inside ORDER
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
            expense.setAmount(AuxiliaryMethods::convertStringToInt(xml.GetData()));

            xml.OutOfElem();

            expenses.push_back(expense);
        }

    }

    return expenses;
}
