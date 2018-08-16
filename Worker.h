#pragma once

#include <QtCore/QObject>
#include "Map.h"

class Worker : public QObject {
Q_OBJECT

private:
    Map *map;
public:
    Worker();
    ~Worker();
};

