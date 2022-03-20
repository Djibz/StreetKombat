#include "menu.h"
#include <QRect>
#include <QFontDatabase>

Menu::Menu(QImage *anImage, int width, int height)
    :itsWidth(width), itsHeight(height)
{
    itsBackground = anImage;
    itsCursorImage = new QImage("../flecheMenu.png");
    itsMenuImage = new QImage("../Victoire.png");
    itsGuardRate = 50;
    itsSelectSound = new QSoundEffect;
    itsSelectSound->setSource(QUrl::fromLocalFile("../sounds/menuSelect.wav"));
    itsSelectSound->setVolume(5);
    itsValidSound = new QSoundEffect;
    itsValidSound->setSource(QUrl::fromLocalFile("../sounds/menuValid.wav"));
    itsValidSound->setVolume(5);
    itsMiniMaps = vector<QImage>(4);
    itsMiniMaps[0] = QImage("../Background/miniMap0.png");
    itsMiniMaps[1] = QImage("../Background/miniMap1.png");
    itsMiniMaps[2] = QImage("../Background/miniMap2.png");
    itsMiniMaps[3] = QImage("../Background/miniMap3.png");
    itsMiniIcons = vector<QImage>(4);
    itsMiniIcons[0] = QImage("../Sprites/icons/P1Icon.png");
    itsMiniIcons[1] = QImage("../Sprites/icons/P2Icon.png");
    itsMiniIcons[2] = QImage("../Sprites/icons/P3Icon.png");
    itsMiniIcons[3] = QImage("../Sprites/icons/P3Icon.png");
}

void Menu::draw(QPainter *aPainter)
{
    aPainter->drawImage(QRect(0, 0, itsWidth, itsHeight), *itsBackground);
    int id = QFontDatabase::addApplicationFont("../font/PixelSansSerif.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    //QFont monospace(family);
    QFont aFont(family);
    aFont.setPixelSize(35);
    aPainter->setFont(aFont);
    aPainter->setPen(QColor(251,242,54,255));
    QString text;
    if(itsCurrentWindow == MAIN)
    {
        text = "Play";
        aPainter->drawText(685,713, text);
        text = "Settings";
        aPainter->drawText(685,763, text);
        text = "Exit";
        aPainter->drawText(685, 813, text);
        aPainter->drawImage(QRect(650, 713 - 32 + itsP1Cursor*50, 16, 32), *itsCursorImage);
    }
    if(itsCurrentWindow == MAPS)
    {
        aPainter->drawImage(QRect(0, 0, 1600, 900), *itsMenuImage);
        aPainter->fillRect(QRect(300, 190, 1000, 150), QColor(34, 32, 52));
        aFont.setPixelSize(35);
        aPainter->setFont(aFont);
        aPainter->drawText(560, 190, "Choose your map");

        for(int i=0; i<4; ++i)
        {
            unsigned int pixel = 7;
            QColor aColor;
            if(itsP1Cursor == i)
            {
                if(isP1Ready)
                    aColor = QColor(200, 150, 150);
                else
                    aColor = QColor(255, 100, 50);
                aPainter->fillRect(QRect(450 - pixel + 183*i, 380 - pixel, 150 + pixel*2, 150+pixel*2), aColor);
            }
            aPainter->fillRect(QRect(450 + 183*i, 380, 150, 150), QColor(255, 255, 0));
            aPainter->drawImage(QRect(450 + 183*i, 380, 150, 150), itsMiniMaps[i]);
        }
    }
    if(itsCurrentWindow == CHARACTERS)
    {
        aPainter->drawImage(QRect(0, 0, 1600, 900), *itsMenuImage);
        aPainter->fillRect(QRect(300, 190, 1000, 150), QColor(34, 32, 52));
        aFont.setPixelSize(35);
        aPainter->setFont(aFont);
        aPainter->drawText(460, 190, "Choose your character");

        for(int i=0; i<4; ++i)
        {
            unsigned int pixel = 7;
            QColor aColor;
            if(itsP1Cursor == i)
            {
                if(isP1Ready)
                    aColor = QColor(200, 150, 150);
                else
                    aColor = QColor(255, 100, 50);
                aPainter->fillRect(QRect(450 - pixel + 183*i, 380 - pixel, 150 + pixel*2, 150+pixel*2), aColor);
            }
            if(itsP2Cursor == i && itsGameMode != TRAINING)
            {
                if(isP2Ready)
                    aColor = QColor(150, 150, 200);
                else
                    aColor = QColor(100, 100, 255);
                aPainter->fillRect(QRect(450 - pixel + 183*i, 380 - pixel, 150 + pixel*2, 150+pixel*2), aColor);
            }
            if(itsP1Cursor == itsP2Cursor && itsP1Cursor == i && itsGameMode != TRAINING)
            {
                if(isP1Ready && isP2Ready)
                    aColor = QColor(200, 150, 200);
                else
                    aColor = QColor(255, 100, 255);
                aPainter->fillRect(QRect(450 - pixel + 183*i, 380 - pixel, 150 + pixel*2, 150+pixel*2), QColor(255, 50, 255));
            }

            aPainter->fillRect(QRect(450 + 183*i, 380, 150, 150), QColor(255, 255, 0));
            aPainter->drawImage(QRect(450 + 183*i, 380, 150, 150), itsMiniIcons[i]);
        }
    }
    if(itsCurrentWindow == SETTINGS)
    {
        aFont.setPixelSize(35);
        aPainter->setFont(aFont);
        aPainter->setPen(QColor(251,242,54,255));
        QString text;
        QString mode = itsGameMode==DEATHMATCH?"DTH":itsGameMode==TIMER?"TMR":"TRN";
        text = "Mode : " + mode;
        aPainter->drawText(685,713, text);
        text = "Guard : " + QString::number(itsGuardRate);
        aPainter->drawText(685,763, text);
        text = "Back";
        aPainter->drawText(685, 813, text);
        aPainter->drawImage(QRect(650, 713 - 32 + itsP1Cursor*50, 16, 32), *itsCursorImage);
    }
}


void Menu::moveP1Cursor(bool up)
{
    if(itsCurrentWindow == MAIN || itsCurrentWindow == SETTINGS)
    {
        itsSelectSound->play();
        if(up)
        {
            if(itsP1Cursor == 0)
                itsP1Cursor = 2;
            else
                itsP1Cursor--;
        }
        else
            if(itsP1Cursor == 2)
                itsP1Cursor = 0;
            else
                itsP1Cursor++;
    }
    if(itsCurrentWindow == CHARACTERS && !isP1Ready)
    {
        if(up)
        {
            if(itsP1Cursor == 0)
                itsP1Cursor = 1;
            else
                itsP1Cursor--;
        }
        else
            if(itsP1Cursor == 1)
                itsP1Cursor = 0;
            else
                itsP1Cursor++;
    }
    if(itsCurrentWindow == MAPS)
    {
        if(up)
        {
            if(itsP1Cursor == 0)
                itsP1Cursor = 3;
            else
                itsP1Cursor--;
        }
        else
            if(itsP1Cursor == 3)
                itsP1Cursor = 0;
            else
                itsP1Cursor++;
    }
}

int Menu::enterP1(Gamemode & aGamemode, int & aGuardRate, int & aMap, int & charP1, int & charP2)
{
    if(itsCurrentWindow == MAIN)
    {
        itsValidSound->play();
        if(itsP1Cursor == 0)
        {
            if(itsGameMode == TRAINING)
            {
                itsCurrentWindow = CHARACTERS;
                itsP2Cursor = 0;
            }
            else
            {
                itsCurrentWindow = MAPS;
                itsP2Cursor = 1;
            }
            itsP1Cursor = 0;
        }
        if(itsP1Cursor == 1)
        {
            itsCurrentWindow = SETTINGS;
            itsP1Cursor = 0;
        }
        if(itsP1Cursor == 2)
        {
            return 1;
        }
    }
    else if(itsCurrentWindow == MAPS)
    {
        itsValidSound->play();
        itsCurrentWindow = CHARACTERS;
        itsCurrentMap = itsP1Cursor;
        itsP1Cursor = 0;
    }
    else if(itsCurrentWindow == CHARACTERS)
    {
        if(isP1Ready)
            isP1Ready = false;
        else
        {
            isP1Ready = true;
            if(isP2Ready || itsGameMode == TRAINING)
            {
                aGamemode = itsGameMode;
                aGuardRate = itsGuardRate;
                aMap = itsCurrentMap;
                charP1 = itsP1Cursor;
                charP2 = itsP2Cursor;
                return 2;
            }
        }
    }
    else if(itsCurrentWindow == SETTINGS)
    {
        itsValidSound->play();
        if(itsP1Cursor == 0)
        {
            if(itsGameMode == DEATHMATCH)
                itsGameMode = TIMER;
            else if(itsGameMode == TIMER)
                itsGameMode = TRAINING;
            else if(itsGameMode == TRAINING)
                itsGameMode = DEATHMATCH;
        }
        if(itsP1Cursor == 1)
        {
            if(itsGuardRate == 100)
                itsGuardRate = 0;
            else
                itsGuardRate += 25;
        }
        if(itsP1Cursor == 2)
        {
            itsCurrentWindow = MAIN;
            itsP1Cursor = 0;
        }
    }
    return 0;
}

void Menu::moveP2Cursor(bool up)
{

    if(itsCurrentWindow == CHARACTERS && !isP2Ready)
    {
        if(up)
        {
            if(itsP2Cursor == 0)
                itsP2Cursor = 1;
            else
                itsP2Cursor--;
        }
        else
            if(itsP2Cursor == 1)
                itsP2Cursor = 0;
            else
                itsP2Cursor++;
    }
}

int Menu::enterP2(Gamemode & aGamemode, int & aGuardRate, int & aMap, int & charP1, int & charP2)
{
    if(itsCurrentWindow == CHARACTERS)
    {
        if(isP2Ready)
            isP2Ready = false;
        else
        {
            isP2Ready = true;
            if(isP1Ready)
            {
                aGamemode = itsGameMode;
                aGuardRate = itsGuardRate;
                aMap = itsCurrentMap;
                charP1 = itsP1Cursor;
                charP2 = itsP2Cursor;
                return 2;
            }
        }
    }
    return 0;
}

void Menu::back()
{
    if(itsCurrentWindow == MAPS || itsCurrentWindow == SETTINGS)
    {
        itsP1Cursor = 0;
        itsP2Cursor = 0;
        itsCurrentWindow = MAIN;
    }
    if(itsCurrentWindow == CHARACTERS)
    {
        isP1Ready = false;
        isP2Ready = false;
        itsP1Cursor = 0;
        itsP2Cursor = 0;
        itsCurrentWindow = MAPS;
    }
}
