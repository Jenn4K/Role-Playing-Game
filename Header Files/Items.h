#ifndef ITEMS_H
#define ITEMS_H

#include <iostream>
#include <string>

//Main Class

class Item {
    protected:
        std::string name;                       //item's name
        int cost;                               //item's cost
        int minLevel;                           //minimum level to unlock item
    public:
        Item(std::string, int, int);
        int get_cost();                         //return's item's cost
        int get_unlock_level();                 //return's item's minLevel
        std::string get_name();                 //returns Item's name
        virtual int get_damage();               //in case we have pointer to base class
        virtual int get_IF_used();
        virtual int get_rate();
        virtual int get_reduction();
        virtual int get_min_magicL();
        virtual int get_hand_control();
        virtual std::string get_classType() = 0;
        virtual int Damage();
        virtual void set_damage(int);
        virtual ~Item();
};

//Derived Classes

class Weapon : public Item {
    private:
        int damage;                             //amount of damage caused using this weapon
        int handControl;                        //0: needs both hands | 1: can be used with one hand
    public:
        Weapon(std::string, int, int, int, int);
        int get_damage();                       //returns the amount of damage this weapon causes
        int get_hand_control();                 //shows if the weapon is to be used with one or both hands
        std::string get_classType();            //returns the Type of Class
        void set_damage(int);                   //changes the value of damage
        ~Weapon();
};

class Potion : public Item {
    private:
        int statisticsRI;                        //rate of statistics increase
    public:
        Potion(std::string, int, int, int);
        int get_rate();                         //returns the rate of statistics increase
        std::string get_classType();            //returns the Type of Class
        ~Potion();
};

class Armor : public Item {
    private:
        int damageRP;                         //damage reduction percentage
    public:
        Armor(std::string, int, int, int);
        int get_reduction();                 //returns the reduction percentagece
        std::string get_classType();         //returns the Type of Class
        ~Armor();
};

#endif
