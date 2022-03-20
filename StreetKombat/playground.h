#ifndef PLAYGROUND_H
#define PLAYGROUND_H

#include <QRect>
#include <QImage>
#include <QPainter>

class Playground
{
    QSize itsSize;
    QRect itsBackground;
    QRect itsFloor;

    QImage itsBackgroundTexture;
    QImage itsFloorTexture;
public:
    //!
    //! \brief La classe qui permet d'afficher le terrain
    //! \param aW : La longueur du terrain
    //! \param aH : La hauteur du terrain
    //! \param fH : La hauteur du sol (inutilisé)
    //! \param aBackGround
    //!
    Playground(int aW, int aH, int fH, QString aBackGround);
    int getSize();
    int getFloor();
    void draw(QPainter * aPainter);
};

#endif // PLAYGROUND_H
