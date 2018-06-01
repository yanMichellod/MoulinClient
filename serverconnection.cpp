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

QByteArray ServerConnection::getMessage()
{
    return message;
}

void ServerConnection::recieve()
{
    // recieve data
    message = socket->readAll();
    qDebug() << message;
    qDebug() << message.length();
    //test different message
    if(message.contains("player")){
        emit positionOfGamer();
    }
    else if(message.contains("begin")){
        emit gamebegin();
    }
    else if(message.contains("turn")){
        emit changingPlayer();
    }
    else if(message.contains("moulin")){
        emit moulin();
    }
    else if(message.contains("replay")){
        emit replay();
    }
    else if(message.length() == 24){
        emit gameUpdated();
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


