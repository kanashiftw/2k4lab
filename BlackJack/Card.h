#pragma once
#include "IFormattable.h"
//////////////////////////////////////////////////////////////////
//      ����� ����� ���������� ����� �����, �������� �����,     //
//     2 ������������ � ����������� ������ ����������� �����,   //
//      ������������ �� ����������, � ���������� �� �����       //
//////////////////////////////////////////////////////////////////
enum CardSuit { CLUBS, DIAMONDS, HEARTS, SPADES };
enum CardRank { TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE };
class Card: public IFormattable {
public:
    CardSuit suit;
    CardRank rank;
    Card() {}
    Card(CardSuit _suit, CardRank _rank) {
        suit = _suit;
        rank = _rank;
    }
    void displayCard();
    void setCard();
    int calculateCard();
    string Format();
    virtual void Prettyprint()override;
};