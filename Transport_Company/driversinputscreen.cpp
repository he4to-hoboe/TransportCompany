//DriversInputScreen.cpp
#include "tc.h"
//метод класса DriversInputScreen//
void DriversInputScreen::setDriver() // добавить данные о водителе
{
    cout << "Enter the driver's name (Alexander Masloy): " << endl; // Введите имя водителя (Александр Маслов):
    getaLine(tName);
    cout << "Enter the flight number (515): " << endl; // Введите номер рейса (515):
    cin >> FlightNo;
    cin.ignore(80, '\n');
    Drivers* ptrDriver = new Drivers(tName, FlightNo); // создать водителя
    ptrDriversList->insertDriver(ptrDriver); // занести в список водителей
}
