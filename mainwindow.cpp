#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QLabel>
#include <QPixmap>
#include "gamewindow.h"
#include <QMediaPlayer>
#include <QAudioOutput>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
    setFixedSize(900, 700);

    player = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);
    player->setAudioOutput(audioOutput);
    player->setSource(QUrl("qrc:/images/menu.mp3"));
    audioOutput->setVolume(50); // громкость от 0 до 100
    player->play();

    // Фон
    QLabel *background = new QLabel(this);
    background->setPixmap(QPixmap(":/images/fonT.png").scaled(size()));
    background->setGeometry(0, 0, width(), height());
    background->lower();

    // Кнопка "Играть"
    QPushButton *playButton = new QPushButton("Играть", this);
    playButton->setGeometry(350, 400, 200, 50);
    connect(playButton, &QPushButton::clicked, this, &MainWindow::onPlayClicked);

    // Кнопка "Выбрать танк"
    QPushButton *chooseButton = new QPushButton("Выбрать танк", this);
    chooseButton->setGeometry(350, 470, 200, 50);
    connect(chooseButton, &QPushButton::clicked, this, &MainWindow::onChooseTankClicked);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::onPlayClicked() {
    GameWindow *game = new GameWindow();
    game->show();
    this->close();    // Закрыть меню
    player->stop();   // Выключить музыку меню
}


void MainWindow::onChooseTankClicked() {
    // Тут появится выбор танка
}
