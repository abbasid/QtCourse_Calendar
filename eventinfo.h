#ifndef EVENTINFO_H
#define EVENTINFO_H

#include <QString>

class eventInfo
{
public:
    eventInfo();
    QString getSubject() const;
    void setSubject(const QString &value);

    int getDuration() const;
    void setDuration(int value);

    QString getLocation() const;
    void setLocation(const QString &value);

    int getReminder() const;
    void setReminder(int value);

    QString getNote() const;
    void setNote(const QString &value);

    int getTime_year() const;
    void setTime_year(int value);

    int getTime_month() const;
    void setTime_month(int value);

    int getTime_date() const;
    void setTime_date(int value);

private:
    QString subject;
    QString location;
    QString note;
    int duration;
    int reminder;
    int time_year;
    int time_month;
    int time_date;
};

#endif // EVENTINFO_H
