#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QKeyEvent>
#include <QPaintEvent>
#include <QFontDatabase>
#include "caracter.cpp"
#include <QRect>
#include <QDebug>
#include <QIcon>

using namespace std;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("Street Kombat");
    this->setMinimumSize(1600, 900);
    this->setMaximumSize(1600, 900);
    setWindowIcon(QIcon("../icon.png"));
    itsWinWindow = new QImage("../Victoire.png");
    itsBackground = new QImage("../Background/fondMenu.png");
    itsMenu = new Menu(itsBackground, 1600, 900);
    //start();
    setWindowFlags(Qt::FramelessWindowHint);
    playerIcons = vector<QImage>(2);
    itsChronomodeTimer = new QTimer;
    connect(itsChronomodeTimer, SIGNAL(timeout()), this, SLOT(timerIncrement()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::keyPressEvent(QKeyEvent * event)
{
    if(inMenu)
        {
            if(event->key() == Qt::Key_Escape)
                itsMenu->back();

            if(event->key() == Qt::Key_Up || event->key() == Qt::Key_Left)
                itsMenu->moveP1Cursor(true);
            if(event->key() == Qt::Key_Down || event->key() == Qt::Key_Right)
                itsMenu->moveP1Cursor(false);
            if(event->key() == Qt::Key_Enter && !event->isAutoRepeat())
            {
                int exitCode = itsMenu->enterP1(itsGamemode, itsGuardRate, itsMap, itsP1Char, itsP2Char);
                if(exitCode == 1)
                    close();
                if(exitCode == 2)
                {
                    inMenu = false;
                    start();
                }
            }

            if(event->key() == Qt::Key_Z || event->key() == Qt::Key_Q)
                itsMenu->moveP2Cursor(true);
            if(event->key() == Qt::Key_S || event->key() == Qt::Key_D)
                itsMenu->moveP2Cursor(false);
            if(event->key() == Qt::Key_Space)
            {
                int exitCode = itsMenu->enterP2(itsGamemode, itsGuardRate, itsMap, itsP1Char, itsP2Char);
                if(exitCode == 2)
                {
                    inMenu = false;
                    start();
                }
            }
        }
        else
        {
            if(event->key() == Qt::Key_Up and !itsFighter1->getIsCrouching())
            {
                itsFighter1->jump();
            }
            if(event->key() == Qt::Key_Left and !itsFighter1->getIsCrouching())
            {
                itsFighter1->setItsSpeed(-1);
                if(itsFighter1->getItsDirection() == RIGHT)
                {
                    itsFighter1->setIsGuarding(true);
                }
            }
            if(event->key() == Qt::Key_Right and !itsFighter1->getIsCrouching())
            {
                itsFighter1->setItsSpeed(1);
                if(itsFighter1->getItsDirection() == LEFT)
                {
                    itsFighter1->setIsGuarding(true);
                }
            }
            if(event->key() == Qt::Key_Down)
            {
                if(!event->isAutoRepeat())
                {
                    itsFighter1->crouch();
                }
            }
            if(event->key() == Qt::Key_1)
            {
                itsFighter1->attack(LIGHT);
            }
            if(event->key() == Qt::Key_2)
            {
                itsFighter1->attack(STRONG);
            }
            if(itsGamemode != TRAINING)
            {
                if(event->key() == Qt::Key_Q and !itsFighter2->getIsCrouching())
                {
                    itsFighter2->setItsSpeed(-1);
                    if(itsFighter2->getItsDirection() == RIGHT)
                    {
                        itsFighter2->setIsGuarding(true);
                    }
                }
                if(event->key() == Qt::Key_D and !itsFighter2->getIsCrouching())
                {
                    itsFighter2->setItsSpeed(1);
                    if(itsFighter2->getItsDirection() == LEFT)
                    {
                        itsFighter2->setIsGuarding(true);
                    }
                }
                if(event->key() == Qt::Key_S)
                {
                    if(!event->isAutoRepeat())
                    {
                        itsFighter2->crouch();
                    }
                }
                if(event->key() == Qt::Key_A)
                {
                    itsFighter2->attack(LIGHT);
                }
                if(event->key() == Qt::Key_E)
                {
                    itsFighter2->attack(STRONG);
                }
                if(event->key() == Qt::Key_Z and !itsFighter2->getIsCrouching())
                {
                    itsFighter2->jump();
                }
            }
            if(event->key() == Qt::Key_Escape)
                end();
        }
        if(battleEnd)
        {
            if(event->key() == Qt::Key_Space)
            {
                end();
            }
        }

        update();

}

void Widget::keyReleaseEvent(QKeyEvent * event)
{
    if(!inMenu)
    {
        if(event->key() == Qt::Key_Left or event->key() == Qt::Key_Right)
        {
            itsFighter1->setItsSpeed(0);
            itsFighter1->setIsGuarding(false);

        }
        if(event->key() == Qt::Key_Q or event->key() == Qt::Key_D)
        {
            itsFighter2->setItsSpeed(0);
            itsFighter2->setIsGuarding(false);
        }
        if(event->key() == Qt::Key_Down)
        {
            if(!event->isAutoRepeat())
            {
                itsFighter1->stand();
            }
        }
        if(event->key() == Qt::Key_S)
        {
            if(!event->isAutoRepeat())
            {
                itsFighter2->stand();
            }

        }
    }
}

void Widget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
    QPainter * painter = new QPainter(this);
    if(inMenu)
    {
        painter->drawImage(QRect(0, 0, 1600, 900), *itsBackground);
        itsMenu->draw(painter);
    }
    else
    {
        painter->drawImage(QRect(0, 0, 1600, 900), itsImagePlayground);
        itsFighter1->draw(painter);
        itsFighter2->draw(painter);
        painter->fillRect(QRect(7,7,506,56), QColor(255, 255, 255, 255));
        painter->fillRect(QRect(1087, 7, 506,56), QColor(255, 255, 255, 255));
        painter->fillRect(itsFighter1->getItsHealthBar(), QColor(255, 0, 0, 255));
        painter->fillRect(itsFighter2->getItsHealthBar(), QColor(255, 0, 0, 255));

        painter->fillRect(7, 68, 100, 100, QColor(255, 255, 255));
        painter->drawImage(QRect(10,71,94,94), playerIcons[1]);

        painter->fillRect(1493, 68, 100, 100, QColor(255, 255, 255));
        painter->drawImage(QRect(1496,71,94,94), playerIcons[0]);

        int id = QFontDatabase::addApplicationFont("../font/PixelSansSerif.ttf");
        QString family = QFontDatabase::applicationFontFamilies(id).at(0);
        //QFont monospace(family);
        QFont aFont(family);
        aFont.setPixelSize(30);
        painter->setFont(aFont);
        painter->setPen(QColor(251,242,54,255));
        painter->drawText(110, 95, "Player 2");
        painter->drawText(1282, 95, "Player 1");

        if(itsGamemode == TIMER)
        {
            aFont.setPixelSize(20);
            painter->setFont(aFont);
            painter->drawText(780, 50, QString::number(itsChronomodeTime));
        }
        if(battleEnd)
        {
            painter->drawImage(QRect(80, 45, 1440, 810), *itsWinWindow);
            aFont.setPixelSize(63);
            painter->setFont(aFont);
            QString text;
            if(itsFighter1->getItsHealth() == itsFighter2->getItsHealth())
            {
                text = "          Draw";
            }
            else if(itsFighter1->getItsHealth() < itsFighter2->getItsHealth())
            {
                text = "Winner is Player 2";
            }
            else
            {
                text = "Winner is Player 1";
            }
            painter->drawText(340,500, text);
        }
    }
    painter->~QPainter();
}

void Widget::start()
{
    delete itsMenu;
    itsMenu = nullptr;
    itsTimer = new QTimer;
    itsFatalityTimer = new QTimer;
    connect(itsTimer, SIGNAL(timeout()), this, SLOT(gameLoop()));
    Music = new QSoundEffect();

    if(itsP1Char == 0)
    {
        itsFighter1 = new Fighter(&perso1, 1, itsGuardRate);
        playerIcons[0] = QImage("../Sprites/icons/P1Icon.png");
    }
    else
    {
        itsFighter1 = new Fighter(&perso2, 1, itsGuardRate);
        playerIcons[0] = QImage("../Sprites/icons/P2Icon.png");
    }
    if(itsP2Char == 0)
    {
        secondC = perso1;
        playerIcons[1] = QImage("../Sprites/icons/P1Icon.png");
    }
    else
    {
        secondC = perso2;
        playerIcons[1] = QImage("../Sprites/icons/P2Icon.png");
    }
    playerIcons[1] = playerIcons[1].mirrored(true, false);
    if(itsP1Char == itsP2Char)
    {
        playerIcons[1] = playerIcons[1].rgbSwapped();
        for(Sprite &i: secondC.light)
        {
            i.arm = i.arm.rgbSwapped();
            i.body = i.body.rgbSwapped();
        }
        for(Sprite &i: secondC.stand)
        {
            i.arm = i.arm.rgbSwapped();
            i.body = i.body.rgbSwapped();
        }
        for(Sprite &i: secondC.move)
        {
            i.arm = i.arm.rgbSwapped();
            i.body = i.body.rgbSwapped();
        }
        for(Sprite &i: secondC.jump)
        {
            i.arm = i.arm.rgbSwapped();
            i.body = i.body.rgbSwapped();
        }
        for(Sprite &i: secondC.strong)
        {
            i.arm = i.arm.rgbSwapped();
            i.body = i.body.rgbSwapped();
        }
        for(Sprite &i: secondC.crouch)
        {
            i.arm = i.arm.rgbSwapped();
            i.body = i.body.rgbSwapped();
        }
        for(Sprite &i: secondC.CLight)
        {
            i.arm = i.arm.rgbSwapped();
            i.body = i.body.rgbSwapped();
        }
        for(Sprite &i: secondC.CStrong)
        {
            i.arm = i.arm.rgbSwapped();
            i.body = i.body.rgbSwapped();
        }
        for(Sprite &i: secondC.AStrong)
        {
            i.arm = i.arm.rgbSwapped();
            i.body = i.body.rgbSwapped();
        }
    }

    itsFighter2 = new Fighter(&secondC, 0, itsGuardRate);
    itsFighter1->setItsOpponent(itsFighter2);
    itsFighter2->setItsOpponent(itsFighter1);
    itsFighter2->changeDir();
    itsFighter1->separate();
    QString aMap;
    if(itsMap == 0)
    {
        aMap = "../Background/fond.png";
        Music->setSource(QUrl::fromLocalFile("../sounds/Retro Synthwave Loop - Creative Commons.wav"));
    }
    if(itsMap == 2)
    {
        aMap = "../Background/fondDojoCorrupt.png";
        Music->setSource(QUrl::fromLocalFile("../sounds/corrupt.wav"));
    }
    if(itsMap == 1 || itsGamemode == TRAINING)
    {
        aMap = "../Background/fondDojo.png";
        Music->setSource(QUrl::fromLocalFile("../sounds/musique_de_fond.wav"));
    }
    if(itsMap == 3)
    {
        aMap = "../Background/fond2.png";
        Music->setSource(QUrl::fromLocalFile("../sounds/Retro Synthwave Loop - Creative Commons.wav"));
    }
    itsImagePlayground = QImage(aMap);
     // la placer  au même endroit que l'image de fond
    Music->setVolume(10);
    Music->setLoopCount(QSoundEffect::Infinite);
    Music->play();
    if(itsGamemode == TIMER)
    {
        itsChronomodeTime = 0.0;
        itsChronomodeTimer->start(100);
    }
    itsTimer->start(6);
}

void Widget::end()
{
    delete itsTimer;
    delete itsFatalityTimer;
    delete itsFighter1;
    delete itsFighter2;
    Music->stop();
    battleEnd = false;
    inMenu = true;
    itsMenu = new Menu(itsBackground, 1600, 900);
    fatalityTime = 2;
}

void Widget::fatality()
{
    fatalityTime--;
}

void Widget::timerIncrement()
{
    itsChronomodeTime += 0.1;
    qDebug() << itsChronomodeTime << Qt::endl;
    if(itsChronomodeTime >= 90)
    {
        itsChronomodeTime = 0;
        itsTimer->stop();
        battleEnd = true;
        update();
    }
}


void Widget::gameLoop()
{
    if((itsFighter1->getItsHealth() <= 0 or itsFighter2->getItsHealth() <= 0))
    {
        if(itsGamemode != TRAINING)
        {
            if(!itsFatalityTimer->isActive())
            {
                itsFatalityTimer->start(200);
                connect(itsFatalityTimer, SIGNAL(timeout()), this, SLOT(fatality()));
            }
            if(fatalityTime == 0 or !itsFatalityTimer->isActive())
            {
                itsTimer->stop();
                battleEnd = true;
            }
        }
    }
    if((itsFighter1->getItsBody()->center().x() < itsFighter2->getItsBody()->center().x() and itsFighter1->getItsDirection() == LEFT) or (itsFighter1->getItsBody()->center().x() > itsFighter2->getItsBody()->center().x() and itsFighter1->getItsDirection() == RIGHT))
    {
        itsFighter1->changeDir();
        itsFighter2->changeDir();
    }
    /*if(itsFighter1->getHitBox()->intersects(*itsFighter2->getHitBox()))
    {
        itsFighter1->setItsSpeed(0);
        itsFighter2->setItsSpeed(0);
    }*/
    itsFighter1->move();
    //itsFighter1->loop();
    itsFighter2->move();
    update();
}
