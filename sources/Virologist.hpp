#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic
{

    class Virologist: public Player
    {
    public:
        Virologist(Board& BOR, City CI) : Player(BOR, CI,"Virologist"){};
        Player &treat(City CI) override;
    };
};