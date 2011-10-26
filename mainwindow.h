#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "sailsizemodel.h"
#include "windsizetablemodel.h"

#include <QMainWindow>


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
    SailSizeModel *model;
    WindSizeTableModel *windSizeTableModel;
    Ui::MainWindow *ui;

    void updateWeightLabel();
    void updateWindRangeLabel();

public slots:
    void setWindSpeed(int);
    void modelUpdated();

};

#endif // MAINWINDOW_H
