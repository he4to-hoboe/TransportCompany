//tc.cpp
#include <iostream>
#include "tc.h"
void getaLine(string & inStr) // получение строки текста
{
    char temp[21];
    cin.get(temp, 20, '\n');
    cin.ignore(20, '\n'); //число пропускаемых символов и символ разделения
    inStr = temp;
}
//---------------------------------------------------------
char getaChar() // получение символа
{
    char ch = cin.get();
    cin.ignore(80, '\n'); //число пропускаемых символов и символ разделения
    return ch;
}





////методы класса FlightRevenue//
//FlightRevenue::FlightRevenue(int an) : FlightNo(an) //конструктор
//{ //Алгоритм fill() помещает копию значения value (у нас это 0)
////в каждый элемент диапазона, ограниченного парой итераторов [first,last).
////Т.е. в конструкторе просто инициализируем массив значениями 0.
//    fill(&months[0], &months[12], 0);
//}
////---------------------------------------------------------
//void FlightRevenue::setRev(int m, float am) // сеттер доход за месяц m, сумма - am
//{
//    months[m] = am; // привязываем оплату к месяцу
//}
////---------------------------------------------------------
//int FlightRevenue::getFlightNo() // геттер запрос номера рейса
//{
//    return FlightNo;
//}
////---------------------------------------------------------
//float FlightRevenue::getRevNo(int month) //Геттер запрос дохода за месяц month
//{
//    return months[month];
//}
////---------------------------------------------------------
//float FlightRevenue::getSumOfRev() // cумма дохода в строке
//{ //По умолчанию алгоритм accumulate() суммирует элементы.
// //Нужно указать точку старта, конечную точку и значение от которого начинаем прибавлять.
// //Чаще всего это ноль, но может быть и результат других вычислений.
//    return accumulate(&months[0], &months[12], 0);
//}



//методы класса RevRecord//
RevRecord::~RevRecord() // деструктор
{ // удалить строки с платежами,
// удалить указатели из множества.
    while (!setPtrsRR.empty())
    {
        iter = setPtrsRR.begin();
        delete* iter;
        setPtrsRR.erase(iter);
    }
}

void RevRecord::insertRev(int FlightNo, int month, float amount)
{
    iter = setPtrsRR.begin(); // Инициализация итератора
    while (iter != setPtrsRR.end()) // условие выхода
    { // если текущий объект совпадает с созданным для поиска,
        if (FlightNo == (*iter)->getFlightNo())
    { // заносим доход в список
            (*iter)->setRev(month, amount);
            return;
        }
        else
            iter++;
    } // если не нашли строку - создаем новую
    FlightRevenue* ptrRow = new FlightRevenue(FlightNo);
    ptrRow->setRev(month, amount); // заносим в нее платеж
    setPtrsRR.push_back(ptrRow); // заносим строку в вектор
}

void RevRecord::display() // отобразить все строки с доходами
{
    cout << "\nNumber\tJan Feb Mar Apr May June July Aug Sept Oct Nov Dec\n" << endl
        << "------------------------------------------------------------------\n" << endl;
    if (setPtrsRR.empty())
        cout << "***No income***\n" << endl;
    else
    {
        iter = setPtrsRR.begin(); //итератор на список с указателями на объекты FlightRevenue
        while (iter != setPtrsRR.end())
        {
            cout << (*iter)->getFlightNo() << '\t'; // вывести номер рейса
            for (int j = 0; j < 12; j++) // вывести доходы по месяцам
            {
                if (((*iter)->getRevNo(j)) == 0)
                    cout << " 0 ";
                else
                    cout << (*iter)->getRevNo(j) << " ";
            }
            cout << endl;
            iter++;
        }
        cout << endl;
        cout << endl;
    }
}

float RevRecord::getSumOfRev() // сумма всех платежей
{
    float sumRevs = 0.0;
    iter = setPtrsRR.begin();
    while (iter != setPtrsRR.end())
    { // плюсуем суммы всех доходов водителей за все время
        sumRevs += (*iter)->getSumOfRev();
        iter++;
    }
    return sumRevs;
}




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



//методы класса UserInterface//
UserInterface::UserInterface()
{
    ptrDriversList = new DriversList;
    ptrRevRecord = new RevRecord;
}


UserInterface::~UserInterface()
{
    delete ptrDriversList;
    delete ptrRevRecord;
}


void UserInterface::interact()
{
    while (true)
    {
            cout << "\n Click to add a driver 'a', \n"      //Нажмите для добавления водителя
                 << " Click to record the driver's income 'b', \n"  //Нажмите для записи дохода водителя
                 << " Click to withdraw drivers 'd', \n"		//Нажмите для вывода водителей
                 << " Click to withdraw revenue 'e', \n"          //Нажмите для вывода доходов
                 << " Click to exit the program 'q'\n";      //Нажмите для выхода из программы
            ch = getaChar();
            switch (ch)
            {
            case 'a': ptrDriversInputScreen = new DriversInputScreen(ptrDriversList);
                ptrDriversInputScreen->setDriver();
                delete ptrDriversInputScreen;
                break;
            case 'b': ptrRevInputScreen = new RevInputScreen(ptrDriversList, ptrRevRecord);
                            ptrRevInputScreen->setRev();
                            delete ptrRevInputScreen;
                            break;
            case 'd': ptrDriversList->display();
                break;
            case 'e': ptrRevRecord->display();
                break;
            case 'q':
                cout << "The program is completed"; // Программа завершена
                    return;
                break;
            default: cout << "Unknown output function\n"; //Неизвестная функция вывода
                break;
            } // конец switch
    } // конец while
} // конец interact()

