#ifndef ATTACK_H
#define ATTACK_H

#include "AttackType.h"
#include <QRect>
#include <vector>
#include <QImage>
#include "caracter.h"
#include <list>

using namespace std;

//!
//! \brief La classe qui permet d'enregistrer une attaque
//!
class Attack
{
    int itsDamages;
    QRect itsHitbox;

    int itsDuration;
    AttackType itsType;

    vector<QImage> itsImages;

    list<Sprite> * itsSprites;

    unsigned int itsHitFrame;
public:
    //!
    //! \brief Le constructeur de la classe Attack
    //! \param damages : Les dégatsdu coup
    //! \param anHitbox : La hitbox du coup
    //! \param aDuration : La durée de l'attaque
    //! \param aType : Le type de l'attaque
    //! \param sprites : La liste d'image de l'ataque
    //! \param attackFrame : La durée au bout de laquelle s'affiche la hitbox du coup
    //!
    Attack(int damages, QRect anHitbox, int aDuration, AttackType aType, list<Sprite> * sprites, unsigned int attackFrame);

    //!
    //! \brief Permet de connaitre le type de l'attaque
    //! \return Le type de l'attaque
    //!
    AttackType getType();

    //!
    //! \brief Permet de connaitre la durée de l'attaque
    //! \return La durée de l'attaque
    //!
    int getDuration();

    //!
    //! \brief Execute l'attaque
    //! \return Le temps d'execution
    //!
    int execute();

    //!
    //! \brief Permet de connaitre la hitbox, les dégats et l'image du coup selon le tick
    //! \param damages : les dégats du coup
    //! \param anArmImage : l'image du bras correspondant au tick
    //! \param anCorpsImage : l'image du corp correspondant au tick
    //! \param Le tick de l'attaque
    //! \return Le rectangle de la hitbox actuelle du coup un rectangle (0, 0, 0, 0) s'il n'y en a pas
    //!
    QRect damage(int & damages, QImage &anArmImage, QImage &anCorpsImage, unsigned int aTick);
};

#endif // ATTACK_H
