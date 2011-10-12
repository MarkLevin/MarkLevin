#ifndef UI_H
#define UI_H

#endif // UI_H

#include <QtGui>
#include <QPushButton>
#include <QLineEdit>
#include <QCheckBox>
#include <QLabel>

FindDialog::FindDialog(QWidget *parent)
        : QDialog(parent)
{
        label=new QLabel(tr("Find &what:"));
        lineEdit=new QLineEdit;
        label->setBuddy(lineEdit);

        caseCheckBox=new QCheckBox(tr("Match &case"));
        backwardCheckBox=new QCheckBox(tr("Search &Backwards"));

        findButton=new QPushButton(tr("&Find"));
        findButton=setDefault(true);
        findButton=setEnabled(false);

        closeButton=new QPushButton(tr("&Quit"));
}
