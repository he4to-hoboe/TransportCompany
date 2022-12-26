TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    TransportCompany.cpp \
    tc.cpp \
    Drivers.cpp \
    DriversList.cpp \
    DriversInputScreen.cpp \
    FlightRevenue.cpp \
    RevRecord.cpp \
    RevInputScreen.cpp \
    ExpenseInputScreen.cpp \
    ExpenseRecord.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    tc.h \
    Drivers.h \
    DriversList.h \
    DriversInputScreen.h \
    FlightRevenue.h \
    RevRecord.h \
    RevInputScreen.h \
    Expense.h \
    ExpenseInputScreen.h \
    ExpenseRecord.h

