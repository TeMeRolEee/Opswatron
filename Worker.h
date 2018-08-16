#pragma once

#include <QtCore/QObject>
#include <QtCore/QTimer>
#include "Map.h"

class Worker : public QObject {
Q_OBJECT

private:
    Map *map;
    int interval;
    QTimer qTimer;
    int currentX, currentY;
    QString direction;
public:
    Worker();
    ~Worker();

    void processData(const QString &input);
};

