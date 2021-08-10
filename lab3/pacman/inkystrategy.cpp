#include "inkystrategy.h"

namespace game {

    InkyStrategy::InkyStrategy(PathAlgorithm* algorithm, QPair<int, int> defaultPath, QVector<QPair<int, int>> corners) {
        this->corners = corners;
        this->algorithm = algorithm;
        indexOfCorner = 0;
        this->defaultPath = defaultPath;
        isDeadMode = false;

    }

    void InkyStrategy::swithDeadMode() {
        this->isDeadMode = !this->isDeadMode;
    }

    QVector<QPair<int, int>> InkyStrategy::getPath() {
        return this->pathToTarget;
    }

    int InkyStrategy::getStep() {
        return STEP;
    }

    void InkyStrategy::calculatePath(QPair<int, int> beginPoint) {
        if (!isDeadMode) {
            if (indexOfCorner >= COUNT_OF_AXIS)
                indexOfCorner = 0;
            pathToTarget = this->algorithm->getPath(beginPoint, corners[indexOfCorner]);
            indexOfCorner++;
        }
        else {
            pathToTarget = this->algorithm->getPath(beginPoint, defaultPath);
        }
    }
}
