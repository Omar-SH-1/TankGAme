
#include <QGraphicsPixmapItem>
#include <QTimer>

class Bullet : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Bullet(qreal angle,QGraphicsItem *owner);


public slots:
    void move();
private:
    qreal angle;
    QGraphicsItem *owner;
};
