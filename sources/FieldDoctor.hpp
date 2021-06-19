#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic{

    class FieldDoctor: public Player {

        public:
        FieldDoctor(Board& BOR, City CI):Player(BOR,CI,"FieldDoctor"){};
        Player &treat(City CI) override;
    };
};