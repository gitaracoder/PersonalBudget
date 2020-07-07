#include "IncomeFile.h"

void IncomeFile::addIncomeToFile(Income income)
{
    CMarkup xml;
    string sPath = "Incomes.xml";
    xml.Load(sPath);

    if (!xml.FindElem("INCOMES"))
    {
        xml.AddElem(("INCOMES"));
    }

    if (xml.IntoElem())
    {
        if (xml.AddElem(("SINGLE_INCOME") ) && xml.IntoElem())
        {
            xml.AddElem("USER_ID", AuxiliaryMethods::convertIntToString(income.getUserId()));
            xml.AddElem("INC_ID", AuxiliaryMethods::convertIntToString(income.getIncomeId()));
            xml.AddElem("DATE", AuxiliaryMethods::convertIntToString(income.getDate()));
            xml.AddElem("ITEM", income.getItem());
            xml.AddElem("AMOUNT", AuxiliaryMethods::convertFloatToString(income.getAmount()));
            xml.OutOfElem();
        }
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

    xml.FindElem();
    xml.IntoElem();
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
            income.setAmount(AuxiliaryMethods::convertStringToFloat(xml.GetData()));

            incomes.push_back(income);
        }
        xml.OutOfElem();
    }

    return incomes;
}

int IncomeFile::getLastIncomeId()
{
    int n = 0;
    CMarkup xml;
    xml.Load("Incomes.xml");
    string lastIncomeId;
    xml.FindElem();
    xml.IntoElem();
    while (xml.FindElem("SINGLE_INCOME"))
    {
        xml.IntoElem();
        xml.FindElem("INC_ID");
        lastIncomeId = xml.GetData();
        xml.OutOfElem();
        n++;
    }

    if (n == 0)
        return 0;
    else
        return AuxiliaryMethods::convertStringToInt(lastIncomeId);
}
