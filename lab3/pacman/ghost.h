#ifndef GHOST_H
#define GHOST_H
#pragma once

#include <QGraphicsItem>
#include <QPainter>
#include <QVector>
#include <QPair>
#include <iostream>
#include "gameconstants.h"
#include "labirintpart.h"
#include "routestrategy.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Ghost; }
QT_END_NAMESPACE

class Ghost : public QObject , public QGraphicsItem {
private:
    static const int X_OF_BOUNDING_RECT = -10;
    static const int Y_OF_BOUNDING_RECT = -10;
    static const int WIDTH_OF_BOUNDING_RECT = 20;
    static const int HEIGHT_OF_BOUNDING_RECT = 20;

public:
    QPair<int, int> getNextTarget();
    void cleanPathToTarget();
    Ghost(game::RouteStrategy* strategy, QColor color);
    void setColor(QColor color);

private:
    QColor color;
    QVector<QPair<int, int>> pathToTarget;
    QPair<int, int> balanceFactor;
    QPair<int, int> stepBalance;
    game::RouteStrategy* strategy;

public slots:
    void slotWalkTimer();

protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR) override;
};

#endif // GHOST_H
