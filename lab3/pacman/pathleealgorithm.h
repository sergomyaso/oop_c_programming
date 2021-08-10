#ifndef PATHLEEALGORITHM_H
#define PATHLEEALGORITHM_H
#pragma once

#include "pathalgorithm.h"
#include "gameconstants.h"
#include "labirintpart.h"
#include <QPair>

namespace game {

    class PathLeeAlgorithm : public PathAlgorithm {
    private:
        QVector<QPair<int, int>> pathToTarget;

    public:
        PathLeeAlgorithm(int* realMap);
        QVector<QPair<int, int>> getPath(QPair<int, int> beginPoint, QPair<int, int> endPoint) override;

    private:
        int* realMap;
        bool leeALgorithmFindShortestPath(QPair<int, int> beginPoint, QPair<int, int> endPoint);
        void generateMapMatrix(int* mapMatrix);
    };
}
#endif // PATHLEEALGORITHM_H
