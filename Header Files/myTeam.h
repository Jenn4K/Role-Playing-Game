#ifndef MYTEAM_H
#define MYTEAM_H

#include <iostream>
#include <list>
#include <string>

#include "Livings.h"

class MyTeam{
    private:
        std::list  <Hero*> my_heroes;                //A list of Player's Team Heroes
        std:: list <Hero*> Sorcerers;                //Lists of all Heroes
        std:: list <Hero*> Warriors;
        std:: list <Hero*> Paladins;

    public:
        MyTeam();                                                           //constructor
        void Insert_Warrior(std::string,int,int,int,int,int,int);           //Inserting into Lists
        void Insert_Sorcerers(std::string,int,int,int,int,int,int);
        void Insert_Paladins(std::string,int,int,int,int,int,int);
        void add_player(std::string);                                       //add players to team
        void Display_Team();                                                //displaying team
        void Display_Team(int);
        void Display_Heroes();
        Hero* Search_Hero(std::string);
        std::string catch_wrongName(std::string);                           //checks if player typed wrong
        std::list <Hero*> get_myHeroes();                                   //returns a list of my Team
        ~MyTeam();                                                          //destructor
};

#endif
