#include <QApplication>
#include "serverconnection.h"
#include <QDebug>
#include <QString>
#include "factory.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


   Factory f;
   f.build();
   f.start();


    // * TEST V 0.0
    /*
    ServerConnection::getInstance()->setIPAdress("153.109.7.56");
    ServerConnection::getInstance()->connectToServer();
    ServerConnection::getInstance()->send(QByteArray("hello"));
    */



    //QByteArray recievedData = ServerConnection::getInstance()->send(data);

    //qDebug() << recievedData.toStdString();

   return a.exec();

}
