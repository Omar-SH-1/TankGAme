#ifndef PLAYERTANK_H
#define PLAYERTANK_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QKeyEvent>

    class PlayerTank : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    PlayerTank();
    int health;
    bool canShoot;
    void takeDamage(int damage);


protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
};

#endif // PLAYERTANK_H
