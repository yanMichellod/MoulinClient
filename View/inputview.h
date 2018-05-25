#ifndef INPUTVIEW_H
#define INPUTVIEW_H
#include "View/view.h"
#include <QLabel>
#include <QLineEdit>
#include <QString>


class InputView : public View
{
    Q_OBJECT
public:
    InputView(int x, int y, int width, int heigth, QString title);
    ~InputView();

private:
    void setupUI();

    QLabel* info;
    QLineEdit* le;
    QLabel* example;

    QString data;

    // View interface
public:
    QString getData();

protected:
    void changed();

private slots:
    void onCommandEntered();

signals:
    void commandEntered();
};

#endif // INPUTVIEW_H
