#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    void deal_back_music();
    int m_speed;
signals:
    void back_music();
    void level_signal(int speed);
    void snake_color(QString str);
    void food_color(QString str);
    void non_human();

private slots:


    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_comboBox_2_currentIndexChanged(const QString &arg1);

    void on_comboBox_3_currentIndexChanged(const QString &arg1);

    void on_pushButton_2_clicked();

private:
    Ui::Dialog *ui;
    int music_bool;


};

#endif // DIALOG_H
