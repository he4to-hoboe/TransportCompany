//Expense.h
#ifndef EXPENSE
#define EXPENSE
#include "tc.h"

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
#endif // EXPENSE
