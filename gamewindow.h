#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "playertank.h"

class GameWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit GameWindow(QWidget *parent = nullptr);
    void enemyDied();  // добавлено
    void showDefeatWindow();


private:
    QGraphicsScene *scene;
    QGraphicsView *view;
    PlayerTank *player;

    void setupScene();
    void setupWalls();
    int enemyCount;
};

#endif // GAMEWINDOW_H
