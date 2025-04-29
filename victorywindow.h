#ifndef VICTORYWINDOW_H
#define VICTORYWINDOW_H

#include <QMainWindow>

class VictoryWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit VictoryWindow(QWidget *parent = nullptr);

private slots:
    void onMenuClicked();
    void onNextLevelClicked();
};

#endif // VICTORYWINDOW_H
