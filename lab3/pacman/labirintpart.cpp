#include "labirintpart.h"

LabirintPart::LabirintPart(bool isBloked) {
    this->_isBlocked = isBloked;
}

bool LabirintPart::isBlocked()const {
    return  this->_isBlocked;
}

void LabirintPart::block() {
    this->_isBlocked = true;
}

QRectF LabirintPart::boundingRect()const {
    return QRectF(X_OF_BOUNDING_RECT, Y_OF_BOUNDING_RECT, WIDTH_OF_BOUNDING_RECT, HEIGHT_OF_BOUNDING_RECT); // area of labirint part
}

void LabirintPart::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    QPolygon polygon;
    polygon << QPoint(X_OF_BOUNDING_RECT, Y_OF_BOUNDING_RECT + HEIGHT_OF_BOUNDING_RECT)
        << QPoint(X_OF_BOUNDING_RECT, Y_OF_BOUNDING_RECT)
        << QPoint(X_OF_BOUNDING_RECT + WIDTH_OF_BOUNDING_RECT, Y_OF_BOUNDING_RECT)
        << QPoint(X_OF_BOUNDING_RECT + WIDTH_OF_BOUNDING_RECT, Y_OF_BOUNDING_RECT + HEIGHT_OF_BOUNDING_RECT); // add point for drawing
    if (this->_isBlocked) {
        painter->setPen(Qt::NoPen);
        painter->setBrush(QColor(19, 6, 156));
        painter->drawPolygon(polygon);
    }

    Q_UNUSED(option);
    Q_UNUSED(widget);
}
