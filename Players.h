#pragma once

#include <QtCore/QString>
#include <QtCore/QMap>
#include <QtCore/QVector>

class Players {

private:
    //QMap<int, QString> name;
    QMap<int, QString> dirs;
    QMap<int, QVector<int>> coords;

public:
    Players();
    ~Players();

    void addPlayer(const int &id ,const QString &dir, const QVector<int> &coord);
    QString getPlayerDirection(const int &id);
    QVector<int> getPlayerCoord(const int  &id);
    void setPlayerStatus(const int &id, const QString &dir,const QVector<int> &coord);
    void updatePlayerPos(const int &id, const QVector<int> &coord);
    void updatePlayerDir(const int &id, const QString &dir);
};

