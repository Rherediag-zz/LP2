#include "agenda.h"
#include "ui_agenda.h"

Agenda::Agenda(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Agenda)
{
    ui->setupUi(this);
}

Agenda::~Agenda()
{
    delete ui;
}
