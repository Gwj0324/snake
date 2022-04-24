#include "widget.h"
#include "ui_widget.h"
#include<QPaintEvent>
#include<QPainter>
#include<QPen>
#include<QBrush>
#include<QKeyEvent>
#include<QSound>
#include<QTime>
#include<QIcon>
QString str;

#define up 0
#define down 1
#define left 2
#define right 3

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    music_deal=0;
    str1="red";
    str2="red";
    non_human_record=0;
    ui->pushButton_3->close();

    sound=new QSound(":/new/prefix1/image/music.wav");
    sound->play();
    sound->setLoops(-1);

    ui->label->setText(QString("0"));
    this->setWindowTitle("Snake");
    this->setWindowIcon(QIcon(":/new/prefix1/image/love1.ico"));

    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    direction=1;
    speed=500;
    grades=0;
    arr[0][0]=1+qrand()%(49-1);
    arr[0][1]=1+qrand()%(49-1);
    food_x=1+qrand()%(49-1);
    food_y=1+qrand()%(49-1);
    m_timer=new QTimer(this);
    connect(m_timer,&QTimer::timeout,this,&Widget::timeslot);
    connect(&form,&Form::play_again,this,&Widget::play_again_deal);
    connect(&dialog,&Dialog::back_music,this,&Widget::w_back_music);
    connect(&dialog,&Dialog::level_signal,this,&Widget::time_open);
    connect(&dialog,&Dialog::snake_color,this,&Widget::deal);
    connect(&dialog,&Dialog::food_color,this,&Widget::food_deal);
    connect(&dialog,&Dialog::non_human,this,
            [=]()
    {
        non_human_record=1;
        dialog.close();
        m_timer->start(speed);

    });
    connect(&dialog_pause,&Dialog_pause::pause,
            [=]()
    {
        m_timer->start(speed);
        ui->pushButton_3->close();
    });



}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.drawPixmap(0,0,this->width(),this->height(),QPixmap(":/new/prefix1/image/back2.jpg"));
    QBrush brush;
    QPen pen;
    pen.setWidth(1);
    pen.setColor(QColor(255,128,192));
    p.setPen(pen);
    p.drawRect(10,10,480,480);
    brush.setColor(Qt::red);
    brush.setStyle(Qt::SolidPattern);
    p.setBrush(brush);
    //画食物
    if(str2=="red")
    {
        p.drawRect(food_x*10,food_y*10,10,10);
    }
    else if(str2=="DJ")
    {
        if(changeable_record%5==0)
        {
            pen.setColor(Qt::red);
            p.setPen(pen);
            brush.setColor(Qt::red);
            brush.setStyle(Qt::SolidPattern);
            p.setBrush(brush);
            p.drawRect(food_x*10,food_y*10,10,10);
        }
        else if(changeable_record%5==1)
        {
            pen.setColor(Qt::yellow);
            p.setPen(pen);
            brush.setColor(Qt::yellow);
            brush.setStyle(Qt::SolidPattern);
            p.setBrush(brush);
            p.drawRect(food_x*10,food_y*10,10,10);
        }
        else if(changeable_record%5==2)
        {
            pen.setColor(Qt::green);
            p.setPen(pen);
            brush.setColor(Qt::green);
            brush.setStyle(Qt::SolidPattern);
            p.setBrush(brush);
            p.drawRect(food_x*10,food_y*10,10,10);
        }
        else if(changeable_record%5==3)
        {
            pen.setColor(Qt::cyan);
            p.setPen(pen);
            brush.setColor(Qt::cyan);
            brush.setStyle(Qt::SolidPattern);
            p.setBrush(brush);
            p.drawRect(food_x*10,food_y*10,10,10);
        }
        else if(changeable_record%5==4)
        {
            pen.setColor(Qt::magenta);
            p.setPen(pen);
            brush.setColor(Qt::magenta);
            brush.setStyle(Qt::SolidPattern);
            p.setBrush(brush);
            p.drawRect(food_x*10,food_y*10,10,10);
        }
    }
    else if(str2=="LOVE")
    {
        p.drawImage(QRect(food_x*10,food_y*10,10,10),QImage(":/new/prefix1/image/love1.jpg"),QRect(0,0,1500,1500));
    }
    brush.setColor(Qt::red);
    brush.setStyle(Qt::SolidPattern);
    p.setBrush(brush);
    pen.setColor(QColor(255,128,192));
    p.setPen(pen);
    //画头
    //画蛇身
    int j;
    for(j=0;j<=grades;j++)
    {
        if(str1=="red")
        {
            brush.setColor(Qt::red);
            brush.setStyle(Qt::SolidPattern);
            p.setBrush(brush);
             p.drawRect(arr[j][0]*10,arr[j][1]*10,10,10);
        }
        else if(str1=="colorful")
        {
            if(j%5==0)
            {
                pen.setColor(Qt::red);
                p.setPen(pen);
                brush.setColor(Qt::red);
                brush.setStyle(Qt::SolidPattern);
                p.setBrush(brush);
            }
            else if(j%5==1)
            {
                pen.setColor(Qt::yellow);
                p.setPen(pen);
                brush.setColor(Qt::yellow);
                brush.setStyle(Qt::SolidPattern);
                p.setBrush(brush);
            }
            else if(j%5==2)
            {
                pen.setColor(Qt::green);
                p.setPen(pen);
                brush.setColor(Qt::green);
                brush.setStyle(Qt::SolidPattern);
                p.setBrush(brush);
            }
            else if(j%5==3)
            {
                pen.setColor(Qt::cyan);
                p.setPen(pen);
                brush.setColor(Qt::cyan);
                brush.setStyle(Qt::SolidPattern);
                p.setBrush(brush);
            }
            else if(j%5==4)
            {
                pen.setColor(Qt::magenta);
                p.setPen(pen);
                brush.setColor(Qt::magenta);
                brush.setStyle(Qt::SolidPattern);
                p.setBrush(brush);
            }
             p.drawRect(arr[j][0]*10,arr[j][1]*10,10,10);
        }
        else if(str1=="changeable")
        {
            if(changeable_record%5==0)
            {
                pen.setColor(Qt::red);
                p.setPen(pen);
                brush.setColor(Qt::red);
                brush.setStyle(Qt::SolidPattern);
                p.setBrush(brush);
            }
            else if(changeable_record%5==1)
            {
                pen.setColor(Qt::yellow);
                p.setPen(pen);
                brush.setColor(Qt::yellow);
                brush.setStyle(Qt::SolidPattern);
                p.setBrush(brush);
            }
            else if(changeable_record%5==2)
            {
                pen.setColor(Qt::green);
                p.setPen(pen);
                brush.setColor(Qt::green);
                brush.setStyle(Qt::SolidPattern);
                p.setBrush(brush);
            }
            else if(changeable_record%5==3)
            {
                pen.setColor(Qt::cyan);
                p.setPen(pen);
                brush.setColor(Qt::cyan);
                brush.setStyle(Qt::SolidPattern);
                p.setBrush(brush);
            }
            else if(changeable_record%5==4)
            {
                pen.setColor(Qt::magenta);
                p.setPen(pen);
                brush.setColor(Qt::magenta);
                brush.setStyle(Qt::SolidPattern);
                p.setBrush(brush);
            }
             p.drawRect(arr[j][0]*10,arr[j][1]*10,10,10);
        }
        else if(str1=="amazing")
        {

            if(changeable_record%5==0)
            {
                pen.setColor(Qt::red);
                p.setPen(pen);
                brush.setColor(Qt::red);
                brush.setStyle(Qt::SolidPattern);
                p.setBrush(brush);
                p.drawRect(arr[0][0]*10,arr[0][1]*10,10,10);
            }
            else if(changeable_record%5==1)
            {
                pen.setColor(Qt::yellow);
                p.setPen(pen);
                brush.setColor(Qt::yellow);
                brush.setStyle(Qt::SolidPattern);
                p.setBrush(brush);
                p.drawRect(arr[0][0]*10,arr[0][1]*10,10,10);
            }
            else if(changeable_record%5==2)
            {
                pen.setColor(Qt::green);
                p.setPen(pen);
                brush.setColor(Qt::green);
                brush.setStyle(Qt::SolidPattern);
                p.setBrush(brush);
                p.drawRect(arr[0][0]*10,arr[0][1]*10,10,10);
            }
            else if(changeable_record%5==3)
            {
                pen.setColor(Qt::cyan);
                p.setPen(pen);
                brush.setColor(Qt::cyan);
                brush.setStyle(Qt::SolidPattern);
                p.setBrush(brush);
                p.drawRect(arr[0][0]*10,arr[0][1]*10,10,10);
            }
            else if(changeable_record%5==4)
            {
                pen.setColor(Qt::magenta);
                p.setPen(pen);
                brush.setColor(Qt::magenta);
                brush.setStyle(Qt::SolidPattern);
                p.setBrush(brush);
                p.drawRect(arr[0][0]*10,arr[0][1]*10,10,10);
            }
            if(j!=0)
            {
                pen.setColor(QColor(255,128,192));
                p.setPen(pen);
                brush.setColor(Qt::red);
                brush.setStyle(Qt::SolidPattern);
                p.setBrush(brush);
                p.drawRect(arr[j][0]*10,arr[j][1]*10,10,10);
            }

        }
        else if(str1=="DJ")
        {
            if(changeable_record%5==0)
            {
                pen.setColor(Qt::red);
                p.setPen(pen);
                p.drawRect(arr[j][0]*10,arr[j][1]*10,10,10);
            }
            else if(changeable_record%5==1)
            {
                pen.setColor(Qt::yellow);
                p.setPen(pen);
                p.drawRect(arr[j][0]*10,arr[j][1]*10,10,10);
            }
            else if(changeable_record%5==2)
            {
                pen.setColor(Qt::green);
                p.setPen(pen);
                p.drawRect(arr[j][0]*10,arr[j][1]*10,10,10);
            }
            else if(changeable_record%5==3)
            {
                pen.setColor(Qt::cyan);
                p.setPen(pen);
                p.drawRect(arr[j][0]*10,arr[j][1]*10,10,10);
            }
            else if(changeable_record%5==4)
            {
                pen.setColor(Qt::magenta);
                p.setPen(pen);
                p.drawRect(arr[j][0]*10,arr[j][1]*10,10,10);
            }

        }
    }



}

void Widget::keyPressEvent(QKeyEvent *e)
{
    if(non_human_record==0)
    {
    switch (e->key()) {
    case Qt::Key_W:
        if(grades==0)
        {
            direction=0;
        }
        else if(direction==1)
        {
            break;
        }
        else
            direction=0;
        break;
    case Qt::Key_S:
        if(grades==0)
        {
            direction=1;
        }
        else if(direction==0)
        {
            break;
        }
        else
            direction=1;
        break;
    case Qt::Key_A:
        if(grades==0)
        {
            direction=2;
        }
        else if(direction==3)
        {
            break;
        }
        else
            direction=2;
        break;
    case Qt::Key_D:
        if(grades==0)
        {
            direction=3;
        }
        else if(direction==2)
        {
            break;
        }
        else
            direction=3;
        break;
    case Qt::Key_J:
        m_timer->stop();
        m_speed=50;
        m_timer->start(m_speed);
        break;
    case Qt::Key_K:
        m_timer->stop();

        m_timer->start(speed);
        break;
    case Qt::Key_P:
        m_timer->stop();
        dialog_pause.show();
        ui->pushButton_3->show();
        break;
    default:
        break; 
    }
   }
    else if(non_human_record==1)
    {
        switch (e->key()) {
        case Qt::Key_W:
            if(grades==0)
            {
                direction=1;
            }
            else if(direction==0)
            {
                break;
            }
            else
                direction=1;
            break;

        case Qt::Key_S:
            if(grades==0)
            {
                direction=0;
            }
            else if(direction==1)
            {
                break;
            }
            else
                direction=0;
            break;
        case Qt::Key_A:
            if(grades==0)
            {
                direction=3;
            }
            else if(direction==2)
            {
                break;
            }
            else
                direction=3;
            break;

        case Qt::Key_D:
            if(grades==0)
            {
                direction=2;
            }
            else if(direction==3)
            {
                break;
            }
            else
                direction=2;
            break;
        case Qt::Key_J:
            m_timer->stop();

            m_timer->start(speed);
            break;
        case Qt::Key_K:
            m_timer->stop();
            m_speed=50;
            m_timer->start(m_speed);
            break;

        case Qt::Key_P:
            m_timer->stop();
            dialog_pause.show();
            ui->pushButton_3->show();
            break;
        default:
            break;
        }
    }
}

void Widget::timeslot()
{
    changeable_record++;
    int j;
    for(j=1;j<=grades;j++)
    {
        if(arr[0][0]==arr[j][0]&&arr[0][1]==arr[j][1])
        {
            m_timer->stop();
            this->hide();
            form.show();
            break;
        }
    }
    if(arr[0][0]==food_x&&arr[0][1]==food_y)
    {
        grades+=1;
        str=QString("%1").arg(grades);
        ui->label->setText(str);

        food_x=1+qrand()%(49-1);
        food_y=1+qrand()%(49-1);
    }
    int i;
    for(i=grades;i>=1;i--)
    {
        arr[i][0]=arr[i-1][0];
        arr[i][1]=arr[i-1][1];
    }
    switch (direction) {
    case up:
        arr[0][1]-=1;

        break;
    case down:
        arr[0][1]+=1;

        break;
    case left:
        arr[0][0]-=1;

        break;
    case right:
        arr[0][0]+=1;

        break;
    default:
        break;
    }
    if(arr[0][0]<1||arr[0][0]>=49||arr[0][1]<1||arr[0][1]>=49)
    {
        m_timer->stop();
        this->hide();
        form.show();

    }
    update();
}

void Widget::deal(QString str)
{
   str1=str;
}

void Widget::play_again_deal()
{
    this->show();
    form.hide();
    init_all();
}

void Widget::init_all()
{
    direction=1;
    grades=0;
    arr[0][0]=1+qrand()%(49-1);
    arr[0][1]=1+qrand()%(49-1);
    food_x=1+qrand()%(49-1);
    food_y=1+qrand()%(49-1);
    ui->label->setText(QString("0"));
    m_timer->start(speed);
}

void Widget::w_back_music()
{
    if(music_deal==0)
   {
        sound->stop();
        music_deal++;
    }
    else if(music_deal==1)
    {
        sound->play();
        music_deal--;
    }
}

void Widget::time_open(int level_speed)
{
    speed=level_speed;
}

void Widget::food_deal(QString str)
{
    str2=str;
}

void Widget::on_pushButton_clicked()
{
    m_timer->start(speed);

}

void Widget::on_pushButton_2_clicked()
{
     dialog.show();
     dialog_pause.close();
}

void Widget::on_pushButton_3_clicked()
{
    m_timer->start(speed);
    ui->pushButton_3->close();
    dialog_pause.close();
}
