#ifndef FIGHTER_H
#define FIGHTER_H

#include <QRect>
#include <string>
#include <list>
#include "attack.h"
#include "FighterStates.h"
#include <QPainter>
#include <QMediaPlayer>

using namespace std;

//!
//! \brief La classe qui permet d'enregistrer un fighter
//!
class Fighter
{
    string itsName;
    int itsHealth;
    int itsSpeed = 0;
    bool isPlayer1;
    bool isGuarding = false;
    bool isInAir = false;
    bool isCrouching = false;
    unsigned int itsAirTime = 0;
    unsigned int itsCrouchTime = 0;
    int guardingRate;

    QMediaPlayer * sound;

    QRect itsHitbox;
    QRect itsBody;
    QRect itsArms;
    QRect itsHealthBar;

    QImage * itsCorps;
    QImage * itsArm;

    Fighter * itsOpponent;

    int itsLockedTime = 0;

    //Compteur de boucle de jeu utiles pour diverses
    int itsTick = 0;

    int itsInvicibleTime = 0;

    Caracter * itsCaracter;
    list<Attack*> itsAttacks;

    Attack * itsCurrentAttack = nullptr;

    Direction itsDirection = LEFT;
    State itsState = STANDING;


public:
    //!
    //! \brief Le constructeur de la classe Fighter
    //! \param aCaracter : Le personnage
    //! \param player1 : Indique si le fighter est le premier ou le deuxième fighter
    //! \param rate : Pourcentage de dégat que la guarde bloque
    //!
    Fighter(Caracter *aCaracter, bool player1, int rate);

    //!
    //! \brief Permet de faire avancer le fighter
    //!
    void move();

    //!
    //! \brief Permet de faire s'accroupire le fighter
    //!
    void crouch();

    //!
    //! \brief Permet de relevé le fighter
    //!
    void stand();

    //!
    //! \brief Affiche le fighter
    //! \param aPainter : le painter utilisé pour afficher
    //!
    void draw(QPainter *aPainter);

    //!
    //! \brief Permet au fighter d'attaquer
    //! \param aType : Le type de l'attaque
    //!
    void attack(AttackType aType);

    //!
    //! \brief Permet au joueur de prendre des dégats
    //! \param aDuration : Le temps pendant lequel le personnage est bloqué et invincible
    //! \param damages : Le nombre de dégats reçu par le fighter
    //!
    void takeDamages(int aDuration, int damages);


    //!
    //! \brief Permet au fighter de sauter
    //!
    void jump();

    //!
    //! \brief Permet de changer la direction du fighter
    //!
    void changeDir();

    //!
    //! \brief Permet de séparer les deux fighter
    //!
    void separate();


    //!
    //! \brief Permet de modifier la vitesse
    //! \param value : La vitesse
    //!
    void setItsSpeed(int value);

    //!
    //! \brief Permet de modifier son lockedTime
    //! \param value : Le lockedTime
    //!
    void setItsLockedTime(int value);

    QRect *getHitBox();
    QRect *getItsBody();
    void setItsOpponent(Fighter *value);
    int getItsHealth() const;    
    Direction getItsDirection() const;
    QRect getItsHealthBar() const;
    void setIsGuarding(bool value);
    void setIsCrouching(bool value);
    bool getIsCrouching() const;

};

#endif // FIGHTER_H
