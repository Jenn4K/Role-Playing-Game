#include <iostream>
#include <string>

#define RST  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

#define FRED(x) KRED x RST
#define FGRN(x) KGRN x RST
#define FYEL(x) KYEL x RST
#define FBLU(x) KBLU x RST
#define FMAG(x) KMAG x RST
#define FCYN(x) KCYN x RST
#define FWHT(x) KWHT x RST

#define BOLD(x) "\x1B[1m" x RST
#define UNDL(x) "\x1B[4m" x RST

#include "Livings.h"


using namespace std;

//Class Living
Living::Living(string n)
                : name(n), level(1), healthPower(200) {}         //starting from level 1

string Living::get_name(){
    return this->name;
}

Living::Living(string n, int lev)
            :name(n), level(lev), healthPower(200) {}


int Living::get_healthP(){
    if(this->healthPower < 0)
        this->healthPower = 0;
    return this->healthPower;
}

int Living::get_level(){
    return this->level;
}

void Living::decrease_healthP(int num){
    this->healthPower = healthPower - num;
}

Living::~Living(){}

//___________________________________________________________________________//

// Class Hero
Hero::Hero(string n,
            int magicP, int str, int ag, int dext, int m, int exp)

                : Living(n), magicPower(magicP), strength(str),
                  agility(ag), dexterity(dext), money(m), experience(exp) {}

void Hero::set_strength(int plus){
    this->strength += plus;
}

void Hero::set_agility(int plus){
    this->agility += ((this->agility * plus)/100);
}

void Hero::set_dexterity(int plus){
    this->dexterity += plus;
}

void Hero::set_magicPower(int plus){
    this->magicPower += plus;
}

void Hero::set_money(int plus){
    this->money += plus;
}

void Hero::set_experience(int plus){
    this->experience += plus;
}

void Hero::set_healthP(int plus){
    this->healthPower += plus;
}

std::string Hero::get_classType(){
    return "Hero";
}

int Hero::get_magicPower(){
    return this->magicPower;
}

int Hero::get_money(){
    return this->money;
}

int Hero::get_strength(){
    return this->strength;
}

int Hero::get_agility(){
    return this->agility;
}

int Hero::get_dexterity(){
    return this->dexterity;
}

int Hero::get_experience(){
    return this->experience;
}

int Hero::get_healthP(){
    if(this->healthPower < 0)
        this->healthPower = 0;
    return this->healthPower;
}

void Hero::decrease_magicP(int decr){
    //decr = spell->get_min_magicP
    this->magicPower = this->magicPower - decr;
}

void Hero::decrease_healthP(int num){
    this->healthPower = this->healthPower - num;
}

//Hero buys an Item / Spell from Market
void Hero::buy(Item* item){
    this->money = (this->money - item->get_cost());
    Items.push_back(item);                              //adding Item to hero's list
}

//Hero sells an Item / Spell to Market
void Hero::sell(Item* item){
    this->money = this->money + (item->get_cost()/2);   //heroes can sell their Items on half price
    list <Item*> :: iterator it;

    for(it = Items.begin(); it!=Items.end(); ++it){    //erase Item from Hero's List
        if(item->get_name() == (*it)->get_name()){
            it = Items.erase(it);
            break;
        }
    }
}

void Hero::buy(Spell* spell){

    this->money = this->money - spell->get_cost();
    Spells.push_back(spell);                    //adding spell to hero's list

    set_dexterity(spell->get_damage());         //spells upgrade hero's strength
    int damage = this->get_level()/100;
    spell->set_damage(damage);                  //the damage a Spell can cause depents on hero's level
}

void Hero::sell(Spell* spell){

    this->money = this->money + (spell->get_cost()/2);   //heroes can sell their Spells on half price
    list <Spell*> :: iterator it;

    for(it = Spells.begin(); it!=Spells.end(); ++it){   //erase Spell from Hero's List
        if(spell->get_name() == (*it)->get_name()){
            it = Spells.erase(it);
            break;
        }
    }
}

//Searching for a specific Item / Spell
//And returnig the object itself
Item* Hero::Search_Items(string name){
    list <Item*> :: iterator it;

    for(it = Items.begin(); it!=Items.end(); ++it){
        if ((*it)->get_name() == name)
            return *it;
    }
    cout << "No valid Name. Please Try Again." << endl;
    return NULL;
}

Spell* Hero::Search_Spells(string name){
    list <Spell*> :: iterator it;

    for(it = Spells.begin(); it!=Spells.end(); ++it){
        if ((*it)->get_name() == name)
            return *it;
    }
    cout << "No valid Name. Please Try Again." << endl;
    return NULL;
}

//Displaying Hero's Invetory
void Hero::checkInvetory(){

    if((Items.empty()) && (Spells.empty())){
        cout << "Empty" << endl;
        return;
    }

    list <Item*> :: iterator ti;
    cout << " Items bought" << endl;
    cout << "***************" << endl;
    cout << "Type of Item" << "\t\t" << "Name" << "\t\t\t" << "Cost" << "\t   " << "Unlock Level" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    for(ti = Items.begin(); ti!=Items.end(); ++ti)
        cout << (*ti)->get_classType() << "\t\t\t" << (*ti)->get_name() << "\t\t\t " << (*ti)->get_cost() << "\t\t" << (*ti)->get_unlock_level() << endl;
    cout << endl <<endl;

    list <Spell*> :: iterator it;
    cout << " Spells bought" << endl;
    cout << "****************" << endl;
    cout << "Type of Spell" << "\t\t" << "Name" << "\t\t\t" << "Cost" << "\t   " << "Unlock Level" << "\t\t" << endl;
    cout << "----------------------------------------------------------------------------------" << endl;
    for(it = Spells.begin(); it!=Spells.end(); ++it)
        cout << (*it)->get_classType() << "\t\t" << (*it)->get_name() << "\t\t" << (*it)->get_cost() << "\t\t" << (*it)->get_unlock_level() << endl;
    cout << endl;
}

//Displaying either Spells or Items, Hero owns
void Hero::checkInvetory(string s){
    cout << endl << endl;
    if(s == "item"){

        if(Items.empty()){
            cout << "You haven't bought any items yet!"  << endl << endl;
            return;
        }

        list <Item*> :: iterator ti;
        cout << " Items bought" << endl;
        cout << "***************" << endl;
        cout << "Type of Item" << "\t\t" << "Name" << "\t\t\t" << "Cost" << "\t   " << "Unlock Level" << endl;
        cout << "---------------------------------------------------------------------------" << endl;
        for(ti = Items.begin(); ti!=Items.end(); ++ti)
            cout << (*ti)->get_classType() << "\t\t\t" << (*ti)->get_name() << "\t\t\t " << (*ti)->get_cost() << "\t\t" << (*ti)->get_unlock_level() << endl;
        cout << endl <<endl;

    }
    else if(s == "spell"){

        if(Spells.empty()){
            cout << "You haven't bought any spells yet!" << endl << endl;
            return;
        }

        list <Spell*> :: iterator it;
        cout << " Spells bought" << endl;
        cout << "****************" << endl;
        cout << "Type of Spell" << "\t\t" << "Name" << "\t\t\t" << "Cost" << "\t   " << "Unlock Level" << "\t\t" << "Damage" << endl;
        cout << "--------------------------------------------------------------------------------------------" << endl;
        for(it = Spells.begin(); it!=Spells.end(); ++it)
            cout << (*it)->get_classType() << "\t\t" << (*it)->get_name() << "\t\t" << (*it)->get_cost() << "\t\t" << (*it)->get_unlock_level() << "\t\t" << (*it)->get_damage() << endl;
        cout << endl;

    }
}

//Catching a Typo
string Hero::searchInvetory(string name){
    string ch_name;
    int found = 0;

    list <Item*> :: iterator it;
    for(it = Items.begin(); it!=Items.end(); ++it){
        if ((*it)->get_name() == name)
            return name;
    }

    list <Spell*> :: iterator ti;
    for(ti = Spells.begin(); ti!=Spells.end(); ++ti){
        if ((*ti)->get_name() == name)
            return name;
    }

    while (found == 0){
        cout << "Wrong Name. Please try again." << endl;
        string n;
        cin >> n;

        for(it = Items.begin(); it!=Items.end(); ++it){
            if ((*it)->get_name() == n){
                ch_name = n;
                found = 1;
                break;
            }
        }

        for(ti = Spells.begin(); ti!=Spells.end(); ++ti){
            if ((*ti)->get_name() == n){
                ch_name = n;
                found = 1;
                break;
            }
        }
    }
    return ch_name;
}

//Equiping an Item from Invetory
//For the Hero to use on a Fight
void Hero::equip(string name){
    name = searchInvetory(name);

    Item *item = Search_Items(name);
    if(item->get_classType() == "Weapon")
        item->set_damage(this->get_strength());     //Hero's strength is added to Weapons damage
    else
        this->set_agility(item->get_reduction());   //Armors increase hero's agility
    cout << "\t\t\t\t\t\t\t" << item->get_name() << " " << "just equiped" << endl;
}

void Hero::equip(){
    if(checkIFempty("Items") == 1){
        cout << endl << endl << KRED << "\t\t\t\t\t\t\t W A R N I N G! " << KWHT << endl << endl;
        cout << "\t\t\t\t\tYou haven't bought any items yet, use your fist to attack" << endl;
        return;
    }
    int flag = 0;
    while(flag == 0){
        checkInvetory("item");
        cout << "Press 1 to change Weapon" << endl;
        cout << "Press 2 to change Armor" << endl;
        cout << "Press 3 to do both" << endl;
        string in;
        cin >> in;
        if(in == "1"){
            if(checkIFempty("Weapon") == 1){
                cout << endl << endl << KRED << "\t\t\t\t\t\t\t W A R N I N G! " << KWHT << endl << endl;
                cout << "\t\t\t\t\tYou haven't bought any Weapons yet, equip something else or use your fist to attack" << endl;
                return;
            }
            flag = 1;
            cout << endl << "Enter the Name of Weapon" << endl;
            string name;
            cin >> name;
            this->equip(name);
        }
        else if(in == "2"){
            if(checkIFempty("Armor") == 1){
                cout << endl << endl << KRED << "\t\t\t\t\t\t\t W A R N I N G! " << KWHT << endl << endl;
                cout << "\t\t\t\t\tYou haven't bought any Armors yet, equip something else or use your fist to attack" << endl;
                return;
            }
            flag = 1;
            cout << endl << "Enter the Name of Armor" << endl;
            string name;
            cin >> name;
            this->equip(name);
        }
        else if (in == "3"){
            flag = 1;
            string name;
            if(checkIFempty("Weapon") != 1){
                cout << endl << "Enter the Name of Weapon" << endl;
                cin >> name;
                this->equip(name);
            }
            if(checkIFempty("Armor") != 1){
                cout << endl << "Enter the Name of Armor" << endl;
                cin >> name;
                this->equip(name);
            }
        }
        else{
            cout << "Did you made a Typo? Please try again." << endl;
        }
    }
}

//Using a Potion from Invetory
//For Hero to increase his Statistics
//Potions can be used only once
//So they get erased after use
void Hero::use(string name){
    Item *item = Search_Items(name);

    list <Item*> :: iterator it;
    for(it = Items.begin(); it!=Items.end(); ++it){
        if(item->get_name() == (*it)->get_name()){
            cout << endl << "\t\t\t\tRemember Potions can be used only one time. "<< item->get_name() << " will be erased from your Invetory." << endl;

            if((*it)->get_name() == "Healing_Potion"){
                this->set_healthP((*it)->get_rate());
                if( this->get_healthP() > 200)
                    this->set_healthP(200);
            }
            if((*it)->get_name() == "Strength_Potion"){
                this->set_strength((*it)->get_rate());
            }
            if((*it)->get_name() == "Magic_Potion"){
                this->set_magicPower((*it)->get_rate());
            }
            if((*it)->get_name() == "Luck_Elixir"){
                this->set_agility((*it)->get_rate());
                this->set_dexterity((*it)->get_rate()/5);
            }
            if((*it)->get_name() == "Mermaid_Tears"){
                this->set_strength((*it)->get_rate());
                this->set_agility((*it)->get_rate()/2);
                this->set_dexterity((*it)->get_rate()/5);
            }
            if((*it)->get_name() == "Ambrosia"){
            this->set_healthP((*it)->get_rate());
                if( this->get_healthP() > 200)
                    this->set_healthP(200);

                this->set_strength((*it)->get_rate()/2);
                this->set_agility((*it)->get_rate()/5);
                this->set_dexterity((*it)->get_rate()/5);
            }

            it = Items.erase(it);
            break;
        }
    }
}

void Hero::use(){
    if(checkIFempty("Potion") == 1){
        cout << endl << endl << KRED << "\t\t\t\t\t\t\t W A R N I N G! " << KWHT << endl << endl;
        cout << "\t\t\t\t\tYou haven't bought any Potions yet, use your fist to attack" << endl;
        return;
    }
    checkInvetory("item");
    cout << endl << "Enter the Name of Potion" << endl;
    string name;
    cin >> name;
    name = searchInvetory(name);
    this->use(name);
}

//Using a Spell from Invetory
//For Hero to use on a Fight
Spell* Hero::castSpell(string name){
    Spell *spell = Search_Spells(name);

    this->magicPower -= spell->get_min_magicP();        //Magic Power decreases after using a Spell
    return spell;
}

Spell* Hero::castSpell(){
    if(checkIFempty("Spells") == 1){
        cout << endl << endl << KRED << "\t\t\t\t\t\t\t W A R N I N G! " << KWHT << endl << endl;
        cout << "\t\t\t\t\tYou haven't bought any spells yet, use your fist to attack" << endl;
        return NULL;
    }
    checkInvetory("spell");
    cout << endl << "Enter the Name of Spell" << endl;
    string name;
    cin >> name;
    name = searchInvetory(name);
    return this->castSpell(name);
}

//Checking if Hero tries to use an Item/Spell
//that he hasn't bought yet
int Hero::checkIFempty(string Type){
    if(Type == "Items"){
        if(Items.empty())   return 1;
    }
    else if(Type == "Spells"){
        if(Spells.empty())  return 1;
    }
    else if(Type == "Potion"){
        int sum = 0;
        list <Item*> :: iterator it;
        for(it = Items.begin(); it!=Items.end(); ++it){
            if ((*it)->get_classType() == "Potion")
                sum++;
        }
        if(sum == 0)    return 1;
    }
    else if(Type == "Weapon"){
        int sum = 0;
        list <Item*> :: iterator it;
        for(it = Items.begin(); it!=Items.end(); ++it){
            if ((*it)->get_classType() == "Weapon")
                sum++;
        }
        if(sum == 0)    return 1;
    }
    else if(Type == "Armor"){
        int sum = 0;
        list <Item*> :: iterator it;
        for(it = Items.begin(); it!=Items.end(); ++it){
            if ((*it)->get_classType() == "Armor")
                sum++;
        }
        if(sum == 0)    return 1;
    }
    return 0;
}

Hero::~Hero(){}

//___________________________________________________________________________//

//Class Warrior
Warrior::Warrior(string n,
         int magicP, int str, int ag, int dext, int m, int exp)

         : Hero(n,magicP,str,ag,dext,m,exp) {}

void Warrior::levelUp(){

    cout << "\t\t\t\t " << this->name << " just  L E V E L E D   U P!" << endl << endl << endl;
    if(this->level >= 10)
        this->level = 3;
    else
        this->level++;
}

string Warrior::get_classType(){
    return "Warrior";
}

Warrior::~Warrior() {}

//___________________________________________________________________________//

//Class Sorcerer
Sorcerer::Sorcerer(string n,
         int magicP, int str, int ag, int dext, int m, int exp)

         : Hero(n,magicP,str,ag,dext,m,exp) {}

void Sorcerer::levelUp(){

    cout << "\t\t\t\t " << this->name << " just  L E V E L E D   U P!" << endl << endl << endl;
    if(this->level >= 10)
        this->level = 3;
    else
        this->level++;
}

string Sorcerer::get_classType(){
    return "Sorcerer";
}

Sorcerer::~Sorcerer() {}

//Class Paladin
Paladin::Paladin(string n,
         int magicP, int str, int ag, int dext, int m, int exp)

         : Hero(n,magicP,str,ag,dext,m,exp) {}

void Paladin::levelUp(){

    cout << "\t\t\t\t " << this->name << " just  L E V E L E D   U P!" << endl << endl << endl;
    if(this->level >= 10)
        this->level = 3;
    else
        this->level++;
}

string Paladin::get_classType(){
    return "Paladin";
}

Paladin::~Paladin() {}
