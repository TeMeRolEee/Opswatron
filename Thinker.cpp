#include "Thinker.h"
#include <QDebug>

Thinker::Thinker() {
    worker = new Worker;
    worker->moveToThread(&workerThread);
    connect(&workerThread, &QThread::finished, worker, &QObject::deleteLater);
    connect(this, &Thinker::operate_signal, worker, &Worker::doWork_slot);
    workerThread.start();
}

Thinker::~Thinker() {

}

void Thinker::handleResults(const QString &value) {

}

void Thinker::setInterval(int interval) {
    Thinker::interval = interval;
}


