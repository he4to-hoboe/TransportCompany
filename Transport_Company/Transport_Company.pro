TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    TransportCompany.cpp \
    tc.cpp \
    Drivers.cpp \
    DriversList.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    tc.h \
    Drivers.h \
    DriversList.h

