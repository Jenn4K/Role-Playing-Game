#include <iostream>
#include <string>
#include <list>
#include <ctime>
#include <cstdlib>
#include <iterator>

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

#include "Grid.h"

using namespace std;

//Constructing an 2D array, which will be our Grid
//Firstly we initialise it radomly with 3 int values: 0, 1 or 2
//0: Common
//1: Market
//2: Non Accessible
Grid::Grid(Market *M){
    Map = new int*[LENGTH];                   //LENGTH and WIDTH are defined in header File
    for( int i = 0; i < LENGTH; i++)
        Map[i] = new int[WIDTH];

    for( int i = 0; i < LENGTH; i++ ){
        for(int j = 0; j < WIDTH; j++ ){
            int possibility = rand()%100+1;
            if(possibility <=20){             //possibility 20% to have a Non Accessible Block
                if((i>0)&&(j>0) && ((Map[i-1][j-1]==2) || (Map[i-1][j]==2) || (Map[i-1][j+1]==2)))
                    Map[i][j] = 0;           //if there are too many Non Accessible Blocks in area, construct a Common Block
                else
                    Map[i][j] = 2;
            }
            else if(possibility <=50)        //possibility 30% to have a Market
                Map[i][j] = 1;
            else
                Map[i][j] = 0;               //possibility 50% to have a Common Block

            if(((i==0) && (j==1)) || ((i==1) && (j==0)))
                Map[i][j] = 1;
        }
        Map[0][0] = 0;          //you always start at a common block
    }

    this->location = 0;
    this->last_location = 0;
    this->play = 0;
    this->myMarket = M;
}

//Moving on Grid - Player taps W S D or A to make a move
//W:Move Forward
//S:Move Backwards
//D:Move Right
//A:Move Left
//When Player tries to move out of boundaries, he replays his move (replay_move())
void Grid::move(){

    string dest;            //aka destination
    cout << "Time for our next destination! Choose your move: ";
    cin >> dest;

    if((dest == "W") || (dest == "w")){
        if(move_forward()!=-1)
            show_location();
        else {
            cout << "You cannot enter the realm of the lost souls for whomever joins the dead never sees light again." << endl;
            location = last_location;
            replay_move();
        }
    }
    else if((dest == "S") || (dest == "s")){
        if(move_backwards()!=-1 )
            show_location();
        else{
            cout << "You cannot enter the realm of the lost souls for whomever joins the dead never sees light again." << endl;
            location = last_location;
            replay_move();
        }
    }
    else if((dest == "A") || (dest == "a")){
        if(move_right()!=-1)
            show_location();
        else{
            cout << "You cannot enter the realm of the lost souls for whomever joins the dead never sees light again." << endl;
            location = last_location;
            replay_move();
        }
    }
    else if((dest == "D") || (dest == "d")){
        if(move_left()!=-1)
            show_location();
        else{
            cout << "You cannot enter the realm of the lost souls for whomever joins the dead never sees light again." << endl;
            location = last_location;
            replay_move();
        }
    }
    else if((dest == "EXIT") || (dest == "exit")){
        quitGame();
        cout << "Are you sure you wanna quit the game?  ";
        string s;
        cin >> s;
        if((s == "NO") || (s == "no"))
            this->play = 0;
        else if((s != "YES") && (s != "yes")){
            cout << "Not a valid answer!Try again." << endl;
            while((s != "yes") && (s != "no") && (s!="YES") && (s!="NO")){
                cout << "Are you sure you wanna quit the game?  ";
                string s;
                cin >> s;
                if((s == "NO") || (s == "no")){
                    this->play = 0;
                    break;
                }
                else if ((s == "YES") || (s == "yes"))  break;
                else if((s != "YES") && (s != "yes"))
                    cout << "Not a valid answer!Try again." << endl;
            }
        }
    }
    else {
        cout << "Not a possible move. Please choose W(=forward), S(=backwards), A(=left) or D(=right) "<< endl;
        replay_move();
    }
}

//Player replays his move
//Kinda the same function as move
void Grid::replay_move(){

    string dest;            //aka destination
    cout << "Time for our next destination! Choose your move: ";
    cin >> dest;

    if((dest == "W") || (dest == "w")){
        if(move_forward()!=-1)
            show_location();
        else{
            cout << "You cannot enter the realm of the lost souls for whomever joins the dead never sees light again." << endl;
            location = last_location;
            move();
        }
    }
    else if((dest == "S") || (dest == "s")){
        if(move_backwards()!=-1)
            show_location();
        else{
            cout << "You cannot enter the realm of the lost souls for whomever joins the dead never sees light again." << endl;
            location = last_location;
            move();
        }
    }
    else if((dest == "A") || (dest == "a")){
        if(move_right()!=-1)
            show_location();
        else{
            location = last_location;
            cout << "You cannot enter the realm of the lost souls for whomever joins the dead never sees light again." << endl;
            move();
        }
    }
    else if((dest == "D") || (dest == "d")){
        if(move_left()!=-1)
            show_location();
        else{
            cout << "You cannot enter the realm of the lost souls for whomever joins the dead never sees light again." << endl;
            location = last_location;
            move();
        }
    }
    else if((dest == "EXIT") || (dest == "exit")){
        quitGame();
        cout << "Are you sure you wanna quit the game?  ";
        string s;
        cin >> s;
        if((s == "NO") || (s == "no"))
            this->play = 0;
        else if((s != "YES") && (s != "yes")){
            cout << "Not a valid answer!Try again." << endl;
            while((s != "yes") && (s != "no") && (s != "YES") && (s != "NO")){
                cout << "Are you sure you wanna quit the game?  ";
                string s;
                cin >> s;
                if((s == "NO") || (s == "no")){
                    this->play = 0;
                    break;
                }
                else if ((s == "YES") || (s == "yes"))  break;
                else if((s != "YES") && (s != "yes"))
                    cout << "Not a valid answer!Try again." << endl;
            }
        }
    }
    else {
        cout << "Not a possible move. Please choose W(=forward), S(=backwards), A(=left) or D(=right) "<< endl;
        move();
    }
}

//Location is a double digit int
//We divide location with 10 to find the coordinates
//Variable possibility is used to calculate the possibility of a fight
//The possibility of getting into fight is 50%
void Grid::show_location(){

    if(Map[(location/10)][location%10] == 0){         //Team is on a Common Block
        Display_Map();
        cout << "Your current location on the map is " << (location / 10) << "x" << (location % 10) << " ." << endl;

        int possibility = rand() % 2;
        if (possibility == 0){
            cout << endl << "\t\tLooks like this area is safe. Get some rest and proceed with caution." << endl << endl;
            get_standarBonus("hero");
            display_heroStatus();
        }
        else{
            cout << endl << endl << endl << KRED << "\t\t\t\t" << BOLD(FYEL("**OH NO! The enemy has appeared. Get ready to fight for your lives!**")) << KWHT << endl << endl;
            Fight();
            cout << "Press q to display Grid or anything else to continue" << endl;
            string in;
            cin >> in;
            if(in == "q")   this->Display_Map();
        }
    }

    if( Map[(location/10)][location%10] == 1 ){         //Team is on Market Block
        this->Display_Map();
        cout << "Your current location on the map is " << (location / 10) << "x" << (location % 10) << " ." << endl;
        cout << "There is a Market in your area. Wanna visit?(Choose YES or NO) : " << endl;
        string answer;
        cin >> answer;

        if((answer == "YES") || (answer == "yes")){
            myMarket->visit_Market();
        }
        else if((answer == "NO") || (answer  == "no"))
            return;

        else{
            cout << "Not a valid option. Please answer correctly:!" << endl;
            while ((answer != "NO") && (answer != "YES") && (answer != "no") && (answer != "yes")){
                cout << "There is a Market in your area. Wanna visit?(Choose YES or NO) : " << endl;
                string answer;
                cin >> answer;

                if((answer == "YES") || (answer == "yes")){
                    myMarket->visit_Market();
                    break;
                }
                else if((answer == "NO") || (answer == "no"))
                    break;
                else
                    cout << "Not a valid option. Please answer correctly:!" << endl;
            }
        }
        get_standarBonus("hero");
        cout << "Press q to display Grid or anything else to continue" << endl;
        string in;
        cin >> in;
        if(in == "q")   this->Display_Map();
    }
    if( Map[(location/10)][location%10] == 2 ){     //Team tries to step on a NON - Accessible Block

        cout << endl << endl << KRED << "\t\t\t\t\t\t\t W A R N I N G! " << KWHT << endl << endl;
        cout << "\t\tYou cannot enter the warlods court. Get away from the walls for they are not as friendly as they seem." << endl << endl;
        location = last_location;
        cout << "Replay your move" << endl;
    }
}

//Here we want to move forward
//So we check only if x is out of boundaries
int Grid::move_forward(){
    int x, y;

    last_location = location;
    x = location / 10;
    y = location % 10;

    if(x < LENGTH - 1){
        x++;
        location = (x*10) + y;
    }
    else{
        //cout << "You cannot enter the realm of the lost souls for whomever joins the dead never sees light again. " << endl;
        location = -1;
    }
    return location;
}

//Same as above
//Here we want to move backwards
//So we check only if x is out of boundaries
int Grid::move_backwards(){

    int x, y;
    last_location = location;
    x = location / 10;
    y = location % 10;

    if(x > 0){
        x--;
        location = (x*10) + y;
    }
    else{
        //cout << "You cannot enter the realm of the lost souls for whomever joins the dead never sees light again. " << endl;
        location = -1;
    }
    return location;
}

//Here we want to move right
//So we check only if y is out of boundaries
int Grid::move_right(){

    int x, y;
    last_location = location;
    x = location / 10;
    y = location % 10;

    if(y < WIDTH-1){
        y++;
        location = (x*10) + y;
    }
    else{
        //cout << "You cannot enter the realm of the lost souls for whomever joins the dead never sees light again. " << endl;
        location = -1;
    }
    return location;
}

//Here we want to move left
//So we check only if y is out of boundaries
int Grid::move_left(){

    int x, y;
    last_location = location;
    x = location / 10;
    y = location % 10;

    if(y > 0){
        y--;
        location = (x*10) + y;
    }
    else{
        //cout << "You cannot enter the realm of the lost souls for whomever joins the dead never sees light again. " << endl;
        location = -1;               // logika sthn main if location == 9 chose another move
    }
    return location;
}

void Grid::Display_Map(){

    for( int i = LENGTH-1; i >=0; i--){
        cout << "----------------------------------------------------------------------------------------------------------------" << endl << endl;
        for( int j = WIDTH-1; j >=0; j--){
            if((i*10 + j) == location)
                cout << "|     " << KRED << "Χ" << KWHT << "      |";
            else if(Map[i][j] == 0)
                cout << "|            |";
            else if(Map[i][j] == 1)
                cout << "|" << KCYN << "     Μ      " << KWHT << "|";
            else if(Map[i][j] == 2)
                cout << "|     &      |";
        }
        cout << endl << endl;
    }
    cout << "----------------------------------------------------------------------------------------------------------------" << endl << endl;
    cout << KRED << " Χ" << KWHT << ": Location    " << KCYN << "M" << KWHT << ": Market    & :NonAccessible " << endl << endl;
}

//Inserting Monsters for Fight
//Monsters appear on a Block only for a fight
//After that they do not exist on Grid anymore
void Grid::Insert_Dragon( string name, int level, int damage, int defence, int attack, int damage_r){
    Monster *newMonster = new Dragon( name, level, damage, defence, attack, damage_r);
    Dragons.push_back(newMonster);
}

void Grid::Insert_Spirit( string name, int level, int damage, int defence, int attack, int damage_r){
    Monster *newMonster = new Spirit( name, level, damage, defence, attack, damage_r);
    Spirits.push_back(newMonster);
}

void Grid::Insert_Exoskeleton( string name, int level, int damage, int defence, int attack, int damage_r){
    Monster *newMonster = new Exoskeleton( name, level, damage, defence, attack, damage_r);
    Exoskeletons.push_back(newMonster);
}

//Firtstly, we choose 3 Monsters - each for 1 Hero - randomly
//Monsters are on the same level with Heroes
//After that Fight begins
//At each round Heroes choose their move
//When the sum of all Heroes' or Monsters' health Power is 0
//Figth stops
void Grid::Fight(){

   MyTeam *T = myMarket->get_myTeam();
   list <Hero*> Squad = T->get_myHeroes();
   list <Hero*> :: iterator it;
   list <Monster*> :: iterator ti;

   //Choosing 3 Monsters randomly
   for(it = Squad.begin(); it != Squad.end(); ++it){
       int randNum = rand() % 3;
       if(randNum == 0){
           for(ti = Dragons.begin(); ti != Dragons.end(); ++ti){
               if(((*it)->get_level()) >= ((*ti)->get_level())){
                   Monster *newMonster = new Dragon( (*ti)->get_name(), (*ti)->get_level(), (*ti)->get_damage(), (*ti)->get_defence(), (*ti)->get_attackAP(), (*ti)->get_damageRange());
                   myMonsters.push_back(newMonster);
                   break;
               }
           }
       }
       if(randNum == 1){
           for(ti = Spirits.begin(); ti != Spirits.end(); ++ti){
               if(((*it)->get_level()) == ((*ti)->get_level())){
                   Monster *newMonster = new Spirit( (*ti)->get_name(), (*ti)->get_level(), (*ti)->get_damage(), (*ti)->get_defence(), (*ti)->get_attackAP(), (*ti)->get_damageRange());
                   myMonsters.push_back(newMonster);
                   break;
               }
           }
       }
       if(randNum == 2){
           for(ti = Exoskeletons.begin(); ti != Exoskeletons.end(); ++ti){
               if(((*it)->get_level()) == ((*ti)->get_level())){
                   Monster *newMonster = new Exoskeleton( (*ti)->get_name(), (*ti)->get_level(), (*ti)->get_damage(), (*ti)->get_defence(), (*ti)->get_attackAP(), (*ti)->get_damageRange() );
                   myMonsters.push_back(newMonster);
                   break;
               }
           }
       }
    }

    cout << endl << "\t\t\t" << KYEL << "The Monsters are closing the distance rapidly! Check their status and decide your move wisely!" << KWHT << endl << endl << endl << endl;
    display_monsterStatus();
    cout << endl << endl << endl << "\t\t\t\t\t\t" << KYEL << "And here is your Team's status" << KWHT << endl << endl;
    display_heroStatus();
    int MonsterSum = 0, HeroSum = 0;
    int round = 1;
    do{
        HeroSum = 0;
        MonsterSum = 0;
        get_standarBonus("battle");
        for(it = Squad.begin(); it != Squad.end(); ++it){
            if((*it)->get_healthP() > 0){
                int flag = 0;
                while(flag == 0){
                    cout << endl << "\t\t\t CHOOSE MOVE FOR " << KBLU << (*it)->get_name() << KWHT << " (EQUIP/equip, ATTACK/attack, CAST/cast, Use/use): ";
                    string answer;
                    cin >> answer;
                    if((answer == "EQUIP") || (answer == "equip")){
                        (*it)->equip();
                        flag = 1;
                    }
                    else if((answer == "ATTACK") || (answer == "attack")){
                        attack((*it)->get_name());
                        flag = 1;
                    }
                    else if((answer == "CAST") || (answer == "cast")){
                        castSpell((*it)->get_name());
                        flag = 1;
                    }
                    else if((answer == "USE") || (answer == "use")){
                        (*it)->use();
                        flag = 1;
                    }
                    else
                        cout << endl << "Not a valid option! Please choose another answer." << endl << endl;
                }
            }
            else
                cout << (*it)->get_name() << " IS OUT!" << endl;
        }
        HeroSum = H_TotalPower();
        MonsterSum = M_TotalPower();
        display_status();
        round++;
        if((HeroSum!=0) && (MonsterSum!=0)){
            if(HeroSum > MonsterSum)
                cout << endl << KYEL << "\t\t\t\t\t\t\t Your Team has the lead" << KWHT << endl;
            else
                cout << endl << KYEL << "\t\t\t\t\t\t\t Enemy has the lead" << KWHT << endl;
            cout << endl << BOLD(FYEL("\t\t\t\t\t\t G E T  R E A D Y  F O R  R O U N D  ")) << round << endl;
        }
    } while((HeroSum!=0) && (MonsterSum!=0));

    // Some prints for effects again //
    //_________________________________________________________________________________________________________________________________________________________________//
    if(HeroSum == 0){
        cout << endl ;
        cout << "\t\t\t\t\t\t" << KRED << "  .-***-." << "\t\t\t" << KRED << "  .-***-." << endl;
        cout << "\t\t\t\t\t\t" << KRED << " /" << KWHT << "* * * *" << KRED << "9" << "\t\t\t" << KRED << " /" << KWHT << "* * * *" << KRED << "9" << endl;
        cout << "\t\t\t\t\t\t" << KRED << ":_.-:`:-._;" << KWHT << "\t\t\t" << KRED << ":_.-:`:-._;" << KWHT << endl;
        cout << "\t\t\t\t\t\t" << "    (_)" << "\t\t\t\t" << "    (_)" << endl;
        cout << "\t\t\t\t\t\t" << KGRN << " !|/" << KWHT << "(_)" << KGRN << "!|/" << " !|/ !|/ !|/ !|/ !|/ !|" << KGRN << "!|/" << KWHT << "(_)" << KGRN << "!|/" ;
        cout << endl << endl << KMAG << "\t\t\t\t\t\t\t ------------------";
        cout << endl << "\t\t\t\t\t\t\t | D e f e a t :( |" << endl;
        cout << "\t\t\t\t\t\t\t ------------------" << KWHT << endl << endl;
        get_standarBonus("loss");
    }
    else if(MonsterSum == 0){
        cout << endl;
        cout << "\t\t\t" << KCYN << "*" << KRED << "                             |>>>" << KCYN << "                    +" << endl;
        cout << "\t\t\t" << KCYN << "+          *" << KYEL << "                      |" << KCYN << "                   *       +" << endl;
        cout << "\t\t\t" << KRED << "                    |>>>" << KYEL << "      _  _|_  _ " << KCYN << "  *" << KRED << "     |>>>" << endl;
        cout << "\t\t\t" << KCYN << "           *" << KYEL << "        |        |;| |;| |;|        |                 " << KCYN << "*" << endl;
        cout << "\t\t\t" << KCYN << "     + " << KYEL << "         _  _|_  _    77.    .  /    _  _|_  _       " << KCYN << "+" << endl;
        cout << "\t\t\t" << KCYN << " *" << KYEL << "             |;|_|;|_|;|    77: +   /    |;|_|;|_|;|" << endl;
        cout << "\t\t\t" << KYEL << "               77..      /    ||:+++. |    77.    .  /           " << KCYN << "*" << endl;
        cout << "\t\t\t" << KCYN << "      +" << KYEL << "         \\.  ,  /     ||:+++  |     77:  .  /" << endl;
        cout << "\t\t\t" << "                 ||:+  |_   _ ||_ . _ | _   _||:+  |       " << KCYN << "*" << endl;
        cout << "\t\t\t" << "          *" << KYEL << "      ||+++.|||_|;|_|;|_|;|_|;|_|;||+++ |          " << KCYN << "+" << endl;
        cout << "\t\t\t" << KYEL << "                 ||+++ ||.    .     .      . ||+++.|   " << KCYN << "*" << endl;
        cout << "\t\t\t" << "+   *" << KYEL << "            ||: . ||:.     . .   .  ,   ||:   |               " << KCYN << "*" << endl;
        cout << "\t\t\t" << "         *" << KYEL << "       ||:   ||:  ,     +       .  ||: , |" << KCYN << "      +" << endl;
        cout << "\t\t\t" << "  *" << KYEL << "              ||:   ||:.     +++++      . ||:   |" << KCYN << "          *" << endl;
        cout << "\t\t\t" << "     +           " << KYEL << "||:   ||.     +++++++  .    ||: . |" << KCYN << "    +" << endl;
        cout << "\t\t\t" << KCYN << "           +" << KYEL << "     ||: . ||: ,   +++++++ .  .  ||:   |             " << KCYN << "+" << endl;
        cout << "\t\t\t" << KYEL << "                 ||: . ||: ,   +++++++ .  .  ||:   |        " << KCYN << "*" << endl;
        cout << "\t\t\t" << KYEL <<  "                 ||: . ||: ,   +++++++ .  .  ||:   |" << endl;
        cout << endl << endl << KCYN << "\t\t\t\t\t\t -----------------";
        cout << endl << "\t\t\t\t\t\t | V I C T O R Y |" << endl;
        cout << "\t\t\t\t\t\t -----------------" << KWHT << endl << endl;
        get_standarBonus("win");
    }
    //_________________________________________________________________________________________________________________________________________________________________//

    //Deleting all Monsters to insert new ones at next Battle
    for(ti = myMonsters.begin(); ti != myMonsters.end(); ++ti)
       delete *ti;
    myMonsters.clear();
}

//Every Hero fights with a Monster of the same level
//First each Hero attacks his enemy
//And then every Monster does the same
void Grid::attack(string s){

    MyTeam *T = myMarket->get_myTeam();
    list <Hero*> Squad = T->get_myHeroes();
    list <Hero*> :: iterator it;
    list <Monster*> :: iterator ti;

    for(it = Squad.begin(), ti = myMonsters.begin(); (it != Squad.end()) && (ti != myMonsters.end()); ++it, ++ti){
        if(s == (*it)->get_name()){
           cout << endl << KBLU << "\t\t\t\t\t\t " << (*it)->get_name() << KWHT << BOLD(" is attacking " )<< (*ti)->get_name() << endl << endl;
           int randNum = rand() % 100;
           if((randNum/5) <= (*ti)->get_attackAP()){
               int dec =  (((*it)->get_strength())*((*it)->get_dexterity())/5500) - (((*ti)->get_defence())*((*ti)->get_attackAP())/5500);
               (*ti)->decrease_healthP(dec);
               //display_monsterStatus((*ti)->get_name());
           }
        }
    }
    cout << endl << "\t\t\t\t\t\t " << "The " << KBLU << "Monster(s) " << KWHT << BOLD("are fighting back!!") << endl << endl;
    for(it = Squad.begin(), ti = myMonsters.begin(); (it != Squad.end()) && (ti != myMonsters.end()); ++it, ++ti){
        if(s == (*it)->get_name()){
            int randNum = rand() % 100;
            if((randNum/5) <= (*it)->get_dexterity()){
                int dec = (((*ti)->get_damage())*((*it)->get_agility())/5500);
                (*it)->decrease_healthP(dec);
                //display_heroStatus((*it)->get_name());
            }
        }
    }
}

//Same function as attack
//Here Hero casts a Spell to the Enemy
void Grid::castSpell(string s){

    MyTeam *T = myMarket->get_myTeam();
    list <Hero*> Squad = T->get_myHeroes();
    list <Hero*> :: iterator it;
    list <Monster*> :: iterator ti;

    for (it = Squad.begin(), ti = myMonsters.begin(); (it != Squad.end()) && (ti != myMonsters.end()); ++it, ++ti){
        if(s == (*it)->get_name()){
          cout << endl << "\t\t\t\t\t\t " << (*it)->get_name() << " is casting a Spell to " << (*ti)->get_name() << endl << endl;
          Spell* spell = (*it)->castSpell();
          if(spell == NULL) return;
          (*ti)->Attacked(spell);
      }
    }

    cout << endl << "\t\t\t\t\t\t The Monster(s) are fighting back!!" << endl << endl;
    for (it = Squad.begin(), ti = myMonsters.begin(); (it != Squad.end()) && (ti != myMonsters.end()); ++it, ++ti){
        if(s == (*it)->get_name()){
            int dec = (((*ti)->get_damage())*((*it)->get_agility())/5000);
            (*it)->decrease_healthP(dec);
            //display_heroStatus((*it)->get_name());
        }
    }
}

//Displaying Statistics of all Monsters
void Grid::display_monsterStatus(){
    list <Monster*> :: iterator it;

    cout << endl;
    cout << BOLD(FYEL("Your Enemy's Troops:")) << endl;
    cout << "Name" << "\t\t\t    " << "Health Power" << "\t      " << "Damage" << "\t      " << "Defence" << "\t      " << "Attack AP" << endl;
    cout << "-------------------------------------------------------------------------------------------------" << endl;
    for(it = myMonsters.begin(); it!=myMonsters.end(); ++it)
        cout << (*it)->get_name() << "\t\t\t" << KBLU << (*it)->get_healthP() << KWHT<< "\t\t\t" << (*it)->get_damage() << "\t\t" << (*it)->get_defence() << "\t\t" << (*it)->get_attackAP() <<  endl;
    cout << endl;
}

//Displaying Statistics of a Specific Monster
void Grid::display_monsterStatus(string s){
    list <Monster*> :: iterator it;

    cout << endl;

    for(it = myMonsters.begin(); it!=myMonsters.end(); ++it){
        if( s == (*it)->get_name() ){
            cout << "\t\t\t\t\t\t "<< (*it)->get_name() << "'s Health Power: " << KBLU << (*it)->get_healthP() << KWHT << endl;
        }
    }
    cout << endl;
}

//Displaying Statistics of a specific Hero
void Grid::display_heroStatus(string name){

    MyTeam *T = myMarket->get_myTeam();
    list <Hero*> Squad = T->get_myHeroes();
    list <Hero*> :: iterator it;

    for(it = Squad.begin(); it!=Squad.end(); ++it){
        if(name == (*it)->get_name()){
            cout << "\t\t\t\t\t\t "<< (*it)->get_name() << "'s Health Power: " << KBLU << (*it)->get_healthP() << KWHT << endl;
        }
    }
    cout << endl;
}

//Displaying Statistics of all Heroes
void Grid::display_heroStatus(){

    MyTeam *T = myMarket->get_myTeam();
    list <Hero*> Squad = T->get_myHeroes();
    list <Hero*> :: iterator it;

    cout << endl;
    cout << BOLD(FYEL("Your Team's Troops:")) << endl;
    cout << "Name" << "\t\t\t    " << "Magic Power" << "\t    " << "Health Power" << "\t" << "Strength" << "\t" << "Agility" << "\t      " << "Dexterity" << "\t     " << "Experience" << endl;
    cout << "-------------------------------------------------------------------------------------------------------------------------" << endl;
    for(it = Squad.begin(); it!=Squad.end(); ++it){
        cout << (*it)->get_name() << "\t\t" << (*it)->get_magicPower() << "\t\t" << (*it)->get_healthP() << "\t\t  " << (*it)->get_strength() << "\t\t  " << (*it)->get_agility() << "\t\t " << (*it)->get_dexterity() << "\t\t" << (*it)->get_experience() << endl;
    }
    cout << endl;
}

//Displaying Statistics of both Teams
void Grid::display_status(){
   cout << endl;
   display_monsterStatus();
   display_heroStatus();
}

//Heroes get a standar Bonus for every move
//If they get into fight and lose
//this bonus is very small
//just to help them to continue moving
//the exact opposite happens when they win
void Grid::get_standarBonus(string s){
    list <Hero*> :: iterator it;
    MyTeam *T = myMarket->get_myTeam();
    list <Hero*> Squad = T->get_myHeroes();


    if(s == "battle"){
        for(it = Squad.begin(); it!=Squad.end(); ++it){
           if((*it)->get_healthP() != 0){
                (*it)->set_magicPower(100);
                (*it)->set_strength(5);
                (*it)->set_agility(5);
                (*it)->set_dexterity(5);
            }
        }
    }

    else if(s == "win"){
        for(it = Squad.begin(); it!=Squad.end(); ++it){
            (*it)->set_money(((*it)->get_level())*(30));
            (*it)->set_experience(10);
            (*it)->levelUp();
         }
    }

    else if(s == "loss"){
        for(it = Squad.begin(); it!=Squad.end(); ++it)
            (*it)->set_money(((*it)->get_money()/2)*(-1));
    }
    else{
        for(it = Squad.begin(); it!=Squad.end(); ++it){
            if((*it)->get_healthP() == 0)
                (*it)->set_healthP(100);
            else{
                if((*it)->get_healthP() <= 190)
                    (*it)->set_healthP(10);
                (*it)->set_magicPower(30);
                (*it)->set_strength(5);
                (*it)->set_agility(1);
                (*it)->set_dexterity(1);
                (*it)->set_experience(5);
            }
        }
    }
}

//Counting Heroes' total Health Power
int Grid::H_TotalPower(){
    list <Hero*> :: iterator it;
    MyTeam *T = myMarket->get_myTeam();
    list <Hero*> Squad = T->get_myHeroes();

    int sum = 0;
    for(it = Squad.begin(); it!=Squad.end(); ++it){
        if((*it)->get_healthP() > 0)
            sum += (*it)->get_healthP();
    }
    return sum;
}

//Counting Monsters' total Health Power
int Grid::M_TotalPower(){
    list <Monster*> :: iterator it;

    int sum = 0;
    for(it = myMonsters.begin(); it!=myMonsters.end(); ++it){
        if((*it)->get_healthP() > 0)
            sum += (*it)->get_healthP();
    }
    return sum;
}

//And here the game begins
//GamePlay calls every function
void Grid::gameplay(){

    cout << endl;
    cout << '\t' << "Do you want to view the basic information for the game? Press yes/YES or no/NO to start the game immediately." << endl << '\t';
    string option;
    cin >> option;
    if( (option == "yes") || (option == "YES") )
    BasicInfo();
    else if( (option != "YES") && (option != "yes")){
        if( (option != "NO") && (option != "no") ){
            cout << "Not a valid answer!Please choose correctly." << endl << '\t';
            cin >> option;
            while((option!="YES") && (option!="yes") && (option!="NO") && (option!="no")){
                cout << "Not a valid answer!Please choose correctly." << endl << '\t';
            }
            if( (option == "yes") || (option == "YES") )
                BasicInfo();
        }
    }
    cout << endl;
    cout << "\t\t\t\t\t" << BOLD(FBLU(" L E T   T H E   G A M E   B E G I N ")) << endl << endl << endl;
    cout << "\t\t\t\t\t\t" << KMAG << " * Choose your Team * " << KWHT << endl << endl << endl;
    MyTeam *T = myMarket->get_myTeam();
    T->Display_Heroes();

    for(int i = 0; i < 3; i++){
        cout << "Enter Hero's name: " ;
        string name;
        cin >> name;
        T->add_player(T->catch_wrongName(name));
        if(i < 2){
            cout << "Do you want to choose another player? Press YES/yes or NO/no" << endl;
            string s;
            cin >> s;
            if((s == "NO") || (s ==  "no")){
                break;
            }
            else if((s!="YES") && (s!="yes")){
                cout << "Not a valid option!Please answer YES/yes or NO/no" << endl;
                cin >> s;
                while((s!="YES") && (s!="yes") && (s!="NO") && (s!="no")){
                    cout << "Not a valid option! Please answer YES/yes or NO/no" << endl;
                    cin >> s;
                }
                if((s=="NO") || (s=="no")){
                    break;
                }
            }
        }
    }
    cout << endl;
    T->Display_Team();
    this->Display_Map();

    while(play == 0){
        move();
    }
}

//Displaying BAsic Infos for user
void Grid::BasicInfo(){
    cout << "\t\t" << KYEL << "   Basic Information"  << KWHT << endl << "\t\t" << KCYN << "=======================" << KWHT << endl << endl;
    cout << endl << "\t\t" << "For movement :" << KYEL << "    W" << KWHT << " - move forward" << endl << "\t\t\t\t" << KYEL << "  A " << KWHT << "- move left" << endl << "\t\t\t\t" << KYEL << "  D" << KWHT << " - move right " << endl << "\t\t\t\t" << KYEL << "  S" << KWHT << " - move backwards" << endl;
    cout << endl << "\t\t" << "You cannot move diagonally!" << endl;
    cout << endl << "\t\t" << "You can buy up to 3 heroes for your adventure." ;
    cout << endl << "\t\t" << "To fight, buy, sell or use an item follow the instructions given during the name(by typing whatever needed)." << endl ;
    cout << "\t\t" << "To" << KCYN << " QUIT " << KWHT << "game press exit whenever you are to make a move. You cannot exit while in a market or during a fight!" << endl;
    cout << endl << endl << '\t' << "Press START/start whenever you are ready!" << endl << '\t';

    string s;
    cin >> s;
    while((s != "START") && (s != "start")){
        cout << endl << '\t' << "Not a valid option! Try again." << endl << '\t' ;
        cin >> s;
    }
}

//Exiting Game
void Grid::quitGame(){
    this->play=1;
}

//Destructor
Grid::~Grid(){
    list <Monster*> :: iterator ti;

    for(ti=Dragons.begin(); ti!=Dragons.end(); ++ti)
        delete *ti;
    for(ti=Spirits.begin(); ti!=Spirits.end(); ++ti)
        delete *ti;
    for(ti=Exoskeletons.begin(); ti!=Exoskeletons.end(); ++ti)
        delete *ti;
    for(ti=myMonsters.begin(); ti!=myMonsters.end(); ++ti)
        delete *ti;

    for(int i = 0; i < LENGTH; i++)
        delete[] Map[i];
    delete[] Map;
}
