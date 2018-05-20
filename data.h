#ifndef DATA_H
#define DATA_H
#include <QString>
#include <QObject>

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
    View* getView(QString view);

private:
    View** allView;
    int viewCnt;

public slots:
    void ipSet();

signals:
    void ipEntered();
};

#endif // DATA_H
