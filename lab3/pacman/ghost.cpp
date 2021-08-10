#include "ghost.h"

Ghost::Ghost(game::RouteStrategy* strategy, QColor color) {
    this->strategy = strategy;
    this->color = color;
    balanceFactor = { 0,0 };
}

void Ghost::setColor(QColor color){
    this->color = color;
}

QRectF Ghost::boundingRect()const {
    return QRectF(X_OF_BOUNDING_RECT, Y_OF_BOUNDING_RECT, WIDTH_OF_BOUNDING_RECT, HEIGHT_OF_BOUNDING_RECT);
}

void Ghost::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    painter->setBrush(color);
    painter->drawEllipse(boundingRect());

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Ghost::cleanPathToTarget(){
    this->pathToTarget.clear();
}

void Ghost::slotWalkTimer() {
    if (pathToTarget.size() == 0) {
        this->strategy->calculatePath(QPair<int, int>(this->x(), this->y()));
        pathToTarget = this->strategy->getPath();
    }

    if (balanceFactor.first == 0 && balanceFactor.second == 0 && pathToTarget.size() > 1) {
        balanceFactor.first = pathToTarget[1].first - pathToTarget[0].first;
        balanceFactor.second = pathToTarget[1].second - pathToTarget[0].second;
        stepBalance.first = balanceFactor.first / (WIDTH_OF_BOUNDING_RECT / this->strategy->getStep());
        stepBalance.second = balanceFactor.second / (WIDTH_OF_BOUNDING_RECT / this->strategy->getStep());
        pathToTarget.pop_front();
    }

    if (balanceFactor.first != 0 || balanceFactor.second != 0) {
        balanceFactor.first -= stepBalance.first;
        balanceFactor.second -= stepBalance.second;
        setPos(mapToParent(stepBalance.first, stepBalance.second));
    }

    if (pathToTarget.size() == 1) {
        pathToTarget.pop_front();
    }

}
