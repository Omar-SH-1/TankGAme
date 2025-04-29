#ifndef ENEMYTANK_H
#define ENEMYTANK_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include "playertank.h"

class GameWindow;

class EnemyTank : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    EnemyTank();
    void moveTowardsPlayer();
    void shoot();
    int health;
    void setPlayer(PlayerTank *p);
    void takeDamage(int damage);
    void setGameWindow(GameWindow *window);  // добавлено

private:
    PlayerTank *player;
    QTimer *actionTimer;
    GameWindow *gameWindow = nullptr;  // добавлено

private slots:
    void updateEnemy();
};

#endif // ENEMYTANK_H
