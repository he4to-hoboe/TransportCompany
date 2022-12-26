TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    TransportCompany.cpp \
    Drivers.cpp \
    DriversList.cpp \
    DriversInputScreen.cpp \
    FlightRevenue.cpp \
    RevRecord.cpp \
    RevInputScreen.cpp \
    ExpenseInputScreen.cpp \
    ExpenseRecord.cpp \
    AnnualReport.cpp \
    UserInterface.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    Drivers.h \
    DriversList.h \
    DriversInputScreen.h \
    FlightRevenue.h \
    RevRecord.h \
    RevInputScreen.h \
    Expense.h \
    ExpenseInputScreen.h \
    ExpenseRecord.h \
    AnnualReport.h \
    UserInterface.h

