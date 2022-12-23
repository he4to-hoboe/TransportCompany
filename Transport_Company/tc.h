//tc.h
#ifndef TC_H
#define TC_H
#include <iostream>
#include <list>
#include "Drivers.h"
#include "DriversList.h"
using namespace std;
// глобальные методы //
void getaLine(string& inStr); // получение строки текста
char getaChar(); // получение символа




//класс DriversInputScreen//
//класс DriversInputScreen. Это класс, отвечающий за отображение «экрана»,
//куда пользователь может ввести данные о новом водителе:
class DriversInputScreen
{
private:
    DriversList* ptrDriversList;
    string tName;
    int FlightNo;
public:
    DriversInputScreen(DriversList* ptrDL) : ptrDriversList(ptrDL)
    {
        /* тут пусто */
    }
    void setDriver(); // добавить данные о водителе
};



//Класс UserInterface//
//Главный класс для запуска приложения:
//этот класс определяет взаимодействие пользователя с программой
class UserInterface
{
private:
    DriversList* ptrDriversList;
    DriversInputScreen* ptrDriversInputScreen;
    char ch;
public:
    UserInterface();
    ~UserInterface();
    void interact();
};
#endif // TC_H
