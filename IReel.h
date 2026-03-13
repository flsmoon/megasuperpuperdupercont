#ifndef IREEL_H
#define IREEL_H
#include <cstddef>
#include "Symbol.h"

class IReel{
public:
    virtual ~IReel()=default;
    virtual void spin() = 0;
    virtual Symbol at(std::size_t row) const = 0;
};

#endif