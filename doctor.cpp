#include "doctor.h"
#include "Database.h"
#include <iostream>

using namespace std;

extern Database db;

void add_doctor(const string& specialization, const string& name) {
    string sql = "INSERT INTO doctors (name, specialization) VALUES ('" + name + "', '" + specialization + "');";
    db.query(sql);
}

void handle_doctors(unordered_map<string, string>& doctors, const string& health_issue) {
    
    sqlite3_stmt* stmt;
    string sql = "SELECT name FROM doctors WHERE specialization='" + health_issue + "'";
    
    // 2. Compile Query
    int rc = sqlite3_prepare_v2(db.get(), sql.c_str(), -1, &stmt, nullptr);
    
    if (rc != SQLITE_OK) {
        cout << " Query Error: " << sqlite3_errmsg(db.get()) << endl;
        return;
    }

 
    if (sqlite3_step(stmt) == SQLITE_ROW) {
       
        const char* resultName = (const char*)sqlite3_column_text(stmt, 0);
        
        cout << " Assigned Doctor: " << resultName << "\n";
    } else {
        cout << " No doctor available for this issue.\n";
    }

    // 4. Cleanup (CRITICAL)
    sqlite3_finalize(stmt);
}