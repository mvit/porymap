#pragma once
#ifndef ASSET_H
#define ASSET_H

#include <QList>
#include <QPair>
#include <QPoint>
#include <QString>

class Asset
{
public:
    Asset();
public:
    QList<uint16_t> *metatiles = nullptr;
    QList<QPair<uint16_t, uint16_t>> *collisions = nullptr;
    QPoint dimensions;
    QString label;

    Asset *copy();
};

#endif // ASSET_H
