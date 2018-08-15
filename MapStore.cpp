#include "MapStore.h"

MapStore::MapStore() {
}

MapStore::~MapStore() {

}

void MapStore::setMap(QJsonArray &jsonArray) {
    x_axis.reserve(jsonArray.first().toInt());
    y_axis.reserve(jsonArray.last().toInt());
}

