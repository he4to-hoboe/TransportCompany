//tc.h
#ifndef TC_H
#define TC_H
#include <iostream>
#include <list>

using namespace std;
// глобальные методы //
void getaLine(string& inStr); // получение строки текста
char getaChar(); // получение символа



// класс Drivers (водители) //
//Он хранит имя водителя и номер рейса, в котором он находится.
class Drivers
{
private:
    string name; // имя водителя
    int flightNumber; // номер рейса, в котором он находится
public:
    Drivers(string n, int aNo);
    ~Drivers();
    int getFlightNumber(); //возвращает номер рейса водителя
    string getName(); //возвращает имя водителя
};



//класс DriversList//
//класс DriversList — список всех водителей.
//Он содержит множество указателей на класс Drivers
// и оперирует ими при выводе
class DriversList
{
private:
    // установить указатели на водителей
    list <Drivers*> setPtrsDrive; // указатели на класс водителей
    list <Drivers*>::iterator iter; //итератор
public:
    ~DriversList(); // деструктор (удаление водителей)
    void insertDriver(Drivers*); // добавить водителя в список
    int getFlightNo(string); // возвращает номер рейса
    void display(); // вывод списка водителей
};



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

