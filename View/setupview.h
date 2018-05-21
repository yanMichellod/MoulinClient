#ifndef SETUPVIEW_H
#define SETUPVIEW_H
#include "View/view.h"
#include <qlineedit.h>
#include <qlabel.h>
#include <QString>

class SetupView : public View
{
    Q_OBJECT
public:
    SetupView(int x, int y, int width, int heigth, QString title);
    ~SetupView();

private:
    // private surcharged function
    void setupUI();

    QLineEdit* le;
    QLabel* ip;
    QLabel* port;

    QString data;

private slots:
    void onCommandEntered();

signals:
    void ipEntered();

    // View interface
public:
    QString getData();

protected:
    void changed();
};

#endif // SETUPVIEW_H
