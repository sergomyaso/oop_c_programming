#include "heropacman.h"

HeroPacman::HeroPacman() {
    isStay = false;
    this->angleOfRotation = 0;
    this->setRotation(this->angleOfRotation);
    this->direction = UP_DIRECTION;
    initKeysVector();
    initMapOfDirection();
}

HeroPacman::HeroPacman(QVector<LabirintPart*>* labirint) {
    this->labirint = labirint;
    this->angleOfRotation = 0;
    this->setRotation(this->angleOfRotation);
    this->direction = UP_DIRECTION;
    initKeysVector();
    initMapOfDirection();
}

QRectF HeroPacman::boundingRect()const {
    return QRectF(X_OF_BOUNDING_RECT,Y_OF_BOUNDING_RECT,WIDTH_OF_BOUNDING_RECT, HEIGHT_OF_BOUNDING_RECT);
}

void HeroPacman::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

    painter->setBrush(Qt::yellow);
    painter->drawEllipse(boundingRect());


    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void HeroPacman::initKeysVector() {
    for(auto i = VK_LEFT; i <= VK_DOWN; i++) {
        this->keysOfAction.push_back(i);
    }
}

void HeroPacman::initMapOfDirection() {
    this->mapOfDirection[VK_LEFT] = std::pair<Direction, qreal>(LEFT_DIRECTION, -ANGLE_90_DEGREES);
    this->mapOfDirection[VK_RIGHT] = std::pair<Direction, qreal>(RIGHT_DIRECTION, ANGLE_90_DEGREES);
    this->mapOfDirection[VK_UP] = std::pair<Direction, qreal>(UP_DIRECTION, NULL);
    this->mapOfDirection[VK_DOWN] = std::pair<Direction, qreal>(DOWN_DIRECTION, ANGLE_90_DEGREES * 2);
}

void HeroPacman::slotTrackKeyTimer() {
    for(auto key : this->keysOfAction){
        if(GetAsyncKeyState(key)){
            this->direction = mapOfDirection[key].first;
            this->angleOfRotation =mapOfDirection[key].second;
            isStay = false;
            break;
        }
    }

    if(!this->isStay){
    setRotation(angleOfRotation);
    setPos(mapToParent(0,-STEP));
    }

}
