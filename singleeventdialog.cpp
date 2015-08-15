#include "singleeventdialog.h"
#include "ui_singleeventdialog.h"

singleEventDialog::singleEventDialog(int row, int column, QDateTime date, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::singleEventDialog)
{
    ui->setupUi(this);
    schedule_row = row;;
    schedule_column = column;
    currentDate = date; //currentDate.currentDateTime();
    updateDateColumn();
    ui->time_year->setText(currentDate.toString("yyyy"));
}

void singleEventDialog::updateDateColumn()
{
    QDateTime dateTmp;
    int userClickedColumn;
    if (local.toString(currentDate, "ddd") == "Sun")
        currentDateColumn = 0;
    else if (local.toString(currentDate, "ddd") == "Mon")
        currentDateColumn = 1;
    else if (local.toString(currentDate, "ddd") == "Tue")
        currentDateColumn = 2;
    else if (local.toString(currentDate, "ddd") == "Wed")
        currentDateColumn = 3;
    else if (local.toString(currentDate, "ddd") == "Thu")
        currentDateColumn = 4;
    else if (local.toString(currentDate, "ddd") == "Fri")
        currentDateColumn = 5;
    else if (local.toString(currentDate, "ddd") == "Sat")
        currentDateColumn = 6;
    dateTmp = currentDate.addDays(schedule_column - currentDateColumn - 1);
    ui->time_month->setText(dateTmp.toString("MM"));
    ui->time_date->setText(dateTmp.toString("dd"));
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
