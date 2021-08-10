#ifndef LABIRINTPART_H
#define LABIRINTPART_H
#pragma once

#include <QGraphicsItem>
#include <QPen>
#include <QPainter>
#include <QColor>

QT_BEGIN_NAMESPACE
namespace Ui { class LabirintPart; }
QT_END_NAMESPACE

class LabirintPart : public QGraphicsItem {
public:
    void block();
    LabirintPart(bool isBlocked);
    bool isBlocked()const;
public:
    static const int X_OF_BOUNDING_RECT = -10;
    static const int Y_OF_BOUNDING_RECT = -10;
    static const int WIDTH_OF_BOUNDING_RECT = 20;
    static const int HEIGHT_OF_BOUNDING_RECT = 20;

    bool _isBlocked;

protected:
    QRectF boundingRect() const override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = Q_NULLPTR) override;
};

#endif // LABIRINTPART_H
