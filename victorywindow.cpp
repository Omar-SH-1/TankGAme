#include "victorywindow.h"
#include "mainwindow.h"
#include "gamewindow.h"
#include <QPushButton>
#include <QLabel>
#include <QPixmap>

VictoryWindow::VictoryWindow(QWidget *parent) : QMainWindow(parent) {
    setFixedSize(700, 800);

    QLabel *background = new QLabel(this);
    background->setPixmap(QPixmap(":/images/victory.png").scaled(size()));
    background->setGeometry(0, 0, width(), height());
    background->lower();

    QPushButton *menuButton = new QPushButton("В меню", this);
    menuButton->setGeometry(250, 400, 200, 50);
    connect(menuButton, &QPushButton::clicked, this, &VictoryWindow::onMenuClicked);

    QPushButton *nextButton = new QPushButton("Следующий уровень", this);
    nextButton->setGeometry(250, 470, 200, 50);
    connect(nextButton, &QPushButton::clicked, this, &VictoryWindow::onNextLevelClicked);
}

void VictoryWindow::onMenuClicked() {
    MainWindow *mainMenu = new MainWindow();
    mainMenu->show();
    this->close();
}

void VictoryWindow::onNextLevelClicked() {
    // Можно заменить на GameWindow или другой уровень
    GameWindow *nextLevel = new GameWindow();
    nextLevel->show();
    this->close();
}
