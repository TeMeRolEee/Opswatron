#include <QtCore/QJsonDocument>
#include <QtCore/QJsonObject>
#include <QDebug>
#include <QtCore/QJsonArray>
#include "Worker.h"


Worker::Worker() {
    map = new Map();
}

Worker::~Worker() {}

void Worker::processData(const QString &input) {
    QJsonObject qJsonObject = QJsonDocument::fromJson(input.toUtf8()).object();

    QJsonValue qJsonValue = qJsonObject.value("interval");
    interval = qJsonValue.toInt();

    qJsonValue = qJsonObject.value("map");
    QJsonArray qJsonArray = qJsonValue.toArray();
    map->setHeight(qJsonArray.first().toInt());
    map->setWidth(qJsonArray.last().toInt());

    qJsonValue = qJsonObject.value("other_players");
    qJsonArray = qJsonValue.toArray();

    for (auto item : qJsonArray) {
        QJsonObject currentObject = item.toObject();
        qJsonValue = currentObject.value("coords");
        QJsonArray tempArray = qJsonValue.toArray();
        map->modifyMap(tempArray.first().toInt(),tempArray.last().toInt());
    }
    qJsonValue = qJsonObject.value("player");
    QJsonObject player = qJsonValue.toObject();
    qJsonValue = player.value("coords");
    qJsonArray = qJsonValue.toArray();
    currentX = qJsonArray.first().toInt();
    currentY = qJsonArray.last().toInt();
    direction = qJsonObject.value("dir").toString();
}

