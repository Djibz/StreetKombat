#include "fighter.h"
#include <QDebug>

void Fighter::setItsSpeed(int value)
{
    itsSpeed = value;
}

void Fighter::setItsLockedTime(int value)
{
    itsLockedTime = value;
}

QRect *Fighter::getHitBox()
{
    return &itsHitbox;
}

void Fighter::attack(AttackType aType)
{
    if(itsLockedTime == 0)
    {
        sound->setMedia(QUrl::fromLocalFile("../sounds/coups_dans_le_vent1.wav"));
        sound->setVolume(60);
        sound->play();
        itsState = ATTACKING;
        if(isCrouching and aType == LIGHT)
        {
            aType = CLIGHT;
        }
        if(isCrouching and aType == STRONG)
        {
            aType = CSTRONG;
        }
        if(isInAir and aType == STRONG)
        {
            aType = ASTRONG;
        }
        for(Attack * i : itsAttacks)
        {
            if(i->getType() == aType)   
            {
                itsCurrentAttack = i;
            }
        }
        itsLockedTime = itsCurrentAttack->getDuration();
        itsTick = 0;
    }
}

void Fighter::takeDamages(int aDuration, int damages)
{
    if(itsState != KNOCKED)
    {
        itsState = KNOCKED;
        itsLockedTime = aDuration;
        itsCurrentAttack = nullptr;
        if(itsHealth > 0)
        {
            if(isGuarding)
            {
                itsHealth -= (damages*(100-guardingRate))/100;
            }
            else
            {
                itsHealth -= damages;
            }
            itsHealthBar.setWidth(itsHealth*5);
            if(itsHealth < 0)
            {
                itsHealthBar.setWidth(0);
            }
        }
        /*if(isPlayer1)
        {
            itsHealthBar.setX(1085+(damages*5));
        }*/
    }
}

void Fighter::jump()
{
    if(!isInAir and itsLockedTime == 0)
    {
        if(itsSpeed==1)
        {
            setItsSpeed(2);
        }
        if(itsSpeed==-1)
        {
            setItsSpeed(-2);
        }
        isInAir = true;
        itsAirTime = 0;
        if(itsDirection == LEFT)
        {
            itsArms.moveTo(itsBody.x()-20, itsArms.y()-10);
        }
        else
        {
            itsArms.moveTo(itsBody.x()+20, itsArms.y()-10);
        }
    }
}

void Fighter::changeDir()
{
    if(/*itsLockedTime == 0*/1)
    {
        itsDirection = itsDirection == RIGHT ? LEFT : RIGHT;
        *itsArm = itsArm->mirrored(true, false);
        *itsCorps = itsCorps->mirrored(true, false);
        itsHitbox.translate(itsDirection == LEFT ? 60 : -60, 0);
        //itsBody.translate(itsDirection == LEFT ? -180 : 180, 0);
        //itsArms.translate(itsDirection == LEFT ? -180 : 180, 0);
    }
}


void Fighter::separate()
{
    itsBody.translate(800, 0);
    itsArms.translate(800, 0);
    itsHitbox.translate(800, 0);
}

void Fighter::crouch()
{

    if(!isCrouching  and itsLockedTime == 0)
    {
        setItsSpeed(0);
        isCrouching = true;
        itsCrouchTime = 0;
        itsHitbox.moveTop(itsHitbox.top()+200);
    }

}

void Fighter::stand()
{
    if(isCrouching)
    {
        isCrouching = false;
        itsHitbox.moveTop(itsHitbox.top()-200);
        itsArms.moveTo(itsBody.x(), itsBody.y());

    }
}


void Fighter::setItsOpponent(Fighter *value)
{
    itsOpponent = value;
}

int Fighter::getItsHealth() const
{
    return itsHealth;
}

Direction Fighter::getItsDirection() const
{
    return itsDirection;
}

QRect Fighter::getItsHealthBar() const
{
    return itsHealthBar;
}

void Fighter::setIsGuarding(bool value)
{
    isGuarding = value;
}
void Fighter::setIsCrouching(bool value)
{
    isCrouching = value;
}

bool Fighter::getIsCrouching() const
{
    return isCrouching;
}

QRect * Fighter::getItsBody()
{
    return &itsBody;
}

Fighter::Fighter(Caracter * aCaracter, bool player1, int rate)
{
    itsCaracter = aCaracter;
    isPlayer1 = player1;
    guardingRate = rate;
    itsHealth = 100;
    sound = new QMediaPlayer;
    itsCorps = new QImage(itsCaracter->stand.front().body);
    itsArm = new QImage(itsCaracter->stand.front().arm);
    itsBody = QRect(200,450,400,400);
    itsArms = QRect(200,450,400,400);
    itsHitbox = QRect(320, 470, 220, 380);
    if(!isPlayer1)
    {
        itsHealthBar = QRect(10,10, 500, 50);
    }
    else
    {
        itsHealthBar = QRect(1090,10, 500, 50);
    }
    itsAttacks.push_back(new Attack(itsCaracter->lightDamages, itsCaracter->lightHitbox, itsCaracter->lightDuration, LIGHT, &(itsCaracter->light), itsCaracter->lightFrame));
    itsAttacks.push_back(new Attack(itsCaracter->strongDamages, itsCaracter->strongHitbox, itsCaracter->strongDuration, STRONG, &(itsCaracter->strong), itsCaracter->strongFrame));
    itsAttacks.push_back(new Attack(itsCaracter->lightDamages, itsCaracter->CLightHitbox, itsCaracter->CLightDuration, CLIGHT, &(itsCaracter->CLight), itsCaracter->CLightFrame));
    itsAttacks.push_back(new Attack(itsCaracter->strongDamages, itsCaracter->CStrongHitbox, itsCaracter->CStrongDuration, CSTRONG, &(itsCaracter->CStrong), itsCaracter->CStrongFrame));
    itsAttacks.push_back(new Attack(itsCaracter->strongDamages, itsCaracter->AStrongHitbox, itsCaracter->AStrongDuration, ASTRONG, &(itsCaracter->AStrong), itsCaracter->AStrongFrame));
}

void Fighter::move()
{
    if(itsLockedTime == 0)
    {
        if((itsBody.x() >= -100 and (itsSpeed == -1 or itsSpeed == -2)) or (itsBody.x() <= 1700-itsBody.width() and (itsSpeed == 1 or itsSpeed == 2)))
        {
            itsBody.translate(itsSpeed, 0);
            itsArms.translate(itsSpeed, 0);
            itsHitbox.translate(itsSpeed, 0);
        }
            if(itsSpeed != 0)
            {
                if(itsState != MOVING)
                    itsTick = 0;
                itsState = MOVING;
                itsCurrentAttack = nullptr;
            }
            else if(itsState == MOVING)
                itsState = STANDING;

    } 
}

void Fighter::draw(QPainter *aPainter)
{
    ++itsTick;
    aPainter->drawImage(itsBody, *itsCorps);
    aPainter->drawImage(itsArms, *itsArm);
    //aPainter->drawRect(itsHitbox);
    //aPainter->drawRect(itsBody);
    //aPainter->drawRect(itsArms);

    if(itsState == MOVING)
    {
        unsigned int aTick = itsTick % itsCaracter->maxMove;
        // On regarde tous les sprites de mouvement
        for(Sprite i: itsCaracter->move)
        {
            if(aTick < 10)
            {
                itsArms.moveTo(itsBody.x(), itsBody.y());
            }
            if(aTick >= 10 and aTick < 20)
            {
                itsArms.moveTo(itsBody.x(), itsBody.y()+4);
            }
            if(aTick >= 20 and aTick < 40)
            {
                if(itsDirection== LEFT)
                {
                    itsArms.moveTo(itsBody.x()-4, itsBody.y()-10);
                }
                else
                {
                    itsArms.moveTo(itsBody.x()+4, itsBody.y()-10);
                }
            }
            if(aTick >= 40 and aTick < 60)
            {
                if(itsDirection== LEFT)
                {
                    itsArms.moveTo(itsBody.x()-10, itsBody.y()+20);
                }
                else
                {
                    itsArms.moveTo(itsBody.x()+10, itsBody.y()+20);
                }
            }
            if(aTick >= 60 and aTick <= 80)
            {
                if(itsDirection== LEFT)
                {
                    itsArms.moveTo(itsBody.x()-40, itsBody.y()+40);
                }
                else
                {
                    itsArms.moveTo(itsBody.x()+40, itsBody.y()+40);
                }
            }
            // Si le sprite correspond au nombre de ticks, on l'affect au personnage
            if(i.frame < aTick)
            {

                *itsArm = i.arm;
                *itsCorps = i.body;
                if(itsDirection == RIGHT) // On met dans la bonne direction
                {
                    *itsArm = (itsArm->mirrored(true, false));
                    *itsCorps = itsCorps->mirrored(true, false);
                }
            }
        }
    }

    if(itsState == STANDING and !isInAir)
    {
        itsArms.moveTo(itsBody.x(), itsBody.y());
        for(Sprite i: itsCaracter->stand)
        {
            // Si le sprite correspond au nombre de ticks, on l'affect au personnage
            if(i.frame < itsAirTime)
            {
                *itsArm = i.arm;
                *itsCorps = i.body;
                if(itsDirection == RIGHT) // On met dans la bonne direction
                {
                    *itsArm = (itsArm->mirrored(true, false));
                    *itsCorps = itsCorps->mirrored(true, false);
                }
            }
            if(itsAirTime <= 120)
            {
                itsAirTime++;
            }
            else
            {
                itsAirTime = 0;
            }
        }
    }

    // Gerer le saut
    if(isInAir)
    {

        if(itsAirTime > 20 && itsAirTime <= 80)
        {
            itsBody.translate(0, -7);
            if(itsDirection == LEFT)
            {
                itsArms.moveTo(itsBody.x()-20, itsArms.y()-7);
            }
            else
            {
                itsArms.moveTo(itsBody.x()+20, itsArms.y()-7);
            }
            itsHitbox.translate(0, -7);
        }

        if(itsAirTime > 80 && itsAirTime <= 140)
        {
            itsBody.translate(0, 7);
            if(itsDirection == LEFT)
            {
                itsArms.moveTo(itsBody.x()-20, itsArms.y()+7);
            }
            else
            {
                itsArms.moveTo(itsBody.x()+20, itsArms.y()+7);
            }
            itsHitbox.translate(0, 7);
        }

        if(itsAirTime >= 150)
        {
            isInAir = false;
            itsArms.moveTo(itsBody.x(), itsBody.y());
        }
        if(itsCurrentAttack == nullptr)
        {
            for(Sprite i: itsCaracter->jump)
            {
                // Si le sprite correspond au nombre de ticks, on l'affect au personnage
                if(i.frame < itsAirTime)
                {
                    *itsArm = i.arm;
                    *itsCorps = i.body;
                    if(itsDirection == RIGHT) // On met dans la bonne direction
                    {
                        *itsArm = (itsArm->mirrored(true, false));
                        *itsCorps = itsCorps->mirrored(true, false);
                    }
                }
            }
        }
        itsAirTime++;
    }

    if(isCrouching)
    {
        if(itsCrouchTime >= 10 and itsCrouchTime <20)
        {
            itsArms.moveTo(itsBody.x(), itsBody.y()+50);
        }
        if(itsCrouchTime >= 20 and itsCrouchTime < 30)
        {
            if(itsDirection == LEFT)
            {
                itsArms.moveTo(itsBody.x()+45,itsBody.y()+190);
            }
            else
            {
                itsArms.moveTo(itsBody.x()-45,itsBody.y()+190);
            }
        }
        if(itsCrouchTime >= 30 and itsCrouchTime < 40)
        {
            if(itsDirection == LEFT)
            {
                itsArms.moveTo(itsBody.x()+45,itsBody.y()+194);
            }
            else
            {
                itsArms.moveTo(itsBody.x()-45,itsBody.y()+194);
            }
        }
        if(itsCrouchTime >= 40 and itsCrouchTime < 50)
        {
            if(itsDirection == LEFT)
            {
                itsArms.moveTo(itsBody.x()+45,itsBody.y()+190);
            }
            else
            {
                itsArms.moveTo(itsBody.x()-45,itsBody.y()+190);
            }
        }
        if(itsCrouchTime >= 50 and itsCrouchTime < 60)
        {
            if(itsDirection == LEFT)
            {
                itsArms.moveTo(itsBody.x()+45,itsBody.y()+192);
            }
            else
            {
                itsArms.moveTo(itsBody.x()-45,itsBody.y()+192);
            }
        }
        if(itsCrouchTime >= 60 and itsCrouchTime <= 70)
        {
            if(itsDirection == LEFT)
            {
                itsArms.moveTo(itsBody.x()+45,itsBody.y()+192);
            }
            else
            {
                itsArms.moveTo(itsBody.x()-45,itsBody.y()+192);
            }
        }
        for(Sprite i: itsCaracter->crouch)
        {
            // Si le sprite correspond au nombre de ticks, on l'affect au personnage
            if(i.frame <= itsCrouchTime)
            {
                *itsArm = i.arm;
                *itsCorps = i.body;
                if(itsDirection == RIGHT) // On met dans la bonne direction
                {
                    *itsArm = (itsArm->mirrored(true, false));
                    *itsCorps = itsCorps->mirrored(true, false);
                }
            }
        }
        if(itsCrouchTime < 70)
            itsCrouchTime++;
        else
        {
            //itsHitbox.
        }
    }

    // Gerer le locked Time
    if(itsLockedTime > 0)
    {
        --itsLockedTime;
        if(itsCurrentAttack != nullptr)
        {
            int damages;
            // Permet de gérer la position des bras en fonction de l'etat du personnage
            if(itsCurrentAttack->getType() == CSTRONG)
            {
                itsArms.moveTo(itsBody.x(),itsBody.y());
            }
            // Permet de gérer la position des bras en fonction de l'etat du personnage
            if(itsCurrentAttack->getType() == CLIGHT)
            {
                if(itsDirection == LEFT)
                {
                    itsArms.moveTo(itsBody.x()+45,itsBody.y()+192);
                }
                else
                {
                    itsArms.moveTo(itsBody.x()-45,itsBody.y()+192);
                }
            }
            QRect aRect = itsCurrentAttack->damage(damages, *itsArm, *itsCorps, itsTick);
            if(itsDirection == RIGHT) // Permet d'inverser la position de la hitbox en fonction de la direction du personnage
            {
                *itsArm = (itsArm->mirrored(true, false));
                *itsCorps = itsCorps->mirrored(true, false);
                aRect.moveTo(itsBody.width() - aRect.x() - aRect.width(), aRect.y());
            }
            //On met la hitbox du coup par rapport au coin haut gauche du perso
            aRect.translate(itsBody.topLeft());
            /*QColor aColor(255, 0, 0, 50);       // Affichage hitbox
            aPainter->fillRect(aRect, aColor);*/  //

            //On test si la hitbox touche
            if(aRect.intersects(*(itsOpponent->getHitBox())))
            {
                // Son des impacts
                sound->stop();
                sound->setMedia(QUrl::fromLocalFile("../sounds/punch_1.wav"));
                sound->setVolume(60);
                sound->play();
                itsOpponent->takeDamages(40, damages);
            }
        }
    }
    else
    {
        //sound->stop();
        // A la fin d'un locked time, on enleve l'attque courante
        if(itsCurrentAttack != nullptr || itsState == KNOCKED)
        {
            itsCurrentAttack = nullptr;
            itsState = STANDING;
        }
    }
}

