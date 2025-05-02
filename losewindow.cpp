#include "losewindow.h"
#include "mainwindow.h"
#include "gamewindow.h"
#include <QPushButton>
#include <QLabel>
#include <QPixmap>
#include <QMediaPlayer>
#include <QAudioOutput>

LoseWindow::LoseWindow(QWidget *parent) : QMainWindow(parent) {
    setFixedSize(700, 800);

    player = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);
    player->setAudioOutput(audioOutput);
    player->setSource(QUrl("qrc:/images/lose.mp3"));
    audioOutput->setVolume(50);
    player->play();

    QLabel *background = new QLabel(this);
    background->setPixmap(QPixmap(":/images/lose.png").scaled(size()));
    background->setGeometry(0, 0, width(), height());
    background->lower();

    QPushButton *menuButton = new QPushButton("В меню", this);
    menuButton->setGeometry(250, 400, 200, 50);
    connect(menuButton, &QPushButton::clicked, this, &LoseWindow::onMenuClicked);

    QPushButton *retryButton = new QPushButton("Попробовать снова", this);
    retryButton->setGeometry(250, 470, 200, 50);
    connect(retryButton, &QPushButton::clicked, this, &LoseWindow::onRetryClicked);


}

void LoseWindow::onMenuClicked() {
    player->stop();  // Остановка музыки
    MainWindow *mainMenu = new MainWindow();
    mainMenu->show();
    this->close();
}

void LoseWindow::onRetryClicked() {
     player->stop();  // Остановка музыки
    GameWindow *retryGame = new GameWindow();
    retryGame->show();
    this->close();
}
