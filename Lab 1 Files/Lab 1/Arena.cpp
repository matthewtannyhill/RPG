#include "Arena.h"
#include "ArenaInterface.h"

#include <sstream>



            /*
            *	addFighter(string)
            *
            *	Adds a new fighter to the collection of fighters in the arena. Do not allow
            *	duplicate names.  Reject any string that does not adhere to the format
            *	outlined in the lab specs.
            *
            *	Return true if a new fighter was added; false otherwise.
            */

            bool Arena::addFighter(std::string info)
            {
                
                stringstream ss(info);
                
                string name;
                string type;
                int max_HP;
                int strength;
                int speed;
                int magic;


                int HP;
                int mana;

            
                ss >> name;
                ss >> type;
                ss >> max_HP;
                ss >> strength;
                ss >> speed;
                ss >> magic;


                if (max_HP <= 0)
                {
                    return false;
                }

                if (strength <= 0)
                {
                    return false;
                }

                if (speed <= 0)
                {
                    return false;
                }
                if (magic <= 0)
                {
                    return false;
                }




                for (int i = 0; i < currentFighters.size(); i++)
                {

                string newName = currentFighters[i]->getName();

                    if (newName == name)
                    {
                            return false;
                    }
                }



                
                if (ss.fail())
                {
                    return false;
                }
                
                if (!ss.eof())
                {
                    return false;
                }


// Archer* a =

                
                if (type == "A")
                {
                    currentFighters.push_back(new Archer(name, max_HP, HP, strength, speed, magic));
                    return true;
                }
                
                else if (type == "C")
                {
                    currentFighters.push_back(new Cleric(name, max_HP, HP, strength, speed, magic));
                    return true;
                }
                
                else if (type == "R")
                {
                    currentFighters.push_back(new Robot(name, max_HP, HP, strength, speed, magic));
                    return true;
                }
            
                return false;

            }












            /*
            *	removeFighter(string)
            *
            *	Removes the fighter whose name is equal to the given name.  Does nothing if
            *	no fighter is found with the given name.
            *
            *	Return true if a fighter is removed; false otherwise.
            */
            bool Arena::removeFighter(string name)
            {

                for (int i = 0; i < currentFighters.size(); i++)
                {
                    string newName = currentFighters[i]->getName();

                    if (newName == name)
                    {
                        currentFighters.erase(currentFighters.begin() + (i));
                        return true;
                    }

                }

                return false;
            }













            /*
            *	getFighter(string)
            *
            *	Returns the memory address of a fighter whose name is equal to the given
            *	name.  Returns NULL if no fighter is found with the given name.
            *
            *	Return a memory address if a fighter is found; NULL otherwise.
            */
            FighterInterface* Arena::getFighter(string name)
            {

                for (int i = 0; i < currentFighters.size(); i++)
                {
                    string newName = currentFighters[i]->getName();

                    if (newName == name)
                    {
                        return currentFighters[i];
                    }

                }
            }











            /*
            *	getSize()
            *
            *	Returns the number of fighters in the arena.
            *
            *	Return a non-negative integer.
            */
            int Arena::getSize() const
            {

                return currentFighters.size();
            }

