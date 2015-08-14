#ifndef SINGLEEVENTDIALOG_H
#define SINGLEEVENTDIALOG_H

#include <QDialog>
#include <QVector>
#include "eventinfo.h"

namespace Ui {
class singleEventDialog;
}

class singleEventDialog : public QDialog
{
    Q_OBJECT

public:
    explicit singleEventDialog(QWidget *parent = 0);
    ~singleEventDialog();

private slots:
    void on_saveButton_clicked();

private:
    Ui::singleEventDialog *ui;
    eventInfo Event;
    QVector<eventInfo> event;
};

#endif // SINGLEEVENTDIALOG_H
