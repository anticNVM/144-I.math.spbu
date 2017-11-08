TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    myfparr.cpp \
    mysorts.cpp

HEADERS += \
    myfparr.h \
    mysorts.h

DISTFILES += \
    ../../../cpp_builds/4_2-Desktop_Qt_5_5_1_GCC_64bit-Debug/input.txt
