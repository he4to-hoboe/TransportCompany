//RevInputScreen.cpp
#include "tc.h"

            //методы класса RevInputScreen//

void RevInputScreen::setRev()
{
    cout << "Enter the driver's name: ";
    getaLine(revName);
    // получить номер рейса по имени водителя
    FlightNo = ptrDriversList->getFlightNo(revName);
    if (FlightNo > 0) // если имя найдено, и такой водитель существует -
    { // получить сумму платежа
        cout << "Enter the amount of income (800.50): " << endl; // Введите сумму дохода (800.50)
        cin >> revPaid; // вводим цену
        cin.ignore(80, '\n');
        cout << "Enter the payment month number (1-12): " << endl; // Введите номер месяца оплаты (1-12)
        cin >> month;
        cin.ignore(80, '\n');
        month--; // (внутренняя нумерация 0-11)
         // вставляем сумму в запись о доходе
        ptrRevRecord->insertRev(FlightNo, month, revPaid);
    }
    else
        cout << "There is no such driver.\n" << endl; //Такого водителя нет
}
