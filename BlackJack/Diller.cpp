#include "Diller.h"
void Diller::fillCards(Deck a) {
    while (score < 16) {
        Card tmp = a.getCard();
        v.push_back(tmp);
        score += tmp.calculateCard();
        if (score < 12) tmp.displayCard();
        else cout << " XX";
        a.number--;
    }
}