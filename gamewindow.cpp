#include "gamewindow.h"
#include <QGraphicsRectItem>
#include "wall.h"
#include "enemy.h"
#include <QMessageBox>
#include "victorywindow.h"
#include "losewindow.h"

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
    enemyCount = 2;  // Начинаем с 2 врагов

    player = new PlayerTank();
    player->setGameWindow(this);
    player->setPos(400, 500);
    scene->addItem(player);

    EnemyTank *enemy1 = new EnemyTank();
    enemy1->setPos(100, 100);
    enemy1->setPlayer(player);
    enemy1->setGameWindow(this);
    scene->addItem(enemy1);

    EnemyTank *enemy2 = new EnemyTank();
    enemy2->setPos(600, 300);
    enemy2->setPlayer(player);
    enemy2->setGameWindow(this);
    scene->addItem(enemy2);

    // Теперь стены добавляются независимо от уровня
    setupWalls();  // Добавляем стены в любом случае
}

void GameWindow::setupWalls() {
    // Добавляем несколько стен на уровне
    Wall *wall1 = new Wall(200, 200, 100, 20);
    scene->addItem(wall1);

    Wall *wall2 = new Wall(400, 300, 100, 20);
    scene->addItem(wall2);

    Wall *wall3 = new Wall(600, 150, 100, 20);
    scene->addItem(wall3);

    // Добавим стены, которые блокируют пути
    Wall *wall4 = new Wall(150, 450, 200, 20);
    scene->addItem(wall4);

    Wall *wall5 = new Wall(500, 450, 200, 20);
    scene->addItem(wall5);
}

void GameWindow::enemyDied() {
    enemyCount--;
    if (enemyCount <= 0) {
        VictoryWindow *victory = new VictoryWindow();
        victory->show();
        this->close();
    }
}
void GameWindow::showDefeatWindow() {
    if (player && player->getHealth() <= 0) {
        LoseWindow *defeatWindow = new LoseWindow();
        defeatWindow->show();
        this->close();
    }
}

