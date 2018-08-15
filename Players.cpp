#include <QtCore/QJsonArray>
#include "Players.h"

Players::Players() {

}

Players::~Players() {

}

void Players::addPlayer(const int &id ,const QString &dir, const QVector<int> &coord) {
    dirs.insert(id, dir);
    coords.insert(id, coord);
}

void Players::setPlayerStatus(const int &id, const QString &dir, const QVector<int> &coord) {
    dirs[id] = dir;
    coords[id] = coord;
}

QString Players::getPlayerDirection(const int &id) {
    return dirs.value(id);
}

QVector<int> Players::getPlayerCoord(const int &id) {
    return coords.value(id);
}

void Players::updatePlayerPos(const int &id, const QVector<int> &coord) {
    coords[id] = coord;
}

void Players::updatePlayerDir(const int &id, const QString &dir) {
    dirs[id] = dir;
}
