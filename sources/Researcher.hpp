#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic{

    class Researcher: public Player {

        public:
        Researcher(Board& BOR, City CI):Player(BOR,CI,"Researcher"){};
        Player& discover_cure(Color COL) override;
    };
};