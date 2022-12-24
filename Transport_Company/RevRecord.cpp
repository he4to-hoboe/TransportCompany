//RevRecord.cpp
#include "tc.h"

//методы класса RevRecord//
RevRecord::~RevRecord() // деструктор
{ // удалить строки с платежами,
// удалить указатели из множества.
    while (!setPtrsRR.empty())
    {
        iter = setPtrsRR.begin();
        delete* iter;
        setPtrsRR.erase(iter);
    }
}

void RevRecord::insertRev(int FlightNo, int month, float amount)
{
    iter = setPtrsRR.begin(); // Инициализация итератора
    while (iter != setPtrsRR.end()) // условие выхода
    { // если текущий объект совпадает с созданным для поиска,
        if (FlightNo == (*iter)->getFlightNo())
    { // заносим доход в список
            (*iter)->setRev(month, amount);
            return;
        }
        else
            iter++;
    } // если не нашли строку - создаем новую
    FlightRevenue* ptrRow = new FlightRevenue(FlightNo);
    ptrRow->setRev(month, amount); // заносим в нее платеж
    setPtrsRR.push_back(ptrRow); // заносим строку в вектор
}

void RevRecord::display() // отобразить все строки с доходами
{
    cout << "\nNumber\tJan Feb Mar Apr May June July Aug Sept Oct Nov Dec\n" << endl
        << "------------------------------------------------------------------\n" << endl;
    if (setPtrsRR.empty())
        cout << "***No income***\n" << endl;
    else
    {
        iter = setPtrsRR.begin(); //итератор на список с указателями на объекты FlightRevenue
        while (iter != setPtrsRR.end())
        {
            cout << (*iter)->getFlightNo() << '\t'; // вывести номер рейса
            for (int j = 0; j < 12; j++) // вывести доходы по месяцам
            {
                if (((*iter)->getRevNo(j)) == 0)
                    cout << " 0 ";
                else
                    cout << (*iter)->getRevNo(j) << " ";
            }
            cout << endl;
            iter++;
        }
        cout << endl;
        cout << endl;
    }
}

float RevRecord::getSumOfRev() // сумма всех платежей
{
    float sumRevs = 0.0;
    iter = setPtrsRR.begin();
    while (iter != setPtrsRR.end())
    { // плюсуем суммы всех доходов водителей за все время
        sumRevs += (*iter)->getSumOfRev();
        iter++;
    }
    return sumRevs;
}

