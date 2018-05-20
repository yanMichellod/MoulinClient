#ifndef SETUPVIEW_H
#define SETUPVIEW_H
#include "View/view.h"
#include <qlineedit.h>
#include <qlabel.h>

class Data;

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

    Data* data;

private slots:
    void onCommandEntered();

signals:
    void ipEntered();

    // View interface
protected:
    void changed();
    void initRelation(Data *d);
};

#endif // SETUPVIEW_H
