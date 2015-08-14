#-------------------------------------------------
#
# Project created by QtCreator 2015-08-13T16:19:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtCourse_Calendar
TEMPLATE = app


SOURCES += main.cpp\
        mycalendar.cpp \
    singleeventdialog.cpp \
    eventinfo.cpp

HEADERS  += mycalendar.h \
    singleeventdialog.h \
    eventinfo.h

FORMS    += mycalendar.ui \
    singleeventdialog.ui
