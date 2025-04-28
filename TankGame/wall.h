#ifndef WALL_H
#define WALL_H

#include <QGraphicsRectItem>

class Wall : public QGraphicsRectItem {
public:
    Wall(qreal x, qreal y, qreal width, qreal height);
};

#endif // WALL_H
