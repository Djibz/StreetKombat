#include "attack.h"

Attack::Attack(int damages, QRect anHitbox, int aDuration, AttackType aType, list<Sprite> * sprites, unsigned int attackFrame)
    :itsDamages(damages), itsHitbox(anHitbox), itsDuration(aDuration), itsType(aType)
{
    itsSprites = (sprites);
    itsHitFrame = attackFrame;
}

AttackType Attack::getType()
{
    return itsType;
}

int Attack::getDuration()
{
    return itsDuration;
}

QRect Attack::damage(int &damages, QImage & anArmImage, QImage &anCorpsImage, unsigned int aTick)
{
    damages = itsDamages;
    unsigned int count = 0;
    QRect hitbox(0, 0, 0, 0);

    for(Sprite & i: *itsSprites)
    {
        if(i.frame < aTick)
        {
            anArmImage = i.arm;
            anCorpsImage = i.body;
            if(count == itsHitFrame)
                hitbox = itsHitbox;
            else
                hitbox = QRect(0, 0, 0, 0);
            count++;
        }
    }

    return hitbox;
}
