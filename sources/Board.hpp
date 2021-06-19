#pragma once
#include "City.hpp"
#include "Color.hpp"
#include <map>
#include <set>
#include <iostream>
using namespace std;
namespace pandemic {

    class Board {
        private:
        set<City> reStations;
        set<Color> med;
        map<City, int> Diseas;
       
        public:
            Board() {}

            int& operator[](City CI);
            bool is_clean();
            static bool is_connected(City& firstCity, City& secC);
            void buildReStation(City CI);
            bool hasResStation(City CI);
            void AddCure(Color COL);
            bool CureIsFound(City CI);
            void remove_cures();
            bool CureIsFoundColor(Color COL);
            static Color GetColor(City CI);
            friend ostream& operator<<(ostream& o, Board& BOR);
    };



}