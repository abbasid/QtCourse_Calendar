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

private slots:
    void on_lastWeek_clicked();

    void on_nextWeek_clicked();

    void on_scheduleTable_cellClicked(int row, int column);

private:
    Ui::MyCalendar *ui;
    QDateTime date;

};

#endif // MYCALENDAR_H
