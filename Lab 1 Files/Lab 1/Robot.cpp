#include "Robot.h"



    Robot::Robot(string name, int max_HP, int HP, int strength, int speed, int magic)
    : Fighter(name, max_HP, HP, strength, speed, magic)
        {
             energy = 2.0 * magic;
             max_energy = 2.0 * magic;
             bonus_damage = 0;
        }




/*
*	reset()
*
*	Restores a fighter's current hit points to its maximum hit points.
*
*	Robot:
*	Also restores a Robot's current energy to its maximum value (which is 2 times its magic).
*	Also resets a Robot's bonus damage (calculated when a Robot uses its ability) to 0.
*
*	Archer:
*	Also resets an Archer's current speed to its original value.
*
*	Cleric:
*	Also restores a Cleric's current mana to its maximum value (which is 5 times its magic).
*/
    void Robot::reset()
    {
        HP = max_HP;

        energy = max_energy;

        bonus_damage = 0;

    }










/*
*	useAbility()
*
*	Attempts to perform a special ability based on the type of fighter.  The
*	fighter will attempt to use this special ability just prior to attacking
*	every turn.
*
*	Robot: Shockwave Punch
*	Adds bonus damage to the Robot's next attack (and only its next attack) equal to (strength  * ((current_energy/maximum_energy)^4)).
*	Can only be used if the Robot has at least [ROBOT_ABILITY_COST] energy.
*	Decreases the Robot's current energy by [ROBOT_ABILITY_COST] (after calculating the additional damage) when used.
*		Examples:
*		strength=20, current_energy=20, maximum_energy=20		=> bonus_damage=20
*		strength=20, current_energy=15, maximum_energy=20		=> bonus_damage=6
*		strength=20, current_energy=10, maximum_energy=20		=> bonus_damage=1
*		strength=20, current_energy=5,  maximum_energy=20		=> bonus_damage=0
*	Robot Note:
*	The bonus damage formula should be computed using double arithmetic, and only
*	the final result should be cast into an integer.
*
*	Archer: Quickstep
*	Increases the Archer's speed by one point each time the ability is used.
*	This bonus lasts until the reset() method is used.
*	This ability always works; there is no maximum bonus speed.
*
*	Cleric: Healing Light
*	Increases the Cleric's current hit points by an amount equal to one third of its magic.
*	Can only be used if the Cleric has at least [CLERIC_ABILITY_COST] mana.
*	Will be used even if the Cleric's current HP is equal to their maximum HP.
*	Decreases the Cleric's current mana by [CLERIC_ABILITY_COST] when used.
*	Cleric Note:
*	This ability, when successful, must increase the Cleric's current hit points
*	by at least one, unless doing so would given the Cleric more hit points than its maximum hit points.
*	Do not allow the current hit points to exceed the maximum hit points.
*
*	Return true if the ability was used; false otherwise.
*/

//DIFFERENT FOR EVERY FIGHTER

bool Robot::useAbility() //FINISHED
{
    if (energy >= ROBOT_ABILITY_COST)
    {
        bonus_damage = bonus_damage + ( (double)strength * pow(((double)energy / max_energy ),4));

        energy = energy - ROBOT_ABILITY_COST;

        return true;
    }
    else
    {
        return false;
    }

}









/*
 *	getDamage()
 *
 *	Returns the amount of damage a fighter will deal.
 *
 *	Robot:
 *	This value is equal to the Robot's strength plus any additional damage added for having just used its special ability.
 *
 *	Archer:
 *	This value is equal to the Archer's speed.
 *
 *	Cleric:
 *	This value is equal to the Cleric's magic.
 */

//DIFFERENT FOR EVERY FIGHTER

int Robot::getDamage()
{
    int ouch;

    ouch = strength + bonus_damage; //additional damage
    bonus_damage = 0;

    return ouch;
}





