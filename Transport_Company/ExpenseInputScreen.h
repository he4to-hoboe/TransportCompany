//ExpenseInputScreen.h
#ifndef EXPENSEINPUTSCREEN
#define EXPENSEINPUTSCREEN
#include "tc.h"

//Класс для ввода расходов
class ExpenseInputScreen
{
private:
    ExpenseRecord* ptrExpenseRecord; // запись о расходах
public:
    ExpenseInputScreen(ExpenseRecord*);
    void setExpense();
};
#endif // EXPENSEINPUTSCREEN
