#include "MapStore.h"

MapStore::MapStore() {
}

MapStore::~MapStore() {

}

void MapStore::setMap(QJsonArray &jsonArray) {
    width = jsonArray.first().toInt();
    height = jsonArray.last().toInt();
    QVector<int> axis;
    axis.reserve(width);
    for(int i = 0; i < jsonArray.last().toInt(); i++)
    {
        matrix.push_back(axis);
    }

}

QVector<int> MapStore::getXaxis(int currentY) {
    return matrix.at(currentY);
}

QVector<int> MapStore::getYaxis(int currentX) {
    QVector<int> tempVector;
    for(int i = 0; i < height; i++)
    {
        tempVector.push_back(matrix.at(i)[currentX]);
    }

    return tempVector;
}

void MapStore::setWall(const int &x, const int &y) {
    QVector<int> temp;
    for(int i = 0; i < width; i++)
    {
        if(i != x)
        {
            temp.push_back(0);
        }
        else
        {
            temp.push_back(1);
        }
    }
    matrix.replace(y, temp);
}

