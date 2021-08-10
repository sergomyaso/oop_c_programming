#ifndef ROUTESTRATEGY_H
#define ROUTESTRATEGY_H

#endif // ROUTESTRATEGY_H
#pragma once

#include <QPair>
#include <QVector>
namespace game {

    class RouteStrategy {
    public:
        virtual QVector<QPair<int, int>> getPath() = 0;
        virtual int getStep() = 0;
        virtual void calculatePath(QPair<int, int> beginPoint) = 0;
        virtual void swithDeadMode() = 0;
    };
}
