#ifndef POCKEYSTRATEGY_H
#define POCKEYSTRATEGY_H

#include "routestrategy.h"
#include "pathalgorithm.h"
#include "heropacman.h"
namespace game {

    class PockeyStrategy : public RouteStrategy {
    private:
        static const int SIMPLE_STEP = 2;
        static const int SUPER_STEP = 4;

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

        PockeyStrategy(PathAlgorithm* algorithm, QPair<int, int> defaultPath, HeroPacman* pacman);
    };
}
#endif // POCKEYSTRATEGY_H
