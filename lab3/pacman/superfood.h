#ifndef SUPERFOOD_H
#define SUPERFOOD_H

#include <QGraphicsItem>
#include <QPainter>
#include <QColor>

QT_BEGIN_NAMESPACE
namespace Ui { class SuperFood; }
QT_END_NAMESPACE

class SuperFood : public QObject, public QGraphicsItem {

private:
    static const int X_OF_BOUNDING_RECT = -5;
    static const int Y_OF_BOUNDING_RECT = -5;
    static const int WIDTH_OF_BOUNDING_RECT = 10;
    static const int HEIGHT_OF_BOUNDING_RECT = 10;

public:
    SuperFood();

protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR) override;

};

#endif // SUPERFOOD_H
