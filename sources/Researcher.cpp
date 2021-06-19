#include "Researcher.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include<array>
using namespace std;
const int cure_NUM = 5;

namespace pandemic
{
        Player &Researcher::discover_cure(Color COL)
        {
                int count = 0;
                for (auto card : cards)
                {
                        if (Board::GetColor(card) == COL)
                        {
                                count++;
                        }
                }
                if (count < cure_NUM)
                {
                        throw invalid_argument("Error");
                }
                for (auto itr = cards.begin(); itr != cards.end(); count++)
                {
                        if (Board::GetColor(*itr) == COL){itr = cards.erase(itr);}
                        else{++itr;}
                }
                board.AddCure(COL);
                return *this;
        }
};