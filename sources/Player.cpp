#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include <map>
#include <set>
#include "Player.hpp"
#include <array>
using namespace pandemic;
using namespace std;

Player &Player::drive(City CI)
{
        if (Board::is_connected(city, CI))
        {
                city = CI;
        }
        else
        {
                throw invalid_argument("Error");
        }
        fly(city);
        return *this;
}
Player &Player::fly_direct(City CI)
{
        if (city == CI || cards.count(CI) == 0)
        {
                throw invalid_argument("Error");
        }
        city = CI;
        cards.erase(CI);
        fly(city);
        return *this;
}
Player &Player::fly_charter(City CI)
{
        if (cards.count(city) == 0)
        {
                throw invalid_argument("Error");
        }
        cards.erase(city);
        city = CI;
        fly(city);
        return *this;
}
Player &Player::fly_shuttle(City CI)
{
        if(this->city==CI){
                throw invalid_argument("Error");
        }
        if ((!board.hasResStation(this->city) || !board.hasResStation(CI)))
        {
                throw invalid_argument("Error");
        }
        city = CI;
        fly(city);
        return *this;
}
Player &Player::build()
{
        if (cards.count(city) == 0)
        {
               throw invalid_argument("No card");
        }
        board.buildReStation(city);
        cards.erase(city);
        return *this;
}
Player &Player::discover_cure(Color color)
{
        if(!board.hasResStation(this->city)){
                throw invalid_argument("Error");
        }
        {
                int Count = 0;
                for (auto card : cards)
                {
                        if (Board::GetColor(card) == color)
                        {
                                Count++;
                        }
                }
                if (Count < color)
                {
                        throw invalid_argument("Error");
                }

                for (auto it = cards.begin(); it != cards.end();)
                {
                        if (Board::GetColor(*it) == color){
                                it = cards.erase(it);
                        }
                        else{
                                ++it;
                        }
                }

                board.AddCure(color);
                return *this;
        }
}
Player &Player::treat(City CI)
{
        if (CI == city && board[CI] > 0)
        {
                if (!board.CureIsFound(CI))
                {     
                        board[CI]--;
                        
                }
                else
                {
                        board[CI] = 0;
                }
                return *this;
        }
        throw invalid_argument("");
}
Player &Player::take_card(City CI)
{
        cards.insert(CI);
        return *this;
}
