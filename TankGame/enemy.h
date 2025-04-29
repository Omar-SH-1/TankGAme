#ifndef ENEMYTANK_H
#define ENEMYTANK_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include"playertank.h"

class EnemyTank : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    EnemyTank();
    void moveTowardsPlayer();
    void shoot();
    int health;
    void setPlayer(PlayerTank *p);
    void takeDamage(int damage);


private:
    PlayerTank *player;
    QTimer *actionTimer;
private slots:
    void updateEnemy();

};

#endif // ENEMYTANK_H
