#pragma once
#include "Card.h"
///////////////////////////////////////////////////////////////////////
//          ����� ������, ���������� � ���� ������ ������� �����,    //
//          ������ �������� ������ CARD � ����������� ������         //
//          �������� �����, ��������� ��������� ������               // 
///////////////////////////////////////////////////////////////////////

class Deck {
public:
    int number = 51;
    Card cards[52];
    Card getCard();
    void generateDeck();
    void printDeck();
};