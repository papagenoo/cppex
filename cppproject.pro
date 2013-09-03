CONFIG += c++11

QT       += core

QT       -= gui

TARGET = cppproject
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += \
    main.cpp \
    quickfind.cpp \
    quickmerge.cpp \
    shift_search.cpp

HEADERS += \
    qfind.h \
    quickfind.h \
    quickmerge.h \
    shift_search.h
