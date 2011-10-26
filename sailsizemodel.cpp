#include "sailsizemodel.h"

#include <iostream>

SailSizeModel::SailSizeModel(QObject *parent, int startWeight, int fromWindSpeed, int toWindSpeed)
    : QObject(parent)
{
    this->userWeight = startWeight;
    this->_windSpeeds = new QVector<int>();
    this->setWindSpeedRange(fromWindSpeed, toWindSpeed);
}

SailSizeModel::~SailSizeModel() {
    delete this->_windSpeeds;
}

void SailSizeModel::setWeight(int weight)
{
    this->userWeight = weight;
    this->updated();
}

int SailSizeModel::weight()
{
    return this->userWeight;
}

QVector<int> * SailSizeModel::windSpeeds()
{
    return this->_windSpeeds;
}

void SailSizeModel::setWindSpeedRange(int from, int to)
{
    this->_fromWindSpeed = from;
    this->_toWindSpeed = to;

    this->_windSpeeds->resize(0);
    for (int i = this->_fromWindSpeed; i < this->_toWindSpeed + 1; i++) {
        this->_windSpeeds->push_back(i);
    }
    this->updated();
}

int SailSizeModel::fromWindSpeed()
{
    return this->_fromWindSpeed;
}

int SailSizeModel::toWindSpeed()
{
    return this->_toWindSpeed;
}



