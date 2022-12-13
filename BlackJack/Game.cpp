#include "Game.h"
Game::Game() {
    i.makeBet();
    srand(time(0));
    for (int i = 0; i < 4; i++) {
        Deck tmp;
        deck_vec.push_back(tmp);
        deck_vec[i].generateDeck();
    }
    cout << "Карты диллера:" << endl;
    srand(time(0));
    Deck sdf = deck_vec[0];
    he.fillCards(sdf);
    deck_vec[0].number -= he.v.size();
    cout << endl;
    cout << "------------------------------------------------------------------" << endl;
    while (action == 1) {
        try {
            cout << "Выберите колоду: " << "1/2/3/4\n";
            cin >> decknum;
            switch (decknum) {
            case 1:i.takeCard(deck_vec[0]);
                deck_vec[0].number--;
                break;
            case 2:i.takeCard(deck_vec[1]);
                deck_vec[1].number--;
                break;
            case 3:i.takeCard(deck_vec[2]);
                deck_vec[2].number--;
                break;
            case 4:i.takeCard(deck_vec[3]);
                deck_vec[3].number--;
                break;
            }
            for (int i = 0; i < 4; i++) {
                deck_vec[i].printDeck();
            }
            cout << "\nВытянуть еще карту?\n1 - да \n2 - нет\n3 - удвоить ставку\n";
            cin >> action;
            cout << endl;
            if (i.score > 21) throw invalid_argument("Перебор!");
        }
        catch (invalid_argument& e) {
            cerr << e.what() << endl;
            break;
        }
    }
    if (action == 3) {
        cout << "Выберите колоду: " << "1/2/3/4\n";
        cin >> decknum;
        i.bet *= 2;
        i.takeCard(deck_vec[decknum]);
        deck_vec[decknum].number--;
        cout << "Вы удвоили ставку: " << i.bet << '$' << endl;
    }
    for (int j = 0;j < i.v.size(); j++) {
        if (i.v[j].calculateCard() != 7) prem = false;
    }
    if (prem) {
        cout << "Поздравляем! Вы выиграли приз: " << i.bet * 12 << endl << endl;
    }
    else
        if (i.score <= 21) {
            cout << "Карты диллера: " << endl;
            for (int i = 0; i < he.v.size();i++) {
                he.v[i].displayCard();
                cout << ' ';
            }
            cout << endl << endl;
            if (i.score == 21) cout << "Победа! 21!, Ваш выигрыш: " << i.bet * 2 << '$';
            else if (i.score > he.score) cout << "Победа!\nВаш счет: " << i.score
                << " больше счета диллера: " << he.score
                << "\nВаш выигрыш : " << i.bet * 2 << '$';
            else if (i.score < he.score && he.score <= 21) cout << "Поражение!\nВаш счет: " << i.score
                << " меньше счета диллера: " << he.score;
            else if (i.score < he.score) cout << "Победа по очкам, перебор у диллера: " << he.score
                << "\nВаш выигрыш : " << i.bet * 2 << '$';
            else cout << "Ровно!\nВаш счет : " << i.score
                << " равен счету диллера : " << he.score;
        }
}