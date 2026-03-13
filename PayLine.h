#ifndef PAYLINE_H
#define PAYLINE_H
#include <vector>           
#include <utility>           
class Field;                
class PayLine {
public:                     
    explicit PayLine(std::vector<std::pair<int,int>> cells);                                          
    const std::vector<std::pair<int,int>>& cells() const {   
        return mcells;                       
    }
    bool proverka(const Field& f) const;      
private:
    std::vector<std::pair<int,int>> mcells;                 
};
std::vector<PayLine> makePayLines(); 
#endif