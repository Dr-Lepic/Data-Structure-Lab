#include<bits/stdc++.h>
using namespace std;

void processDeck(int n) {
    std::queue<int> deck;
    for (int i = 1; i <= n; i++) {
        deck.push(i);
    }

    std::vector<int> discarded;
    while (deck.size() > 1) {
        discarded.push_back(deck.front());
        deck.pop();
        deck.push(deck.front());
        deck.pop();
    }

    std::cout << "Discarded cards: ";
    for (size_t i = 0; i < discarded.size(); i++) {
        std::cout << discarded[i];
        if (i < discarded.size() - 1) std::cout << ", ";
    }
    std::cout << "\nRemaining card: " << deck.front() << std::endl;
}

int main() {
    int n;
    std::cout << "Enter number of cards (0 to stop): ";
    while (std::cin >> n && n != 0) {
        processDeck(n);
    }
    return 0;
}