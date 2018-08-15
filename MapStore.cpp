#include "MapStore.h"

MapStore::MapStore() {
    //matrix = new int[][];
}

MapStore::~MapStore() {

}

void MapStore::setMap(QJsonArray &jsonArray) {
        QVector<int> axis;
        axis.reserve(jsonArray.first().toInt());
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
    matrix.at(y)[x] = 1;
}

