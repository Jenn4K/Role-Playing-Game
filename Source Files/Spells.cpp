#include <iostream>
#include <string>

#include "Spells.h"


using namespace std;

// Class Spell
Spell::Spell(string n, int c, int minLvl, int loss, int minLevel)
                : name(n) ,cost(c) ,minLevel(minLvl), damage(loss), minMagicPower(minLevel) {}

int Spell::get_min_magicP(){
    return this->minMagicPower;
}

int Spell::get_damage(){
    return this->damage;
}

int Spell::get_cost(){
    return this->cost;
}

int Spell::get_unlock_level(){
    return this->minLevel;
}

string Spell::get_name(){
    return this->name;
}

void Spell::set_damage(int damage){
    this->damage = this->damage + damage;
}

Spell::~Spell(){}

//___________________________________________________________________________//

// Class IceSpell
IceSpell::IceSpell(string n, int c, int minLvl, int loss, int minLevel, int r)
                    : Spell(n,c,minLvl,loss,minLevel), reduction(r) {}

int IceSpell::get_reduction(){
    return this->reduction;
}

string IceSpell::get_classType(){
    return "IceSpell";
}

IceSpell::~IceSpell(){}

//___________________________________________________________________________//

//Class FireSpell
FireSpell::FireSpell(string n, int c, int minLvl, int loss, int minLevel, int r)
                    : Spell(n,c,minLvl,loss,minLevel), reduction(r) {}

int FireSpell::get_reduction(){         //reduction of Monster's defence rate
    return this->reduction;
}

string FireSpell::get_classType(){
    return "FireSpell";
}

FireSpell::~FireSpell(){}

//___________________________________________________________________________//

//Class LightingSpell
LightingSpell::LightingSpell(string n, int c, int minLvl, int loss, int minLevel, int r)
                            : Spell(n,c,minLvl,loss,minLevel), reduction(r) {}

int LightingSpell::get_reduction(){     //reduction of Monster's attack rate
    return this->reduction;
}

string LightingSpell::get_classType(){
    return "LightingSpell";
}

LightingSpell::~LightingSpell(){}
