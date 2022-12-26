//ExpenseInputScreen.cpp
#include "tc.h"

//методы класса ExpenseInputScreen//
// конструктор
ExpenseInputScreen::ExpenseInputScreen(ExpenseRecord* per) : ptrExpenseRecord(per)
{
    /*пусто*/
}

void ExpenseInputScreen::setExpense()
{
    int month, day;
    string category, payee;
    float amount;
    cout << "Enter the month (1-12): "; //Введите месяц (1-12)
    cin >> month;
    cin.ignore(80, '\n');
    cout << "Enter the day (1-31): ";   //Введите день (1-31)
    cin >> day;
    cin.ignore(80, '\n');
    cout << "Enter the expense category (fuel, toll roads, repair, taxes): ";  // Введите категорию расходов (Топливо, Платные дороги, Ремонт, Налоги)
    getaLine(category);
    cout << "Enter the recipient (Gazprom, rosavtodor,service station, Russia): "; // Введите получателя (Газпром, РОСАВТОДОР, СТО, Россия)
    getaLine(payee);
    cout << "Enter the amount (350.65): "; // Введите сумму
    cin >> amount;
    cin.ignore(80, '\n');
    // создаем новый расход
    Expense* ptrExpense = new Expense(month, day, category, payee, amount);
    // вставляем расход в список всех расходов
    ptrExpenseRecord->insertExp(ptrExpense);
}
