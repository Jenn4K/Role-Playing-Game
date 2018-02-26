#ifndef SPELLS_H
#define SPELLS_H

#include <iostream>
#include <string>

class Spell {
    protected:
        std::string name;                   //item's name
        int cost;                           //item's cost
        int minLevel;                       //minimum level to unlock item
        int damage;                         //amount of damage caused using Spell
        int minMagicPower;                  //minimum magic power needed to use Spell
    public:
        Spell(std::string, int, int, int, int);
        int get_min_magicP();               //returns minimum magic level to unlock Spell
        int get_damage();                   //returns the amount of damage this Spell causes
        int get_cost();                     //return's item's cost
        int get_unlock_level();             //return's item's minLevel
        std::string get_name();             //returns Item's name
        void set_damage(int);               //change damage's value

        virtual int get_reduction() = 0;
        virtual std::string get_classType() = 0;   //returns the Type of Spell
        virtual ~Spell();
};

// Derived Classes

class IceSpell : public Spell{
    private:
        int reduction;          //value of Monster's attack rate reduction
    public:
        IceSpell(std::string, int, int, int, int, int);
        int get_reduction();
        std::string get_classType();
        ~IceSpell();
};

class FireSpell : public Spell{
    private:
        int reduction;              //value of Monster's defence rate reduction
    public:
        FireSpell(std::string, int, int, int, int, int);
        int get_reduction();
        std::string get_classType();
        ~FireSpell();
};

class LightingSpell : public Spell{
    private:
        int reduction;               //value of Monster's possibility of avoiding an attack reduction
    public:
        LightingSpell(std::string, int, int, int, int, int);
        int get_reduction();
        std::string get_classType();
        ~LightingSpell();
};

#endif
