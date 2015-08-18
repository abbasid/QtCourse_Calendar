#include "mycalendar.h"
#include "ui_mycalendar.h"

MyCalendar::MyCalendar(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyCalendar)
{
    ui->setupUi(this);
    ui->scheduleTable->setRowCount(24);
    ui->scheduleTable->setColumnCount(8);
    date = date.currentDateTime();
    updateDate();
    addTimeInterval();
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
        ui->scheduleTable->setItem(0, i + 1, new QTableWidgetItem(local.toString(dateTmp,"yy/MM/dd ddd.")));
    }
}

void MyCalendar::addTimeInterval()
{
    ui->scheduleTable->setItem( 1, 0, new QTableWidgetItem("0:00 ~ 1:00"));
    ui->scheduleTable->setItem( 2, 0, new QTableWidgetItem("1:00 ~ 2:00"));
    ui->scheduleTable->setItem( 3, 0, new QTableWidgetItem("2:00 ~ 3:00"));
    ui->scheduleTable->setItem( 4, 0, new QTableWidgetItem("3:00 ~ 4:00"));
    ui->scheduleTable->setItem( 5, 0, new QTableWidgetItem("4:00 ~ 5:00"));
    ui->scheduleTable->setItem( 6, 0, new QTableWidgetItem("5:00 ~ 6:00"));
    ui->scheduleTable->setItem( 7, 0, new QTableWidgetItem("6:00 ~ 7:00"));
    ui->scheduleTable->setItem( 8, 0, new QTableWidgetItem("7:00 ~ 8:00"));
    ui->scheduleTable->setItem( 9, 0, new QTableWidgetItem("8:00 ~ 9:00"));
    ui->scheduleTable->setItem( 10, 0, new QTableWidgetItem("9:00 ~ 10:00"));
    ui->scheduleTable->setItem( 11, 0, new QTableWidgetItem("10:00 ~ 11:00"));
    ui->scheduleTable->setItem( 12, 0, new QTableWidgetItem("11:00 ~ 12:00"));
    ui->scheduleTable->setItem( 13, 0, new QTableWidgetItem("12:00 ~ 13:00"));
    ui->scheduleTable->setItem( 14, 0, new QTableWidgetItem("13:00 ~ 14:00"));
    ui->scheduleTable->setItem( 15, 0, new QTableWidgetItem("14:00 ~ 15:00"));
    ui->scheduleTable->setItem( 16, 0, new QTableWidgetItem("15:00 ~ 16:00"));
    ui->scheduleTable->setItem( 17, 0, new QTableWidgetItem("16:00 ~ 17:00"));
    ui->scheduleTable->setItem( 18, 0, new QTableWidgetItem("17:00 ~ 18:00"));
    ui->scheduleTable->setItem( 19, 0, new QTableWidgetItem("18:00 ~ 19:00"));
    ui->scheduleTable->setItem( 20, 0, new QTableWidgetItem("19:00 ~ 20:00"));
    ui->scheduleTable->setItem( 21, 0, new QTableWidgetItem("20:00 ~ 21:00"));
    ui->scheduleTable->setItem( 22, 0, new QTableWidgetItem("21:00 ~ 22:00"));
    ui->scheduleTable->setItem( 23, 0, new QTableWidgetItem("22:00 ~ 23:00"));
    ui->scheduleTable->setItem( 24, 0, new QTableWidgetItem("23:00 ~ 24:00"));
}

MyCalendar::~MyCalendar()
{
    delete ui;
}

void MyCalendar::receiveDuration(int duration)
{
    myCalendar_duration = duration;
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

void MyCalendar::on_scheduleTable_cellClicked(int row, int column)
{
    userClicked_row = row;
    userCliecked_column = column;
    singleEventDialog myEvent(row, column, date);
    myEvent.setModal(true);
    connect(&myEvent, SIGNAL(sendDuration(int)), this, SLOT(receiveDuration(int)));
    qDebug() << myCalendar_duration;
    myEvent.exec();

}

