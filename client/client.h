#ifndef CLIENT_H
#define CLIENT_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDebug>
#include <QAbstractSocket>
#include <QByteArray>
#include <QImage>
#include <QBuffer>
#include <QImageReader>
#include <QMessageBox>
#include <QHostAddress>
#include <QDataStream>


namespace Ui {
class client;
}

class client : public QMainWindow
{
    Q_OBJECT

public:
    explicit client(QWidget *parent = 0);
    ~client();

private:
    Ui::client *ui;
    QTcpSocket *socket;
    int dataSize;
    char buffer[1024];


public slots:
    void connect_server();
    void disconnect_server();
    void connected();
    void disconnected();
    void bytesWritten(qint64 bytes);
    void readyRead();
    void getImage();
    void goUp();
    void goRight();
    void goDown();
    void goLeft();

};

#endif // CLIENT_H
