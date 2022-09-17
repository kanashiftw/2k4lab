#include <iostream>
#include <Windows.h>
#include <vector>
enum CardSuit { CLUBS, DIAMONDS, HEARTS, SPADES };
enum CardRank { SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE };
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
    case SIX: return 6;
    case SEVEN: return 7;
    case EIGHT: return 8;
    case NINE: return 9;
    case TEN: return 10;
    case JACK: return 2;
    case QUEEN: return 3;
    case KING: return 4;
    case ACE: return 11;
    }
}
//Метод вывода карты на экран
void Card::displayCard()
{
    switch (rank)
    {
    case SIX:cout << '6'; break;
    case SEVEN:cout << '7'; break;
    case EIGHT:cout << '8'; break;
    case NINE:cout << '9'; break;
    case TEN:cout << "10"; break;
    case JACK:cout << 'J'; break;
    case QUEEN:cout << 'Q'; break;
    case KING:cout << 'K'; break;
    case ACE:cout << 'A';
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
    int number = 35;
    Card cards[36];
    Card getCard();
    void generateDeck();
    void printDeck();
};
//Метод вывода количества карт на экран
void Deck::printDeck() {
    cout << "Колода [" << number+1 << "]"<<endl;
}
//Метод возврата крайней карты колоды
Card Deck::getCard() {
    return cards[number];
}
//Генерация случайной колоды
void Deck::generateDeck() {
    for (int i = 0; i < 36; i++) {
        cards[i].suit = static_cast<CardSuit>(i % 4);
        cards[i].rank = static_cast<CardRank>(i % 9);
    }
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
};

void Player::takeCard(Deck a) {
    Card tmp = a.getCard();
    v.push_back(tmp);
    score += tmp.calculateCard();
    tmp.displayCard();
    cout << "\nСчет: "<<score<<endl;
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
    while (score < 17) {
        Card tmp = a.getCard();
        v.push_back(tmp);
        score += tmp.calculateCard();
        if (score < 12) tmp.displayCard();
        else cout << " XX";
    }
}

////////////////////////////////////////////////////////////////////
//     КЛАСС ИГРА, СОДЕРЖАЩИЙ ИГРОКА, КОЛОДУ И РЕШЕНИЕ ИГРОКА    //
///////////////////////////////////////////////////////////////////

class Game {
public:
    Player i;
    Diller he;
    Deck _deck;
    int action;
    Game() {
        cout << "Сделайте ставку: ";
        cin >> i.bet;
        cout << "Ваша ставка: " << i.bet <<"$" << endl;
        cout << "Карты диллера:" << endl;
        he.fillCards(_deck);
        _deck.number -= he.v.size();
        srand(time(0));
        _deck.generateDeck();
        i.takeCard(_deck);
        _deck.number--;
        _deck.printDeck();

        cout << "Вытянуть еще карту?\n1 - да \n2 - нет\n";
        cin >> action;
        _deck.number--;
        cout << endl;
        while (action == 1) {
            i.takeCard(_deck);
            _deck.number--;
            _deck.printDeck();
            cout << "Вытянуть еще карту?\n1 - да \n2 - нет\n";
            cin >> action;
            cout << endl;
        }
        cout << "Карты диллера: " << endl;
        for (int i = 0; i < he.v.size();i++) {
            he.v[i].displayCard();
            cout << ' ';
        }
        if (i.score > 21) "Перебор!";
        else if (i.score == 21) cout << "Очко! ";
        else if (i.score > he.score) cout << "Победа!\nВаш счет: "<<i.score
            <<" больше счета диллера: "<<he.score;
        else if (i.score < he.score) cout << "Поражение!\nВаш счет: " << i.score 
            << " меньше счета диллера: " << he.score;
        else cout << "Ровно!\nВаш счет : " << i.score 
            << " равен счету диллера : " << he.score;
    }
};
/////////////////////////////////////////////////////////////

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Game a;
}

