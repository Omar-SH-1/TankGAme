#ifndef LOSEWINDOW_H
#define LOSEWINDOW_H

#include <QMainWindow>

class LoseWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit LoseWindow(QWidget *parent = nullptr);

private slots:
    void onMenuClicked();
    void onRetryClicked();

};

#endif // LOSEWINDOW_H
