#pragma once


#include <QtCore/QVector>
#include <QtCore/QJsonArray>

class MapStore {
    QVector<bool> x_axis;
    QVector<bool> y_axis;

public:
    MapStore();
    ~MapStore();

    void setMap(QJsonArray& jsonArray);
};

