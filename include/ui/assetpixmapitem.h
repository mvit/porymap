#ifndef ASSETPIXMAPITEM_H
#define ASSETPIXMAPITEM_H

#include "map.h"
#include "metatileselector.h"
#include "asset.h"
#include <QGraphicsPixmapItem>

class AssetPixmapItem : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    AssetPixmapItem(Map *map, MetatileSelector *metatileSelector, Asset *asset) {
        this->map = map;
        this->metatileSelector = metatileSelector;
        this->asset = asset;
    }
    Map *map = nullptr;
    MetatileSelector *metatileSelector = nullptr;
    Asset *asset = nullptr;
    void draw();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *);
};

#endif // ASSETPIXMAPITEM_H
