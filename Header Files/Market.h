#ifndef MARKET_H
#define MARKET_H

#include <list>
#include <string>

#include "myTeam.h"

class Market {
    private:
        std:: list <Item*> Weapons;             //Lists of Items and Spells
        std:: list <Item*> Armors;
        std:: list <Item*> Potions;
        std:: list <Spell*> IceSpells;
        std:: list <Spell*> FireSpells;
        std:: list <Spell*> LightingSpells;

        std:: list <Spell*> SpellsOnSell;       //Lists of Items and Spell on Sell by Heroes
        std:: list <Item*> ItemsOnSell;
        MyTeam *Squad;                          //pointing directly to "MyTeam" 

    public:
        explicit Market(MyTeam*);                                           //constructor
        void Insert_Weapon(std::string,int,int,int,int);                    //Inserting into Lists
        void Insert_Armor(std::string,int,int,int);
        void Insert_Potion(std::string,int,int,int);
        void Insert_IceSpell(std::string,int,int,int,int,int);
        void Insert_FireSpell(std::string,int,int,int,int,int);
        void Insert_LightingSpell(std::string,int,int,int,int,int);
        void DisplayMarket();                                               //Displaying Market
        void DisplayOnSell();
        void Display_Items();
        void Display_Spells();
        Item* Search_Items(std::string);                                    //Searching for a Specific Item/Spell/Hero
        Spell* Search_Spells(std::string);
        Item* Search_ItemsOnSell(std::string);
        Spell* Search_SpellsOnSell(std::string);
        void buy();                                                         //Buying from Market
        void buy_Item(std::string);
        void buy_Spell(std::string);
        void sell();                                                        //Selling an Item or Spell
        void sell_Item(std::string);
        void sell_Spell(std::string);
        void visit_Market();
        void print_effects();                                               //prints a dragon
        std::string catch_wrongName(std::string, std::string);              //checks if player typed wrong
        MyTeam* get_myTeam();
        ~Market();                                                          //destructor
};

#endif
