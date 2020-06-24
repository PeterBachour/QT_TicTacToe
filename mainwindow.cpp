#include "mainwindow.h"
#include "ui_mainwindow.h"

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
}

MainWindow::~MainWindow()
{
    delete ui;
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
