#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <QMainWindow>
#include <QDateTime>

#include "mycalendar.h"
#include "ui_mycalendar.h"


class schedule : private Ui::MyCalendar
{
public:
    schedule();
    void updateDate();

private:
    QDateTime date;
};

#endif // SCHEDULE_H
