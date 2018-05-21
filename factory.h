#ifndef FACTORY_H
#define FACTORY_H
#include <QObject>

class SetupView;
class WaitingView;
class Data;
class Controller;

class Factory:public QObject
{
    Q_OBJECT
public:
    Factory();
    ~Factory();
    void build();
    void start();

private:
    SetupView* sv;
    WaitingView* wv;
    Data* dt;
    Controller* c;
};

#endif // FACTORY_H
