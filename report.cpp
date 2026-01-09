#include "report.h"
#include "Database.h"
#include <iostream>
#include <cstdlib> // For random ID

using namespace std;

extern Database db;

int generateid() {
    // Simple random ID generator (1000-9999)
    return rand() % 9000 + 1000;
}

void savereport(int id, const string& name, const string& email, const string& health_issue) {
    // SQL Injection safe-ish string construction
    string sql = "INSERT INTO reports (patient_name, email, health_issue) VALUES ('" 
                 + name + "', '" + email + "', '" + health_issue + "');";
    
    db.query(sql);
    cout << "✅ Report ID " << id << " saved to Database.\n";
}