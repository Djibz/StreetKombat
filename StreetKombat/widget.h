#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QSoundEffect>

#include "fighter.h"
#include "menu.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent * event);
    void paintEvent(QPaintEvent *event);

private slots :
    //!
    //! \brief La boucle du jeu, elle est appellée toutes les 6ms
    //!
    void gameLoop();

    //!
    //! \brief Permet de lancer le jeu
    //!
    void start();

    //!
    //! \brief Permet de terminer une partie
    //!
    void end();

    //!
    //! \brief Lance un fatality (non operationel)
    //!
    void fatality();

    //!
    //! \brief Permet l'incrementation du timer lors du mode de jeu timer
    //!
    void timerIncrement();

private:
    Ui::Widget *ui;

    //!
    //! \brief Le timer de la boucle principale du jeu
    //!
    QTimer * itsTimer;

    //!
    //! \brief Le timer pour gérer la durée d'enclenchement du fatality
    //!
    QTimer * itsFatalityTimer;

    //!
    //! \brief Le Timer du mode de jeu Timer
    //!
    QTimer * itsChronomodeTimer;

    //!
    //! \brief Le temps écoulé du mode de jeu timer
    //!
    double itsChronomodeTime = 0.0;

    //!
    //! \brief Le premier personnage
    //!
    Fighter * itsFighter1;

    //!
    //! \brief Le second personnage
    //!
    Fighter * itsFighter2;

    //!
    //! \brief Le menu
    //!
    Menu * itsMenu;

    //!
    //! \brief Utilisé pour inverser les couleurs du second personnage si besoin
    //!
    Caracter secondC;

    //!
    //! \brief L'image de l'ecran de fin
    //!
    QImage * itsWinWindow;

    //!
    //! \brief L'image du fond du terrain
    //!
    QImage * itsBackground;

    //!
    //! \brief La musique du combat
    //!
    QSoundEffect * Music;

    //!
    //! \brief Permet de savoir si le combat est terminé
    //!
    bool battleEnd = false;

    //!
    //! \brief La durée d'enclenchement du fatality
    //!
    int fatalityTime = 2;

    //!
    //! \brief inMenu
    //!
    bool inMenu = true;

    //!
    //! \brief Le mode de jeu de la partie
    //!
    Gamemode itsGamemode;

    //!
    //! \brief Le taux de la guarde
    //!
    int itsGuardRate;

    //!
    //! \brief Le personnage choisi par le premier joueur
    //!
    int itsP1Char = 0;

    //!
    //! \brief Le personnage choisi par le second joueur
    //!
    int itsP2Char = 0;

    //!
    //! \brief Le terrain choisi
    //!
    int itsMap = 0;

    //!
    //! \brief Les deux petites icones des joueurs
    //!
    vector<QImage> playerIcons;

    //!
    //! \brief itsImagePlayground
    //!
    QImage itsImagePlayground;
};
#endif // WIDGET_H
