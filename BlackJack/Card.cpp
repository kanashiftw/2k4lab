#include "Card.h"
#include <iostream>
using namespace std;
//����������� ������ ������� �����
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
//����� ������ ����� �� �����
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
//����� ������� ���������� �����
void Card::setCard() {
    suit = static_cast<CardSuit>(rand() % SPADES);
    rank = static_cast<CardRank>(rand() % ACE);
}

string Card::Format() {
    string tmp = "----\n|";
    switch (rank)
    {
    case TWO:tmp+='2';   break;
    case THREE:tmp += '3'; break;
    case FOUR:tmp += '4';  break;
    case FIVE:tmp += '5';  break;
    case SIX:tmp += '6';   break;
    case SEVEN:tmp += '7'; break;
    case EIGHT:tmp += '8'; break;
    case NINE:tmp += '9';  break;
    case TEN:tmp += "10";  break;
    case JACK:tmp += 'J';  break;
    case QUEEN:tmp += 'Q'; break;
    case KING:tmp += 'K';  break;
    case ACE:tmp += 'A';
    }
    switch (suit)
    {
    case CLUBS:tmp += "\x06"; break;
    case DIAMONDS:tmp += "\x05"; break;
    case HEARTS:tmp += "\x04"; break;
    case SPADES:tmp += "\x03"; break;
    }
    tmp += "|\n----";
    return tmp;
}
void Card::Prettyprint() {
   string ex= Format();
   cout<<ex;
}