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



//методы класса Drivers//
//в конструкторе задаём имя водителя и номер рейса
Drivers::Drivers(string n, int aNo) : name(n), flightNumber(aNo)
{
    /* тут пусто */
}


Drivers::~Drivers() // деструктор
{
    /* тут тоже пусто */
}


int Drivers::getFlightNumber() //геттер возвращает номер рейса водителя
{
    return flightNumber;
}


string Drivers::getName() //геттер возвращает имя водителя
{
    return name;
}



//метод класса DriversInputScreen//
void DriversInputScreen::setDriver() // добавить данные о водителе
{
    cout << "Enter the driver's name (Alexander Masloy): " << endl; // Введите имя водителя (Александр Маслов):
    getaLine(tName);
    cout << "Enter the flight number (515): " << endl; // Введите номер рейса (515):
    cin >> FlightNo;
    cin.ignore(80, '\n');
    Drivers* ptrDriver = new Drivers(tName, FlightNo); // создать водителя
    ptrDriversList->insertDriver(ptrDriver); // занести в список водителей
}



//методы класса DriversList//
DriversList::~DriversList() // деструктор
{
    while (!setPtrsDrive.empty()) // удаление всех водителей,
    { // удаление указателей из контейнера
        iter = setPtrsDrive.begin();
        delete* iter;
        setPtrsDrive.erase(iter);
    }
}


void DriversList::insertDriver(Drivers* ptrD)
{
    setPtrsDrive.push_back(ptrD); // вставка нового водителя в список
}


int DriversList::getFlightNo(string tName) // получить номер рейса по имени водителя
{
    int FlightNo;
    iter = setPtrsDrive.begin();
    while (iter != setPtrsDrive.end())
    { // поиск водителя в списке (достаем у каждого водителя номер рейса)
        FlightNo = (*iter)->getFlightNumber();
        if (tName == ((*iter)->getName())) // сравниваем по именам и
        {
            // если получившаяся пара совпадает - значит,
            //мы нашли запись об этом водителе в списке, в этом случае
            return FlightNo; // возвращаем номер его рейса
        }
        iter++;
    }
    return -1; // если нет - возвращаем -1
}


void DriversList::display() // вывод списка водителей
{
    cout << "\nNumber#\tName Driver\n-------------------\n";
    if (setPtrsDrive.empty()) // если список водителей пуст
        cout << "***No driver***\n" << endl; // выводим запись, что он пуст)
    else
    {
        iter = setPtrsDrive.begin();
        while (iter != setPtrsDrive.end()) // распечатываем всех водителей
        {
            cout << (*iter)->getFlightNumber() << "   || " << (*iter)->getName() << endl;
            *iter++;
        }
    }
}


//методы класса UserInterface//
UserInterface::UserInterface()
{
    ptrDriversList = new DriversList;
}


UserInterface::~UserInterface()
{
    delete ptrDriversList;
}


void UserInterface::interact()
{
    while (true)
    {
            cout << "\n Click to add a driver 'a', \n"      //Нажмите для добавления водителя
                << " Click to withdraw drivers 'd', \n"		//Нажмите для вывода водителей
                << " Click to exit the program 'q'\n";      //Нажмите для выхода из программы
            ch = getaChar();
            switch (ch)
            {
            case 'a': ptrDriversInputScreen = new DriversInputScreen(ptrDriversList);
                ptrDriversInputScreen->setDriver();
                delete ptrDriversInputScreen;
                break;
            case 'd': ptrDriversList->display();
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
