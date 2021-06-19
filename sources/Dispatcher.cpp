#include"Dispatcher.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"
using namespace std;
using namespace pandemic;

namespace pandemic{
    Player& Dispatcher::fly_direct(City CI){
        if (city == CI)
        {
            throw invalid_argument("Error");
        }
        if(!board.hasResStation(city)){
            return Player:: fly_direct(CI);
        }
        city = CI;
        return *this;
    }
};