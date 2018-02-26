#ifndef LIVINGS_H
#define LIVINGS_H

#include <iostream>
#include <string>
#include <list>

#include "Items.h"
#include "Spells.h"

class Living {
    protected:
        std::string name;                       //Living's name
        int level;                              //Living's current level
        int healthPower;                        //Living's amount of healthPower

    public:
        explicit Living(std::string);
        Living(std::string, int);

        std::string get_name();                 //returns Living's name
        int get_level();                        //returns Living's level
        virtual int get_healthP();              //returns Living's healthP
        virtual void decrease_healthP(int);     //decreases hP during fights

        virtual void levelUp() = 0;
        virtual ~Living();
};

class Hero : public Living {
    protected:
        int magicPower;                         //Hero's amount of magicPower
        int strength, agility , dexterity;      //Hero's fighting skills
        int money;                              //Hero's collected so far
        int experience;                         //Hero's experience level

        std:: list <Item*> Items;               //Hero's Lists of Items and Spells
        std:: list <Spell*> Spells;

    public:
        Hero(std::string, int, int, int, int, int, int);
        virtual void levelUp() = 0;              //upgrating Hero
        virtual std::string get_classType();     //getting the type of Class

        void set_strength(int);                  //Mutators
        void set_agility(int);
        void set_dexterity(int);
        void set_magicPower(int);
        void set_money(int);
        void set_experience(int);
        void set_healthP(int);

        int get_magicPower();                    //Accessors
        int get_healthP();
        int get_money();
        int get_strength();
        int get_agility();
        int get_dexterity();
        int get_experience();

        void decrease_magicP(int);
        void decrease_healthP(int);
        void buy(Item*);                            //buying an Item
        void buy(Spell*);                           //buying a Spells
        void sell(Item*);                           //selling an Item
        void sell(Spell*);                          //selling a Spell
        Item* Search_Items(std::string);            //searching for a specific item in Invetory
        Spell* Search_Spells(std::string);          //searching for a specific spell in Invetory
        void checkInvetory();                       //displaying Hero's Items and Spells
        void checkInvetory(std::string);            //display either spell or item accordind to the string
        std::string searchInvetory(std::string);
        void equip(std::string);                    //changing weapon
        void equip();
        void use(std::string);                      //using a potion
        void use();
        Spell* castSpell();                         //casting a Spell
        Spell* castSpell(std::string);
        int checkIFempty(std::string);              //Checking for a specific Type of Items/Spells
        virtual ~Hero();
};

//Derived Classes

class Warrior : public Hero {
    public:
        Warrior(std::string, int, int, int, int, int, int);
        void levelUp();
        std::string get_classType();
        ~Warrior();
};

class Sorcerer : public Hero {
    public:
        Sorcerer(std::string, int, int, int, int, int, int);
        void levelUp();
        std::string get_classType();
        ~Sorcerer();
};

class Paladin : public Hero {
    public:
        Paladin(std::string, int, int, int, int, int, int);
        void levelUp();
        std::string get_classType();
        ~Paladin();
};

class Monster : public Living {
    protected:
        int damage;                                 //amount of damage this monster can cause
        int defence;                                //Monster's defence amount
        int attack_AP;                              //Monster's possibility of avoiding an attack
        int damage_range;                           //Monster's damage range
    public:
        Monster(std::string, int, int, int, int, int);
        int get_damage();                           //returns monster's damage
        int get_defence();
        int get_attackAP();
        int get_damageRange();
        virtual void levelUp() = 0;
        void decrease_damage(int);                  //decrease Monster's damage
        void reduce_damageR(int);                   //reduces Monster's damage range
        void reduce_defence(int);                   //reduces Monster's defence
        void reduce_attackAP(int);                  //reduces Monster's possibility of avoiding an attack
        void Attacked(Spell*);                      //Monster got attacked by a hero
        virtual ~Monster();
};

class Dragon : public Monster {
    public:
        Dragon(std::string, int,int, int, int, int);
        void levelUp(){}
        ~Dragon();
};

class Exoskeleton : public Monster {
    public:
        Exoskeleton(std::string, int, int, int, int, int);
        void levelUp(){}
        ~Exoskeleton();
};

class Spirit : public Monster {
    public:
        Spirit(std::string, int, int, int, int, int);
        void levelUp(){}
        ~Spirit();
};

#endif
