#ifndef SINGLEEVENTDIALOG_H
#define SINGLEEVENTDIALOG_H

#include <QDialog>
#include <QVector>
#include <QDateTime>
#include <QLocale>
#include "eventinfo.h"
#include "mycalendar.h"

namespace Ui {
class singleEventDialog;
}

class singleEventDialog : public QDialog
{
    Q_OBJECT

public:
    explicit singleEventDialog(int row, int column, QDateTime date, QWidget *parent = 0);
    void updateDateColumn();
    ~singleEventDialog();

private slots:
    void on_saveButton_clicked();

private:
    Ui::singleEventDialog *ui;
    eventInfo Event;
    QVector<eventInfo> event;
    QDateTime currentDate;
    int schedule_row;
    int schedule_column;
    int currentDateColumn;
    QLocale local = QLocale::English;
};

#endif // SINGLEEVENTDIALOG_H
