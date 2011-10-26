#ifndef SAILSIZEMODEL_H
#define SAILSIZEMODEL_H

#include <QObject>
#include <QVector>

class SailSizeModel : public QObject
{
    Q_OBJECT
public:
    SailSizeModel(QObject *parent = 0, int startWeight = 80,
                  int fromWindSpeed = 4, int toWindSpeed = 20);
    ~SailSizeModel();
    int weight();
    QVector<int> *windSpeeds();
    void setWindSpeedRange(int from, int to);

    int fromWindSpeed();
    int toWindSpeed();

private:
    int userWeight;
    int _fromWindSpeed;
    int _toWindSpeed;
    QVector<int> *_windSpeeds;

public slots:
    void setWeight(int weight);


signals:
    void updated();

};

#endif // SAILSIZEMODEL_H
