#include "Player.h"

void Player::takeCard(Deck a) {
    Card tmp = a.getCard();
    v.push_back(tmp);
    score += tmp.calculateCard();
    tmp.displayCard();
    cout << "\n����: " << score << endl;
}
void Player::makeBet() {
    cout << "�������� ������: ";
    cin >> bet;
    cout << "���� ������: " << bet << "$" << endl;
}
