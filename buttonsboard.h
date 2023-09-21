#ifndef BUTTONSBOARD_H
#define BUTTONSBOARD_H


#include <QVBoxLayout>
#include <QWidget>


class buttonsboard: public QWidget
{
public:
    buttonsboard();
    ~buttonsboard();

    QVBoxLayout &GetVbox() {return *vbox;};
private:
    QVBoxLayout *vbox;
};

#endif // BUTTONSBOARD_H
