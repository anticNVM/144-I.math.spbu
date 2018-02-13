TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    mergesort.cpp \
    list.cpp

HEADERS += \
    mergesort.h \
    list.h

DISTFILES += \
    input.txt

