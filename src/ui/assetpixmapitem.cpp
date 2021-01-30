#include "assetpixmapitem.h"
#include "imageproviders.h"
#include <QPainter>

void AssetPixmapItem::mousePressEvent(QGraphicsSceneMouseEvent * event) {
    //Make it so on mouse click, selection is overwritten
    //On right click tile is overwritten
    QList<uint16_t> assetTiles = *asset->metatiles;
    QList<QPair<uint16_t, uint16_t>> assetCollisions = *asset->collisions;
    QPoint assetDimensions = asset->dimensions;
    int width = assetDimensions.x();
    int height = assetDimensions.y();

    metatileSelector->setExternalSelection(
                width,
                height,
                assetTiles,
                assetCollisions
                );
}

void AssetPixmapItem::draw() {
    QList<uint16_t> *assetTiles = asset->metatiles;
    QPoint assetDimensions = asset->dimensions;
    int width = assetDimensions.x();
    int height = assetDimensions.y();
    QImage image(width * 16, height * 16, QImage::Format_RGBA8888);
    QPainter painter(&image);

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            int x = i * 16;
            int y = j * 16;
            int index = j * width + i;
            QImage metatile_image = getMetatileImage(
                        assetTiles->at(index),
                        map->layout->tileset_primary,
                        map->layout->tileset_secondary,
                        map->metatileLayerOrder,
                        map->metatileLayerOpacity);
            QPoint metatile_origin = QPoint(x, y);
            painter.drawImage(metatile_origin, metatile_image);
        }
    }
    painter.end();
    setPixmap(QPixmap::fromImage(image));
}
