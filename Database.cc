#include "Database.h"

#include <cstdlib>
#include <iostream>
#include <pqxx/pqxx>

static std::string get_env_or_default(const char* name, const char* default_value) {
    const char* value = std::getenv(name);
    return value ? value : default_value;
}

Database::Database() {
    std::string host = get_env_or_default("DB_HOST", "db");
    std::string port = get_env_or_default("DB_PORT", "5432");
    std::string dbname = get_env_or_default("DB_NAME", "slotdb");
    std::string user = get_env_or_default("DB_USER", "slotuser");
    std::string password = get_env_or_default("DB_PASSWORD", "1111");
    connection_string_=
        "host=" + host +
        " port=" + port +
        " dbname=" + dbname +
        " user=" + user +
        " password=" + password;
}
bool Database::save_result(
    const std::string& player_name,
    int bet,
    int win,
    int balance_after
) {
    try {
        pqxx::connection connection(connection_string_);

        pqxx::work transaction(connection);

        transaction.exec_params(
            "INSERT INTO game_results "
            "(player_name, bet, win, balance_after) "
            "VALUES ($1, $2, $3, $4)",
            player_name,
            bet,
            win,
            balance_after
        );
        transaction.commit();
        return true;
    }
    catch (const std::exception& e) {
        std::cerr << "Database error: " << e.what() << std::endl;
        return false;
    }
}
