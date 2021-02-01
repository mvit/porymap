#include "asset.h"

Asset::Asset()
{
    metatiles = new QList<uint16_t>;
    for (uint16_t i = 0; i < 4; i++) {
        metatiles->append(i);
    }
    collisions = new QList<QPair<uint16_t,uint16_t>>;
}

Asset* Asset::copy() {
    Asset * copy = new Asset;
    copy->dimensions = this->dimensions;
    copy->metatiles = new QList<uint16_t>;
    for(uint16_t tile: *this->metatiles) {
        copy->metatiles->append(tile);
    }
    copy->collisions = new QList<QPair<uint16_t,uint16_t>>;
    for(QPair<uint16_t, uint16_t> collision: *this->collisions) {
        copy->collisions->append(collision);
    }
    return copy;
}
