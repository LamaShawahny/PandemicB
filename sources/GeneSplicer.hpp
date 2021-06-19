#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic
{

    class GeneSplicer: public Player
    {
    public:
        GeneSplicer(Board& BOR, City CI) : Player(BOR, CI, "GeneSplicer"){};
        Player& discover_cure(Color COL) override;
    };
};