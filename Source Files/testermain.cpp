#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <ctime>

#include "Grid.h"

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

int main (void){

    srand(time(NULL));

    MyTeam squad;
    Market ThisMarket(&squad);
    Grid Gameplay(&ThisMarket);


    //Reading from Files
    //and constructing Market and MyTeam
    ifstream Potions("Potions.txt");
    if(!Potions){
        cout << "Cannot open file\n" << endl;;
        return 1;
    }
    ifstream Armory("Armory.txt");
    if(!Armory){
        cout << "Cannot open file\n" << endl;;
        return 1;
    }
    ifstream Weaponry("Weaponry.txt");
    if(!Weaponry){
       cout << "Cannot open file\n" << endl;;
       return 1;
    }

    ifstream FireSpells("FireSpells.txt");
    if(!FireSpells){
        cout << "Cannot open file\n" << endl;;
        return 1;
    }
    ifstream IceSpells("IceSpells.txt");
    if(!IceSpells){
        cout << "Cannot open file\n" << endl;;
        return 1;
    }
    ifstream LightningSpells("LightningSpells.txt");
    if(!LightningSpells){
       cout << "Cannot open file\n" << endl;;
       return 1;
    }

    ifstream Warriors("Warriors.txt");
    if(!Warriors){
       cout << "Cannot open file\n" << endl;;
       return 1;
    }

    ifstream Sorcerers("Sorcerers.txt");
    if(!Sorcerers){
       cout << "Cannot open file\n" << endl;;
       return 1;
    }

    ifstream Paladins("Paladins.txt");
    if(!Paladins){
       cout << "Cannot open file\n" << endl;;
       return 1;
    }

     ifstream Dragons("Dragons.txt");
    if(!Dragons){
       cout << "Cannot open file\n" << endl;;
       return 1;
    }

    ifstream Spirits("Spirits.txt");
    if(!Spirits){
       cout << "Cannot open file\n" << endl;;
       return 1;
    }

    ifstream Exoskeletons("Exoskeletons.txt");
    if(!Exoskeletons){
       cout << "Cannot open file\n" << endl;;
       return 1;
    }

    string name;
    int cost, level, RI;
    while(Potions >> name >> cost >> level >> RI){
        ThisMarket.Insert_Potion(name,cost,level,RI);
    }

    int damage, handControl;
    while(Weaponry >> name >> cost >> level >> damage >> handControl){
        ThisMarket.Insert_Weapon(name,cost,level,damage,handControl);
    }

    while(Armory >> name >> cost >> level >> RI){
        ThisMarket.Insert_Armor(name,cost,level,RI);
    }

    string nam;
    int  mp, strength, agility, dexterity, money, exp;
    while(Warriors >> nam >> mp >> strength >> agility >> dexterity >> money >> exp){
        squad.Insert_Warrior(nam, mp, strength, agility, dexterity, money, exp);
    }

    while(Sorcerers >> nam >> mp >> strength >> agility >> dexterity >> money >> exp){
        squad.Insert_Sorcerers(nam, mp, strength, agility, dexterity, money, exp);
    }

    while(Paladins >> nam >> mp >> strength >> agility >> dexterity >> money >> exp){
        squad.Insert_Paladins(nam, mp, strength, agility, dexterity, money, exp);
    }

    int minL, loss, mP, red;
    while(IceSpells >> nam >> cost >> minL >> loss >> mP >> red){
        ThisMarket.Insert_IceSpell(nam, cost, minL, loss, mP, red);
    }

    while(FireSpells >> nam >> cost >> minL >> loss >> mP >> red){
        ThisMarket.Insert_FireSpell(nam, cost, minL, loss, mP, red);
    }

    while(LightningSpells >> nam >> cost >> minL >> loss >> mP >> red){
        ThisMarket.Insert_LightingSpell(nam, cost, minL, loss, mP, red);
    }

    int dam, def, att, dam_r;
    while( Dragons >> nam >> level >> dam >> def >> att >> dam_r){
        Gameplay.Insert_Dragon( nam, level, dam, def, att, dam_r);
    }

    while( Spirits >> nam >> level >> dam >> def >> att >> dam_r){
        Gameplay.Insert_Spirit( nam, level, dam, def, att, dam_r);
    }

    while( Exoskeletons >> nam >> level >> dam >> def >> att >> dam_r){
        Gameplay.Insert_Exoskeleton( nam, level, dam, def, att, dam_r);
    }

    // Some prints for effects //

    cout << endl << endl;
    cout << '\t' << KGRN << "\t\t\t\tK I N G D O M    O F   F R Y V I E L:   R E B I R T H" << KWHT << endl;
    cout << '\t' << KCYN << "--<<O>>--<<O>>--<<O>>--<<O>>--<<O>>--<<O>>--<<O>>--<<O>>--<<O>>--<<O>>--<<O>>--<<O>>--<<O>>--<<O>>--<<O>>--<<O>>--" << KWHT << endl << endl;
    cout << '\t' << "\t" << "In the ancient times king Arowen , the conquerer of the Sun Empire,after defeating the commander" << endl <<  '\t' << '\t' << "of the evil troops Manticore, bestowed peace amongst humans and builted his capitol" << endl;
    cout << '\t' << "\t" << "named after his only daughter and sole succesor to the throne Fryviel. The princess , though as   " << endl << '\t' << '\t' << "she was born with the gift of prophecy foretold a grim future for the human nation " << endl;
    cout << '\t' << "\t" << "for the Queen of Evil, the Mother of Monsters, the vicious Echidna was still not dead and hiding" << endl << '\t' << '\t' << " somewhere inside the kingdom was slowly rising a new army to detroy them all..." << endl;
    cout << '\t' << "\t" << "But the night before her father's death, Fryviel saw a bright spot to their kingdom's future." << endl << '\t' << '\t' << "She spoke of a final victory someone would bring,wether a single man or a team of heroes " << endl;
    cout << '\t' << "\t" << "would fight the enemies and restore peace to their great kingdom. And finally that day came..." << endl << '\t' << '\t' << " " << endl;
    cout << endl;

    cout << KYEL << "       .--.   _," << KWHT << endl;
    cout << KYEL << "        .--;    7 /(_" << KWHT << endl;
    cout << KYEL << "       /    '.   |   '-._    . ' ." << KWHT << endl;
    cout << KYEL << "      |       7  7    ,-.)  -= * =-" << KWHT << endl;
    cout << KYEL << "       7 /7_   '. 7((` .(    '/. '" << KWHT   << endl;
    cout << KYEL << "        )! /     7 )7  _/   _/" << KWHT << "\t\t   A new adventure will shortly begin!" << endl;
    cout << KYEL << "       /  7!    .-'   '--. /_7" << KWHT << endl;
    cout << KYEL << "      |    7!_.' ,        7/||" <<  KWHT  << endl;
    cout << KYEL << "      7     _.-';,_) _)'7 7||" << KWHT << "\t\tNow it's up to you to decide who the hero or heroes will be." << endl;
    cout << KYEL << "       '.       /`9   (   '._/" << KWHT << endl;
    cout << KYEL << "         `7   .;  |  . '." << KWHT << "\t\t  Get ready to roam the kingdom and fight for its glory." << endl;
    cout << KYEL << "           ).'  )/|       ?" << KWHT << endl;
    cout << KYEL << "           `    ` |  6|   |" << KWHT << "\t\tFor the time has arrived that the war will spread"<< endl;
    cout << KYEL << "                   7  |   |" << KWHT << "\t\tlike hellfire so that peace can be bestowed once more." << endl;
    cout << KYEL << "                    '.|   |" << KWHT << endl;
    cout << KYEL << "                       !  '7__" << KWHT << "\t\tWith the gift of wisdom these Fae have given you and" << endl;
    cout << KYEL << "                        `-._  '. _" << KWHT << "\t\tthe courage you have start your journey and may" << endl;
    cout << KYEL << "                           7`;-.` `._" << KWHT << "\t\tit be victorious!" << endl;
    cout << KYEL << "                            7 ! `'-._7" << KWHT << endl;
    cout << KYEL << "                             7 |" << KWHT << endl;
    cout << KYEL << "                              7 )" << KWHT << endl;
    cout << KYEL << "                               7_7" << KWHT << endl;

    Gameplay.gameplay();
}
