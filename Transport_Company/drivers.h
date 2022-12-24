//Drivers.h
#ifndef DRIVERS
#define DRIVERS
#include "tc.h"
using namespace std;
// класс Drivers (водители) //
//Он хранит имя водителя и номер рейса, в котором он находится.
class Drivers
{
private:
    string name; // имя водителя
    int flightNumber; // номер рейса, в котором он находится
public:
    Drivers(string n, int aNo);
    ~Drivers();
    int getFlightNumber(); //возвращает номер рейса водителя
    string getName(); //возвращает имя водителя
};
#endif // DRIVERS

