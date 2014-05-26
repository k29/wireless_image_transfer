#include "server.h"

server::server(QWidget *parent) :
    QMainWindow(parent)
{
    myserver=new QTcpServer(this);
    connect(myserver,SIGNAL(newConnection()),this,SLOT(newConnection()));
    
    if(!myserver->listen(QHostAddress::Any,9876))
    {
        qDebug()<<"server could not start";
    }
    else
        qDebug()<<"server started";



}



void server::newConnection()
{
    socket=myserver->nextPendingConnection();
    qDebug()<<"connected with "<<socket->peerAddress()<<" "<<socket->peerPort();
    if(socket->state()==QTcpSocket::ConnectedState)
    {
        qDebug()<<"connection established";
    }

    connect(socket, SIGNAL(disconnected()),this, SLOT(disconnected()));
    connect(socket, SIGNAL(readyRead()),this, SLOT(readyRead()));

    //qDebug()<<socket->readAll();
    //last_char=input_string.right(1);
    //qDebug()<<"last char " <<last_char;
}


void server::readyRead()
{
    qDebug()<<"in ready read";
    while(socket->canReadLine())
    {
        qDebug()<<"in while loop";
        QByteArray ba=socket->readLine();
        if (strcmp(ba.constData(),"exit\n")==0)
        {
            socket->disconnectFromHost();
            break;
        }
        qDebug()<<">>"<<ba.constData();
        if(strcmp(ba.constData(),"i\n\0")==0)
        {
            sendImage();
        }
        else if(strcmp(ba.constData(),"u\n\0")==0)
        {
            goUp();
        }
        else if(strcmp(ba.constData(),"d\n\0")==0)
        {
            goDown();
        }
        else if(strcmp(ba.constData(),"r\n\0")==0)
        {
            goRight();
        }
        else if(strcmp(ba.constData(),"l\n\0")==0)
        {
            goLeft();
        }
    }

}

void server::disconnected()
{
    qDebug()<<"connection disconnected";

    disconnect(socket, SIGNAL(disconnected()));
    disconnect(socket, SIGNAL(readyRead()));
    socket->deleteLater();

}


QImage server::get_image_from_file()
{

    qDebug()<<"getting qimage";
    return QImage("images/test.png");
}

void server::sendImage()
{
    qDebug()<<"sending image";
    QBuffer buffer;
    QImageWriter writer(&buffer, "PNG");
    writer.write( get_image_from_file() );
    qDebug()<<"after getting image";

    QByteArray data;
    QDataStream stream( &data, QIODevice::WriteOnly );
    stream.setVersion( QDataStream::Qt_4_0 );
    stream << (quint32)buffer.data().size();
    data.append( buffer.data() );
    socket->write( data );
    qDebug()<<"data written";

}


void server::goUp()
{
    qDebug()<<"Up";

}

void server::goDown()
{
    qDebug()<<"Down";

}

void server::goRight()
{
    qDebug()<<"Right";

}

void server::goLeft()
{
    qDebug()<<"Left ";

}


