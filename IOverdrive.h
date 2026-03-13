#ifndef IOVERDRIVE_H
#define IOVERDRIVE_H
class IOD {                    
public:
    virtual ~IOD() = default; 
    virtual double mult(int spins) const = 0; 
};
#endif