#include "serverconnection.h"

const QString* adress = new QString("153.109.7.53");

ServerConnection::ServerConnection()
{
    socket = new QTcpSocket(nullptr);
    socket->connectToHost("153.109.7.53",3333);
}

ServerConnection::~ServerConnection()
{
    delete instance;
    delete socket;
}

ServerConnection *ServerConnection::getInstance()
{
    if(instance == nullptr){
        instance = new ServerConnection();
    }

    return instance;
}

QByteArray ServerConnection::send(QByteArray *data)
{
    socket->write(*data,data->length());
    socket->flush();
    socket->waitForReadyRead(3000);
    QByteArray recievedData = socket->readAll();
}

