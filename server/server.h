#ifndef SERVER_H
#define SERVER_H

#include <QMainWindow>
#include <QDebug>
#include <QTcpServer>
#include <QThread>
#include <QDir>
#include <QImage>
#include <QTcpSocket>
#include <QBuffer>
#include <QImageWriter>
#include <QString>
#include <QByteArray>




class server : public QMainWindow
{
    Q_OBJECT

public:
    explicit server(QWidget *parent = 0);
    void sendImage();
    void goUp();
    void goDown();
    void goRight();
    void goLeft();

private:

    QTcpServer *myserver;
    QTcpSocket *socket;
    QString input_string;
    QString last_char;
    QImage get_image_from_file();
    
    
public slots:
    void newConnection();
    void readyRead();
    void disconnected();

    
};

#endif // SERVER_H
