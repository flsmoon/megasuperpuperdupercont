#ifndef DATABASE_H
#define DATABASE_H
#include <string>

class Database {
public:
    Database();
    bool save_result(
        const std::string& player_name,
        int bet,
        int win,
        int balance_after
    );
private:
    std::string connection_string_;
};
#endif
