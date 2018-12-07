#ifndef AGENDA_H
#define AGENDA_H

#include <QWidget>

namespace Ui {
class Agenda;
}

class Agenda : public QWidget
{
    Q_OBJECT

public:
    explicit Agenda(QWidget *parent = nullptr);
    ~Agenda();

private:
    Ui::Agenda *ui;
};

#endif // AGENDA_H
