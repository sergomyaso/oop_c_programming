#ifndef HEROPACMAN_H
#define HEROPACMAN_H
#pragma once
#include <QGraphicsItem>
#include <QPen>
#include <QPainter>
#include <QVector>
#include <QMap>
#include <iostream>
#include <windows.h>

#include "labirintpart.h"

QT_BEGIN_NAMESPACE
namespace Ui { class HeroPacman; }
QT_END_NAMESPACE

class HeroPacman : public QObject, public QGraphicsItem {
private:
    enum Direction {LEFT_DIRECTION, RIGHT_DIRECTION, UP_DIRECTION, DOWN_DIRECTION};
    static const int X_OF_BOUNDING_RECT = -8;
    static const int Y_OF_BOUNDING_RECT = -8;
    static const int WIDTH_OF_BOUNDING_RECT = 16;
    static const int HEIGHT_OF_BOUNDING_RECT = 16;
    const qreal ANGLE_90_DEGREES = 90;

    QVector<LabirintPart*>* labirint;
    QMap<int, std::pair<Direction, qreal>> mapOfDirection;
    QVector<int> keysOfAction;
    Direction direction;
    qreal angleOfRotation;

public:
    static const int STEP = 2;
    bool isStay;
    HeroPacman();
    HeroPacman(QVector<LabirintPart*>* labirint);

private:
    void initKeysVector();
    void initMapOfDirection();

public slots:
    void slotTrackKeyTimer();

protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR) override;

};

#endif // HEROPACMAN_H
