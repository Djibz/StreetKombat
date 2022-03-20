#ifndef FIGHTERSTATES_H
#define FIGHTERSTATES_H

//!
//! \brief Les différents type de direction
//!
enum Direction{
    RIGHT,
    LEFT
};

//!
//! \brief Les diffirents états du personnage
//!
enum State{
    MOVING,
    STANDING,
    ATTACKING,
    KNOCKED
};

#endif // FIGHTERSTATES_H
