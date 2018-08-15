#pragma once

#include <QtCore/QObject>
#include <QtCore/QThread>
#include <QtCore/QTimer>
#include "MapStore.h"
#include "Worker.h"

class Thinker : public QObject
{
    Q_OBJECT
private:
    int interval;
    QTimer qTimer;
    MapStore *mapStore;
    Worker *worker;
    QThread workerThread;
public:
    Thinker();
    ~Thinker();

    void setInterval(int interval);

public slots:
    void handleResults(const QString &value);
signals:
    void  operate_signal();

};

