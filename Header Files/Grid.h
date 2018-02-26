#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <string>
#include <list>
#include <ctime>

#include "Market.h"

#define LENGTH 8                                                                //size of Grid is defined here
#define WIDTH 8


class Grid{
    private:
        int **Map;
        Market *myMarket;
        int location;                                                           //will be displayed as one number as current LENGTH*10 + current WIDTH
        int last_location;
        int play;
        std::list <Monster*> Dragons;
        std::list <Monster*> Spirits;
        std::list <Monster*> Exoskeletons;
        std::list <Monster*> myMonsters;                                        //monsters in each square
    public:
        explicit Grid(Market*);                                                 //constructor
        void move();                                                            //functions to move over Map
        void replay_move();
        int move_forward();
        int move_backwards();
        int move_left();
        int move_right();
        void show_location();
        void Display_Map();                                                     //desplaying Map
        void display_status();                                                  //desplaying Statistics of Heroes or Monsters
        void display_monsterStatus();
        void display_monsterStatus(std::string);
        void display_heroStatus();
        void display_heroStatus(std::string);
        void Insert_Dragon( std::string, int, int, int, int, int );             //Inserting Monsters from files
        void Insert_Spirit( std::string, int, int, int, int, int );
        void Insert_Exoskeleton( std::string, int, int, int, int, int );
        void Fight();
        void attack(std::string);
        int H_TotalPower();                                                     //counting Team's total Health Power
        int M_TotalPower();
        void get_standarBonus(std::string);                                     //gives bonus depending if you are during a battle, walking around, winning or losing
        void gameplay();                                                        //game starts here
        void castSpell(std::string);
        void quitGame();                                                        //exiting game
        void BasicInfo();                                                       //prints the basic information about the gameplay
        void print_effects(int);
        ~Grid();                                                                //destructor
};

#endif
