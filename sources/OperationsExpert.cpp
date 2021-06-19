#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "OperationsExpert.hpp"
namespace pandemic{
    Player& OperationsExpert::build(){
        if (!board.hasResStation(city)){
            board.buildReStation(city);
            }
        return *this;
    }
};