#ifndef MAIN_H
#define MAIN_H

#include <QMainWindow>

namespace Ui {
    class main;
}

class main : public QMainWindow {
    Q_OBJECT
public:
    main(QWidget *parent = 0);
    ~main();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::main *ui;
};

#endif // MAIN_H
