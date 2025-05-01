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

    QMediaPlayer *player = new QMediaPlayer(this);
    QAudioOutput *audioOutput = new QAudioOutput(this);
    player->setAudioOutput(audioOutput);
    player->setSource(QUrl("qrc:/images/lose.mp3"));
    audioOutput->setVolume(50);
    player->play();
}

void LoseWindow::onMenuClicked() {
    MainWindow *mainMenu = new MainWindow();
    mainMenu->show();
    this->close();
}

void LoseWindow::onRetryClicked() {
    GameWindow *retryGame = new GameWindow();
    retryGame->show();
    this->close();
}
