//tc.h
#ifndef TC_H
#define TC_H

#include <iostream>
#include <list>
#include <vector>
#include <numeric> //для accumulate()
#include "Drivers.h"
#include "DriversList.h"
#include "DriversInputScreen.h"
#include "FlightRevenue.h"
using namespace std;
// глобальные методы //
void getaLine(string& inStr); // получение строки текста
char getaChar(); // получение символа


//////////////////// класс RevRecord ///////////////////////
//класс RevRecord. Он хранит непосредственно записи доходов.
//С ним будет взаимодействовать экран добавления дохода.
class RevRecord
{
private:
    list <FlightRevenue*> setPtrsRR; // указатели на объекты FlightRevenue (по одному на водителя)
    list <FlightRevenue*>::iterator iter;
public:
    ~RevRecord();
    void insertRev(int, int, float); // добавить плату
    void display(); // отобразить все строки с платами
    float getSumOfRev(); // подсчитать сумму всех платежей всех водителей
};



////////////////////класс RevInputScreen //////////////////
//Экран для добавления платы
class RevInputScreen
{
private:
    DriversList* ptrDriversList; // список водителей
    RevRecord* ptrRevRecord; // список записей об оплате
    string revName; // имя водителя, который приносит прибыль
    float revPaid; // плата
    int month; // за месяц
    int FlightNo; // по рейсам
public:
    RevInputScreen(DriversList* ptrDL, RevRecord* ptrRR) : ptrDriversList(ptrDL),
        ptrRevRecord(ptrRR)
    {
        /*тут пусто*/
    }
    void setRev(); // добавить доход с одного водителя за месяц
};




//Класс UserInterface//
//Главный класс для запуска приложения:
//этот класс определяет взаимодействие пользователя с программой
class UserInterface
{
private:
    DriversList* ptrDriversList;
    DriversInputScreen* ptrDriversInputScreen;
    RevRecord* ptrRevRecord;
    RevInputScreen* ptrRevInputScreen;

    char ch;
public:
    UserInterface();
    ~UserInterface();
    void interact();
};
#endif // TC_H

