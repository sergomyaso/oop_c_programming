#ifndef SIMPLEFOOD_H
#define SIMPLEFOOD_H
#pragma once
#include <QGraphicsItem>
#include <QPainter>
#include <QColor>

QT_BEGIN_NAMESPACE
namespace Ui { class SimpleFood; }
QT_END_NAMESPACE

class SimpleFood : public QObject, public QGraphicsItem {
private:
    static const int X_OF_BOUNDING_RECT = -3;
    static const int Y_OF_BOUNDING_RECT = -3;
    static const int WIDTH_OF_BOUNDING_RECT = 6;
    static const int HEIGHT_OF_BOUNDING_RECT = 6;

public:
    SimpleFood();

protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR) override;

};

#endif // SIMPLEFOOD_H
