#include <QCoreApplication>
#include "serverconnection.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString* test = new QString("Hello");
    QByteArray* data = new QByteArray(test->toLatin1());
    QByteArray recievedData = ServerConnection::getInstance()->send(data);

   // qDebug() << recievedData.toStdString();
    return a.exec();
}
