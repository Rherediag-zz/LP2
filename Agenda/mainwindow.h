#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;

}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
private slots:
   // void IteratePressed();
   // void ActionButtons();

    void on_addButton_clicked();
    void on_backButton_clicked();
    void on_delButton_clicked();
    void on_nextButton_clicked();
};

#endif // MAINWINDOW_H
