//Drivers.cpp
#include "UserInterface.h"

//в конструкторе задаём имя водителя и номер рейса
Drivers::Drivers(string n, int aNo) : name(n), flightNumber(aNo)
{
    /* тут пусто */
}

Drivers::~Drivers() // деструктор
{
    /* тут тоже пусто */
}

int Drivers::getFlightNumber() //геттер возвращает номер рейса водителя
{
    return flightNumber;
}

string Drivers::getName() //геттер возвращает имя водителя
{
    return name;
}
