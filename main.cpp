#include <iostream>
#include <unordered_map>
#include <string>
#include "Database.h" // Include the helper
#include "auth.h"
#include "doctor.h"
#include "report.h"
#include "Patient.h"
#include "STAFF.h"

using namespace std;

// create the global database instance
Database db; 

int main() {
    unordered_map<string, string> doctors;
    
    // Pre-load some doctors (Optional)
    doctors["Headache"] = "Dr. Smith";
    doctors["Fever"] = "Dr. House";

    Patient patient;
    staff s;
    
    s.takeinputfromstaff(); // Defined in STAFF.cpp
    
    cout << "Do you have an account? (YES/NO): ";
    string choice;
    cin >> choice;
    
    string email_id;
    cout << "Enter your email_id: ";
    cin >> email_id;

    // Pass the logic to Staff
    s.find_typeof_staff(choice, doctors, email_id);

    return 0;
}