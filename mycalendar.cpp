#include "mycalendar.h"
#include "ui_mycalendar.h"

MyCalendar::MyCalendar(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyCalendar)
{
    ui->setupUi(this);
    ui->scheduleTable->setRowCount(24);
    ui->scheduleTable->setColumnCount(7);
    date = date.currentDateTime();
    updateDate();
}

void MyCalendar::updateDate()
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
        ui->scheduleTable->setItem(0, i, new QTableWidgetItem(local.toString(dateTmp,"yyyy/MM/dd ddd.")));
    }
}

MyCalendar::~MyCalendar()
{
    delete ui;
}

void MyCalendar::on_lastWeek_clicked()
{
    date = date.addDays(-7);
    updateDate();
}

void MyCalendar::on_nextWeek_clicked()
{
    date = date.addDays(7);
    updateDate();
}
