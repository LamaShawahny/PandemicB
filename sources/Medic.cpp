#include"Medic.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"
using namespace std;

namespace pandemic{
    Player& Medic::treat(City CI){
        if (CI == city && board[CI] > 0)
        {
            board[CI] = 0;
            return *this;
        }
        throw invalid_argument("Error");
    }

    void Medic::fly(City CI){
        if (board.CureIsFound(CI))
        {
            board[CI] = 0;
        }
    }
};