#include "Evaluator.h"  
#include "Field.h"       
#include <stdexcept>     
E::E(std::shared_ptr<PT> pt): mpt(std::move(pt)){
    if (!mpt) {
        throw std::invalid_argument("Evaluator: payTable is null");
    }
}
win E::schet(const Field& field, const PayLine& line, int id) const {
    if (!line.proverka(field)) {
        return {id,0,0};
    }
    const auto& cells =line.cells();
    Symbol base=field.get(cells[0].first, cells[0].second);
    if (base==Symbol::Wild) {
        for (auto [r, c] :cells) {             
            Symbol s = field.get(r, c);          
            if (s!=Symbol::Wild) {        
                base =s;                        
                break;
            }
        }
    }
    int match =0;
    for (auto [r,c]: cells) {
        Symbol s=field.get(r,c);
        if (s==base || s==Symbol::Wild || base==Symbol::Wild) {
            ++match;    
        } else {
            break;  
        }
    }
    int payout=0;
    if (match>=3) {
        payout=mpt->skoka(base, match);
    }
    return {id,match,payout};
}
int E::schetall(const Field& field, const std::vector<PayLine>& lines) const {
    int total=0;
    for (int i=0; i<(int)lines.size(); ++i) {
        win w = schet(field,lines[i],i);
        total+=w.payout;  
    }
    return total;
}
