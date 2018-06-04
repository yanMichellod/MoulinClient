#ifndef DATA_H
#define DATA_H
#include <QString>
#include <QObject>

#define MaxView 4
#define MaxPosition 24

class ServerConnector;
class View;

class Data: public QObject
{
    Q_OBJECT
public:
    Data();
    ~Data();
    void subscribe(View* view);
    void setVisible(QString view , bool visible);
    void enableWindow(QString view , bool enable);
    View* getView(QString title);
    void setPlayer(int number);
    int getPlayer();
    void setMoulin(bool val);
    bool isMoulin();
    void setTocken(int position , int state);
    int *getTocken();

private:
    View** allView;
    int viewCnt;
    int player;
    int* tocken;
    bool moulin;

public slots:
    void ipSet();
    void commandEntered();
    void gameUpdated();

signals:
    void ipEntered();
    void commandToControl();
    void updatePiece();
};

#endif // DATA_H
