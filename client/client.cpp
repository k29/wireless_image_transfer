#include "client.h"
#include "ui_client.h"

client::client(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::client)
{
    ui->setupUi(this);
    socket=new QTcpSocket(this);
    connect(socket,SIGNAL(connected()),this,SLOT(connected()));
    connect(socket,SIGNAL(disconnected()),this,SLOT(disconnected()));
    connect(socket,SIGNAL(bytesWritten(qint64)),this, SLOT(bytesWritten(qint64)));
    connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()));

    qDebug()<<"Connecting...";


}

void client::connect_server()
{
    socket->connectToHost(ui->lineEdit->text(),9876);
    qDebug()<<"connected to host @"<<socket->peerAddress()<<" "<< socket->peerPort();
    if(!socket->waitForConnected(1000))
    {
        qDebug()<<"Error: "<<socket->errorString();
    }
}



void client::disconnect_server()
{
    socket->disconnectFromHost();
    qDebug()<<socket->state();

}



void client::connected()
{
    qDebug()<<"connected!!";
}

void client::disconnected()
{
    qDebug()<<"disconnected!!";
}


void client::getImage()
{
    QTimer *timer=new QTimer(this);
    qDebug()<<"callign timer";
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));
    timer->start(100);
    qDebug()<<"called timer";

}

void client::update()
{
    dataSize=0;
    qDebug()<<"in update!!";
    socket->write("i\n\0");
    socket->flush();
}

void client::goUp()
{
    socket->write("u\n\0");
    socket->flush();
}

void client::goRight()
{
    socket->write("r\n\0");
    socket->flush();
}

void client::goDown()
{
    socket->write("d\n\0");
    socket->flush();
}

void client::goLeft()
{

    socket->write("l\n\0");
    socket->flush();
}



void client::bytesWritten(qint64 bytes)
{
    qDebug()<<"No. of bytes written: "<<bytes;
}


void client::readyRead()
{


    qDebug()<<"in tcp ready, readyread signal emmitted!! and datasize is "<<dataSize;
    if(dataSize==0)
    {
        qDebug("yes datasize is zero!!");

        QDataStream stream( socket );
        stream.setVersion( QDataStream::Qt_4_0 );

        if( socket->bytesAvailable() < sizeof(quint32) )
            return;

        stream >> dataSize;
        qDebug()<<"now the data size is "<<dataSize;
    }

    if( dataSize > socket->bytesAvailable() )
        return;

    qDebug()<<"yes i am here";
    QByteArray array = socket->read(dataSize);
    QBuffer buffer(&array);
    buffer.open( QIODevice::ReadOnly );
    QImageReader reader(&buffer);
    QImage image = reader.read();

    if( !image.isNull() )
    {
        qDebug()<<"image being displayed";
        QPixmap pix=QPixmap::fromImage(image);
        ui->label->setPixmap(pix.scaledToWidth(ui->label->width()));
    }
    else
    {
        ui->label->setText( tr("<i>Invalid image received!</i>") );
    }
    ui->pushButtonGetImage->setEnabled( true );
}

client::~client()
{
    delete ui;
}



