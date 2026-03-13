#include "SlotMachine.h"
#include <cstddef>
#include <iostream>

SlotMachine::SlotMachine(): payl(makePayLines()),pt(makeDPT()),evaluator(pt){

    std::vector<Symbol> tape = {
        Symbol::Lemon,
        Symbol::Cherry,
        Symbol::Seven,
        Symbol::Cherry,
        Symbol::Wild,
        Symbol::Lemon,
        Symbol::Bonus,
        Symbol::Cherry,
        Symbol::Seven,
        Symbol::Lemon
    };

    reels = {
        Reel(tape), Reel(tape), Reel(tape), Reel(tape), Reel(tape)};
}

int SlotMachine::getBalance() const{
    return player.getBalance();
}

void SlotMachine::spin(int bet) {
    if (!player.placeBet(bet)) {
        std::cout << "Not enough funds\n";
        return;
    }

    for (int i = 0; i < 5; i++) {
        reels[i].spin();
    }

    for (size_t col = 0; col < 5; col++) {
        for (size_t row = 0; row < 3; row++) {
            field.set(row, col, reels[col].at(row));
        }
    }

    int multiplier = evaluator.schetall(field, payl);

    if (multiplier) {
        ++spin_count;
    } else {
        spin_count = 0;
    }

    int od_mult = overdrive.mult(spin_count);
    int win = bet * multiplier * od_mult;

    player.addWin(win);

    std::cout << "Multiplier: " << multiplier << "\n";
    std::cout << "Overdrive: " << od_mult << "\n";
    std::cout << "Win: " << win << "\n";

    field.print();
}
