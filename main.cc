#include "Database.h"
#include "SlotMachine.h"
#include <iostream>
#include <string>

int main() {
    SlotMachine sm;
    Database db;
    std::string player_name;
    std::cout<<" Enter your name: ";
    std::cin >>player_name;

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

        int balance_before=sm.getBalance();
        sm.spin(bet);
        int balance_after=sm.getBalance();
        int win=balance_after-balance_before+bet;
        db.save_result(player_name,bet, win,balance_after);
    }

    std::cout << "---------- YOU DIED ---------\n";
    return 0;
}
