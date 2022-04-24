#ifndef DIALOG_PAUSE_H
#define DIALOG_PAUSE_H

#include <QDialog>
#include <QKeyEvent>

namespace Ui {
class Dialog_pause;
}

class Dialog_pause : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_pause(QWidget *parent = 0);
    ~Dialog_pause();
    void keyPressEvent(QKeyEvent *e);
signals:
    void pause();

private:
    Ui::Dialog_pause *ui;
};

#endif // DIALOG_PAUSE_H
