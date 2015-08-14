#include "eventinfo.h"

eventInfo::eventInfo()
{

}
QString eventInfo::getSubject() const
{
    return subject;
}

void eventInfo::setSubject(const QString &value)
{
    subject = value;
}

int eventInfo::getDuration() const
{
    return duration;
}

void eventInfo::setDuration(int value)
{
    duration = value;
}
QString eventInfo::getLocation() const
{
    return location;
}

void eventInfo::setLocation(const QString &value)
{
    location = value;
}
int eventInfo::getReminder() const
{
    return reminder;
}

void eventInfo::setReminder(int value)
{
    reminder = value;
}
QString eventInfo::getNote() const
{
    return note;
}

void eventInfo::setNote(const QString &value)
{
    note = value;
}
int eventInfo::getTime_year() const
{
    return time_year;
}

void eventInfo::setTime_year(int value)
{
    time_year = value;
}
int eventInfo::getTime_month() const
{
    return time_month;
}

void eventInfo::setTime_month(int value)
{
    time_month = value;
}
int eventInfo::getTime_date() const
{
    return time_date;
}

void eventInfo::setTime_date(int value)
{
    time_date = value;
}










