#include "Card.h"
#include <iostream>
using namespace std;
//Определение метода расчета очков
int Card::calculateCard() {
    switch (rank) {
    case TWO: return 2;
    case THREE: return 3;
    case FOUR: return 4;
    case FIVE: return 5;
    case SIX: return 6;
    case SEVEN: return 7;
    case EIGHT: return 8;
    case NINE: return 9;
    case TEN: return 10;
    case JACK: return 10;
    case QUEEN: return 10;
    case KING: return 10;
    case ACE: return 11;
    }
}
//Метод вывода карты на экран
void Card::displayCard()
{
    switch (rank)
    {
    case TWO:cout << '2';   break;
    case THREE:cout << '3'; break;
    case FOUR:cout << '4';  break;
    case FIVE:cout << '5';  break;
    case SIX:cout << '6';   break;
    case SEVEN:cout << '7'; break;
    case EIGHT:cout << '8'; break;
    case NINE:cout << '9';  break;
    case TEN:cout << "10";  break;
    case JACK:cout << 'J';  break;
    case QUEEN:cout << 'Q'; break;
    case KING:cout << 'K';  break;
    case ACE:cout << 'A';
        cout << ' ';
    }
    switch (suit)
    {
    case CLUBS:cout << "\x06"; break;
    case DIAMONDS:cout << "\x05"; break;
    case HEARTS:cout << "\x04"; break;
    case SPADES:cout << "\x03"; break;
    }
}
//Метод задания параметров карте
void Card::setCard() {
    suit = static_cast<CardSuit>(rand() % SPADES);
    rank = static_cast<CardRank>(rand() % ACE);
}