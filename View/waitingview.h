#ifndef WAITINGVIEW_H
#define WAITINGVIEW_H
#include "View/view.h"
#include <QLabel>
#include <QString>


class WaitingView : public View
{
public:
    WaitingView(int x, int y, int width, int heigth, QString title);
    ~WaitingView();

private:
    void setupUI();
    QLabel* info;

    // View interface
public:
    QString getData();

protected:
    void changed();
};

#endif // WAITINGVIEW_H
