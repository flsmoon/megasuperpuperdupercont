#ifndef FIELD_H
#define FIELD_H
#include <cstddef>
#include <iostream>
#include "Symbol.h"

class Field{
private:
    Symbol field[15];
public:
    void set(std::size_t row, std::size_t col, Symbol x){
        size_t idx = col*3+row;
        *(field + idx) = x;
    };
    Symbol get(std::size_t row, std::size_t col) const{
        size_t idx = col*3+row;
        return *(field + idx);
    };
    void print(){
        for(int i = 0; i < 3 ; ++i){
            std::cout << char_return(field[i]) << " " <<
            char_return(field[i+3]) << " " <<
            char_return(field[i+6]) << " " <<
            char_return(field[i+9]) << " " <<
            char_return(field[i+12]) << std::endl;
        };
    };

    size_t rows() const{ return 3;};
    size_t cols() const{ return 5;};
};


#endif