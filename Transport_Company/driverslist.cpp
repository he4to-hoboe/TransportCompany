//DriversList.cpp
#include "UserInterface.h"

DriversList::~DriversList() // деструктор
{
    while (!setPtrsDrive.empty()) // удаление всех водителей,
    { // удаление указателей из контейнера
        iter = setPtrsDrive.begin();
        delete* iter;
        setPtrsDrive.erase(iter);
    }
}

void DriversList::insertDriver(Drivers* ptrD)
{
    setPtrsDrive.push_back(ptrD); // вставка нового водителя в список
}

int DriversList::getFlightNo(string tName) // получить номер рейса по имени водителя
{
    int FlightNo;
    iter = setPtrsDrive.begin();
    while (iter != setPtrsDrive.end())
    { // поиск водителя в списке (достаем у каждого водителя номер рейса)
        FlightNo = (*iter)->getFlightNumber();
        if (tName == ((*iter)->getName())) // сравниваем по именам и
        {
            // если получившаяся пара совпадает - значит,
            //мы нашли запись об этом водителе в списке, в этом случае
            return FlightNo; // возвращаем номер его рейса
        }
        iter++;
    }
    return -1; // если нет - возвращаем -1
}

void DriversList::display() // вывод списка водителей
{
    cout << "\nNumber#\tName Driver\n-------------------\n";
    if (setPtrsDrive.empty()) // если список водителей пуст
        cout << "***No driver***\n" << endl; // выводим запись, что он пуст)
    else
    {
        iter = setPtrsDrive.begin();
        while (iter != setPtrsDrive.end()) // распечатываем всех водителей
        {
            cout << (*iter)->getFlightNumber() << "   || " << (*iter)->getName() << endl;
            *iter++;
        }
    }
}
