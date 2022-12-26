//AnnualReport.h
#ifndef ANNUALREPORT
#define ANNUALREPORT
#include "UserInterface.h"
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
#endif // ANNUALREPORT

