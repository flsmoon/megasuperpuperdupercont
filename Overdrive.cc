#include "Overdrive.h"          
double od::mult(int spins) const {   
    if (spins>=10) return 2.0;     
    if (spins>=5) return 1.5;     
    if (spins>=3) return 1.2;      
    return 1.0;                       
}
double od1::mult(int spins) const {   
    if (spins>=10) return 5.0;     
    if (spins>=5) return 4.5;     
    if (spins>=3) return 3.2;      
    return 1.0;                       
}
