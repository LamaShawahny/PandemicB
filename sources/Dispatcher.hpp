#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic{

    class Dispatcher: public Player {

        public:
        Dispatcher(Board& BOR, City CI):Player(BOR,CI, "Dispatcher"){};
        Player &fly_direct(City CI) override;
 
    };
};