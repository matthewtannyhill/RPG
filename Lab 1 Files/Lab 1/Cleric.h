#ifndef CLERIC_H
#define CLERIC_H

#include "Fighter.h"

/*
*	This class specifies the methods for a fighter.
*
*	All fighters have the following attributes:
*		Name - The fighter's name
*		Hit Points - The amount of health the fighter has, with a specified maximum; reaching 0 is equivalent to losing. A Fighter's
*			starting Hit Points (which is a Fighter's maximum Hit Points) must be greater than 0. There is no upper bound to what
*			a Fighter's starting/maximum Hit Points could be.
*		Strength - Physical power, used to determine hit point regeneration. Must be greater than 0. No maximum value.
*		Speed - Dexterity and physical movement, used to reduce damage when being attacked. Must be greater than 0. No maximum value.
*		Magic - Magical prowess, used for some special abilities. Must be greater than 0. No maximum value.
*
*	The three fighter types have unique abilities:
*		Robot - Relies on strength to deal damage.  Also can use stored energy to temporarily increase damage (max/starting energy equal to 2*magic).
*			Only Robots have energy.
*		Archer - Relies on speed to deal damage.  Also can increase its speed for the remainder of the battle (no max bonus speed).
*		Cleric - Relies on magic to deal damage.  Also can heal itself using mana, restoring hit points (max/starting mana equal to 5*magic).
*			Only Clerics have mana.
*
*	More details about how stats are used and how abilities work can be found in the comments below.
*/

class Cleric : public Fighter
{

protected:

    int max_mana;
    int mana;

public:
    Cleric(string name, int max_HP, int HP, int strength, int speed, int magic);

    void reset();

    bool useAbility();

    int getDamage();

    void regenerate();

};

#endif // CLERIC_H
