#include "main.h"
#include "ui_main.h"
#include <QLabel>

main::main(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::main)
{
    ui->setupUi(this);
}

main::~main()
{
    delete ui;
}

void main::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
