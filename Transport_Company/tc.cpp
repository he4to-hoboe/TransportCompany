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
