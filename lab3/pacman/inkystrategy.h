#ifndef INKYSTRATEGY_H
#define INKYSTRATEGY_H

#pragma once
#include "routestrategy.h"
#include "heropacman.h"
#include "pathalgorithm.h"
#include "pathleealgorithm.h"

namespace game {

    class InkyStrategy : public RouteStrategy {
    private:
        static const int STEP = 2;

        PathAlgorithm* algorithm;
        QVector<QPair<int, int>> pathToTarget;
        QVector<QPair<int, int>> corners;
        int indexOfCorner;
        QPair<int, int> defaultPath;
        bool isDeadMode;

    public:
        QVector<QPair<int, int>> getPath() override;
        int getStep() override;
        void calculatePath(QPair<int, int> beginPoint) override;
        void swithDeadMode() override;
        InkyStrategy(PathAlgorithm* algorithm, QPair<int, int> defaultPath, QVector<QPair<int, int>> corners);

    };
}
#endif // INKYSTRATEGY_H
