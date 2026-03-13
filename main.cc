
#include "SlotMachine.h"
#include <iostream>
#include <string>

int main() {
    SlotMachine sm;

    std::cout << "----- LET'S GO GAMBLING -----\n";

    while (sm.getBalance() > 0) {
        std::cout << "\nBalance: " << sm.getBalance() << "\n";
        std::cout << "Place your bet (or q to quit): ";

        std::string input;
        std::cin >> input;

        if (input == "q" || input == "exit") {
            std::cout << "Game over.\n";
            return 0;
        }

        int bet = 0;
        try {
            bet = std::stoi(input);
        } catch (...) {
            std::cout << "Invalid value\n";
            continue;
        }

        if (bet <= 0) {
            std::cout << "Bet must be greater than zero\n";
            continue;
        }

        sm.spin(bet);
    }

    std::cout << "---------- YOU DIED ---------\n";
    return 0;
}
