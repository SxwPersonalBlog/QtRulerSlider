#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->horizontalSlider_2->setFixedSize(this->width(),50);
    ui->horizontalSlider_2->setSingleStep(1);
    ui->horizontalSlider_2->setRulerSliderRange(0,100);
    ui->horizontalSlider_2->setRulerSliderValue(50);

    QObject::connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),this,SLOT(sliderValueChanged(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::sliderValueChanged(int value)
{
    ui->horizontalSlider_2->setSingleStep(4);
    ui->horizontalSlider_2->setRulerSliderRange(value,value+400);
}
