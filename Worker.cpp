#include <QtCore/QThread>
#include "Worker.h"
#include "Thinker.h"
#include <QDebug>

void Worker::currentThreadId() {
    qDebug() << QThread::currentThreadId();

}

void Worker::doWork_slot() {
}
