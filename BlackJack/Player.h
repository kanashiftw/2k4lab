#pragma once
#include <iostream>
#include <vector>
#include "Card.h"
#include "Deck.h"
using namespace std;
////////////////////////////////////////////////////////////////////////////
//           ����� �����, ���������� ���� ������, ������ ���� ������     //
//           ����� ������ ������� ����� ������                           //
///////////////////////////////////////////////////////////////////////////

class Player {
public:
    int bet = 0;
    int score = 0;
    vector<Card> v;
    Player() {}
    void takeCard(Deck a);
    void makeBet();
};