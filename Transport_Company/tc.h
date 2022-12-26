//tc.h
#ifndef TC_H
#define TC_H

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <numeric> //для accumulate()
#include "Drivers.h"
#include "DriversList.h"
#include "DriversInputScreen.h"
#include "FlightRevenue.h"
#include "RevRecord.h"
#include "RevInputScreen.h"
#include "Expense.h"
#include "ExpenseRecord.h"
#include "ExpenseInputScreen.h"

using namespace std;
// глобальные методы //
void getaLine(string& inStr); // получение строки текста
char getaChar(); // получение символа

//класс AnnualReport//
//Класс годового отчета
class AnnualReport
{
private:
    RevRecord* ptrRR; // записи доходов
    ExpenseRecord* ptrER; // записи расходов
    float expenses, revenues; // суммы доходов и расходов
public:
    AnnualReport(RevRecord*, ExpenseRecord*);
    void display(); // отображение годового отчета
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
    ExpenseRecord* ptrExpenseRecord;
    ExpenseInputScreen* ptrExpenseInputScreen;
    AnnualReport* ptrAnnualReport;
    char ch;
public:
    UserInterface();
    ~UserInterface();
    void interact();
};
#endif // TC_H

