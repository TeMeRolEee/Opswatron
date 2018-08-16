#pragma once

#include <QtCore/QVector>

class Map {

private:
    QVector<QVector<int>> matrix;
public:
    void setMatrix();

public:
    const QVector<QVector<int>> &getMatrix() const;

    int getWidth() const;

    int getHeight() const;

private:
    int width,height;
public:
    void setWidth(int width);

    void setHeight(int height);

public:
    Map();
    ~Map();

    void modifyMap(const int &x, const int &y);

    QVector<int> getXaxis(const int &requiredY);
    QVector<int> getYaxis(const int &requiredX);
};