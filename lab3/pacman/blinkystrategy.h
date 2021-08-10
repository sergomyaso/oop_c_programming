#ifndef BLINKYSTRATEGY_H
#define BLINKYSTRATEGY_H

#pragma once
#include "routestrategy.h"
#include "heropacman.h"
#include "pathalgorithm.h"
#include "pathleealgorithm.h"

namespace game {

    class BlinkyStrategy : public RouteStrategy {

    private:
        static const int SIMPLE_STEP = 2;
        static const int SUPER_STEP = 4;

        PathAlgorithm* algorithm;
        HeroPacman* pacman;
        int* foodCounter;
        int* generalCountFood;
        QVector<QPair<int, int>> pathToTarget;
        QPair<int, int> defaultPath;
        bool isDeadMode;

    public:
        QVector<QPair<int, int>> getPath() override;
        int getStep() override;
        void calculatePath(QPair<int, int> beginPoint) override;
        void swithDeadMode() override;
        BlinkyStrategy(PathAlgorithm* algorithm, QPair<int, int> defaultPath, HeroPacman* pacman, int* foodCounter, int* generalCountFood);
    };
}
#endif // BLINKYSTRATEGY_H
