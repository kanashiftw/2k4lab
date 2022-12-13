#include "Player.h"

void Player::takeCard(Deck a) {
    Card tmp = a.getCard();
    v.push_back(tmp);
    score += tmp.calculateCard();
    tmp.displayCard();
    cout << "\nСчет: " << score << endl;
}
void Player::makeBet() {
    cout << "Сделайте ставку: ";
    cin >> bet;
    cout << "Ваша ставка: " << bet << "$" << endl;
}
