#include "dialog_pause.h"
#include "ui_dialog_pause.h"

Dialog_pause::Dialog_pause(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_pause)
{
    ui->setupUi(this);
    //去窗口裱框
    setWindowFlags(Qt::FramelessWindowHint|windowFlags());
    this->hide();

}

Dialog_pause::~Dialog_pause()
{
    delete ui;
}

void Dialog_pause::keyPressEvent(QKeyEvent *e)
{
    if(e->key()==Qt::Key_P)
    {
        this->hide();
        emit pause();
    }
}
