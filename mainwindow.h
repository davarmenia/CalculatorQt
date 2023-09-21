#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QLabel *lbl;
    QLabel *lbl_all;
    void TextStartZero(QString num);


    void ConstructBoard();

    float equal_num = 0;
    float first_num = 0;
    float second_num = 0;

private slots:
    void btn_num_clk();
    void btn_operation();
    void btn_AC();
    void btn_invert();
    void btn_equals();
    void btn_procent();

};
#endif // MAINWINDOW_H
