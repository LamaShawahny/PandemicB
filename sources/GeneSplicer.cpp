#include "GeneSplicer.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include <array>
using namespace std;
const int NEED_CURES = 5;

namespace pandemic
{
    Player &GeneSplicer::discover_cure(Color COL)
    {
        if(cards.size() < NEED_CURES){
            throw invalid_argument{"Error"};
        }
        if(!board.hasResStation(city)){
             throw invalid_argument{"Error"};
        }
        
        if(!board.CureIsFoundColor(COL)){
        auto i= cards.begin();
        while(i != cards.end()){ 
            i=cards.erase(i);
            i++; 
        }
        board.AddCure(COL);
    }
    return *this;
    }
};