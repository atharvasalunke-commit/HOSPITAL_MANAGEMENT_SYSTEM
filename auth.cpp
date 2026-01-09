#include "auth.h"
#include "Database.h" 
#include <iostream>
#include <functional>

using namespace std;

extern Database db; 

int hashpassword(const string& password) {
    hash<string> h;
    return h(password);
}

void signup(const string& email, int passwordhash) {
   
    string sql = "INSERT INTO accounts (email, password_hash) VALUES ('" + email + "', " + to_string(passwordhash) + ");";
    db.query(sql);
}

bool signin(const string& email, int passwordhash) {
    
    sqlite3_stmt* stmt;
    string sql = "SELECT * FROM accounts WHERE email='" + email + "' AND password_hash=" + to_string(passwordhash) + ";";
    
    sqlite3_prepare_v2(db.get(), sql.c_str(), -1, &stmt, nullptr);
    
    bool found = false;
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        cout << "Login successful! Welcome " << email << "\n";
        found = true;
    } else {
        cout << "Wrong email or password.\n";
    }
    
    sqlite3_finalize(stmt);
    return found;
}

void handle_account(const string& choice) {
    string email, password;
    cout << "Enter Email: "; cin >> email;
    cout << "Enter Password: "; cin >> password;

    int hashed = hashpassword(password);

    if (choice == "NO") {
        signup(email, hashed);
    } else {
        if (!signin(email, hashed)) {
            exit(0); // Stop program if login fails
        }
    }
}