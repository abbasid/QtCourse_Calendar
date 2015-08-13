#ifndef MYCALENDAR_H
#define MYCALENDAR_H

#include <QMainWindow>
#include <QDateTime>
#include <qDebug>
#include <QTextCodec>
#include <QLocale>

namespace Ui {
class MyCalendar;
}

class MyCalendar : public QMainWindow
{
    Q_OBJECT

public:
    explicit MyCalendar(QWidget *parent = 0);
    ~MyCalendar();

private:
    Ui::MyCalendar *ui;
    int currentDay;
    bool isDay;
};

#endif // MYCALENDAR_H
