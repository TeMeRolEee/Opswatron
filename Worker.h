#pragma once

#include <QtCore/QObject>
#include "MapStore.h"

class Worker : public QObject
{
    Q_OBJECT
private:

public:
    void currentThreadId();

public slots:
    void doWork_slot();

signals:
    void resultReady(const QString &result);
};

