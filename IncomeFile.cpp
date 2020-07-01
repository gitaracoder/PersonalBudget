#include "IncomeFile.h"

void IncomeFile::addIncomeToFile(Income income)
{
    CMarkup xml;
    string sPath = "Incomes.xml";

    xml.Load(sPath);

// If the root element "INCOMES" does not exist, create it.
    if (!xml.FindElem("INCOMES"))
    {
        xml.AddElem(("INCOMES"));
    }

// Navigate into the root element.
    if (xml.IntoElem())
    {
        // AddElem() adds a new element at the end of the existing elements.
        if (xml.AddElem(("SINGLE_INCOME") ) && xml.IntoElem())
        {
            xml.AddElem("USER_ID", AuxiliaryMethods::convertIntToString(income.getUserId()));
            xml.AddElem("INC_ID", AuxiliaryMethods::convertIntToString(income.getIncomeId()));
            xml.AddElem("DATE", AuxiliaryMethods::convertIntToString(income.getDate()));
            xml.AddElem("ITEM", income.getItem());
            xml.AddElem("AMOUNT", AuxiliaryMethods::convertIntToString(income.getAmount()));
            xml.OutOfElem();
        }

        // Since the file will be closed, you don't really have to navigate out
        // of the root here, but it is just good practice to always have a
        // matching IntoElem()/OutOfElem() pair.
        xml.OutOfElem();
    }

    xml.Save(sPath);
}

vector <Income> IncomeFile::loadIncomesOfLoggedInUserFromFile(int userID)
{
    vector <Income> incomes;
    Income income;

    CMarkup xml;
    xml.Load("Incomes.xml");


    xml.FindElem(); // root ORDER element
    xml.IntoElem(); // inside ORDER
    while (xml.FindElem("SINGLE_INCOME"))
    {
        xml.IntoElem();

        xml.FindElem("USER_ID");
        if (AuxiliaryMethods::convertStringToInt(xml.GetData()) == userID)
        {
            xml.FindElem("USER_ID");
            income.setUserId(AuxiliaryMethods::convertStringToInt(xml.GetData()));

            xml.FindElem("INC_ID");
            income.setIncomeId(AuxiliaryMethods::convertStringToInt(xml.GetData()));

            xml.FindElem("DATE");
            income.setDate(AuxiliaryMethods::convertStringToInt(xml.GetData()));

            xml.FindElem("ITEM");
            income.setItem(xml.GetData());

            xml.FindElem("AMOUNT");
            income.setAmount(AuxiliaryMethods::convertStringToInt(xml.GetData()));

            xml.OutOfElem();

            incomes.push_back(income);
        }

    }

    return incomes;
}
