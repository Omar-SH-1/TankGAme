#include "wall.h"
#include <QBrush>

Wall::Wall(qreal x, qreal y, qreal width, qreal height) {
    setRect(x, y, width, height);
    setBrush(Qt::gray);
}
