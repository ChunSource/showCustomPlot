#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qcustomplot.h"
namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT
	
public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();
	
private:
	Ui::MainWindow *ui;
	QCustomPlot *customPlot;
	
	//记录每条轴的最大值和最小值
	int MaxX = 2;
	int MaxY = 2;
	int MinX = 0;
	int MinY = 0;
	
	QVector<double> x;
	QVector<double> y;
	
	
private slots:
	void pushData();
};

#endif // MAINWINDOW_H
