#include "singleeventdialog.h"
#include "ui_singleeventdialog.h"

singleEventDialog::singleEventDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::singleEventDialog)
{
    ui->setupUi(this);
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
