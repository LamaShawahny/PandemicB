#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"
#include <set>
#include <map>
#include <iostream>
using namespace std;
static map<City, set<City>> neighbors{
    { Algiers, {Madrid, Paris, Istanbul, Cairo } },
    { Atlanta, {Chicago, Miami, Washington } },
    { Baghdad, {Tehran, Istanbul, Cairo, Riyadh, Karachi } },
    { Bangkok, {Kolkata, Chennai, Jakarta, HoChiMinhCity, HongKong } },
    { Beijing, {Shanghai, Seoul } },
    { Bogota, {MexicoCity, Lima, Miami, SaoPaulo, BuenosAires } },
    { BuenosAires, {Bogota, SaoPaulo } },
    { Cairo, {Algiers, Istanbul, Baghdad, Khartoum, Riyadh } },
    { Chennai, {Mumbai, Delhi, Kolkata, Bangkok, Jakarta } },
    { Chicago, {SanFrancisco, LosAngeles, MexicoCity, Atlanta, Montreal } },
    { Delhi, {Tehran, Karachi, Mumbai, Chennai, Kolkata } },
    { Essen, {London, Paris, Milan, StPetersburg } },
    { HoChiMinhCity, {Jakarta, Bangkok, HongKong, Manila } },
    { HongKong, {Bangkok, Kolkata, HoChiMinhCity, Shanghai, Manila, Taipei } },
    { Istanbul, {Milan, Algiers, StPetersburg, Cairo, Baghdad, Moscow } },
    { Jakarta, {Chennai, Bangkok, HoChiMinhCity, Sydney } },
    { Johannesburg, {Kinshasa, Khartoum } },
    { Karachi, {Tehran, Baghdad, Riyadh, Mumbai, Delhi } },
    { Khartoum, {Cairo, Lagos, Kinshasa, Johannesburg } },
    { Kinshasa, {Lagos, Khartoum, Johannesburg } },
    { Kolkata, {Delhi, Chennai, Bangkok, HongKong } },
    { Lagos, {SaoPaulo, Khartoum, Kinshasa } },
    { Lima, {MexicoCity, Bogota, Santiago } },
    { London, {NewYork, Madrid, Essen, Paris } },
    { Montreal, {Chicago, Washington, NewYork } },
    { Moscow, {StPetersburg, Istanbul, Tehran } },
    { LosAngeles, {SanFrancisco, Chicago, MexicoCity, Sydney } },
    { Taipei, {Shanghai, HongKong, Osaka, Manila } },
    { Tehran, {Baghdad, Moscow, Karachi, Delhi } },
    { Tokyo, {Seoul, Shanghai, Osaka, SanFrancisco } },
    { Miami, {Atlanta, MexicoCity, Washington, Bogota } },
    { Milan, {Essen, Paris, Istanbul } },
    { Madrid, {London, NewYork, Paris, SaoPaulo, Algiers } },
    { Manila, {Taipei, SanFrancisco, HoChiMinhCity, Sydney, HongKong } },
    { MexicoCity, {LosAngeles, Chicago, Miami, Lima, Bogota } },
    { Mumbai, {Karachi, Delhi, Chennai } },
    { NewYork, {Montreal, Washington, London, Madrid } },
    { Osaka, {Taipei, Tokyo } },
    { Paris, {Algiers, Essen, Madrid, Milan, London } },
    { Riyadh, {Baghdad, Cairo, Karachi } },
    { SanFrancisco, {LosAngeles, Chicago, Tokyo, Manila } },
    { Santiago, {Lima } },
    { SaoPaulo, {Bogota, BuenosAires, Lagos, Madrid } },
    { StPetersburg, {Essen, Istanbul, Moscow } },
    { Sydney, {Jakarta, Manila, LosAngeles } },
    { Seoul, {Beijing, Shanghai, Tokyo } },
    { Shanghai, {Beijing, HongKong, Taipei, Seoul, Tokyo } },
    { Washington, {Atlanta, NewYork, Montreal, Miami } }};

static map<City, Color> Cities{
    { Algiers, Black },
    { Atlanta, Blue },
    { Baghdad, Black },
    { Bangkok, Red },
    { Beijing, Red },
    { Bogota, Yellow },
    { BuenosAires, Yellow },
    { Cairo, Black },
    { Chennai, Black },
    { Chicago, Blue },
    { Delhi, Black },
    { Essen, Blue },
    { HoChiMinhCity, Red },
    { HongKong, Red },
    { Istanbul, Black },
    { Jakarta, Red },
    { Johannesburg,Yellow },
    { Karachi, Black },
    { Khartoum, Yellow },
    { Kinshasa, Yellow },
    { Kolkata, Black },
    { Lagos, Yellow },
    { Lima, Yellow },
    {London, Blue },
    { LosAngeles, Yellow },
    { Madrid, Blue },
    { Manila, Red },
    { MexicoCity, Yellow },
    { Miami, Yellow },
    { Milan, Blue },
    { Montreal, Blue },
    { Moscow, Black },
    { Mumbai, Black },
    { NewYork,Blue },
    { Osaka, Red },
    {Paris, Blue },
    { Riyadh, Black },
    { SanFrancisco, Blue },
    { Santiago, Yellow },
    { SaoPaulo, Yellow },
    { Seoul, Red },
    { Shanghai, Red },
    { StPetersburg, Blue },
    { Sydney, Red },
    { Taipei, Red },
    { Tehran, Black },
    { Tokyo, Red },
    { Washington, Blue }};


namespace pandemic
{

    int &Board::operator[](City CI)
    {
        return Diseas[CI];
    }
    bool Board::is_clean()
    {
        for (auto i : Diseas)
        {
            if (i.second != 0)
            {
                return false;
            }
        }
        return true;
    }
    bool Board::is_connected(City &firstCity, City &secCity)
    {
        if (neighbors.count(firstCity) == 0){
            return false;
        }
        if (neighbors[firstCity].count(secCity) == 0)
        {
            return false;
        }
        return true;
        
    }
    void Board::buildReStation(City CI)
    {
        reStations.insert(CI);
    }
    bool Board::hasResStation(City CI)
    {
        return !(reStations.count(CI) == 0);
    }
    void Board::AddCure(Color COL)
    {
        med.insert(COL);
    }
    bool Board::CureIsFound(City CI)
    {
        return !(med.count(GetColor(CI)) == 0);
    }
    bool Board::CureIsFoundColor(Color COL)
    {
    
        return !(med.count((COL)) == 0);
    }
    void Board::remove_cures()
    {
        med.clear();
    }
    Color Board::GetColor(City CI)
    {
        return Cities.at(CI);
    }
    ostream &operator<<(ostream &o, Board &BOR)
    {
        o<<"THIS IS MY BOARD";
        return o;
    }
    

};
