#ifndef PINKYSTRATEGY_H
#define PINKYSTRATEGY_H

#include "routestrategy.h"
#include "heropacman.h"
#include "pathalgorithm.h"

namespace game {

    class PinkyStrategy : public RouteStrategy {
    private:
        static const int STEP = 2;

        PathAlgorithm* algorithm;
        HeroPacman* pacman;
        QVector<QPair<int, int>> pathToTarget;
        QPair<int, int> defaultPath;
        bool isDeadMode;

    public:
        QVector<QPair<int, int>> getPath() override;
        int getStep() override;
        void calculatePath(QPair<int, int> beginPoint) override;
        void swithDeadMode() override;
        PinkyStrategy(PathAlgorithm* algorithm, QPair<int, int> defaultPath, HeroPacman* pacman);

    };
}
#endif // PINKYSTRATEGY_H
