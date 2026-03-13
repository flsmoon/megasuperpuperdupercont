#include "PayLine.h"         
#include "Field.h"          
#include <utility>          
PayLine::PayLine(std::vector<std::pair<int,int>> cells):mcells(std::move(cells)){}
bool PayLine::proverka(const Field& f) const { 
    if (mcells.size()!=f.cols())
        return false;
    for (auto [r,c]:mcells) {
        if (r<0 || r >= static_cast<int>(f.rows()))
            return false;
        if (c<0 || c >= static_cast<int>(f.cols()))
            return false;}
    return true;
}
std::vector<PayLine> makePayLines() { 
    std::vector<PayLine> lines;                                
    lines.emplace_back(std::vector<std::pair<int,int>>{{0,0},{0,1},{0,2},{0,3},{0,4}});
    lines.emplace_back(std::vector<std::pair<int,int>>{{1,0},{1,1},{1,2},{1,3},{1,4}});
    lines.emplace_back(std::vector<std::pair<int,int>>{{2,0},{2,1},{2,2},{2,3},{2,4}});
    lines.emplace_back(std::vector<std::pair<int,int>>{{0,0},{1,1},{2,2},{1,3},{0,4}});
    lines.emplace_back(std::vector<std::pair<int,int>>{{2,0},{1,1},{0,2},{1,3},{2,4}});                                            
    return lines;
}                                              