#ifndef SERVERCONNECTION_H
#define SERVERCONNECTION_H
#include <QTcpSocket>
#include <QByteArray>

class Data;

class ServerConnection: public QObject
{
    Q_OBJECT
public:

    ~ServerConnection();
    static ServerConnection *getInstance();
    void send(QByteArray data);
    QString getMessage();
    void setIPAdress(QString adress);
    QString getIPAdress();
    void connectToServer();
    bool isConnected();


private:
    explicit ServerConnection();
    static ServerConnection* instance ;
    QTcpSocket* socket;
    QString adress;
    QString message;
    bool connected;

public slots:
    void recieve();

signals:
    void connectedToServer();

};


#endif // SERVERCONNECTION_H
