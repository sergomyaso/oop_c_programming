#include "pinkystrategy.h"

namespace game {

    PinkyStrategy::PinkyStrategy(PathAlgorithm* algorithm, QPair<int, int> defaultPath, HeroPacman* pacman) {
        this->algorithm = algorithm;
        this->pacman = pacman;
        this->defaultPath = defaultPath;
        this->isDeadMode = false;

    }

    QVector<QPair<int, int>> PinkyStrategy::getPath() {
        return this->pathToTarget;
    }

    int PinkyStrategy::getStep() {
        return STEP;
    }

    void PinkyStrategy::swithDeadMode() {
        this->isDeadMode = !this->isDeadMode;
    }

    void PinkyStrategy::calculatePath(QPair<int, int> beginPoint) {
        if (!isDeadMode) {
            pathToTarget = this->algorithm->getPath(beginPoint, QPair<int, int>((int)pacman->x() / 10 * 10, (int)pacman->y() / 10 * 10));
        }
        else {
            pathToTarget = this->algorithm->getPath(beginPoint, defaultPath);

        }

    }
}
