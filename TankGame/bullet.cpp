
#include "bullet.h"
#include <QtMath>
#include <QGraphicsScene>
#include "enemy.h"

Bullet::Bullet(qreal angle, QGraphicsItem *ownerItem) {
    setPixmap(QPixmap(":/images/bullet.png").scaled(10, 10));
    setRotation(angle);
    owner = ownerItem;

    QTimer *moveTimer = new QTimer(this);
    connect(moveTimer, &QTimer::timeout, this, &Bullet::move);
    moveTimer->start(16);
}


void Bullet::move() {
    qreal step = 10;
    qreal dx = step * qCos(qDegreesToRadians(rotation()));
    qreal dy = step * qSin(qDegreesToRadians(rotation()));
    setPos(x() - dx, y() - dy);

    // Проверка на выход за пределы сцены
    if (!scene()->sceneRect().contains(pos())) {
        scene()->removeItem(this);
        delete this;
    }

    // Проверка на столкновение
    QList<QGraphicsItem*> colliding = collidingItems();
    for (auto item : colliding) {
        if (item == owner) continue; // Не трогаем своего владельца!

        if (dynamic_cast<PlayerTank*>(item)) {
            // Урон игроку
            PlayerTank *player = dynamic_cast<PlayerTank*>(item);
            player->takeDamage(10);  // Функция, которая уменьшает здоровье игрока
        } else if (dynamic_cast<EnemyTank*>(item)) {
            // Урон врагу
            EnemyTank *enemy = dynamic_cast<EnemyTank*>(item);
            enemy->takeDamage(10);  // Функция, которая уменьшает здоровье врага
        }

        scene()->removeItem(this);
        delete this;
        return;
    }
}

