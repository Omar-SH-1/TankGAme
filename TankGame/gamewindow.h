#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "playertank.h"
#include "victorywindow.h"

class GameWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit GameWindow(QWidget *parent = nullptr);
private:
    QGraphicsScene *scene;
    QGraphicsView *view;
    PlayerTank *player;

    void setupScene();
    void setupWalls();
    int enemyCount;
};

#endif // GAMEWINDOW_H
