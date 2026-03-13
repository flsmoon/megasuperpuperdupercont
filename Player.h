#ifndef PLAYER_H
#define PLAYER_H

class Player{
private:
    int balance = 100;
    int bet = 0;
public:
    Player() = default;

    bool placeBet(int b){
        if((balance - b) >= 0){
            bet = b;
            balance -= bet;
            
            return true;
        }
        return false;
    }

    void addWin(double amout){
        balance += amout;    
    }

    int getBalance() const{
        return balance;
    }

};

#endif 