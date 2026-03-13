#include "Reel.h"
#include "Symbol.h"
#include <random>
#include <cstddef>
#include <time.h>

Reel::Reel(std::vector<Symbol> tape)
    : tape_(std::move(tape)), rnd(std::random_device{}()){}

void Reel::spin(){
    std::uniform_int_distribution<int> dist(0, tape_.size() - 1);
    offset = dist(rnd);
}

Symbol Reel::at(std::size_t row) const{
    Symbol element = tape_[(offset + row)%tape_.size()];
    return element;
}