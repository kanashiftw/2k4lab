#pragma once
#include "Player.h"
#include "Diller.h"
#include <iostream>
#include <algorithm>
#include <random>

////////////////////////////////////////////////////////////////////
//     ����� ����, ���������� ������, ������ � ������� ������    //
///////////////////////////////////////////////////////////////////
class Game {
public:
    Player i;
    Diller he;
    vector <Deck>deck_vec;
    bool prem = true;
    int action = 1;
    int decknum;
    Game();
};