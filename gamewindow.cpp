#include "gamewindow.h"
#include <QGraphicsRectItem>
#include "wall.h"
#include "enemy.h"
#include <QMessageBox>
#include "victorywindow.h"

GameWindow::GameWindow(QWidget *parent) : QMainWindow(parent) {
    setFixedSize(800, 600);

    scene = new QGraphicsScene(this);
    view = new QGraphicsView(scene, this);
    view->setGeometry(0, 0, 800, 600);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setupScene();
}

void GameWindow::setupScene() {
    scene->setSceneRect(0, 0, 800, 600);
    enemyCount = 2;

    player = new PlayerTank();
    player->setPos(400, 500);
    scene->addItem(player);

    EnemyTank *enemy1 = new EnemyTank();
    enemy1->setPos(100, 100);
    enemy1->setPlayer(player);
    enemy1->setGameWindow(this);  // добавлено
    scene->addItem(enemy1);

    EnemyTank *enemy2 = new EnemyTank();
    enemy2->setPos(600, 300);
    enemy2->setPlayer(player);
    enemy2->setGameWindow(this);  // добавлено
    scene->addItem(enemy2);
}

void GameWindow::enemyDied() {
    enemyCount--;
    if (enemyCount <= 0) {
        VictoryWindow *victory = new VictoryWindow();
        victory->show();
        this->close();
    }
}
