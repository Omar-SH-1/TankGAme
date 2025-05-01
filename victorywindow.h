#ifndef VICTORYWINDOW_H
#define VICTORYWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QAudioOutput>


class VictoryWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit VictoryWindow(QWidget *parent = nullptr);
private:
    QMediaPlayer *player;
    QAudioOutput *audioOutput;

private slots:
    void onMenuClicked();
    void onNextLevelClicked();
};

#endif // VICTORYWINDOW_H
