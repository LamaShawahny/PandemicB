#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic{

    class Scientist: public Player {
        private:
        int number;
        public:
        Scientist(Board& BOR, City CI, int number):Player(BOR,CI,"Scientist"), number(number){};
        Player& discover_cure(Color c) override;
    };
};