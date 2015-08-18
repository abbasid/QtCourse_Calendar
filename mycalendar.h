#ifndef MYCALENDAR_H
#define MYCALENDAR_H

#include <QMainWindow>
#include <QDateTime>
#include <qDebug>
#include <QLocale>
#include "singleeventdialog.h"

namespace Ui {
class MyCalendar;
}

class MyCalendar : public QMainWindow
{
    Q_OBJECT

public:
    explicit MyCalendar(QWidget *parent = 0);
    void updateDate();
    void addTimeInterval();
    ~MyCalendar();

public slots:
    void receiveDuration(int duration);

private slots:
    void on_lastWeek_clicked();

    void on_nextWeek_clicked();

    void on_scheduleTable_cellClicked(int row, int column);

private:
    Ui::MyCalendar *ui;
    QDateTime date;
    int userClicked_row;
    int userCliecked_column;
    int myCalendar_duration;

};

#endif // MYCALENDAR_H
