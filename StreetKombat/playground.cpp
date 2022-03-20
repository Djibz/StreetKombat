#include "playground.h"
#include <QColor>

int Playground::getSize()
{
    return itsSize.width();
}

int Playground::getFloor()
{
    return itsFloor.height();
}

void Playground::draw(QPainter *aPainter)
{
    aPainter->drawImage(itsBackground, itsBackgroundTexture);
}

Playground::Playground(int aW, int aH, int fH, QString aBackGround)
{
    itsSize = QSize(aW, aH);
    itsBackground = QRect(0, 0, aW, aH);
    itsFloor = QRect(0, aH - fH, aW, fH);
    //itsBackgroundTexture = QImage("../Background/fond.png");
    itsBackgroundTexture = QImage(aBackGround);
}
