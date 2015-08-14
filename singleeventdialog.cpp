#include "singleeventdialog.h"
#include "ui_singleeventdialog.h"

singleEventDialog::singleEventDialog(int row, int column, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::singleEventDialog)
{
    ui->setupUi(this);
    schedule_row = row;;
    schedule_column = column;
    currentDate = currentDate.currentDateTime();
    updateDateRow();
    ui->time_year->setText(currentDate.toString("yyyy"));
}

void singleEventDialog::updateDateRow()
{
    QDateTime dateTmp;
    if (local.toString(currentDate, "ddd") == "Sun")
        currentDateRow = 0;
    else if (local.toString(currentDate, "ddd") == "Mon")
        currentDateRow = 1;
    else if (local.toString(currentDate, "ddd") == "Tue")
        currentDateRow = 2;
    else if (local.toString(currentDate, "ddd") == "Wed")
        currentDateRow = 3;
    else if (local.toString(currentDate, "ddd") == "Thu")
        currentDateRow = 4;
    else if (local.toString(currentDate, "ddd") == "Fri")
        currentDateRow = 5;
    else if (local.toString(currentDate, "ddd") == "Sat")
        currentDateRow = 6;
}

singleEventDialog::~singleEventDialog()
{
    delete ui;
}

void singleEventDialog::on_saveButton_clicked()
{
    Event.setSubject(ui->subject->text());
    Event.setTime_year((ui->time_year->text()).toInt());
    Event.setTime_month((ui->time_month->text()).toInt());
    Event.setTime_date((ui->time_date->text()).toInt());
    Event.setReminder(ui->reminder->currentRow());
    Event.setDuration(ui->duration->currentRow());
    Event.setLocation(ui->location->text());
    Event.setNote(ui->note->toPlainText());
    event.append(Event);
}
