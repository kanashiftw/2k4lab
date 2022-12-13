#include "Game.h"
Game::Game() {
    i.makeBet();
    srand(time(0));
    for (int i = 0; i < 4; i++) {
        Deck tmp;
        deck_vec.push_back(tmp);
        deck_vec[i].generateDeck();
    }
    cout << "����� �������:" << endl;
    srand(time(0));
    Deck sdf = deck_vec[0];
    he.fillCards(sdf);
    deck_vec[0].number -= he.v.size();
    cout << endl;
    cout << "------------------------------------------------------------------" << endl;
    while (action == 1) {
        try {
            cout << "�������� ������: " << "1/2/3/4\n";
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
            cout << "\n�������� ��� �����?\n1 - �� \n2 - ���\n3 - ������� ������\n";
            cin >> action;
            cout << endl;
            if (i.score > 21) throw invalid_argument("�������!");
        }
        catch (invalid_argument& e) {
            cerr << e.what() << endl;
            break;
        }
    }
    if (action == 3) {
        cout << "�������� ������: " << "1/2/3/4\n";
        cin >> decknum;
        i.bet *= 2;
        i.takeCard(deck_vec[decknum]);
        deck_vec[decknum].number--;
        cout << "�� ������� ������: " << i.bet << '$' << endl;
    }
    for (int j = 0;j < i.v.size(); j++) {
        if (i.v[j].calculateCard() != 7) prem = false;
    }
    if (prem) {
        cout << "�����������! �� �������� ����: " << i.bet * 12 << endl << endl;
    }
    else
        if (i.score <= 21) {
            cout << "����� �������: " << endl;
            for (int i = 0; i < he.v.size();i++) {
                he.v[i].displayCard();
                cout << ' ';
            }
            cout << endl << endl;
            if (i.score == 21) cout << "������! 21!, ��� �������: " << i.bet * 2 << '$';
            else if (i.score > he.score) cout << "������!\n��� ����: " << i.score
                << " ������ ����� �������: " << he.score
                << "\n��� ������� : " << i.bet * 2 << '$';
            else if (i.score < he.score && he.score <= 21) cout << "���������!\n��� ����: " << i.score
                << " ������ ����� �������: " << he.score;
            else if (i.score < he.score) cout << "������ �� �����, ������� � �������: " << he.score
                << "\n��� ������� : " << i.bet * 2 << '$';
            else cout << "�����!\n��� ���� : " << i.score
                << " ����� ����� ������� : " << he.score;
        }
}