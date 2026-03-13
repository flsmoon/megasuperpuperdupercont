#ifndef REEL_H
#define REEL_H
#include "IReel.h"
#include "Symbol.h"
#include <cstddef>
#include <vector>
#include <random>

class Reel: public IReel{
private:
    std::vector<Symbol> tape_;
    std::size_t offset{0};
    std::mt19937 rnd;

public:
    Reel(std::vector<Symbol> tape);
    void spin() override;
    Symbol at(std::size_t row) const override;
};

#endif