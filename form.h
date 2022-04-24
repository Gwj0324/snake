#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include<QTimer>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);
    ~Form();
    void m_form_grades();
    void show_label_3();
    void emit_signal();
    void paintEvent(QPaintEvent *e);
signals:
    void play_again();

private:
    Ui::Form *ui;
    QTimer *m_timer_sub;
};

#endif // FORM_H
