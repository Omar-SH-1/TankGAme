#ifndef VICTORYWINDOW_H
#define VICTORYWINDOW_H

#include <QMainWindow>

class VictoryWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit VictoryWindow(QWidget *parent = nullptr);

signals:
    void goToMenu();
    void nextLevel();
};

#endif // VICTORYWINDOW_H
