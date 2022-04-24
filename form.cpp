#include "form.h"
#include "ui_form.h"
#include<Qpainter>
extern QString str;


Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    this->setWindowTitle("Snake");
    m_timer_sub=new QTimer(this);
    this->hide();
    m_timer_sub->start(200);
    connect(m_timer_sub,&QTimer::timeout,this,&Form::m_form_grades);
    connect(ui->pushButton,&QPushButton::clicked,this,&Form::emit_signal);
}

Form::~Form()
{
    delete ui;
}

void Form::m_form_grades()
{
    show_label_3();
}

void Form::show_label_3()
{
    ui->label_3->setText(str);
}

void Form::emit_signal()
{
    emit play_again();
}

void Form::paintEvent(QPaintEvent *e)
{
    QPainter p(this);
    p.drawPixmap(0,0,this->width(),this->height(),QPixmap(":/new/prefix1/image/back2.jpg"));
}
