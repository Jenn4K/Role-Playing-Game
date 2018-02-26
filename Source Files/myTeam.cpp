#include <iostream>
#include <string>
#include <list>
#include <cstdlib>
#include <iterator>

#include "myTeam.h"

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

using namespace std;

MyTeam::MyTeam(){}

//Inserting all heroes from files
//Player will choose his team later
void MyTeam::Insert_Warrior(string name, int magicP, int strength,
                         int agility, int dexterity, int money, int experience){

    Hero *NewHero = new Warrior(name,magicP,strength,agility,dexterity,money,experience);
    Warriors.push_back(NewHero);
}

void MyTeam::Insert_Sorcerers(string name,  int magicP, int strength,
                         int agility, int dexterity, int money, int experience){

    Hero *NewHero = new Sorcerer(name,magicP,strength,agility,dexterity,money,experience);
    Sorcerers.push_back(NewHero);
}

void MyTeam::Insert_Paladins(string name, int magicP, int strength,
                         int agility, int dexterity, int money, int experience){

    Hero *NewHero = new Paladin(name,magicP,strength,agility,dexterity,money,experience);
    Paladins.push_back(NewHero);
}

//Displaying Available Heroes
void MyTeam::Display_Heroes(){

    list <Hero*> :: iterator it;

    cout << " Available Warriors" << endl;
    cout << "********************" << endl << endl;
    cout << "Name" << "\t\t\t    " << "Magic Power" << "\t    " << "Health Power" << "\t" << "Strength" << "\t" << "Agility" << "\t      " << "Dexterity" << "\t     " << "Experience" << endl;
    cout << "-------------------------------------------------------------------------------------------------------------------------" << endl;
    for(it = Warriors.begin(); it!=Warriors.end(); ++it)
        cout << (*it)->get_name() << "\t\t" << (*it)->get_magicPower() << "\t\t" << (*it)->get_healthP() << "\t\t  " << (*it)->get_strength() << "\t\t  " << (*it)->get_agility() << "\t\t " << (*it)->get_dexterity() << "\t\t" << (*it)->get_experience() << endl;
    cout << endl;

    cout << " Available Sorcerers" << endl;
    cout << "*********************" << endl << endl;
    cout << "Name" << "\t\t\t    " << "Magic Power" << "\t    " << "Health Power" << "\t" << "Strength" << "\t" << "Agility" << "\t      " << "Dexterity" << "\t     " << "Experience" << endl;
    cout << "-------------------------------------------------------------------------------------------------------------------------" << endl;
    for(it = Sorcerers.begin(); it!=Sorcerers.end(); ++it)
        cout << (*it)->get_name() << "\t\t" << (*it)->get_magicPower() << "\t\t" << (*it)->get_healthP() << "\t\t  " << (*it)->get_strength() << "\t\t  " << (*it)->get_agility() << "\t\t " << (*it)->get_dexterity() << "\t\t" << (*it)->get_experience() << endl;
    cout << endl;

    cout << " Available Paladins" << endl;
    cout << "********************" << endl << endl;
    cout << "Name" << "\t\t\t    " << "Magic Power" << "\t    " << "Health Power" << "\t" << "Strength" << "\t" << "Agility" << "\t      " << "Dexterity" << "\t     " << "Experience" << endl;
    cout << "-------------------------------------------------------------------------------------------------------------------------" << endl;
    for(it = Paladins.begin(); it!=Paladins.end(); ++it)
    cout << (*it)->get_name() << "\t\t" << (*it)->get_magicPower() << "\t\t" << (*it)->get_healthP() << "\t\t  " << (*it)->get_strength() << "\t\t  " << (*it)->get_agility() << "\t\t " << (*it)->get_dexterity() << "\t\t" << (*it)->get_experience() << endl;
    cout << endl;
}

//Catching a Typo
//In case of wrong input, user will be asked to type the name again
std::string MyTeam::catch_wrongName(string name){
    string ch_name;
    list <Hero*> :: iterator it;
    int found = 0;

    for(it = Warriors.begin(); it!=Warriors.end(); ++it){
        if ((*it)->get_name() == name)
            return name;
    }

    for(it = Sorcerers.begin(); it!=Sorcerers.end(); ++it){
        if ((*it)->get_name() == name)
                return name;
    }

    for(it = Paladins.begin(); it!=Paladins.end(); ++it){
        if ((*it)->get_name() == name)
                return name;
    }
    while (found == 0){
        cout << "Wrong Name for Hero. Please try again." << endl;
        string n;
        cin >> n;
        for(it = Warriors.begin(); it!=Warriors.end(); ++it){
            if ((*it)->get_name() == n){
                ch_name = n;
                found = 1;
                break;
            }
        }

        for(it = Sorcerers.begin(); it!=Sorcerers.end(); ++it){
            if ((*it)->get_name() == n){
                ch_name = n;
                found = 1;
                break;
            }
        }

        for(it = Paladins.begin(); it!=Paladins.end(); ++it){
            if ((*it)->get_name() == n){
                ch_name = n;
                found = 1;
                break;
            }
        }
    }
    return ch_name;
}

//Searching for a specif hero.
//This function returns the object itself
Hero* MyTeam::Search_Hero(string name){
    list <Hero*> :: iterator it;

    for(it = Warriors.begin(); it!=Warriors.end(); ++it){
        if ((*it)->get_name() == name)
            return *it;
    }

    for(it = Sorcerers.begin(); it!=Sorcerers.end(); ++it){
        if ((*it)->get_name() == name)
                return *it;
    }

    for(it = Paladins.begin(); it!=Paladins.end(); ++it){
        if ((*it)->get_name() == name)
                return *it;
    }
    return NULL;
}

//Adding a Hero to Team
//User's Team cannot have more than 3 members
void MyTeam::add_player(std::string name){

    if (my_heroes.size() >= 3){
        cout << "Squads with more than 3 members are not allowed!" << endl;
        return;
    }
    else{

        Hero* hero = Search_Hero(name);                              //Searching for a specific Hero
        if (hero->get_classType() == "Warrior"){                     //Add this hero to My_Team List and return
            Hero *NewHero = new Warrior(name,hero->get_magicPower(),hero->get_strength(),hero->get_agility(),hero->get_dexterity(),hero->get_money(),hero->get_experience());
            my_heroes.push_back(NewHero);
        }
        else if(hero->get_classType() == "Sorcerer"){
            Hero *NewHero = new Sorcerer(name,hero->get_magicPower(),hero->get_strength(),hero->get_agility(),hero->get_dexterity(),hero->get_money(),hero->get_experience());
            my_heroes.push_back(NewHero);
        }
        else {
            Hero *NewHero = new Paladin(name,hero->get_magicPower(),hero->get_strength(),hero->get_agility(),hero->get_dexterity(),hero->get_money(),hero->get_experience());
            my_heroes.push_back(NewHero);
        }
    }
}

//Displaying Team Status
void MyTeam::Display_Team(){
    list <Hero*> :: iterator it;

    cout << endl << endl << BOLD(FGRN("Your Team Members:")) << endl;
    cout << "Name" << "\t\t\t    " << "Magic Power" << "\t    " << "Health Power" << "\t" << "Strength" << "\t" << "Agility" << "\t      " << "Dexterity" << "\t     " << "Experience" << endl;
    cout << "-------------------------------------------------------------------------------------------------------------------------" << endl;
    for(it = my_heroes.begin(); it!=my_heroes.end(); ++it)
    cout << (*it)->get_name() << "\t\t" << (*it)->get_magicPower() << "\t\t" << KGRN << (*it)->get_healthP() << KWHT << "\t\t  " << (*it)->get_strength() << "\t\t  " << (*it)->get_agility() << "\t\t " << (*it)->get_dexterity() << "\t\t" << (*it)->get_experience() << endl;
    cout << endl;
}

void MyTeam::Display_Team(int f){
    list <Hero*> :: iterator it;

    cout << endl << endl << BOLD(FGRN("Your Team Members:")) << endl;
    cout << "Name" << "\t\t\t        " << "Money" << endl;
    cout << "--------------------------------------------" << endl;
    for(it = my_heroes.begin(); it!=my_heroes.end(); ++it)
        cout << (*it)->get_name() << "\t\t" << (*it)->get_money() << " $" << endl;
    cout << endl;
}

//Returnig the list of User's Team members
//To iterate over them into Grid
list <Hero*> MyTeam::get_myHeroes(){
    return my_heroes;
}

//Destructor
MyTeam::~MyTeam(){
    list <Hero*> :: iterator ti;

    for(ti=Warriors.begin(); ti!=Warriors.end(); ++ti)
        delete *ti;
    for(ti=Sorcerers.begin(); ti!=Sorcerers.end(); ++ti)
        delete *ti;
    for(ti=Paladins.begin(); ti!=Paladins.end(); ++ti)
        delete *ti;
    for(ti=my_heroes.begin(); ti!=my_heroes.end(); ++ti)
        delete *ti;
}
