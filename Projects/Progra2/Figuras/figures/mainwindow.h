#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QColor>
#include <QPainter>
#include <QPixmap>
#include <QPen>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

private slots:
	void on_b_draw_circle_clicked();

private:
	void draw_circle(QPainter * painter);

private:
	Ui::MainWindow *ui;

	// draw objects
	QPainter * painter;
	QPixmap * pixmap;
	QPen * pen;
};

#endif // MAINWINDOW_H
