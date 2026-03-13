#include "Paytable.h"
#include <stdexcept>
void PT::zachto(Symbol s, int count, int pay) {
    if (count<1 || count>mc) {
        throw std::invalid_argument("Count must be in range [1..5]");
    }
    if (pay< 0) {
        throw std::invalid_argument("Pay must be >= 0");
    }
    auto& pays=table[s];
    pays[count]=pay;
}
int PT::skoka(Symbol s, int count) const {
    if (count<1 || count>mc) {
        return 0;
    }
    auto it=table.find(s);
    if (it==table.end()) {
        return 0;
    }
    return it->second[count];
}
bool PT::has(Symbol s, int count) const {
    return skoka(s,count) > 0;
}
std::shared_ptr<PT> makeDPT() {
    auto pt=std::make_shared<PT>();

    pt->zachto(Symbol::Cherry,3,2);
    pt->zachto(Symbol::Cherry,4,3);
    pt->zachto(Symbol::Cherry,5,4);

    pt->zachto(Symbol::Lemon,3,2);
    pt->zachto(Symbol::Lemon,4,3);
    pt->zachto(Symbol::Lemon,5,4);

    pt->zachto(Symbol::Bonus,3,3);
    pt->zachto(Symbol::Bonus,4,5);
    pt->zachto(Symbol::Bonus,5,7);

    pt->zachto(Symbol::Seven,3,5);
    pt->zachto(Symbol::Seven,4,10);
    pt->zachto(Symbol::Seven,5,15);

    pt->zachto(Symbol::Wild,3,0);
    pt->zachto(Symbol::Wild,4,0);
    pt->zachto(Symbol::Wild,5,20);
    return pt;
}