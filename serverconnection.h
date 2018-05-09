#ifndef SERVERCONNECTION_H
#define SERVERCONNECTION_H
#include <qtcpsocket.h>
#include <qbytearray.h>

class ServerConnection
{
public:

    ~ServerConnection();
    static ServerConnection *getInstance();
    QByteArray send(QByteArray* data);

private:
    ServerConnection();
    static ServerConnection* instance ;
    QTcpSocket* socket;

};

ServerConnection* ServerConnection::instance = nullptr;

#endif // SERVERCONNECTION_H
