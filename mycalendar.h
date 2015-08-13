#ifndef MYCALENDAR_H
#define MYCALENDAR_H

#include <QMainWindow>
#include <QDateTime>
#include <qDebug>
#include <QLocale>

namespace Ui {
class MyCalendar;
}

class MyCalendar : public QMainWindow
{
    Q_OBJECT

public:
    explicit MyCalendar(QWidget *parent = 0);
    void updateDate();
    ~MyCalendar();

private slots:
    void on_lastWeek_clicked();

    void on_nextWeek_clicked();

private:
    Ui::MyCalendar *ui;
    QDateTime date;

};

#endif // MYCALENDAR_H
