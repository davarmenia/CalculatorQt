#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QPushButton>
#include <QGridLayout>
#include <QFont>
#include <QRegularExpression>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ConstructBoard();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ConstructBoard()
{
    this->setWindowTitle("Calculator");

    QGridLayout *layout = new QGridLayout();
    centralWidget()->setLayout (layout);

    lbl = new QLabel();
    lbl->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    lbl->setText("0");
    lbl->setFont(QFont("Courier New", 18, QFont::Bold));

    lbl_all = new QLabel();
    lbl_all->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    lbl_all->setText("0"); //
    lbl_all->setFont(QFont("Courier New", 10, QFont::Bold));

    QPushButton *btn0 = new QPushButton("0");
    QPushButton *btn1 = new QPushButton("1");
    QPushButton *btn2 = new QPushButton("2");
    QPushButton *btn3 = new QPushButton("3");
    QPushButton *btn4 = new QPushButton("4");
    QPushButton *btn5 = new QPushButton("5");
    QPushButton *btn6 = new QPushButton("6");
    QPushButton *btn7 = new QPushButton("7");
    QPushButton *btn8 = new QPushButton("8");
    QPushButton *btn9 = new QPushButton("9");
    QPushButton *btndot = new QPushButton(".");
    QPushButton *btninvert = new QPushButton("±");
    QPushButton *btnplus = new QPushButton("+");
    QPushButton *btnminus = new QPushButton("-");
    QPushButton *btndevide = new QPushButton("/");
    QPushButton *btnmultyple = new QPushButton("*");
    QPushButton *btnequals = new QPushButton("=");
    QPushButton *btnAC = new QPushButton("AC");
    QPushButton *btnprocent = new QPushButton("%");

    lbl->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    lbl_all->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    btn0->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    btn1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    btn2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    btn3->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    btn4->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    btn5->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    btn6->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    btn7->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    btn8->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    btn9->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    btnplus->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    btnminus->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    btndevide->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    btnmultyple->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    btnequals->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    btndot->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    btninvert->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    btnAC->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    btnprocent->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    layout->addWidget(lbl_all,0,0, 1, 4);
    layout->addWidget(lbl,1,0, 1, 4);

    layout->addWidget(btnAC,2,0);
    layout->addWidget(btninvert,2,1);
    layout->addWidget(btnprocent,2,2);
    layout->addWidget(btndevide,2,3);

    layout->addWidget(btn7,3,0);
    layout->addWidget(btn8,3,1);
    layout->addWidget(btn9,3,2);
    layout->addWidget(btnmultyple,3,3);

    layout->addWidget(btn4,4,0);
    layout->addWidget(btn5,4,1);
    layout->addWidget(btn6,4,2);
    layout->addWidget(btnminus,4,3);

    layout->addWidget(btn1,5,0);
    layout->addWidget(btn2,5,1);
    layout->addWidget(btn3,5,2);
    layout->addWidget(btnplus,5,3);

    layout->addWidget(btn0,6,0,1,2);
    layout->addWidget(btndot,6,2);
    layout->addWidget(btnequals,6,3);

    connect(btn0, &QPushButton::clicked, this, &MainWindow::btn_num_clk);
    connect(btn1, &QPushButton::clicked, this, &MainWindow::btn_num_clk);
    connect(btn2, &QPushButton::clicked, this, &MainWindow::btn_num_clk);
    connect(btn3, &QPushButton::clicked, this, &MainWindow::btn_num_clk);
    connect(btn4, &QPushButton::clicked, this, &MainWindow::btn_num_clk);
    connect(btn5, &QPushButton::clicked, this, &MainWindow::btn_num_clk);
    connect(btn6, &QPushButton::clicked, this, &MainWindow::btn_num_clk);
    connect(btn7, &QPushButton::clicked, this, &MainWindow::btn_num_clk);
    connect(btn8, &QPushButton::clicked, this, &MainWindow::btn_num_clk);
    connect(btn9, &QPushButton::clicked, this, &MainWindow::btn_num_clk);
    connect(btnplus, &QPushButton::clicked, this, &MainWindow::btn_operation);
    connect(btnminus, &QPushButton::clicked, this, &MainWindow::btn_operation);
    connect(btndevide, &QPushButton::clicked, this, &MainWindow::btn_operation);
    connect(btnmultyple, &QPushButton::clicked, this, &MainWindow::btn_operation);
    connect(btnAC, &QPushButton::clicked, this, &MainWindow::btn_AC);
    connect(btninvert, &QPushButton::clicked, this, &MainWindow::btn_invert);
    connect(btnequals, &QPushButton::clicked, this, &MainWindow::btn_equals);
    connect(btnprocent, &QPushButton::clicked, this, &MainWindow::btn_procent);
}

void MainWindow::TextStartZero(QString num)
{
    if (lbl->text() == "0"){
        lbl->clear();
    }
    lbl->setText(lbl->text().append(num));
}

void MainWindow::btn_num_clk()
{
    QPushButton *but = qobject_cast<QPushButton * >( sender() );
    TextStartZero(but ->text());
}

void MainWindow::btn_operation()
{
    QPushButton *but = qobject_cast<QPushButton * >( sender() );

    if ((lbl_all->text().endsWith("+") || lbl_all->text().endsWith("-") || lbl_all->text().endsWith("/") || lbl_all->text().endsWith("*")) && lbl->text() == "0"){
        lbl_all->setText(lbl_all->text().removeLast());
        lbl_all->setText(lbl_all->text().append(but ->text()));
        return;
    }

    if (lbl_all->text() == "0"){
        lbl_all->clear();
    }

    if (lbl_all->text().endsWith("=")){
        lbl_all->clear();
        equal_num = 0;
    }

    if (lbl_all->text().endsWith("+")){
        equal_num += lbl->text().toFloat();
    }
    if (lbl_all->text().endsWith("-")){
        equal_num -= lbl->text().toFloat();
    }
    if (lbl_all->text().endsWith("*")){
        equal_num *= lbl->text().toFloat();
    }
    if (lbl_all->text().endsWith("/")){
        equal_num /= lbl->text().toFloat();
    }

    if (lbl->text().startsWith("-")){
        lbl_all->setText(lbl_all->text().append("(" + lbl->text() + ")" + but ->text()));
    }else
        lbl_all->setText(lbl_all->text().append(lbl->text() + but ->text()));

    if (equal_num == 0){
        equal_num += lbl->text().toFloat();
        lbl->setText("0");
        return;
    }

    lbl->setText("0");
}

void MainWindow::btn_AC()
{
    if (lbl->text() == "0"){
        lbl_all->setText("0");
    }else{
        lbl->setText("0");
        return;
    }

    equal_num = 0;
}

void MainWindow::btn_invert()
{
    if (lbl->text().startsWith("-")){
        lbl->setText(lbl->text().removeFirst());
    }else if (lbl->text() != "0"){
        lbl->setText("-" + lbl->text());
    }
}

void MainWindow::btn_equals()
{  
    if (lbl_all->text().endsWith("+")){
        equal_num += lbl->text().toFloat();
        lbl_all->setText(lbl_all->text() + lbl->text() + "=");
    }
    if (lbl_all->text().endsWith("-")){
        equal_num -= lbl->text().toFloat();
        lbl_all->setText(lbl_all->text() + lbl->text() + "=");
    }
    if (lbl_all->text().endsWith("*")){
        equal_num *= lbl->text().toFloat();
        lbl_all->setText(lbl_all->text() + lbl->text() + "=");
    }
    if (lbl_all->text().endsWith("/")){
        equal_num /= lbl->text().toFloat();
        lbl_all->setText(lbl_all->text() + lbl->text() + "=");
    }
    lbl->setText(QString::number(equal_num));
}

void MainWindow::btn_procent() {
    lbl->setText(QString::number(equal_num*lbl->text().toFloat()/100));
}
