#ifndef MENU_H
#define MENU_H
#include <QImage>
#include <QKeyEvent>
#include <QPainter>
#include <QSoundEffect>
#include <vector>

using namespace std;

//!
//! \brief Toutes les différentes fenêtres du menu
//!
enum Window{
    MAIN,
    CHARACTERS,
    SETTINGS,
    MAPS
};

//!
//! \brief Les différents modes de jeu
//!
enum Gamemode{
    DEATHMATCH,
    TIMER,
    TRAINING
};

//!
//! \brief La classe qui nous permet d'afficher et d'utiliser le menu
//! \author Erwan Brunelliere
//!
class Menu
{
    QImage * itsBackground;
    QImage * itsCursorImage;
    QImage * itsMenuImage;
    Window itsCurrentWindow = MAIN;
    int itsP1Cursor = 0;
    int itsP2Cursor = 0;
    bool isP1Ready = false;
    bool isP2Ready = false;
    int itsWidth;
    int itsHeight;
    QFont * itsFont;
    Gamemode itsGameMode = DEATHMATCH;
    int itsGuardRate = 100;
    int itsCurrentMap = 0;
    QSoundEffect * itsSelectSound;
    QSoundEffect * itsValidSound;
    vector<QImage> itsMiniMaps;
    vector<QImage> itsMiniIcons;
public:
    //!
    //! \brief Constructeur
    //! \param anImage : Image de fond du menu
    //! \param width : La largeur du menu
    //! \param height : La hauteur du menu
    //!
    Menu(QImage * anImage, int width, int height);

    //!
    //! \brief Afficher le menu, en fonction de la fenetre dans laquelle on est et des curseurs
    //! \param aPainter : l'event qui est appelé
    //!
    void draw(QPainter * aPainter);

    //!
    //! \brief Bouger le curseur du premier joueur, il peut choisir son personnage et c'est lui qui choisis la map et les parametres
    //! \param up : true si le curseur va vers le haut, false vers le bas
    //!
    void moveP1Cursor(bool up);

    //!
    //! \brief Faire valider le premier joueur, fait différentes choses en fonction de la fenêtre
    //! \param aGamemode : Le mode de jeu qui sera renvoyé au jeu
    //! \param aGuardRate : Le type de guarde qui sera envoyé au jeu
    //! \param aMap : Le terrain qui sera envoyé au jeu
    //! \param charP1 : Le personnage choisis par le premier joueur qui sera envoyé au jeu
    //! \param charP2 : Le personnage choisis par le second joueur qui sera envoyé au jeu
    //! \return 0 si il n'y a pas de changement pour le jeu, 1 si le jeu doit se fermer, 2 si le jeu doit se lancer
    //!
    int enterP1(Gamemode &aGamemode, int &aGuardRate, int & aMap, int & charP1, int & charP2);

    //!
    //! \brief Bouger le curseur du second joueur, il peut choisir son personnage
    //! \param up
    //!
    void moveP2Cursor(bool up);

    //!
    //! \brief Faire valider le second joueur, fait différentes choses en fonction de la fenêtre
    //! \param aGamemode : Le mode de jeu qui sera renvoyé au jeu
    //! \param aGuardRate : Le type de guarde qui sera envoyé au jeu
    //! \param aMap : Le terrain qui sera envoyé au jeu
    //! \param charP1 : Le personnage choisis par le premier joueur qui sera envoyé au jeu
    //! \param charP2 : Le personnage choisis par le second joueur qui sera envoyé au jeu
    //! \return 0 si il n'y a pas de changement pour le jeu, 1 si le jeu doit se fermer, 2 si le jeu doit se lancer
    //!
    int enterP2(Gamemode & aGamemode, int & aGuardRate, int & aMap, int & charP1, int & charP2);

    //!
    //! \brief Revenir un fenêtre en arrière
    //!
    void back();
};

#endif // MENU_H
