#ifndef SYMBOL_H
#define SYMBOL_H

enum class Symbol{
    Cherry,
    Lemon,
    Seven,
    Wild,
    Bonus
};

inline char char_return(Symbol x){
    switch (x){
    case Symbol::Cherry: 
        return 'C';
        break;
    case Symbol::Lemon: 
        return 'L';
        break;
    case Symbol::Seven: 
        return '7';
        break;
    case Symbol::Wild: 
        return '#';
        break;
    case Symbol::Bonus: 
        return '$';       
        break;
    default:
         return '-';
    }
}
 
#endif