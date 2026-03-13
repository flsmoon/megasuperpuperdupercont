#ifndef SLOT_MACHINE_H
#define SLOT_MACHINE_H
#include "Player.h"
#include "Reel.h"
#include "Field.h"
#include "Symbol.h"
#include "PayLine.h"
#include "Evaluator.h"
#include "Overdrive.h"
#include <vector>
#include <cstddef>

class SlotMachine{
private:
    Player player;
    Field field;
    std::vector<PayLine> payl;
    std::vector<Reel> reels;
    std::shared_ptr<PT> pt;
    E evaluator;
    od overdrive;
    int spin_count = 0;
public:
    SlotMachine();
    void spin(int bet);
    int getBalance() const;
};

#endif
