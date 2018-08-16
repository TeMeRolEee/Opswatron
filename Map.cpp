//
// Created by temerole on 2018.08.16..
//

#include "Map.h"

const QVector<QVector<int>> &Map::getMatrix() const {
    return matrix;
}

int Map::getWidth() const {
    return width;
}

int Map::getHeight() const {
    return height;
}

void Map::modifyMap(const int &x, const int &y) {
    matrix[x][y] = 1;
}

QVector<int> Map::getXaxis(const int &requiredY) {
    return matrix.at(requiredY);
}

QVector<int> Map::getYaxis(const int &requiredX) {
    QVector<int> yAxis;
    for (auto item : matrix) {
        yAxis.push_back(item[requiredX]);
    }
    return yAxis;
}

void Map::setWidth(int width) {
    Map::width = width;
}

void Map::setHeight(int height) {
    Map::height = height;
}

void Map::setMatrix() {
    QVector<int> xAxis;
    xAxis.reserve(width);
    for (int i = 0; i < height; i++) {
        matrix.push_back(xAxis);
    }
}

Map::Map() {

}

Map::~Map() {

}
