#ifndef CARACTER_H
#define CARACTER_H
#include <QImage>
#include <list>
#include <QRect>

using namespace std;

//!
//! \brief La structure pour enregistrer un sprite
//!
struct Sprite{
    QImage body;
    QImage arm;
    unsigned int frame;
};

//!
//! \brief La structure qui permet d'enregistrer un personnage avec ses animations
//!
struct Caracter{
    list<Sprite> light;
    QRect lightHitbox;
    unsigned int lightFrame;
    unsigned int lightDuration;

    list<Sprite> strong;
    QRect strongHitbox;
    unsigned int strongFrame;
    unsigned int strongDuration;

    list<Sprite> ALight;
    QRect ALightHitbox;
    unsigned int ALightFrame;
    unsigned int ALightDuration;

    list<Sprite> AStrong;
    QRect AStrongHitbox;
    unsigned int AStrongFrame;
    unsigned int AStrongDuration;

    list<Sprite> CLight;
    QRect CLightHitbox;
    unsigned int CLightFrame;
    unsigned int CLightDuration;

    list<Sprite> CStrong;
    QRect CStrongHitbox;
    unsigned int CStrongFrame;
    unsigned int CStrongDuration;

    list<Sprite> stand;
    list<Sprite> move;
    list<Sprite> jump;
    list<Sprite> crouch;
    unsigned int maxStand;
    unsigned int maxMove;
    unsigned int lightDamages;
    unsigned int strongDamages;
};
#endif // CARACTER_H
