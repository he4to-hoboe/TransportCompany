//tc.h
#ifndef TC_H
#define TC_H
#include <iostream>
#include <list>
#include "Drivers.h"
#include "DriversList.h"
#include "DriversInputScreen.h"
using namespace std;
// глобальные методы //
void getaLine(string& inStr); // получение строки текста
char getaChar(); // получение символа



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
