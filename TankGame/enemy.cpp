#include "enemy.h"
#include <QPixmap>
#include <QRandomGenerator>
#include "playertank.h"
#include "bullet.h"
#include <QGraphicsScene>
#include <QtMath>

void EnemyTank::setPlayer(PlayerTank *p) {
    player = p;
}

EnemyTank::EnemyTank() {
    setPixmap(QPixmap(":/images/T64_5.gif").scaled(100, 50));
    health = 50;
    actionTimer = new QTimer(this);
    connect(actionTimer, &QTimer::timeout, this, &EnemyTank::updateEnemy);
    actionTimer->start(300);


}
void EnemyTank::updateEnemy() {
    if (!player) return;

    moveTowardsPlayer();

    if (rand() % 2 == 0) {
        shoot();
    }
}
void EnemyTank::moveTowardsPlayer() {
    if (!player) return;

    // Вычисляем угол до игрока
    QLineF line(pos(), player->pos());
    qreal targetAngle = -line.angle(); // Qt повороты против часовой стрелки

    // Плавный поворот: сравниваем текущий угол и целевой
    qreal currentAngle = rotation();
    qreal diff = targetAngle - currentAngle;

    if (qAbs(diff) > 180) {
        if (diff > 0) diff -= 360;
        else diff += 360;
    }

    if (qAbs(diff) > 5) {
        if (diff > 0) setRotation(currentAngle + 5); // Плавно поворачиваем на 5°
        else setRotation(currentAngle - 5);
    } else {
        setRotation(targetAngle); // Если очень близко — сразу устанавливаем
    }

    // Двигаемся вперед в сторону текущего поворота
    double angle_rad = qDegreesToRadians(rotation());
    double dx = qCos(angle_rad) * 2;
    double dy = -qSin(angle_rad) * 2;
    moveBy(dx, dy);
}

void EnemyTank::shoot() {
    if (!scene()) return;
    Bullet *bullet = new Bullet(rotation(), this);
    scene()->addItem(bullet);
    bullet->setPos(pos() + QPointF(boundingRect().width()/2, boundingRect().height()/2));
}
void EnemyTank::takeDamage(int damage) {
    health -= damage;
    if (health <= 0) {
        // Логика для смерти врага, например:
        scene()->removeItem(this);
        delete this;
    }
}


