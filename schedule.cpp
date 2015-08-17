#include "schedule.h"


schedule::schedule()
{
    date = date.currentDateTime();
}

void schedule::updateDate()
{
    QDateTime dateTmp;
    int currentDay;
    QLocale local = QLocale::English;
    if (local.toString(date, "ddd") == "Sun")
        currentDay = 0;
    else if (local.toString(date, "ddd") == "Mon")
        currentDay = 1;
    else if (local.toString(date, "ddd") == "Tue")
        currentDay = 2;
    else if (local.toString(date, "ddd") == "Wed")
        currentDay = 3;
    else if (local.toString(date, "ddd") == "Thu")
        currentDay = 4;
    else if (local.toString(date, "ddd") == "Fri")
        currentDay = 5;
    else if (local.toString(date, "ddd") == "Sat")
        currentDay = 6;

    for(int i = 0; i < 7; i++)
    {
        dateTmp = date.addDays(-currentDay + i);
        ui->scheduleTable->setItem(0, i, new QTableWidgetItem(local.toString(dateTmp,"MM/dd ddd")));
    }
}

