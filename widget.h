#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QTimer>
#include<form.h>
#include<dialog.h>
#include<QSound>
#include<dialog_pause.h>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *e);
    void timeslot();
    void deal(QString str);
    void play_again_deal();
    void init_all();
    void w_back_music();
    void time_open(int level_speed);
    void food_deal(QString str);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Widget *ui;
    int arr[100][2];
    QTimer *m_timer;
    int direction;
    int food_x,food_y;
    int grades;
    Form form;
    int speed;
    Dialog dialog;
    QSound *sound;
    int music_deal;
    Dialog_pause dialog_pause;
    QString str1;
    QString str2;
    int changeable_record;
    int m_speed;
    int non_human_record;


};

#endif // WIDGET_H
