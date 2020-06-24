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
    bool checkwin(char player);              //checks if a player won
    void checkmove(int x, int y);            //checks if the move is available
    void initializeSpots();                  //initializes all spots to initial value
    void enableSpots(bool x);                // enable all spots
    void showSpots();                        // shows all spots
    void drawWinLine();                      // draws line if all values are equal
    bool checkDraw();                        // checks if the game ends with a draw
    bool showEndGame();                      // shows the winner
    bool isAvailableSpot(int x, int y);      // checks if a spot is available
    void newGame();                          // launches a new game
    void minimax(char AIboard[3][3]);        // minimax algorithm for AI
    int minSearch(char AIboard[3][3]);       // minSearch algorithm for AI
    int maxSearch(char AIboard[3][3]);       // maxSearch algorithm for AI
    int score();                             // calculates the score for the minimax algorithm



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
    void on_CB_darkmode_clicked();           // dark mode button
    void on_PB_new_game_clicked();           // new game button


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
