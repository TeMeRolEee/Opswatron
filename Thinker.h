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
    Worker *worker;
    QThread workerThread;
    Players *players;
public:
    Thinker();
    ~Thinker();

    void setInterval(int interval);
    void statusHandler(const QString& input);

public slots:
    void handleWorkerResults_slot(const QString &value);
signals:
    void  operate_signal();

};

