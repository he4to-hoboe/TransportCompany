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

