#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic{

    class Medic: public Player {
        public:
        Medic(Board& BOR, City CI):Player(BOR,CI,"Medic"){};
        Player &treat(City CI) override;
        void fly(City CI) override;
    };
};