#pragma once


#include <QtCore/QVector>
#include <QtCore/QJsonArray>

class MapStore {
    QList<QVector<int>> matrix;
    int width;
    int height;

public:
    MapStore();
    ~MapStore();
    QVector<int> getXaxis(int currentY);
    QVector<int> getYaxis(int currentX);
    void setMap(QJsonArray& jsonArray);
    void setWall(const int &x, const int &y);
};

