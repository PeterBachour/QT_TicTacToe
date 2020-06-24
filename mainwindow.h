#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    bool checkwin(char player);
    void checkmove(int x, int y);
    void initializeSpots();
    void enableSpots(bool x);
    void showSpots();
    void drawWinLine();
    bool checkDraw();
    bool showEndGame();
    bool isAvailableSpot(int x, int y);
    void newGame();
    void minimax(char AIboard[3][3]);
    int minSearch(char AIboard[3][3]);
    int maxSearch(char AIboard[3][3]);
    int score();



private slots:
    void on_place_0_clicked();
    void on_place_1_clicked();
    void on_place_2_clicked();
    void on_place_3_clicked();
    void on_place_4_clicked();
    void on_place_5_clicked();
    void on_place_6_clicked();
    void on_place_7_clicked();
    void on_place_8_clicked();
    void on_CB_darkmode_clicked();
    void on_PB_new_game_clicked();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
