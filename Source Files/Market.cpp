#include <iostream>
#include <string>
#include <list>
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

#include "Market.h"

using namespace std;

Market::Market(MyTeam* Team){
    //cout << "Welcome to your market" << endl << endl;
    this->Squad = Team;
}

//Constructing new Items Spells and
//Inserting them each Item or Spell into its List
void Market::Insert_Weapon(string name, int cost, int unlockL, int damage, int handControl){
    Item *NewItem = new Weapon(name,cost,unlockL,damage,handControl);
    Weapons.push_back(NewItem);
}

void Market::Insert_Armor(string name,int cost, int unlockL, int damageRP){
    Item *NewItem = new Armor(name,cost,unlockL,damageRP);
    Armors.push_back(NewItem);
}

void Market::Insert_Potion(string name,int cost, int unlockL, int statisticsRI){
    Item *NewItem = new Potion(name,cost,unlockL,statisticsRI);
    Potions.push_back(NewItem);
}

void Market::Insert_IceSpell(string name, int cost, int unlockL, int damage, int minMagicP, int reduction){
    Spell *NewSpell = new IceSpell(name,cost,unlockL,damage,minMagicP,reduction);
    IceSpells.push_back(NewSpell);
}

void Market::Insert_FireSpell(string name, int cost, int unlockL, int damage, int minMagicP, int reduction){
    Spell *NewSpell = new FireSpell(name,cost,unlockL,damage,minMagicP,reduction);
    FireSpells.push_back(NewSpell);
}

void Market::Insert_LightingSpell(string name, int cost, int unlockL, int damage, int minMagicP, int reduction){
    Spell *NewSpell = new LightingSpell(name,cost,unlockL,damage,minMagicP,reduction);
    LightingSpells.push_back(NewSpell);
}

//Displaying Available Items or Spells
//Player can choose to display a Specific Category
//Or all of them
void Market::Display_Items(){
    list <Item*> :: iterator it;

    cout << endl << endl << endl;
    cout << " Available Weapons" << endl;
    cout << "********************" << endl;
    cout << "Name" << "\t\t" << "Cost" << "\t   " << "Unlock Level" << "\t       " << "Damage" << endl;
    cout << "------------------------------------------------------" << endl;
    for(it = Weapons.begin(); it!=Weapons.end(); ++it)
        cout << (*it)->get_name() << "\t\t" << (*it)->get_cost() << "\t\t" << (*it)->get_unlock_level() << "\t\t" << (*it)->get_damage() << endl;
    cout << endl <<endl;

    cout << " Available Armors" << endl;
    cout << "********************" << endl;
    cout << "Name" << "\t\t\t" << "Cost" << "\t   " << "Unlock Level" << "\t       " << "Defence Level" << endl;
    cout << "-----------------------------------------------------------------------" << endl;
    for(it = Armors.begin(); it!=Armors.end(); ++it)
        cout << (*it)->get_name() << "\t\t" << (*it)->get_cost() << "\t\t" << (*it)->get_unlock_level() << "\t\t" << (*it)->get_reduction() << endl;
    cout << endl << endl;

    cout << " Available Potions" << endl;
    cout << "********************" << endl;
    cout << "Name" << "\t\t\t" << "Cost" << "\t   " << "Unlock Level" << "\t       " << "Agility's Increase Rate" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
    for(it = Potions.begin(); it!=Potions.end(); ++it)
    cout << (*it)->get_name() << "\t\t" << (*it)->get_cost() << "\t\t" << (*it)->get_unlock_level() << "\t\t" << (*it)->get_rate() << endl;
    cout << endl << endl;
}

void Market::Display_Spells(){
    list <Spell*> :: iterator it;

    cout << endl << endl << endl;
    cout << " Available Ice Spells" << endl;
    cout << "**********************" << endl;
    cout << "Name" << "\t\t\t" << "Cost" << "\t   " << "Unlock Level" << "\t\t" << "Damage" << "\t\t" << "Minimum Magic Power" << "\t\t" << "Enemy's Attack Decrease %" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------------------" << endl;
    for(it = IceSpells.begin(); it!=IceSpells.end(); ++it)
        cout << (*it)->get_name() << "\t\t" << (*it)->get_cost() << "\t\t" << (*it)->get_unlock_level() << "\t\t" << (*it)->get_damage() << "\t\t\t" << (*it)->get_min_magicP() << "\t\t\t\t" << (*it)->get_reduction() << endl;
    cout << endl;

    cout << " Available Fire Spells" << endl;
    cout << "************************" << endl;
    cout << "Name" << "\t\t\t" << "Cost" << "\t   " << "Unlock Level" << "\t\t" << "Damage" << "\t\t" << "Minimum Magic Power" << "\t\t" << "Enemy's Defence Decrease %" << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------------------" << endl;
    for(it = FireSpells.begin(); it!=FireSpells.end(); ++it)
        cout << (*it)->get_name() << "\t\t" << (*it)->get_cost() << "\t\t" << (*it)->get_unlock_level() << "\t\t" << (*it)->get_damage() << "\t\t\t" << (*it)->get_min_magicP() << "\t\t\t\t" << (*it)->get_reduction() << endl;
    cout << endl;

    cout << " Available Lightning Spells" << endl;
    cout << "****************************" << endl;
    cout << "Name" << "\t\t\t" << "Cost" << "\t   " << "Unlock Level" << "\t\t" << "Damage" << "\t\t" << "Minimum Magic Power" << "\t\t" << "Enemy's Pos.of avoiding Attack Decrease %" << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    for(it = LightingSpells.begin(); it!=LightingSpells.end(); ++it)
        cout << (*it)->get_name() << "\t\t" << (*it)->get_cost() << "\t\t" << (*it)->get_unlock_level() << "\t\t" << (*it)->get_damage() << "\t\t\t" << (*it)->get_min_magicP() << "\t\t\t\t" << (*it)->get_reduction() << endl;
    cout << endl;
}

void Market::DisplayOnSell(){

    if((ItemsOnSell.empty()) || (SpellsOnSell.empty()))
        return;

    list <Item*> :: iterator ti;

    cout << endl << endl << endl;
    cout << " Available Items" << endl;
    cout << "*****************" << endl;
    cout << "Type of Item" << "\t\t" << "Name" << "\t\t\t" << "Cost" << "\t   " << "Unlock Level" << "\t\t" << "Damage" << endl;
    cout << "-------------------------------------------------------------------------------------------" << endl;
    for(ti = ItemsOnSell.begin(); ti!=ItemsOnSell.end(); ++ti)
        cout << (*ti)->get_classType() << "\t\t\t" << (*ti)->get_name() << "\t\t\t " << (*ti)->get_cost() << "\t\t" << (*ti)->get_unlock_level() << "\t\t " << (*ti)->get_damage() << endl;
    cout << endl <<endl;

    list <Spell*> :: iterator it;

    cout << " Available Spells" << endl;
    cout << "******************" << endl;
    cout << "Type of Spell" << "\t\t" << "Name" << "\t\t\t" << "Cost" << "\t   " << "Unlock Level" << "\t\t" << "Damage" << endl;
    cout << "--------------------------------------------------------------------------------------------" << endl;
    for(it = SpellsOnSell.begin(); it!=SpellsOnSell.end(); ++it)
        cout << (*it)->get_classType() << "\t\t" << (*it)->get_name() << "\t\t" << (*it)->get_cost() << "\t\t" << (*it)->get_unlock_level() << "\t\t" << (*it)->get_damage() << endl;
    cout << endl;
}

void Market::DisplayMarket(){

    cout << "You have entered the Market!" << endl;
        Display_Items();
        Display_Spells();
        DisplayOnSell();
}

//Catching a Typo
//In case of wrong input, user will be asked to type the name again
//This function works generally for all Types of Lists
std::string Market::catch_wrongName(string name, string classType){

    string ch_name;
    if(classType == "Items"){
        list <Item*> :: iterator it;
        int found = 0;
        for(it = Weapons.begin(); it!=Weapons.end(); ++it){
            if ((*it)->get_name() == name)
                return name;
        }

        for(it = Armors.begin(); it!=Armors.end(); ++it){
            if ((*it)->get_name() == name)
                    return name;
        }

        for(it = Potions.begin(); it!=Potions.end(); ++it){
            if ((*it)->get_name() == name)
                    return name;
        }

        while (found == 0){
            cout << "Wrong Name for Item. Please try again." << endl;
            string n;
            cin >> n;
            for(it = Weapons.begin(); it!=Weapons.end(); ++it){
                if ((*it)->get_name() == n){
                    ch_name = n;
                    found = 1;
                    break;
                }
            }

            for(it = Armors.begin(); it!=Armors.end(); ++it){
                if ((*it)->get_name() == n){
                    ch_name = n;
                    found = 1;
                    break;
                }
            }

            for(it = Potions.begin(); it!=Potions.end(); ++it){
                if ((*it)->get_name() == n){
                    ch_name = n;
                    found = 1;
                    break;
                }
            }
        }
        return ch_name;
    }
    else if(classType == "Spells"){
        list <Spell*> :: iterator it;
        int found = 0;
        for(it = IceSpells.begin(); it!=IceSpells.end(); ++it){
            if ((*it)->get_name() == name)
                return name;
        }

        for(it = FireSpells.begin(); it!=FireSpells.end(); ++it){
            if ((*it)->get_name() == name)
                    return name;
        }

        for(it = LightingSpells.begin(); it!=LightingSpells.end(); ++it){
            if ((*it)->get_name() == name)
                    return name;
        }

        while (found == 0){
            cout << "Wrong Name for Spell. Please try again." << endl;
            string n;
            cin >> n;
            for(it = IceSpells.begin(); it!=IceSpells.end(); ++it){
                if ((*it)->get_name() == n){
                    ch_name = n;
                    found = 1;
                    break;
                }
            }

            for(it = FireSpells.begin(); it!=FireSpells.end(); ++it){
                if ((*it)->get_name() == n){
                    ch_name = n;
                    found = 1;
                    break;
                }
            }

            for(it = LightingSpells.begin(); it!=LightingSpells.end(); ++it){
                if ((*it)->get_name() == n){
                    ch_name = n;
                    found = 1;
                    break;
                }
            }
        }
        return ch_name;
    }
    else if (classType == "Search"){

        //at this part we are searching
        //for a specific Item/Spell on Sale
        //if it exists function returns YES
        //in other case it returns NO
        //this part is called by using "Search" as 2nd argument
        list <Item*> :: iterator it;
        for(it = ItemsOnSell.begin(); it!=ItemsOnSell.end(); ++it){
            if ((*it)->get_name() == name)
                return "YES";
        }

        list <Spell*> :: iterator ti;
        for(ti = SpellsOnSell.begin(); ti!=SpellsOnSell.end(); ++ti){
            if ((*ti)->get_name() == name)
                return "YES";
        }

        return "NO";
    }
    return NULL;
}

//Searching for a Specific Item or Spell
//Functions return the object itself for further usage
Item* Market::Search_Items(string name){
    list <Item*> :: iterator it;

    for(it = Weapons.begin(); it!=Weapons.end(); ++it){
        if ((*it)->get_name() == name)
            return *it;
    }

    for(it = Armors.begin(); it!=Armors.end(); ++it){
        if ((*it)->get_name() == name)
                return *it;
    }

    for(it = Potions.begin(); it!=Potions.end(); ++it){
        if ((*it)->get_name() == name)
                return *it;
    }
    return NULL;
}

Item* Market::Search_ItemsOnSell(string name){
    list <Item*> :: iterator it;

    for(it = ItemsOnSell.begin(); it!=ItemsOnSell.end(); ++it){
        if ((*it)->get_name() == name)
                return *it;
    }
    return NULL;
}

Spell* Market::Search_Spells(string name){
    list <Spell*> :: iterator it;

    for(it = IceSpells.begin(); it!=IceSpells.end(); ++it){
        if ((*it)->get_name() == name)
            return *it;
    }

    for(it = FireSpells.begin(); it!=FireSpells.end(); ++it){
        if ((*it)->get_name() == name)
                return *it;
    }

    for(it = LightingSpells.begin(); it!=LightingSpells.end(); ++it){
        if ((*it)->get_name() == name)
                return *it;
    }
    return NULL;
}

Spell* Market::Search_SpellsOnSell(string name){
    list <Spell*> :: iterator it;

    for(it = SpellsOnSell.begin(); it!=SpellsOnSell.end(); ++it){
        if ((*it)->get_name() == name)
                return *it;
    }
    return NULL;
}

//Lists of Items/Spells are Displayed for Every Team Member before Sale
//In order to be easier to choose what they prefer
//Everything on Market is unlimited
void Market::buy(){
    cout << "Choose Catecory" << endl;
    cout << "Press 1. for Items 2. for Spells" << endl;
    string category;
    cin >> category;

    int flag = 0;
    while(flag == 0){
        if ((category != "1") && (category != "2")){
            cout << "Wrong Input. Try Again." << endl;
            cout << "Choose Catecory" << endl;
            cout << "Press 1. for Items 2. for Spells" << endl;
            cin >> category;
        }
        else
            flag = 1;
    }

    Squad->Display_Team(1);
    cout << endl << endl <<"Enter the name of Hero who will use the Item/Spell" << endl;
    string n;
    cin >> n;
    n = Squad->catch_wrongName(n);

    if (category == "1"){
        Display_Items();
        buy_Item(n);
    }
    else if(category == "2"){
        Display_Spells();
        buy_Spell(n);
    }
}

//A Team Member can buy from Market or from other Team Members
//The 2nd option is only available when a Hero does not have enough money to buy from Market
void Market::buy_Item(string n){

    list <Hero*> Sq = Squad->get_myHeroes();
    list <Hero*> :: iterator it;

    cout << "Enter the name of the Item, you want to buy" << endl;
    string name;
    cin >> name;
    name = catch_wrongName(name,"Items");

    for(it = Sq.begin(); it!=Sq.end(); ++it){
        if((*it)->get_name() == n){
            if(((*it)->get_level() >= Search_Items(name)->get_unlock_level()) && ((*it)->get_money() >= Search_Items(name)->get_cost())){
                (*it)->buy(Search_Items(name));
                return;
            }
            else{
                cout << "You cannot buy this Item." << endl;
                if(Search_ItemsOnSell(name)!=NULL){
                    if((*it)->get_money() >= Search_ItemsOnSell(name)->get_cost()){

                        cout << "But you can buy it on Sale with only " << Search_ItemsOnSell(name)->get_cost() << endl;
                        cout << "Do you want to continue? Press YES/yes or NO/no" << endl;
                        string in;
                        cin >> in;
                        if((in == "YES")|| (in == "yes")){
                            (*it)->buy(Search_ItemsOnSell(name));
                        }
                        else if((in == "NO") || (in == "no"))
                            return;
                        else{
                            cout << "Not a possible option. Please answer YES/yes or NO/no: ";
                            while((in != "YES") && (in!="yes")){
                                string in;
                                cin >> in;
                                if((in == "YES")|| (in == "yes")){
                                    (*it)->buy(Search_ItemsOnSell(name));
                                    sell_Item(name);
                                    break;
                                }
                                else if((in == "NO") || (in == "no"))
                                    break;
                            }
                        }
                    }
                }
            }
        }
    }
}

void Market::buy_Spell(string n){

    list <Hero*> Sq = Squad->get_myHeroes();
    list <Hero*> :: iterator it;

    cout << "Enter the name of the Spell, you want to buy" << endl;
    string name;
    cin >> name;
    name = catch_wrongName(name,"Spells");

    for(it = Sq.begin(); it!=Sq.end(); ++it){
        if((*it)->get_name() == n){
            if(((*it)->get_level() >= Search_Spells(name)->get_unlock_level()) && ((*it)->get_money() >= Search_Spells(name)->get_cost())
                && ((*it)->get_magicPower() >= Search_Spells(name)->get_min_magicP())){
                (*it)->buy(Search_Spells(name));
                return;
            }
            else{
                cout << "You cannot buy this Spell." << endl;
                if(Search_SpellsOnSell(name)!=NULL){
                    if((*it)->get_money() >= Search_SpellsOnSell(name)->get_cost()){

                        cout << "But you can buy it on Sale with only " << Search_SpellsOnSell(name)->get_cost() << endl;
                        cout << "Do you want to continue? Press YES/yes or NO/no" << endl;
                        string in;
                        cin >> in;
                        if((in == "YES")|| (in == "yes")){
                            (*it)->buy(Search_SpellsOnSell(name));
                        }
                        else if((in == "NO") || (in == "no"))
                            return;
                        else{
                            cout << "Not a possible option. Please answer YES/yes or NO/no: ";
                            while((in != "YES") && (in!="yes")){
                                string in;
                                cin >> in;
                                if((in == "YES")|| (in == "yes")){
                                    (*it)->buy(Search_SpellsOnSell(name));
                                    sell_Item(name);
                                    break;
                                }
                                else if((in == "NO") || (in == "no"))
                                    break;
                            }
                        }
                    }
                }
            }
        }
    }
}

//Team Members can sell their Items in order to collect some money
//but he finally collects them only if an other member buys this specific Item
void Market::sell(){

    list <Hero*> Sq = Squad->get_myHeroes();
    list <Hero*> :: iterator it;

    cout << "Choose Category" << endl;
    cout << "Press 1. for Items 2. for Spells" << endl;
    string category;
    cin >> category;

    int flag = 0;
    while(flag == 0){
        if ((category != "1") && (category != "2")){
            cout << "Wrong Input. Try Again." << endl;
            cout << "Choose Catecory" << endl;
            cout << "Press 1. for Items 2. for Spells" << endl;
            string category;
            cin >> category;
        }
        else
            flag = 1;
    }

    Squad->Display_Team(1);
    cout << "Enter the name of Hero who will sell the Item" << endl;
    string name;
    cin >> name;
    name = Squad->catch_wrongName(name);

    if (category == "1"){
        for(it = Sq.begin(); it!=Sq.end(); ++it){
            if((*it)->get_name() == name){
                if((*it)->checkIFempty("Items") == 1){
                    cout << "Your Invetory is Empty. You cannot sell." << endl;
                    return;
                }
            }
        }
        sell_Item(name);
    }
    else if(category == "2"){
        for(it = Sq.begin(); it!=Sq.end(); ++it){
            if((*it)->get_name() == name){
                if((*it)->checkIFempty("Spells") == 1){
                    cout << "Your Invetory is Empty. You cannot sell." << endl;
                    return;
                }
            }
        }
        sell_Spell(name);
    }
    //DisplayOnSell();
}

void Market::sell_Item(string n){

    list <Hero*> Sq = Squad->get_myHeroes();
    list <Hero*> :: iterator it;

    for(it = Sq.begin(); it!=Sq.end(); ++it){
        if((*it)->get_name() == n)
            (*it)->checkInvetory("item");
    }

    cout << "Enter the name of the Item, you want to sell" << endl;
    string name, Type;
    cin >> name;

    for(it = Sq.begin(); it!=Sq.end(); ++it){
        if((*it)->get_name() == n){
            name = (*it)->searchInvetory(name);
            Item* item = (*it)->Search_Items(name);                    //Checking Invetory for Item
            Type = item->get_classType();
            (*it)->sell(item);

            if(Type == "Weapon"){                                    //Constructing a new Item and pushint into SpellsOnSell List
                Item *NewItem = new Weapon(name,(item->get_cost()/2),item->get_unlock_level(),item->get_damage(),item->get_hand_control());
                ItemsOnSell.push_back(NewItem);
            }

            else if(Type == "Potion"){
                Item *NewItem = new Potion(name,(item->get_cost()/2),item->get_unlock_level(),item->get_rate());
                ItemsOnSell.push_back(NewItem);
            }
            else{
                Item *NewItem = new Armor(name,(item->get_cost()/2),item->get_unlock_level(),item->get_reduction());
                ItemsOnSell.push_back(NewItem);
            }
        }
    }
}

void Market::sell_Spell(string n){

    list <Hero*> Sq = Squad->get_myHeroes();
    list <Hero*> :: iterator it;

    for(it = Sq.begin(); it!=Sq.end(); ++it){
        if((*it)->get_name() == n)
            (*it)->checkInvetory("spell");
    }

    cout << "Enter the name of the Spell, you want to sell" << endl;
    string name, Type;
    cin >> name;

    for(it = Sq.begin(); it!=Sq.end(); ++it){
        if((*it)->get_name() == n){
            name = (*it)->searchInvetory(name);
            Spell* spell = (*it)->Search_Spells(name);                    //Checking Invetory for Item
            Type = spell->get_classType();
            (*it)->sell(spell);

            if(Type == "IceSpell"){                                           //Constructing a new Item and pushint into SpellsOnSell List
                Spell *NewSpell = new IceSpell(name,(spell->get_cost()/2),spell->get_unlock_level(),spell->get_damage(),spell->get_min_magicP(),spell->get_reduction());
                SpellsOnSell.push_back(NewSpell);
            }

            else if(Type == "FireSpell"){
                Spell *NewSpell = new FireSpell(name,(spell->get_cost()/2),spell->get_unlock_level(),spell->get_damage(),spell->get_min_magicP(),spell->get_reduction());
                SpellsOnSell.push_back(NewSpell);
            }
            else{
                Spell *NewSpell = new LightingSpell(name,(spell->get_cost()/2),spell->get_unlock_level(),spell->get_damage(),spell->get_min_magicP(),spell->get_reduction());
                SpellsOnSell.push_back(NewSpell);
            }
        }
    }
}

//Here is "a some - kind of menu"
//Player choose whether to buy an Item or sell, to exit or to stay in Market
void Market::visit_Market(){

    this->print_effects();

    cout << endl << '\t' << "Press BUY/buy , SELL/sell or EXIT/exit according to your purposes : " ;

    string answer;
    cin >> answer;

    if((answer == "BUY") || (answer == "buy")){
        this->buy();
        cout << "Do you want to buy anything else?(Choose YES/yes or NO/no): ";
        string option;
        cin >> option;

        while((option == "YES") || (option == "yes")){
            this->buy();
            cout << "Do you want to buy anything else?(Choose YES/yes or NO/no): ";
            string option;
            cin >> option;
            if((option == "NO") || (option == "no"))
                break;
        }
        while((option != "YES") && (option != "yes") && (option != "NO") && (option != "no")){
            cout << "This is not an option. Try again!" << endl;
            cin >> option;
            while((option == "YES") || (option == "yes")){
                this->buy();
                cout << "Do you want to buy anything else?(Choose YES/yes or NO/no): ";
                string option;
                cin >> option;
                if((option == "NO") || (option == "no"))
                    break;
            }
            if( (option == "NO") || (option == "no") )
                break;
            }

    }
    else if((answer == "SELL")|| (answer == "sell")){
         this->sell();
         cout << "Do you want to sell anything else?(Choose YES/yes or NO/no): ";
         string option;
         cin >> option;

        while((option == "YES") || (option == "yes")){
            this->sell();
            cout << "Do you want to sell anything else?(Choose YES/yes or NO/no): ";
            string option;
            cin >> option;
            if((option == "NO") || (option == "no"))
                break;
        }
        while((option != "YES") && (option != "yes") && (option != "NO") && (option != "no")){
            cout << "This is not an option. Try again!" << endl;
            cin >> option;
            while((option == "YES") || (option == "yes")){
                this->buy();
                cout << "Do you want to buy anything else?(Choose YES/yes or NO/no): ";
                string option;
                cin >> option;
                if((option == "NO") || (option == "no"))
                    break;
            }
            if( (option == "NO") || (option == "no") )
                break;
            }
    }
    else if((answer == "EXIT") || (answer == "exit"))
        return;

    else{

        cout << "Not a valid option. Please answer correctly." << endl;
        while((answer != "YES") || (answer != "NO")){

            cout << endl << '\t' << "Press BUY/buy , SELL/sell or EXIT/exit according to your purposes : " ;
            string answer;
            cin >> answer;

            if((answer == "BUY")|| (answer == "buy")){
                this->buy();

                cout << "Do you want to buy anything else?(Choose YES/yes or NO/no): ";
                string option;
                cin >> option;

                while((option == "YES") || (option == "yes")){
                    this->buy();
                    cout << "Do you want to buy anything else?(Choose YES/yes or NO/no): ";
                    string option;
                    cin >> option;

                    if( option == "NO" || option == "no" )
                        break;
                }
                break;
            }
            else if((answer == "SELL") || (answer == "sell")){
                 this->sell();
                 cout << "Do you want to sell anything else?(Choose YES/yes or NO/no): ";
                 string option;
                 cin >> option;

                 while((option == "YES") || (option == "yes")){
                    this->sell();
                    cout << "Do you want to sell anything else?(Choose YES/yes or NO/no): ";
                    string option;
                    cin >> option;

                    if((option == "NO") || (option == "no"))
                        break;
                }
                break;
            }
            else if((answer == "EXIT") || (answer == "exit"))
                break;
        }
    }
}

MyTeam* Market::get_myTeam(){
    return this->Squad;
}

//Deleting all the Items , constructed in first place
Market::~Market(){

    list <Item*> :: iterator it;

    for(it=Weapons.begin(); it!=Weapons.end(); ++it)
        delete *it;
    for(it=Armors.begin(); it!=Armors.end(); ++it)
        delete *it;
    for(it=Potions.begin(); it!=Potions.end(); ++it)
        delete *it;
    for(it=ItemsOnSell.begin(); it!=ItemsOnSell.end(); ++it)
        delete *it;

    list <Spell*> :: iterator i;

    for(i=IceSpells.begin(); i!=IceSpells.end(); ++i)
        delete *i;
    for(i=FireSpells.begin(); i!=FireSpells.end(); ++i)
        delete *i;
    for(i=LightingSpells.begin(); i!=LightingSpells.end(); ++i)
        delete *i;
    for(i=SpellsOnSell.begin(); i!=SpellsOnSell.end(); ++i)
        delete *i;
}

//_______________________________________________________________________________________________________________________________//
//And Some effects down here
void Market::print_effects(){

    cout << endl << endl << endl;
    cout << '\t' << '\t'  << "(@)" << KGRN << "                      /|7      ))_((     /|7                            "  << endl;
    cout << '\t' << '\t' <<  "|-|" << KGRN << "                     / | 7    (/7|/7)   / | 7                      " << KWHT << "(@)" << endl;
    cout << '\t' << '\t' <<  "| | -------------------" << KGRN << "/--|-voV---1`|'/--Vov-|--7" << KWHT << "---------------------|-|" << endl;
    cout << '\t' << '\t' <<  "|-|" << KGRN << "                         '^`   (o o)  '^`                          " << KWHT << "| |" << endl;
    cout << '\t' << '\t' <<  "| |" << KWHT<< "                               `1Y1'                               " << KWHT << "|-|" << endl;
    cout << '\t' << '\t' <<  "|-|                                                                   | |" << endl;
    cout << '\t' << '\t' <<  "| |" << KYEL << BOLD("           W E L C O M E   T O   T H E   M A R K E T  !            ") << KWHT << "|-|" << endl;
    cout << '\t' << '\t' <<  "|-|                                                                   | |" << endl;
    cout << '\t' << '\t' <<  "| |                                                                   |-|" << endl;
    cout << '\t' << '\t' <<  "|_|___________________________________________________________________| |" << endl;
    cout << '\t' << '\t' <<  "(@)" << KGRN << "              l  / 7 /         ( (      7 / 7   l                  " << KWHT << "|-|" << endl;
    cout << '\t' << '\t' << KGRN << "                 l /   V           7 7       V   7 l                  " << KWHT << "(@)" << endl;
    cout << '\t' << '\t' << KGRN << "                 l/                _) )_          7I"                      << endl;
    cout << '\t' << '\t' << KGRN << "                                  `7 /'" << KWHT << endl;

}
