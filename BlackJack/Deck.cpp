#include <random>
#include "Deck.h"
#include <algorithm>
#include <iostream>
using namespace std;
// ����� ������ ���������� ���� �� �����
void Deck::printDeck() {
    cout << "������ [" << number + 1 << "]\t";
}
//����� �������� ������� ����� ������
Card Deck::getCard() {
    return cards[number];
}
//��������� ��������� ������
void Deck::generateDeck() {
    for (int i = 0; i < 52; i++) {
        cards[i].suit = static_cast<CardSuit>(i % 4);
        cards[i].rank = static_cast<CardRank>(i % 13);
    }
    random_shuffle(begin(cards), end(cards));
    cout << "\n";
}
