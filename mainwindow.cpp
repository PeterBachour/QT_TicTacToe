#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iostream"
#include <QtWidgets>

using namespace std;


char board[3][3];
int player = 0;
bool vs_computer;
bool vs_player;
string winner;
string turn;
int scoreX = 0;
int scoreO = 0;
int reponse;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Tic Tac Toe by Bachour&Deleau");

    //Labels
    ui->label_win1->setVisible(0);
    ui->label_win1->setVisible(0);

    //Slider
    ui->slider_music->setValue(100);
    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/Sound/music.mp3"));
    music->play();
    connect(ui->slider_music,SIGNAL(valueChanged(int)),music,SLOT(setVolume(int)));



    QMessageBox messageBox(QMessageBox::Question,
    tr("Please choose against who you want to play."),
    tr("Please choose against who you want to play."),
    QMessageBox::Yes | QMessageBox::No,
    NULL);
    messageBox.setButtonText(QMessageBox::Yes, tr("Player"));
    messageBox.setButtonText(QMessageBox::No, tr("Computer"));
    reponse = messageBox.exec();

    newGame();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newGame(){
    if(reponse == QMessageBox::No){
        vs_computer = true;
        ui->RB_vs_computer->setChecked(true);
    }else if(reponse == QMessageBox::Yes){
        vs_player = true;
        ui->RB_vs_player->setChecked(true);
    }else {
        vs_computer = ui->RB_vs_computer->isChecked();
        vs_player = ui->RB_vs_player->isChecked();
    }

    QMessageBox msgBox1;
            msgBox1.setText("You are going to play against another the player.");
            msgBox1.setStandardButtons(QMessageBox::Ok);
            msgBox1.setDefaultButton(QMessageBox::Ok);
    QMessageBox msgBox2;
            msgBox2.setText("You are going to play against a computer.");
            msgBox2.setStandardButtons(QMessageBox::Ok);
            msgBox2.setDefaultButton(QMessageBox::Ok);

    if(vs_player){
       msgBox1.exec();
    }
    else if(vs_computer){
       msgBox2.exec();
    }

    for (int i = 0; i<3; i++)
        for (int j = 0; j<3; j++)
            board[i][j] = '_';
}
bool MainWindow::isAvailableSpot(int x, int y){
    return (board[x][y] == '_');
}
bool MainWindow::checkwin(){

    char turn;
    if(player%2 == 0)
        turn = 'X';
    else
        turn = 'O';

    for(int i = 0; i < 3; i++) {
        // Check horizontals
        if(board[i][0] == turn && board[i][1] == turn
            && board[i][2] == turn){
            drawWinLine(i);
            return true;
         }
        // Check verticals
    if(board[0][i] == turn && board[1][i] == turn
        && board[2][i] == turn){
            drawWinLine(3+i);
            return true;
        }

    }
    // Check diagonals
    if (board[0][0] == turn && board[1][1] == turn && board[2][2] == turn) {
        drawWinLine(6);
        return true;
    } else if (board[0][2] == turn && board[1][1] == turn && board[2][0] == turn) {
        return true;
    }

    return false;
}
bool MainWindow::checkDraw() {
    bool empty = false;
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == '_' || board[i][1] == '_' || board[i][2] == '_')
            empty = true;
    }
    return !empty;
}
void MainWindow::showEndGame(){
    if(checkwin() || checkDraw()){
        if(checkwin()){
            if(player%2 == 0){
                winner = "X won.";
                scoreX++;
            }
            else{
                winner = "O won.";
                scoreO++;
            }
            ui->label_turn->setText(winner.c_str());
        }
        if(checkDraw()){
            ui->label_turn->setText("Draw");
        }
        ui->label_O_score->setText(to_string(scoreO).c_str());
        ui->label_X_score->setText(to_string(scoreX).c_str());
        enableSpots(false);
    }
}
void MainWindow::checkmove(int x, int y){
    if(!isAvailableSpot(x, y))
        return;

    if(player%2 == 0){
        board[x][y] = 'X';
        turn = "O's turn.";
    }else{
        board[x][y] = 'O';
        turn = "X's turn.";
    }
    ui->label_turn->setText(turn.c_str());
    showSpots();
    showEndGame();
    player++;
}
void MainWindow::drawWinLine(int i){
    QPicture pi;
    QPainter p(&pi);
    p.setRenderHint(QPainter::Antialiasing);
    p.setPen(QPen(Qt::red, 15));
    if(i == 0){ //first column
        p.drawLine(0,40,243,40);
        ui->label_win1->setGeometry(150,70,243,81);
    }else if (i == 1){ // 2nd column
        p.drawLine(0,124,243,124);
        ui->label_win1->setGeometry(150,151,243,81);
    } else if (i == 2){ //3rd column
        p.drawLine(0,207,243,207);
        ui->label_win1->setGeometry(150,232,243,81);
    } else if (i == 3){ //1st row
        p.drawLine(40,0,40,243);
        ui->label_win1->setGeometry(183,70,81,243);
    } else if (i == 4){ // 2nd row
        p.drawLine(124,0,124,243);
        ui->label_win1->setGeometry(264,70,81,243);
    } else if (i == 5){ // 3rd row
        p.drawLine(207,0,207,243);
        ui->label_win1->setGeometry(345,70,81,243);
    } else if (i == 6){ //1st diagonal
        p.drawLine(0,0,243,243);
        ui->label_win1->setGeometry(150,70,243,243);
    } else if (i == 7){ //2nd diagonal
        p.drawLine(0,243,243,0);
        ui->label_win1->setGeometry(150,70,243,243);
    }
    p.end();
    ui->label_win1->setPicture(pi);
    ui->label_win1->setVisible(1);

}
void MainWindow::showSpots(){
    if(!isAvailableSpot(0,0))
        ui->place_0->setText(string(1, board[0][0]).c_str());
    if(!isAvailableSpot(0,1))
        ui->place_1->setText(string(1, board[0][1]).c_str());
    if(!isAvailableSpot(0,2))
        ui->place_2->setText(string(1, board[0][2]).c_str());
    if(!isAvailableSpot(1,0))
        ui->place_3->setText(string(1, board[1][0]).c_str());
    if(!isAvailableSpot(1,1))
        ui->place_4->setText(string(1, board[1][1]).c_str());
    if(!isAvailableSpot(1,2))
        ui->place_5->setText(string(1, board[1][2]).c_str());
    if(!isAvailableSpot(2,0))
        ui->place_6->setText(string(1, board[2][0]).c_str());
    if(!isAvailableSpot(2,1))
        ui->place_7->setText(string(1, board[2][1]).c_str());
    if(!isAvailableSpot(2,2))
        ui->place_8->setText(string(1, board[2][2]).c_str());
}
void MainWindow::initializeSpots(){
    ui->place_0->setText("");
    ui->place_1->setText("");
    ui->place_2->setText("");
    ui->place_3->setText("");
    ui->place_4->setText("");
    ui->place_5->setText("");
    ui->place_6->setText("");
    ui->place_7->setText("");
    ui->place_8->setText("");
}
void MainWindow::enableSpots(bool x){
    ui->place_0->setEnabled(x);
    ui->place_1->setEnabled(x);
    ui->place_2->setEnabled(x);
    ui->place_3->setEnabled(x);
    ui->place_4->setEnabled(x);
    ui->place_5->setEnabled(x);
    ui->place_6->setEnabled(x);
    ui->place_7->setEnabled(x);
    ui->place_8->setEnabled(x);
}


void MainWindow::on_place_0_clicked(){
    checkmove(0,0);
}
void MainWindow::on_place_1_clicked(){
    checkmove(0,1);
}
void MainWindow::on_place_2_clicked(){
    checkmove(0,2);
}
void MainWindow::on_place_3_clicked(){
    checkmove(1,0);
}
void MainWindow::on_place_4_clicked(){
    checkmove(1,1);
}
void MainWindow::on_place_5_clicked(){
    checkmove(1,2);
}
void MainWindow::on_place_6_clicked(){
    checkmove(2,0);
}
void MainWindow::on_place_7_clicked(){
    checkmove(2,1);
}
void MainWindow::on_place_8_clicked(){
    checkmove(2,2);
}
void MainWindow::on_CB_darkmode_clicked(){
    if(ui->CB_darkmode->isChecked()){
        ui->label_background->setStyleSheet("QLabel { background-color : black;}");
        ui->label_turn->setStyleSheet("QLabel { color : white;}");
        ui->label_music->setStyleSheet("QLabel { color : white;}");
        ui->label_O->setStyleSheet("QLabel { color : white;}");
        ui->label_O_score->setStyleSheet("QLabel { color : white;}");
        ui->label_Score->setStyleSheet("QLabel { color : white;}");
        ui->label_Select->setStyleSheet("QLabel { color : white;}");
        ui->label_signature->setStyleSheet("QLabel { color : white;}");
        ui->label_win1->setStyleSheet("QLabel { color : white;}");
        ui->label_X->setStyleSheet("QLabel { color : white;}");
        ui->label_X_score->setStyleSheet("QLabel { color : white;}");
        ui->label_dark_mode->setStyleSheet("QLabel { color : white;}");
        ui->RB_vs_computer->setStyleSheet("QRadioButton { color : white;}");
        ui->RB_vs_player->setStyleSheet("QRadioButton { color : white;}");
        ui->PB_new_game->setStyleSheet("QPushButton { color : white; background-color: black; border: 4px solid white}");
        ui->place_0->setStyleSheet("QPushButton { color : white; background-color: black; border: 4px solid white;}");
        ui->place_1->setStyleSheet("QPushButton { color : white; background-color: black; border: 4px solid white;}");
        ui->place_2->setStyleSheet("QPushButton { color : white; background-color: black; border: 4px solid white;}");
        ui->place_3->setStyleSheet("QPushButton { color : white; background-color: black; border: 4px solid white;}");
        ui->place_4->setStyleSheet("QPushButton { color : white; background-color: black; border: 4px solid white;}");
        ui->place_5->setStyleSheet("QPushButton { color : white; background-color: black; border: 4px solid white;}");
        ui->place_6->setStyleSheet("QPushButton { color : white; background-color: black; border: 4px solid white;}");
        ui->place_7->setStyleSheet("QPushButton { color : white; background-color: black; border: 4px solid white;}");
        ui->place_8->setStyleSheet("QPushButton { color : white; background-color: black; border: 4px solid white;}");
        ui->label_bigLogo->setStyleSheet("QLabel { background: url(:/images/logoblack1.png)}");
        ui->label_logo->setStyleSheet("QLabel { background: url(:/images/logoblack2.png)}");
    }
    else{
        ui->label_background->setStyleSheet("QLabel { background-color : white; }");
        ui->label_turn->setStyleSheet("QLabel { color : black;}");
        ui->label_music->setStyleSheet("QLabel { color : black;}");
        ui->label_O->setStyleSheet("QLabel { color : black;}");
        ui->label_O_score->setStyleSheet("QLabel { color : black;}");
        ui->label_Score->setStyleSheet("QLabel { color : black;}");
        ui->label_Select->setStyleSheet("QLabel { color : black;}");
        ui->label_signature->setStyleSheet("QLabel { color : black;}");
        ui->label_win1->setStyleSheet("QLabel { color : black;}");
        ui->label_X->setStyleSheet("QLabel { color : black;}");
        ui->label_X_score->setStyleSheet("QLabel { color : black;}");
        ui->label_dark_mode->setStyleSheet("QLabel { color : black;}");
        ui->RB_vs_computer->setStyleSheet("QRadioButton { color : black;}");
        ui->RB_vs_player->setStyleSheet("QRadioButton { color : black;}");
        ui->PB_new_game->setStyleSheet("QPushButton { color : black; background-color: white; border: 4px solid black;}");

        ui->place_0->setStyleSheet("QPushButton { color : black; background-color: white; border: 4px solid black;}");
        ui->place_1->setStyleSheet("QPushButton { color : black; background-color: white; border: 4px solid black;}");
        ui->place_2->setStyleSheet("QPushButton { color : black; background-color: white; border: 4px solid black;}");
        ui->place_3->setStyleSheet("QPushButton { color : black; background-color: white; border: 4px solid black;}");
        ui->place_4->setStyleSheet("QPushButton { color : black; background-color: white; border: 4px solid black;}");
        ui->place_5->setStyleSheet("QPushButton { color : black; background-color: white; border: 4px solid black;}");
        ui->place_6->setStyleSheet("QPushButton { color : black; background-color: white; border: 4px solid black;}");
        ui->place_7->setStyleSheet("QPushButton { color : black; background-color: white; border: 4px solid black;}");
        ui->place_8->setStyleSheet("QPushButton { color : black; background-color: white; border: 4px solid black;}");

        ui->label_bigLogo->setStyleSheet("QLabel { background: url(:/images/large_logo.png)}");
        ui->label_logo->setStyleSheet("QLabel { background: url(:/images/small_logo_100px.png)}");

    }
}
void MainWindow::on_PB_new_game_clicked(){
    newGame();
    initializeSpots();
    enableSpots(true);
    ui->label_win1->setVisible(0);
    if(player%2 == 0)
        turn = "X's turn.";
    else
        turn = "O's turn.";
    ui->label_turn->setText(turn.c_str());
}











