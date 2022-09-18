#include <iostream>
#include <algorithm>
#include <random>
#include <Windows.h>
#include <vector>

enum CardSuit { CLUBS, DIAMONDS, HEARTS, SPADES };
enum CardRank { TWO, THREE, FOUR, FIVE,SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE };
using namespace std;

//////////////////////////////////////////////////////////////////
//      КЛАСС КАРТЫ СОДЕРЖАЩИЙ МАСТЬ КАРТЫ, ЗНАЧЕНИЕ КАРТЫ,     //
//     2 КОНСТРУКТОРА И ВИРТУАЛЬНЫЕ МЕТОДЫ ОТОБРАЖЕНИЯ КАРТЫ,   //
//      РАНДОМИЗАЦИИ ЕЕ ПАРАМЕТРОВ, И ВЫЧИСЛЕНИЯ ЕЕ ОЧКОВ       //
//////////////////////////////////////////////////////////////////

class Card {
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
};
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

///////////////////////////////////////////////////////////////////////
//          КЛАСС КОЛОДА, СОДЕРЖАЩИЙ В СЕБЕ ИНДЕКС КРАЙНЕЙ КАРТЫ,    //
//          МАССИВ ОБЪЕКТОВ КЛАССА CARD И ВИРТУАЛЬНЫЕ МЕТОДЫ         //
//          ВОЗВРАТА КАРТЫ, ГЕНЕРАЦИИ СЛУЧАЙНОЙ КОЛОДЫ               // 
///////////////////////////////////////////////////////////////////////

class Deck {
public:
    int number = 51;
    Card cards[52];
    Card getCard();
    void generateDeck();
    void printDeck();
};
//Метод вывода количества карт на экран
void Deck::printDeck() {
    cout << "Колода [" << number+1 << "]\t";
}
//Метод возврата крайней карты колоды
Card Deck::getCard() {
    return cards[number];
}
//Генерация случайной колоды
void Deck::generateDeck() {
    for (int i = 0; i < 52; i++) {
        cards[i].suit = static_cast<CardSuit>(i % 4);
        cards[i].rank = static_cast<CardRank>(i % 13);
    } 
    random_shuffle(begin(cards), end(cards));
    cout << "\n";
}

////////////////////////////////////////////////////////////////////////////
//           КЛАСС ИГРОК, СОДЕРЖАЩИЙ СЧЕТ ИГРОКА, ВЕКТОР КАРТ ИГРОКА     //
//           МЕТОД ВЗЯТИЯ КРАЙНЕЙ КАРТЫ КОЛОДЫ                           //
///////////////////////////////////////////////////////////////////////////

class Player {
public:
    int bet = 0;
    int score = 0;
    vector<Card> v;
    Player(){}
    void takeCard(Deck a);
    void makeBet();
};

void Player::takeCard(Deck a) {
    Card tmp = a.getCard();
    v.push_back(tmp);
    score += tmp.calculateCard();
    tmp.displayCard();
    cout << "\nСчет: "<<score<<endl;
}
void Player::makeBet() {
    cout << "Сделайте ставку: ";
    cin >> bet;
    cout << "Ваша ставка: " << bet << "$" << endl;
}
/////////////////////////////////////////////////////////////////////
//      КЛАСС ДИЛЛЕР                                              //
////////////////////////////////////////////////////////////////////
class Diller : public Player{
public:
    Diller() {}
    void fillCards(Deck a);
};
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

////////////////////////////////////////////////////////////////////
//     КЛАСС ИГРА, СОДЕРЖАЩИЙ ИГРОКА, КОЛОДУ И РЕШЕНИЕ ИГРОКА    //
///////////////////////////////////////////////////////////////////

class Game {
public:
    Player i;
    Diller he;
    vector <Deck>deck_vec;
    bool prem = true;
    int action = 1;
    int decknum;
    Game() {
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
            cout << "Поздравляем! Вы выиграли приз: " << i.bet * 12<<endl<<endl;
        }else
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
                << "\nВаш выигрыш : " << i.bet * 2<<'$';
            else if (i.score < he.score && he.score <= 21) cout << "Поражение!\nВаш счет: " << i.score
                << " меньше счета диллера: " << he.score;
            else if (i.score < he.score) cout << "Победа по очкам, перебор у диллера: " << he.score
                << "\nВаш выигрыш : " << i.bet * 2 << '$';
            else cout << "Ровно!\nВаш счет : " << i.score
                << " равен счету диллера : " << he.score;
        }
    }
};
/////////////////////////////////////////////////////////////

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Game a;
}
