#include "Thinker.h"
#include <QDebug>
#include <QtCore/QJsonObject>
#include <QtCore/QJsonDocument>
#include <QtCore/QJsonArray>
#include <iostream>

Thinker::Thinker() {
    players = new Players();
    mapStore = new MapStore();
    qTimer.setInterval(interval);
    connect(&qTimer, &QTimer::timeout, this, &Thinker::doWork);
    position.push_back(0);
    position.push_back(0);
}

Thinker::~Thinker() {
    workerThread.quit();
    workerThread.wait();
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
    //qDebug() << list;
    foreach(const QString& key, qJsonObject.keys())
    {
        QJsonValue qJsonValue1 = qJsonObject.value(key);
        //qDebug() << qJsonValue1.type() << qJsonValue1;
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
        //qDebug() << "current player:" << item;
        QJsonValue tempValue = item;
        player = tempValue.toObject();
        //qDebug() << "item:" << player.keys();
        QJsonArray coords = player.value("coords").toArray();
        //qDebug() << coords.first().toInt() << coords.last().toInt();
        int id = player.value("id").toInt();
        QString dir = player.value("dir").toString();
        QVector<int> coord;
        coord.push_back(coords.first().toInt());
        coord.push_back(coords.last().toInt());
        if(staticSet == false)
        {
            players->addPlayer(id, dir, coord);
        }
    }
    staticSet = true;
    //qDebug() << qJsonObject.keys();
    QJsonObject qJsonObject1 = qJsonObject.value("player").toObject();

    direction = qJsonObject1.value("dir").toString();

    QJsonArray positionArray = qJsonObject1.value("coords").toArray();

    position[0] = positionArray.first().toInt();
    position[1] = positionArray.last().toInt();

    //qDebug() << direction << position[0] << position[1];

    qJsonValue = qJsonObject.value("walls");
    qJsonArray = qJsonValue.toArray();

    for(auto item : qJsonArray)
    {
        qJsonValue = item;
        qJsonObject = qJsonValue.toObject();
        QJsonArray coordArray = qJsonObject.value("coords").toArray();
        mapStore->setWall(coordArray.first().toInt(), coordArray.last().toInt());
        //qDebug() << coordArray.first().toInt() << coordArray.last().toInt();
        QVector<int> qVector;
        qVector.push_back(coordArray.first().toInt());
        qVector.push_back(coordArray.last().toInt());
        players->updatePlayerPos(qJsonObject.value("player_id").toInt(), qVector);
        //qDebug() << qJsonValue;
    }
    qTimer.start();
    //qDebug() << qJsonObject2.keys();
    //qDebug() << "interval value:" << interval;
}

void Thinker::doWork() {
    QVector<int> closeset_wall_X;
    QVector<int> closeset_wall_Y;
    if(direction == "LEFT" || direction == "RIGHT")
    {
        QVector<int> x_axis = mapStore->getXaxis(position.first());
        if(direction == "LEFT")
        {
            for(int i = position.first(); i < mapStore->getWidth() - position.first(); i--)
            {
                if(x_axis.value(i) == 1 || i == 1)
                {
                    closeset_wall_X.push_back(i);
                    closeset_wall_X.push_back(position.last());
                }
            }
        } else
        {
            for(int i = position.first(); i < mapStore->getWidth(); i++)
            {
                if(x_axis.value(i) == 1 || i == mapStore->getWidth()-1)
                {
                    closeset_wall_X.push_back(i);
                    closeset_wall_X.push_back(position.last());
                }
            }
        }
    }
    if(direction == "UP" || direction == "DOWN")
    {
        QVector<int> y_axis = mapStore->getXaxis(position.first());
        if(direction == "DOWN")
        {
            for(int i = position.first(); i < mapStore->getHeight() - position.last(); i--)
            {
                if(y_axis.value(i) == 1 || i == 1)
                {
                    closeset_wall_Y.push_back(i);
                    closeset_wall_Y.push_back(position.last());
                }
            }
        } else
        {
            for(int i = position.first(); i < mapStore->getHeight(); i++)
            {
                if(y_axis.value(i) == 1|| i == mapStore->getHeight()-1)
                {
                    closeset_wall_Y.push_back(i);
                    closeset_wall_Y.push_back(position.last());
                }
            }
        }
    }

    int diff_x = closeset_wall_X[0] - position.first();
    int diff_y = closeset_wall_Y[0] - position.last();

    if(diff_x < diff_y && diff_x < 0)
    {
        std::cout << R"({"dir": "UP"})" << std::endl;
    }
    if(diff_x > diff_y && diff_x > 0)
    {
        std::cout << R"({"dir": "DOWN"})" << std::endl;
    }
    if(diff_x < diff_y && diff_y < 0)
    {
        std::cout << R"({"dir": "LEFT"})" << std::endl;
    }
    if(diff_x > diff_y && diff_y > 0)
    {
        std::cout << R"({"dir": "RIGHT"})" << std::endl;
    }



}


/*
{"interval":500,"map":[25,25],"other_players":[{"alive":true,"coords":[21,21],"dir":"DOWN","id":1,"name":"DUMMY"}],"player":{"alive":true,"coords":[0,0],"dir":"UP","id":0,"name":"drop_table_users"},"walls":[{"coords":[0,1],"player_id":0},{"coords":[21,20],"player_id":1}]}
*/