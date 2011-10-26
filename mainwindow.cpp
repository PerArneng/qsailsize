#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "windsizetablemodel.h"

#include <iostream>
#include <algorithm>

#include <QRect>
#include <QDesktopWidget>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->model = new SailSizeModel(parent, 80);
    this->windSizeTableModel = new WindSizeTableModel(this, this->model);
    // connect the weightslider to the model
    QObject::connect(ui->weightSlider,SIGNAL(valueChanged(int)), this->model, SLOT(setWeight(int)));

    // connect the fromWindSlider to the model
    QObject::connect(ui->windSlider1,SIGNAL(valueChanged(int)),
                     this, SLOT(setWindSpeed(int)));

    // connect the fromWindSlider to the model
    QObject::connect(ui->windSlider2,SIGNAL(valueChanged(int)),
                     this, SLOT(setWindSpeed(int)));

    // connect the model update signal to the main window
    QObject::connect(this->model,SIGNAL(updated()), this, SLOT(modelUpdated()));

    ui->weightSlider->setValue(this->model->weight());

    ui->weightLabel->setMinimumWidth(90);
    ui->windRangeLabel->setMinimumWidth(90);

    this->updateWeightLabel();
    this->updateWindRangeLabel();

    ui->sailSizeTable->setModel(this->windSizeTableModel);
    ui->sailSizeTable->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    // center window on screen
    QRect frect = frameGeometry();
    frect.moveCenter(QDesktopWidget().availableGeometry().center());
    move(frect.topLeft());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateWeightLabel()
{
    this->ui->weightLabel->setText(QString("%1 Kg").arg(this->model->weight(), 3, 10));
}

void MainWindow::modelUpdated()
{
    this->updateWeightLabel();
    this->updateWindRangeLabel();
}

void MainWindow::setWindSpeed(int speed)
{
    int s1 = this->ui->windSlider1->value();
    int s2 = this->ui->windSlider2->value();
    int min = std::min(s1, s2);
    int max = std::max(s1, s2);
    this->model->setWindSpeedRange(min, max);
}

void MainWindow::updateWindRangeLabel()
{
    int from = this->model->fromWindSpeed();
    int to = this->model->toWindSpeed();
    this->ui->windRangeLabel->setText(QString("%1 -%2 m/s").arg(from, 3, 10).arg(to, 3, 10));
}





