#include "pockeystrategy.h"

namespace game {

    PockeyStrategy::PockeyStrategy(PathAlgorithm* algorithm, QPair<int, int> defaultPath, HeroPacman* pacman) {
        this->algorithm = algorithm;
        this->pacman = pacman;
        this->defaultPath = defaultPath;
        this->isDeadMode = false;
    }

    void PockeyStrategy::swithDeadMode() {
        this->isDeadMode = !this->isDeadMode;
    }

    QVector<QPair<int, int>> PockeyStrategy::getPath() {
        return this->pathToTarget;
    }

    int PockeyStrategy::getStep() {
        if (pathToTarget.size() < 5) {
            return SUPER_STEP;
        }
        return SIMPLE_STEP;
    }

    void PockeyStrategy::calculatePath(QPair<int, int> beginPoint) {
        if (!isDeadMode) {
            pathToTarget = this->algorithm->getPath(beginPoint, QPair<int, int>((int)pacman->x() / 10 * 10, (int)pacman->y() / 10 * 10));
        }
        else {
            pathToTarget = this->algorithm->getPath(beginPoint, defaultPath);

        }
    }
}
