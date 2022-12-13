#pragma once
#include <iostream>
#include <vector>
#include "Card.h"
#include "Deck.h"
using namespace std;
////////////////////////////////////////////////////////////////////////////
//           йкюяя хцпнй, яндепфюыхи явер хцпнйю, бейрнп йюпр хцпнйю     //
//           лернд бгърхъ йпюимеи йюпрш йнкндш                           //
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