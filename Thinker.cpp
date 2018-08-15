#include "Thinker.h"
#include <QDebug>
#include <QtCore/QJsonObject>
#include <QtCore/QJsonDocument>
#include <QtCore/QJsonArray>

Thinker::Thinker() {
    mapStore = new MapStore();
    worker = new Worker;
    worker->moveToThread(&workerThread);
    connect(&workerThread, &QThread::finished, worker, &QObject::deleteLater);
    connect(this, &Thinker::operate_signal, worker, &Worker::doWork_slot);
    connect(worker, &Worker::resultReady, this, &Thinker::handleWorkerResults_slot);
    workerThread.start();
}

Thinker::~Thinker() {

}

void Thinker::handleWorkerResults_slot(const QString &value) {

}

void Thinker::setInterval(int interval) {
    Thinker::interval = interval;
}

QJsonObject ObjectFromString(const QString& in)
{
    QJsonValue val(in);
    return val.toObject();
}

void Thinker::statusHandler(const QString& input) {
    QJsonObject qJsonObject = QJsonDocument::fromJson(input.toUtf8()).object();
    QJsonObject intervalDocument = qJsonObject.value("interval").toObject();
    QStringList list = qJsonObject.keys();
    qDebug() << list;
    foreach(const QString& key, qJsonObject.keys())
    {
        QJsonValue qJsonValue1 = qJsonObject.value(key);
        qDebug() << qJsonValue1.type() << qJsonValue1;
    }
    QJsonValue qJsonValue = qJsonObject.value("interval");
    interval = qJsonValue.toVariant().toInt();
    qJsonValue = qJsonObject.value("map");
    QJsonArray qJsonArray = qJsonValue.toArray();
    //qDebug() << qJsonArray.first().toInt() << qJsonArray.last().toInt();
    mapStore->setMap(qJsonArray);
    qJsonValue = qJsonObject.value("other_players");
    //qDebug() << qJsonValue;
    QJsonArray faszom_kivan_mar = qJsonValue.toArray();
    QJsonObject player;
    for(auto item : faszom_kivan_mar)
    {
        qDebug() << "current player:" << item;
        QJsonValue tempValue = item;
        player = tempValue.toObject();
        //qDebug() << "item:" << player.keys();
    }

    //qDebug() << qJsonObject2.keys();


    qDebug() << "interval value:" << interval;
}

/*
{"interval":500,"map":[25,25],"other_players":[{"alive":true,"coords":[21,21],"dir":"DOWN","id":1,"name":"DUMMY"}],"player":{"alive":true,"coords":[0,0],"dir":"UP","id":0,"name":"drop_table_users"},"walls":[{"coords":[0,1],"player_id":0},{"coords":[21,20],"player_id":1}]}
 */