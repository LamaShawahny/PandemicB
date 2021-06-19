#include"FieldDoctor.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include <iostream>
#include <sstream>
using namespace std;
using namespace pandemic;

namespace pandemic{
    Player& FieldDoctor::treat(City CI){
        if(!((board[CI] > 0)&&( CI == city || Board::is_connected(city, CI)))){
             throw invalid_argument("Error");
        }
        if (board.CureIsFound(CI))
        {
            board[CI] = 0;
            return *this;
        }
        board[CI]--;
        return *this;

    }
};