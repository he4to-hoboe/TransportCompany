//DriversInputScreen.h
#ifndef DRIVERSINPUTSCREEN
#define DRIVERSINPUTSCREEN
#include "UserInterface.h"
//класс DriversInputScreen. Это класс, отвечающий за отображение «экрана»,
//куда пользователь может ввести данные о новом водителе:
class DriversInputScreen
{
private:
    DriversList* ptrDriversList;
    string tName;
    int FlightNo;
public:
    DriversInputScreen(DriversList* ptrDL) : ptrDriversList(ptrDL)
    {
        /* тут пусто */
    }
    void setDriver(); // добавить данные о водителе
};
#endif // DRIVERSINPUTSCREEN
