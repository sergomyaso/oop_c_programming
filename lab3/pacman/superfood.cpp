#include "superfood.h"

SuperFood::SuperFood(){}

QRectF SuperFood::boundingRect()const {
    return QRectF(X_OF_BOUNDING_RECT, Y_OF_BOUNDING_RECT, WIDTH_OF_BOUNDING_RECT, HEIGHT_OF_BOUNDING_RECT);
}

void SuperFood::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    painter->setBrush(QColor(255, 222, 173));
    painter->drawEllipse(boundingRect());


    Q_UNUSED(option);
    Q_UNUSED(widget);
}
