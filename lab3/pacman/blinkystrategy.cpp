#include "blinkystrategy.h"

namespace game {

    BlinkyStrategy::BlinkyStrategy(PathAlgorithm* algorithm, QPair<int, int> defaultPath, HeroPacman* pacman, int* foodCounter, int* generalCountFood) {
        this->algorithm = algorithm;
        this->pacman = pacman;
        this->foodCounter = foodCounter;
        this->generalCountFood = generalCountFood;
        this->defaultPath = defaultPath;
        this->isDeadMode = false;
    }

    void BlinkyStrategy::swithDeadMode() {
        this->isDeadMode = !this->isDeadMode;
    }

    QVector<QPair<int, int>> BlinkyStrategy::getPath() {
        return this->pathToTarget;
    }

    int BlinkyStrategy::getStep() {
        if ((*generalCountFood - *foodCounter) < 10) {
            return SUPER_STEP;
        }
        return SIMPLE_STEP;
    }

    void BlinkyStrategy::calculatePath(QPair<int, int> beginPoint) {
        if (!isDeadMode) {
            pathToTarget = this->algorithm->getPath(beginPoint, QPair<int, int>((int)pacman->x() / 10 * 10, (int)pacman->y() / 10 * 10));
        }
        else {
            pathToTarget = this->algorithm->getPath(beginPoint, this->defaultPath);
        }
    }
}

