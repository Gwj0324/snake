#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Snake");
    this->hide();
    music_bool=0;
    connect(ui->pushButton,&QPushButton::clicked,this,&Dialog::deal_back_music);

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::deal_back_music()
{
    if(music_bool==0)
    {
        ui->pushButton->setStyleSheet("QPushButton{"
                                  "background-color: rgba(255, 255, 255, 0);"
                                  "background-image: url(:/new/prefix1/image/music_close.png);"
                                  "}");
        music_bool=1;
        emit back_music();
    }
    else if(music_bool==1)
    {
        ui->pushButton->setStyleSheet("QPushButton{"
                                  "background-color: rgba(255, 255, 255, 0);"
                                  "background-image: url(:/new/prefix1/image/music_open.png);"
                                  "}");
        music_bool=0;
        emit back_music();
    }

}

void Dialog::on_comboBox_currentIndexChanged(const QString &arg1)
{
    if(arg1=="easy")
    {
      m_speed=500;
      emit level_signal(m_speed);
    }
    else if(arg1=="ordinary")
    {
        m_speed=300;
        emit level_signal(m_speed);
    }
    else if(arg1=="difficult")
    {
        m_speed=100;
        emit level_signal(m_speed);
    }
}

void Dialog::on_comboBox_2_currentIndexChanged(const QString &arg1)
{
    emit snake_color(arg1);
}

void Dialog::on_comboBox_3_currentIndexChanged(const QString &arg1)
{
    emit food_color(arg1);
}

void Dialog::on_pushButton_2_clicked()
{
    emit non_human();
}
