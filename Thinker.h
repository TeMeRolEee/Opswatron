#pragma once

#include <QtCore/QObject>
#include <QtCore/QThread>
#include <QtCore/QTimer>
#include "MapStore.h"
#include "Worker.h"
#include "Players.h"

class Thinker : public QObject
{
    Q_OBJECT
private:
    bool staticSet = false;
    int interval;
    QTimer qTimer;
    MapStore *mapStore;
    QThread workerThread;
    Players *players;
    QString direction;
    QVector<int> position;
public:
    Thinker();
    ~Thinker();

    void setInterval(int interval);
    void statusHandler(const QString& input);
    void doWork();
public slots:

signals:

};

