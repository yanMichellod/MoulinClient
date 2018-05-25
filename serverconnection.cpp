#include "serverconnection.h"
#include "data.h"
#include <qdebug.h>
#include <QHostAddress>

ServerConnection* ServerConnection::instance = nullptr;

ServerConnection::ServerConnection()
{
    socket = new QTcpSocket(nullptr);
    connected = false;
    connect(socket,SIGNAL(readyRead()),this,SLOT(recieve()));
}

ServerConnection::~ServerConnection()
{
    delete socket;
}

ServerConnection *ServerConnection::getInstance()
{
    if(instance == nullptr){
        instance = new ServerConnection();
    }

    return instance;
}

void ServerConnection::send(QByteArray data)
{
    socket->write(data,data.length());
    socket->flush();
}

QString ServerConnection::getMessage()
{
    return message;
}

void ServerConnection::recieve()
{
    // recieve data and transfomr to QString
    QByteArray recievedData = socket->readAll();
    QString data = recievedData.data();
    qDebug() << data;
    message = data;

    //test different message
    if(data.contains("player")){
        emit positionOfGamer();
    }
    else if(data.contains("begin")){
        emit gamebegin();
    }
}

void ServerConnection::setIPAdress(QString adress)
{
    this->adress = adress;
}

QString ServerConnection::getIPAdress()
{
    return adress;
}

void ServerConnection::connectToServer()
{
    qDebug() << "connection" ;
    socket->connectToHost(QHostAddress(adress),3333);
    if( socket->waitForConnected(3000)){
        qDebug() << "connected";
        connected = true;
    }   

    emit connectedToServer();
}

bool ServerConnection::isConnected()
{
    return connected;
}


