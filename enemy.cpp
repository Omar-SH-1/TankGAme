#include "enemy.h"
#include "playertank.h"
#include "bullet.h"
#include <QGraphicsScene>
#include <QtMath>
#include "gamewindow.h"

EnemyTank::EnemyTank() {
    QPixmap tankPixmap(":/images/T64_5.gif");
    QTransform transform;
    transform.rotate(180);  // Поворачиваем изображение на 180°
    setPixmap(tankPixmap.transformed(transform).scaled(100, 50));
    setTransformOriginPoint(boundingRect().center());  // Вращение относительно центра
    health = 50;
    actionTimer = new QTimer(this);
    connect(actionTimer, &QTimer::timeout, this, &EnemyTank::updateEnemy);
    actionTimer->start(222);
}

void EnemyTank::setPlayer(PlayerTank *p) {
    player = p;
}

void EnemyTank::setGameWindow(GameWindow *window) {
    gameWindow = window;
}

void EnemyTank::updateEnemy() {
    if (!player) return;
    moveTowardsPlayer();
    if (rand() % 2 == 0) shoot();
}

void EnemyTank::moveTowardsPlayer() {
    if (!player) return;

    QLineF line(pos(), player->pos());
    qreal targetAngle = -line.angle();
    qreal currentAngle = rotation();
    qreal diff = targetAngle - currentAngle;

    if (qAbs(diff) > 180) {
        diff = (diff > 0) ? diff - 360 : diff + 360;
    }

    if (qAbs(diff) > 5) {
        setRotation(currentAngle + (diff > 0 ? 5 : -5));
    } else {
        setRotation(targetAngle);
    }

    double angle_rad = qDegreesToRadians(rotation());
    moveBy(qCos(angle_rad) * 2, -qSin(angle_rad) * 2);
}

void EnemyTank::shoot() {
    if (!scene()) return;
    Bullet *bullet = new Bullet(rotation() + 180, this);
    scene()->addItem(bullet);
    bullet->setPos(pos() + QPointF(boundingRect().width() / 2, boundingRect().height() / 2));
}

void EnemyTank::takeDamage(int damage) {
    health -= damage;
    if (health <= 0) {
        scene()->removeItem(this);
        delete this;
        if (gameWindow) gameWindow->enemyDied();  // вызываем при уничтожении
    }
}
