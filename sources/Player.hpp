#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include <set>
using namespace std;
namespace pandemic
{

    class Player
    {

    public:
        Board& board;
        City city;
        set<City> cards;
        string ROLE;
        Player(Board &BOR, City CI, string NAME = "Player") : board(BOR), city(CI), ROLE(NAME){};
        Player &drive(City CI);
         virtual Player &fly_direct(City CI);
        Player &fly_charter(City CI);
        Player &fly_shuttle(City CI);
        virtual Player &build();
        virtual Player &discover_cure(Color COL);
        virtual Player &treat(City CI);
        Player &take_card(City CI);
        virtual void fly(City CI){};
        string role(){return ROLE;};
    };
};