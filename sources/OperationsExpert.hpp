#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic{

    class OperationsExpert: public Player {

        public:
        OperationsExpert(Board& BOR, City CI):Player(BOR,CI,"OperationsExpert"){};
        Player& build() override;
    };
};