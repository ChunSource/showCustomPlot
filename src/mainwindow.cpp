#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	connect(ui->pushButton,&QPushButton::clicked,this,&MainWindow::pushData);
	
	
	customPlot = ui->widget; // 创建一个指针，方便使用，省去  "ui->"
	
	customPlot->addGraph();   //说白了就是添加一条线
	
	customPlot->xAxis->setLabel("这里是X轴");   //XY轴的名字
	customPlot->yAxis->setLabel("这里是Y轴");  //
	
	customPlot->xAxis->setRange(MinX,MaxX);   //这里我们设置默认的轴值
	customPlot->yAxis->setRange(MinY,MaxY);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::pushData()
{
	double xNumber = ui->LineX->text().toInt();
	double yNumber = ui->LineY->text().toInt();
	
	
	if(xNumber > MaxX)
		{
			MaxX = xNumber;
		}
	if(xNumber < MinX)
		{
			MinX = xNumber;
		}
	if(yNumber > MaxY)
		{
			MaxY = yNumber;
		}
	if(yNumber < MinY)
		{
			MinY = yNumber;
		}
	x.push_back(xNumber);
	y.push_back(yNumber);
	customPlot->xAxis->setRange(MinX,MaxX);   //这里我们设置默认的轴值
	customPlot->yAxis->setRange(MinY,MaxY);
	customPlot->graph(0)->setData(x,y);
	customPlot->replot();
	qDebug()<<"X "<<x;
	qDebug()<<"Y "<<y;
}
