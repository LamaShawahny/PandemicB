#include"Virologist.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"
using namespace std;

namespace pandemic{
    Player& Virologist::treat(City CI){
        if(board[CI] == 0||(cards.count(CI)==0 && CI!=city)){
        throw invalid_argument{"Error" };
    }
    if(!board.CureIsFound(CI))
    {
        board[CI]--;
    }
    else{
         board[CI]=0;
    }
    return *this;
    }
};