#include "playertank.h"
#include <QPixmap>
#include "wall.h"
#include "bullet.h"
#include <QGraphicsScene>
#include "gamewindow.h"


PlayerTank::PlayerTank() {
    setPixmap(QPixmap(":/images/T64_5.gif").scaled(100, 50));
    setFlag(QGraphicsItem::ItemIsFocusable); // Важно!
    setFocus(); // Важно!
    setTransformOriginPoint(boundingRect().width() / 2, boundingRect().height() / 2);
    health = 100;
    canShoot = true;

}

void PlayerTank::keyPressEvent(QKeyEvent *event) {
    int step = 10;
    QPointF oldPos = pos(); // запомним позицию

    switch (event->key()) {
    case Qt::Key_W:
    case Qt::Key_S: {
        qreal angle = rotation();
        qreal dx = step * qCos(qDegreesToRadians(angle));
        qreal dy = step * qSin(qDegreesToRadians(angle));
        if (event->key() == Qt::Key_S)
            setPos(x() + dx, y() + dy);
        else
            setPos(x() - dx, y() - dy);
        break;
    }
    case Qt::Key_A:
        setRotation(rotation() - 5);
        break;
    case Qt::Key_D:
        setRotation(rotation() + 5);
        break;
    case Qt::Key_Space:
        if (!event->isAutoRepeat() && canShoot)  {
            Bullet *bullet = new Bullet(rotation(), this);
            scene()->addItem(bullet);
            bullet->setPos(pos() + QPointF(boundingRect().width()/2, boundingRect().height()/2));

            canShoot = false;
        }
        break;
    default:
        break;
    }

    // Если столкнулся с чем-то — вернуться назад
    QList<QGraphicsItem *> colliding = collidingItems();
    for (auto item : colliding) {
        if (dynamic_cast<Wall *>(item)) {
            setPos(oldPos); // вернуть на старое место
            break;
        }
    }
}
void PlayerTank::keyReleaseEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Space) {
        canShoot = true;
    }
}
void PlayerTank::setGameWindow(GameWindow* window) {
    gameWindow = window;
}
int PlayerTank::getHealth() const {
    return health;
}


void PlayerTank::takeDamage(int damage) {
    health -= damage;
    if (health <= 0) {
        if (gameWindow) gameWindow->showDefeatWindow();  // сначала окно
        scene()->removeItem(this);
        delete this;  // потом удаляем игрока
    }
}




