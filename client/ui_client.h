/********************************************************************************
** Form generated from reading UI file 'client.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_H
#define UI_CLIENT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_client
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QPushButton *pushButtonUp;
    QPushButton *pushButtonLeft;
    QPushButton *pushButtonRight;
    QPushButton *pushButtonDown;
    QPushButton *pushButtonGetImage_3;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonGetImage;
    QPushButton *pushButtonGetImage_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QButtonGroup *buttonGroup;

    void setupUi(QMainWindow *client)
    {
        if (client->objectName().isEmpty())
            client->setObjectName(QString::fromUtf8("client"));
        client->resize(641, 488);
        centralWidget = new QWidget(client);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(210, 10, 401, 391));
        pushButtonUp = new QPushButton(centralWidget);
        buttonGroup = new QButtonGroup(client);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(pushButtonUp);
        pushButtonUp->setObjectName(QString::fromUtf8("pushButtonUp"));
        pushButtonUp->setGeometry(QRect(100, 200, 31, 31));
        pushButtonLeft = new QPushButton(centralWidget);
        buttonGroup->addButton(pushButtonLeft);
        pushButtonLeft->setObjectName(QString::fromUtf8("pushButtonLeft"));
        pushButtonLeft->setGeometry(QRect(60, 240, 31, 31));
        pushButtonRight = new QPushButton(centralWidget);
        buttonGroup->addButton(pushButtonRight);
        pushButtonRight->setObjectName(QString::fromUtf8("pushButtonRight"));
        pushButtonRight->setGeometry(QRect(140, 240, 31, 31));
        pushButtonDown = new QPushButton(centralWidget);
        buttonGroup->addButton(pushButtonDown);
        pushButtonDown->setObjectName(QString::fromUtf8("pushButtonDown"));
        pushButtonDown->setGeometry(QRect(100, 240, 31, 31));
        pushButtonGetImage_3 = new QPushButton(centralWidget);
        pushButtonGetImage_3->setObjectName(QString::fromUtf8("pushButtonGetImage_3"));
        pushButtonGetImage_3->setGeometry(QRect(80, 140, 85, 31));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 187, 74));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButtonGetImage = new QPushButton(layoutWidget);
        pushButtonGetImage->setObjectName(QString::fromUtf8("pushButtonGetImage"));

        horizontalLayout->addWidget(pushButtonGetImage);

        pushButtonGetImage_2 = new QPushButton(layoutWidget);
        pushButtonGetImage_2->setObjectName(QString::fromUtf8("pushButtonGetImage_2"));

        horizontalLayout->addWidget(pushButtonGetImage_2);


        verticalLayout->addLayout(horizontalLayout);

        client->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(client);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 641, 27));
        client->setMenuBar(menuBar);
        mainToolBar = new QToolBar(client);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        client->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(client);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        client->setStatusBar(statusBar);

        retranslateUi(client);
        QObject::connect(pushButtonGetImage, SIGNAL(clicked()), client, SLOT(connect_server()));
        QObject::connect(pushButtonUp, SIGNAL(clicked()), client, SLOT(goUp()));
        QObject::connect(pushButtonRight, SIGNAL(clicked()), client, SLOT(goRight()));
        QObject::connect(pushButtonDown, SIGNAL(clicked()), client, SLOT(goDown()));
        QObject::connect(pushButtonLeft, SIGNAL(clicked()), client, SLOT(goLeft()));
        QObject::connect(pushButtonGetImage_3, SIGNAL(clicked()), client, SLOT(getImage()));
        QObject::connect(pushButtonGetImage_2, SIGNAL(clicked()), client, SLOT(disconnect_server()));

        QMetaObject::connectSlotsByName(client);
    } // setupUi

    void retranslateUi(QMainWindow *client)
    {
        client->setWindowTitle(QApplication::translate("client", "client", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("client", "TextLabel", 0, QApplication::UnicodeUTF8));
        pushButtonUp->setText(QApplication::translate("client", "U", 0, QApplication::UnicodeUTF8));
        pushButtonLeft->setText(QApplication::translate("client", "L", 0, QApplication::UnicodeUTF8));
        pushButtonRight->setText(QApplication::translate("client", "R", 0, QApplication::UnicodeUTF8));
        pushButtonDown->setText(QApplication::translate("client", "D", 0, QApplication::UnicodeUTF8));
        pushButtonGetImage_3->setText(QApplication::translate("client", "GetImage", 0, QApplication::UnicodeUTF8));
        pushButtonGetImage->setText(QApplication::translate("client", "Connect", 0, QApplication::UnicodeUTF8));
        pushButtonGetImage_2->setText(QApplication::translate("client", "Disconnect", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class client: public Ui_client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
