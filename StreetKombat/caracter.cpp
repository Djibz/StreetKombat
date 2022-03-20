#include "caracter.h"

// Personnage 1
list<Sprite> perso1_light{
    Sprite{QImage("../Sprites/P1/P1_Corps_Idle1.png"), QImage("../Sprites/P1/P1_Bras_Frappe1.png"), 0},
    Sprite{QImage("../Sprites/P1/P1_Corps_Idle1.png"), QImage("../Sprites/P1/P1_Bras_Frappe2.png"), 10},
    Sprite{QImage("../Sprites/P1/P1_Corps_Idle1.png"), QImage("../Sprites/P1/P1_Bras_Frappe3.png"), 20},
    Sprite{QImage("../Sprites/P1/P1_Corps_Idle1.png"), QImage("../Sprites/P1/P1_Bras_Frappe4.png"), 30},
    Sprite{QImage("../Sprites/P1/P1_Corps_Idle1.png"), QImage("../Sprites/P1/P1_Bras_Frappe5.png"), 40},
    Sprite{QImage("../Sprites/P1/P1_Corps_Idle1.png"), QImage("../Sprites/P1/P1_Bras_Frappe6.png"), 60},
    Sprite{QImage("../Sprites/P1/P1_Corps_Idle1.png"), QImage("../Sprites/P1/P1_Bras_Frappe7.png"), 90},
    Sprite{QImage("../Sprites/P1/P1_Corps_Idle1.png"), QImage("../Sprites/P1/P1_Bras_Frappe8.png"), 100},
    Sprite{QImage("../Sprites/P1/P1_Corps_Idle1.png"), QImage("../Sprites/P1/P1_Bras_Frappe9.png"), 109}
};

list<Sprite> perso1_light_crouch{
    Sprite{QImage("../Sprites/P1/P1_Corps_Accroupissage7.png"), QImage("../Sprites/P1/P1_Bras_Frappe1.png"), 0},
    Sprite{QImage("../Sprites/P1/P1_Corps_Accroupissage7.png"), QImage("../Sprites/P1/P1_Bras_Frappe2.png"), 10},
    Sprite{QImage("../Sprites/P1/P1_Corps_Accroupissage7.png"), QImage("../Sprites/P1/P1_Bras_Frappe3.png"), 20},
    Sprite{QImage("../Sprites/P1/P1_Corps_Accroupissage7.png"), QImage("../Sprites/P1/P1_Bras_Frappe4.png"), 30},
    Sprite{QImage("../Sprites/P1/P1_Corps_Accroupissage7.png"), QImage("../Sprites/P1/P1_Bras_Frappe5.png"), 40},
    Sprite{QImage("../Sprites/P1/P1_Corps_Accroupissage7.png"), QImage("../Sprites/P1/P1_Bras_Frappe6.png"), 60},
    Sprite{QImage("../Sprites/P1/P1_Corps_Accroupissage7.png"), QImage("../Sprites/P1/P1_Bras_Frappe7.png"), 90},
    Sprite{QImage("../Sprites/P1/P1_Corps_Accroupissage7.png"), QImage("../Sprites/P1/P1_Bras_Frappe8.png"), 100},
    Sprite{QImage("../Sprites/P1/P1_Corps_Accroupissage7.png"), QImage("../Sprites/P1/P1_Bras_Frappe9.png"), 109}
};

list<Sprite> perso1_idle{
    Sprite{QImage("../Sprites/P1/P1_Corps_Idle1.png"), QImage("../Sprites/P1/P1_Bras_Idle1.png"), 0},
    Sprite{QImage("../Sprites/P1/P1_Corps_Idle2.png"), QImage("../Sprites/P1/P1_Bras_Idle2.png"), 60}
};

list<Sprite> perso1_move{
    Sprite{QImage("../Sprites/P1/P1_Corps_Marche1.png"), QImage("../Sprites/P1/P1_Bras_Idle1.png"), 0},
    Sprite{QImage("../Sprites/P1/P1_Corps_Marche2.png"), QImage("../Sprites/P1/P1_Bras_Idle1.png"), 10},
    Sprite{QImage("../Sprites/P1/P1_Corps_Marche3.png"), QImage("../Sprites/P1/P1_Bras_Idle1.png"), 20},
    Sprite{QImage("../Sprites/P1/P1_Corps_Marche4.png"), QImage("../Sprites/P1/P1_Bras_Idle1.png"), 40},
    Sprite{QImage("../Sprites/P1/P1_Corps_Marche5.png"), QImage("../Sprites/P1/P1_Bras_Idle1.png"), 60}
};

list<Sprite> perso1_strong{
    Sprite{QImage("../Sprites/P1/P1_Corps_FrappeLourde1.png"), QImage("../Sprites/P1/P1_Bras_FrappeLourde1.png"), 0},
    Sprite{QImage("../Sprites/P1/P1_Corps_FrappeLourde2.png"), QImage("../Sprites/P1/P1_Bras_FrappeLourde2.png"), 50},
    Sprite{QImage("../Sprites/P1/P1_Corps_FrappeLourde3.png"), QImage("../Sprites/P1/P1_Bras_FrappeLourde3.png"), 80},
    Sprite{QImage("../Sprites/P1/P1_Corps_FrappeLourde4.png"), QImage("../Sprites/P1/P1_Bras_FrappeLourde4.png"), 110},
    Sprite{QImage("../Sprites/P1/P1_Corps_FrappeLourde5.png"), QImage("../Sprites/P1/P1_Bras_FrappeLourde5.png"), 120},
    Sprite{QImage("../Sprites/P1/P1_Corps_FrappeLourde6.png"), QImage("../Sprites/P1/P1_Bras_FrappeLourde6.png"), 140},
    Sprite{QImage("../Sprites/P1/P1_Corps_FrappeLourde7.png"), QImage("../Sprites/P1/P1_Bras_FrappeLourde7.png"), 150},
    Sprite{QImage("../Sprites/P1/P1_Corps_FrappeLourde8.png"), QImage("../Sprites/P1/P1_Bras_FrappeLourde8.png"), 190},
    Sprite{QImage("../Sprites/P1/P1_Corps_FrappeLourde9.png"), QImage("../Sprites/P1/P1_Bras_FrappeLourde9.png"), 220}
};

list<Sprite> perso1_strong_jump{
    Sprite{QImage("../Sprites/P1/P1_Corps_SFrappeLourde1.png"), QImage("../Sprites/P1/P1_Bras_SFrappeLourde1.png"), 0},
    Sprite{QImage("../Sprites/P1/P1_Corps_SFrappeLourde2.png"), QImage("../Sprites/P1/P1_Bras_SFrappeLourde2.png"), 10},
    Sprite{QImage("../Sprites/P1/P1_Corps_SFrappeLourde3.png"), QImage("../Sprites/P1/P1_Bras_SFrappeLourde3.png"), 30},
    Sprite{QImage("../Sprites/P1/P1_Corps_SFrappeLourde4.png"), QImage("../Sprites/P1/P1_Bras_SFrappeLourde4.png"), 50},
    Sprite{QImage("../Sprites/P1/P1_Corps_SFrappeLourde5.png"), QImage("../Sprites/P1/P1_Bras_SFrappeLourde5.png"), 70},
    Sprite{QImage("../Sprites/P1/P1_Corps_SFrappeLourde2.png"), QImage("../Sprites/P1/P1_Bras_SFrappeLourde2.png"), 90}
};

list<Sprite> perso1_strong_crouch{
    Sprite{QImage("../Sprites/P1/P1_Corps_AFrappeLourde1.png"), QImage("../Sprites/P1/P1_Bras_AFrappeLourde1.png"), 0},
    Sprite{QImage("../Sprites/P1/P1_Corps_AFrappeLourde2.png"), QImage("../Sprites/P1/P1_Bras_AFrappeLourde2.png"), 50},
    Sprite{QImage("../Sprites/P1/P1_Corps_AFrappeLourde4.png"), QImage("../Sprites/P1/P1_Bras_AFrappeLourde4.png"), 110},
    Sprite{QImage("../Sprites/P1/P1_Corps_AFrappeLourde5.png"), QImage("../Sprites/P1/P1_Bras_AFrappeLourde5.png"), 120},
    Sprite{QImage("../Sprites/P1/P1_Corps_AFrappeLourde6.png"), QImage("../Sprites/P1/P1_Bras_AFrappeLourde6.png"), 140},
    Sprite{QImage("../Sprites/P1/P1_Corps_AFrappeLourde7.png"), QImage("../Sprites/P1/P1_Bras_AFrappeLourde7.png"), 150},
    Sprite{QImage("../Sprites/P1/P1_Corps_AFrappeLourde8.png"), QImage("../Sprites/P1/P1_Bras_AFrappeLourde8.png"), 190},
    Sprite{QImage("../Sprites/P1/P1_Corps_AFrappeLourde9.png"), QImage("../Sprites/P1/P1_Bras_AFrappeLourde9.png"), 220}
};

list<Sprite> perso1_jump{
    Sprite{QImage("../Sprites/P1/P1_Corps_Saut1.png"), QImage("../Sprites/P1/P1_Bras_Idle1.png"), 0},
    Sprite{QImage("../Sprites/P1/P1_Corps_Saut2.png"), QImage("../Sprites/P1/P1_Bras_Idle1.png"), 5},
    Sprite{QImage("../Sprites/P1/P1_Corps_Saut3.png"), QImage("../Sprites/P1/P1_Bras_Idle1.png"), 10},
    Sprite{QImage("../Sprites/P1/P1_Corps_Saut4.png"), QImage("../Sprites/P1/P1_Bras_Idle1.png"), 20},
    Sprite{QImage("../Sprites/P1/P1_Corps_Saut5.png"), QImage("../Sprites/P1/P1_Bras_Idle1.png"), 100},
    Sprite{QImage("../Sprites/P1/P1_Corps_Saut6.png"), QImage("../Sprites/P1/P1_Bras_Idle1.png"), 140}
};

list<Sprite> perso1_crouch{
    Sprite{QImage("../Sprites/P1/P1_Corps_Accroupissage1.png"), QImage("../Sprites/P1/P1_Bras_Idle1.png"), 0},
    Sprite{QImage("../Sprites/P1/P1_Corps_Accroupissage2.png"), QImage("../Sprites/P1/P1_Bras_Idle1.png"), 10},
    Sprite{QImage("../Sprites/P1/P1_Corps_Accroupissage3.png"), QImage("../Sprites/P1/P1_Bras_Idle1.png"), 20},
    Sprite{QImage("../Sprites/P1/P1_Corps_Accroupissage4.png"), QImage("../Sprites/P1/P1_Bras_Idle1.png"), 30},
    Sprite{QImage("../Sprites/P1/P1_Corps_Accroupissage5.png"), QImage("../Sprites/P1/P1_Bras_Idle1.png"), 40},
    Sprite{QImage("../Sprites/P1/P1_Corps_Accroupissage6.png"), QImage("../Sprites/P1/P1_Bras_Idle1.png"), 50},
    Sprite{QImage("../Sprites/P1/P1_Corps_Accroupissage7.png"), QImage("../Sprites/P1/P1_Bras_Idle1.png"), 60}
};

Caracter perso1{
            perso1_light,
            QRect(0, 100, 150, 50),
            3,
            110,

            perso1_strong,
            QRect(0, 150, 150, 100),
            6,
            250,



            perso1_light,
            QRect(0, 100, 150, 50),
            3,
            50,

            perso1_strong_jump,
            QRect(0, 100, 150, 50),
            4,
            100,

            perso1_light_crouch,
            QRect(45, 302, 150, 50),
            5,
            110,

            perso1_strong_crouch,
            QRect(0, 330, 150, 50),
            6,
            250,

            perso1_idle,
            perso1_move,
            perso1_jump,
            perso1_crouch,
            1,
            80,
            10,
            20
};

//----------------------------------------------------------------------------------------------------------
//Personnage 2

list<Sprite> perso2_light{
    Sprite{QImage("../Sprites/P2/P2_Corps_Idle1.png"), QImage("../Sprites/P2/P2_Bras_Frappe1.png"), 0},
    Sprite{QImage("../Sprites/P2/P2_Corps_Idle1.png"), QImage("../Sprites/P2/P2_Bras_Frappe2.png"), 10},
    Sprite{QImage("../Sprites/P2/P2_Corps_Idle1.png"), QImage("../Sprites/P2/P2_Bras_Frappe3.png"), 20},
    Sprite{QImage("../Sprites/P2/P2_Corps_Idle1.png"), QImage("../Sprites/P2/P2_Bras_Frappe4.png"), 30},
    Sprite{QImage("../Sprites/P2/P2_Corps_Idle1.png"), QImage("../Sprites/P2/P2_Bras_Frappe5.png"), 40},
    Sprite{QImage("../Sprites/P2/P2_Corps_Idle1.png"), QImage("../Sprites/P2/P2_Bras_Frappe6.png"), 60},
    Sprite{QImage("../Sprites/P2/P2_Corps_Idle1.png"), QImage("../Sprites/P2/P2_Bras_Frappe7.png"), 90},
    Sprite{QImage("../Sprites/P2/P2_Corps_Idle1.png"), QImage("../Sprites/P2/P2_Bras_Frappe8.png"), 100},
    Sprite{QImage("../Sprites/P2/P2_Corps_Idle1.png"), QImage("../Sprites/P2/P2_Bras_Frappe9.png"), 109}
};

list<Sprite> perso2_light_crouch{
    Sprite{QImage("../Sprites/P2/P2_Corps_Accroupissage7.png"), QImage("../Sprites/P2/P2_Bras_Frappe1.png"), 0},
    Sprite{QImage("../Sprites/P2/P2_Corps_Accroupissage7.png"), QImage("../Sprites/P2/P2_Bras_Frappe2.png"), 10},
    Sprite{QImage("../Sprites/P2/P2_Corps_Accroupissage7.png"), QImage("../Sprites/P2/P2_Bras_Frappe3.png"), 20},
    Sprite{QImage("../Sprites/P2/P2_Corps_Accroupissage7.png"), QImage("../Sprites/P2/P2_Bras_Frappe4.png"), 30},
    Sprite{QImage("../Sprites/P2/P2_Corps_Accroupissage7.png"), QImage("../Sprites/P2/P2_Bras_Frappe5.png"), 40},
    Sprite{QImage("../Sprites/P2/P2_Corps_Accroupissage7.png"), QImage("../Sprites/P2/P2_Bras_Frappe6.png"), 60},
    Sprite{QImage("../Sprites/P2/P2_Corps_Accroupissage7.png"), QImage("../Sprites/P2/P2_Bras_Frappe7.png"), 90},
    Sprite{QImage("../Sprites/P2/P2_Corps_Accroupissage7.png"), QImage("../Sprites/P2/P2_Bras_Frappe8.png"), 100},
    Sprite{QImage("../Sprites/P2/P2_Corps_Accroupissage7.png"), QImage("../Sprites/P2/P2_Bras_Frappe9.png"), 109}
};


list<Sprite> perso2_strong{
    Sprite{QImage("../Sprites/P2/P2_Corps_FrappeLourde1.png"), QImage("../Sprites/P2/P2_Bras_FrappeLourde1.png"), 0},
    Sprite{QImage("../Sprites/P2/P2_Corps_FrappeLourde2.png"), QImage("../Sprites/P2/P2_Bras_FrappeLourde2.png"), 50},
    Sprite{QImage("../Sprites/P2/P2_Corps_FrappeLourde3.png"), QImage("../Sprites/P2/P2_Bras_FrappeLourde3.png"), 80},
    Sprite{QImage("../Sprites/P2/P2_Corps_FrappeLourde4.png"), QImage("../Sprites/P2/P2_Bras_FrappeLourde4.png"), 110},
    Sprite{QImage("../Sprites/P2/P2_Corps_FrappeLourde5.png"), QImage("../Sprites/P2/P2_Bras_FrappeLourde5.png"), 120},
    Sprite{QImage("../Sprites/P2/P2_Corps_FrappeLourde6.png"), QImage("../Sprites/P2/P2_Bras_FrappeLourde6.png"), 140},
    Sprite{QImage("../Sprites/P2/P2_Corps_FrappeLourde7.png"), QImage("../Sprites/P2/P2_Bras_FrappeLourde7.png"), 150},
    Sprite{QImage("../Sprites/P2/P2_Corps_FrappeLourde8.png"), QImage("../Sprites/P2/P2_Bras_FrappeLourde8.png"), 190},
    Sprite{QImage("../Sprites/P2/P2_Corps_FrappeLourde9.png"), QImage("../Sprites/P2/P2_Bras_FrappeLourde9.png"), 220}
};

list<Sprite> perso2_strong_jump{
    Sprite{QImage("../Sprites/P2/P2_Corps_SFrappeLourde1.png"), QImage("../Sprites/P2/P2_Bras_SFrappeLourde1.png"), 0},
    Sprite{QImage("../Sprites/P2/P2_Corps_SFrappeLourde2.png"), QImage("../Sprites/P2/P2_Bras_SFrappeLourde2.png"), 10},
    Sprite{QImage("../Sprites/P2/P2_Corps_SFrappeLourde3.png"), QImage("../Sprites/P2/P2_Bras_SFrappeLourde3.png"), 30},
    Sprite{QImage("../Sprites/P2/P2_Corps_SFrappeLourde4.png"), QImage("../Sprites/P2/P2_Bras_SFrappeLourde4.png"), 50},
    Sprite{QImage("../Sprites/P2/P2_Corps_SFrappeLourde5.png"), QImage("../Sprites/P2/P2_Bras_SFrappeLourde5.png"), 70},
    Sprite{QImage("../Sprites/P2/P2_Corps_SFrappeLourde2.png"), QImage("../Sprites/P2/P2_Bras_SFrappeLourde2.png"), 90}
};

list<Sprite> perso2_idle{
    Sprite{QImage("../Sprites/P2/P2_Corps_Idle1.png"), QImage("../Sprites/P2/P2_Bras_Idle1.png"), 0},
    Sprite{QImage("../Sprites/P2/P2_Corps_Idle2.png"), QImage("../Sprites/P2/P2_Bras_Idle2.png"), 60}
};

list<Sprite> perso2_crouch{
    Sprite{QImage("../Sprites/P2/P2_Corps_Accroupissage1.png"), QImage("../Sprites/P2/P2_Bras_Idle1.png"), 0},
    Sprite{QImage("../Sprites/P2/P2_Corps_Accroupissage2.png"), QImage("../Sprites/P2/P2_Bras_Idle1.png"), 10},
    Sprite{QImage("../Sprites/P2/P2_Corps_Accroupissage3.png"), QImage("../Sprites/P2/P2_Bras_Idle1.png"), 20},
    Sprite{QImage("../Sprites/P2/P2_Corps_Accroupissage4.png"), QImage("../Sprites/P2/P2_Bras_Idle1.png"), 30},
    Sprite{QImage("../Sprites/P2/P2_Corps_Accroupissage5.png"), QImage("../Sprites/P2/P2_Bras_Idle1.png"), 40},
    Sprite{QImage("../Sprites/P2/P2_Corps_Accroupissage6.png"), QImage("../Sprites/P2/P2_Bras_Idle1.png"), 50},
    Sprite{QImage("../Sprites/P2/P2_Corps_Accroupissage7.png"), QImage("../Sprites/P2/P2_Bras_Idle1.png"), 60}
};

list<Sprite> perso2_move{
    Sprite{QImage("../Sprites/P2/P2_Corps_Marche1.png"), QImage("../Sprites/P2/P2_Bras_Idle1.png"), 0},
    Sprite{QImage("../Sprites/P2/P2_Corps_Marche2.png"), QImage("../Sprites/P2/P2_Bras_Idle1.png"), 10},
    Sprite{QImage("../Sprites/P2/P2_Corps_Marche3.png"), QImage("../Sprites/P2/P2_Bras_Idle1.png"), 20},
    Sprite{QImage("../Sprites/P2/P2_Corps_Marche4.png"), QImage("../Sprites/P2/P2_Bras_Idle1.png"), 40},
    Sprite{QImage("../Sprites/P2/P2_Corps_Marche5.png"), QImage("../Sprites/P2/P2_Bras_Idle1.png"), 60}
};

list<Sprite> perso2_jump{
    Sprite{QImage("../Sprites/P2/P2_Corps_Saut1.png"), QImage("../Sprites/P2/P2_Bras_Idle1.png"), 0},
    Sprite{QImage("../Sprites/P2/P2_Corps_Saut2.png"), QImage("../Sprites/P2/P2_Bras_Idle1.png"), 5},
    Sprite{QImage("../Sprites/P2/P2_Corps_Saut3.png"), QImage("../Sprites/P2/P2_Bras_Idle1.png"), 10},
    Sprite{QImage("../Sprites/P2/P2_Corps_Saut4.png"), QImage("../Sprites/P2/P2_Bras_Idle1.png"), 20},
    Sprite{QImage("../Sprites/P2/P2_Corps_Saut5.png"), QImage("../Sprites/P2/P2_Bras_Idle1.png"), 100},
    Sprite{QImage("../Sprites/P2/P2_Corps_Saut6.png"), QImage("../Sprites/P2/P2_Bras_Idle1.png"), 140}
};

list<Sprite> perso2_strong_crouch{
    Sprite{QImage("../Sprites/P2/P2_Corps_AFrappeLourde1.png"), QImage("../Sprites/P2/P2_Bras_AFrappeLourde1.png"), 0},
    Sprite{QImage("../Sprites/P2/P2_Corps_AFrappeLourde2.png"), QImage("../Sprites/P2/P2_Bras_AFrappeLourde2.png"), 50},
    Sprite{QImage("../Sprites/P2/P2_Corps_AFrappeLourde4.png"), QImage("../Sprites/P2/P2_Bras_AFrappeLourde4.png"), 110},
    Sprite{QImage("../Sprites/P2/P2_Corps_AFrappeLourde5.png"), QImage("../Sprites/P2/P2_Bras_AFrappeLourde5.png"), 120},
    Sprite{QImage("../Sprites/P2/P2_Corps_AFrappeLourde6.png"), QImage("../Sprites/P2/P2_Bras_AFrappeLourde6.png"), 140},
    Sprite{QImage("../Sprites/P2/P2_Corps_AFrappeLourde7.png"), QImage("../Sprites/P2/P2_Bras_AFrappeLourde7.png"), 150},
    Sprite{QImage("../Sprites/P2/P2_Corps_AFrappeLourde8.png"), QImage("../Sprites/P2/P2_Bras_AFrappeLourde8.png"), 190},
    Sprite{QImage("../Sprites/P2/P2_Corps_AFrappeLourde9.png"), QImage("../Sprites/P2/P2_Bras_AFrappeLourde9.png"), 220}
};

Caracter perso2{
            perso2_light,
            QRect(0, 100, 150, 50),
            3,
            110,

            perso2_strong,
            QRect(0, 150, 150, 100),
            6,
            250,



            perso2_light,
            QRect(0, 100, 150, 50),
            3,
            50,

            perso2_strong_jump,
            QRect(0, 100, 150, 50),
            4,
            100,

            perso2_light_crouch,
            QRect(45, 302, 150, 50),
            5,
            110,

            perso2_strong_crouch,
            QRect(0, 330, 150, 50),
            6,
            250,

            perso2_idle,
            perso2_move,
            perso2_jump,
            perso2_crouch,
            1,
            80,
            10,
            20
};


