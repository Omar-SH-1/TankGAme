#ifndef LOSEWINDOW_H
#define LOSEWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QAudioOutput>

class LoseWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit LoseWindow(QWidget *parent = nullptr);
private:
    QMediaPlayer *player;
    QAudioOutput *audioOutput;


private slots:
    void onMenuClicked();
    void onRetryClicked();

};

#endif // LOSEWINDOW_H
