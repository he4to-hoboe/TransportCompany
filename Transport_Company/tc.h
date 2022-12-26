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
using namespace std;
// глобальные методы //
void getaLine(string& inStr); // получение строки текста
char getaChar(); // получение символа

//класс Expense//
//Класс затрат
class Expense
{
public:
    int month, day; // месяц и день уплаты расходов
    string category; // категория расходов (топливо, платные налоги, ремонт/ТО, налоги)
    string payee; // кому платим (АЗС, РОСАВТОДОР, СТО, государство, )
    float amount; // сколько платим
    Expense()
    { }
    Expense(int m, int d, string c, string p, float a) :
        month(m), day(d), category(c), payee(p), amount(a)
    {
        /* тут пусто! */
    }
};


//класс ExpenseRecord//
//Класс записей о затратах
class ExpenseRecord
{
private:
    vector<Expense*> vectPtrsExpenses; //вектор указателей на расходы
    vector<Expense*>::iterator iter;
public:
    ~ExpenseRecord();
    void insertExp(Expense*);
    void display();
    float displaySummary(); // нужно для годового отчета
};

//класс ExpenseInputScreen//
//Класс для ввода расходов
class ExpenseInputScreen
{
private:
    ExpenseRecord* ptrExpenseRecord; // запись о расходах
public:
    ExpenseInputScreen(ExpenseRecord*);
    void setExpense();
};

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

