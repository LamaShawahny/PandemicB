#include"Scientist.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"
using namespace std;


namespace pandemic{

    Player &Scientist::discover_cure(Color COL){
        if(!board.CureIsFoundColor(COL)){
        if(!board.hasResStation(city)){throw invalid_argument{"Error"};}
        int C_C=0;
        for(auto card: cards){
            if(Board::GetColor(card) == COL){
                C_C++;
            }
        }
        if(C_C < number){
                throw invalid_argument{"Error"};
                } 
        auto i= cards.begin();
        while(i != cards.end()){
            if(Board::GetColor(*i) != COL){ 
            i++;
            }
            else{
            i=cards.erase(i);
            C_C--;
            }
        }
        board.AddCure(COL);
    }
    return *this;
};
}