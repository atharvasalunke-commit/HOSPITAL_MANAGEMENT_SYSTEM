#ifndef DATABASE_H
#define DATABASE_H

#include "sqlite3.h"
#include <string>
#include <iostream>
#include <vector>

class Database {
    sqlite3* db;

public:
    // Constructor: Connects automatically
    Database() {
        if (sqlite3_open("hospital.db", &db) != SQLITE_OK) {
            std::cerr << "DB Error: " << sqlite3_errmsg(db) << "\n";
        } else {
            std::cout << " Connected to Database.\n";
        }
    }

    ~Database() {                                                   
        sqlite3_close(db);
    }

    void query(std::string sql) {
        char* errMsg = nullptr;
        if (sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg) != SQLITE_OK) {
            std::cerr << " SQL Error: " << errMsg << "\n";
            sqlite3_free(errMsg);
        } else {
            std::cout << "Saved.\n";
        }
    }
    
    sqlite3* get() { return db; }
};

#endif