#include "victorywindow.h"
#include <QPushButton>
#include <QLabel>
#include <QPixmap>

VictoryWindow::VictoryWindow(QWidget *parent) : QMainWindow(parent) {
    setFixedSize(800, 600);

    QLabel *background = new QLabel(this);
    background->setPixmap(QPixmap(":/images/victory.png").scaled(size()));
    background->setGeometry(0, 0, width(), height());
    background->lower();

    QPushButton *menuButton = new QPushButton("В меню", this);
    menuButton->setGeometry(300, 400, 200, 50);
    connect(menuButton, &QPushButton::clicked, this, &VictoryWindow::goToMenu);

    QPushButton *nextButton = new QPushButton("Следующий уровень", this);
    nextButton->setGeometry(300, 470, 200, 50);
    connect(nextButton, &QPushButton::clicked, this, &VictoryWindow::nextLevel);
}
