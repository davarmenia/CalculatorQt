#include "buttonsboard.h"

#include <QPushButton>
#include <QVBoxLayout>

buttonsboard::buttonsboard()
{
    vbox = new QVBoxLayout(this);
    vbox->setSpacing(1);

    QPushButton *settings = new QPushButton("Settings", this);
    QPushButton *accounts = new QPushButton("Accounts", this);
    QPushButton *loans = new QPushButton("Loans", this);
    QPushButton *cash = new QPushButton("Cash", this);
    QPushButton *debts = new QPushButton("Debts", this);

    accounts->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    loans->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    cash->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    settings->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    debts->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    vbox->addWidget(settings);
    vbox->addWidget(accounts);
    vbox->addWidget(loans);
    vbox->addWidget(cash);
    vbox->addWidget(debts);

    setLayout(vbox);
}

buttonsboard::~buttonsboard()
{

}
