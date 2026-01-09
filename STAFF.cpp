#include "STAFF.h"
#include "doctor.h"
#include "report.h"
#include "auth.h"
#include "Patient.h"
#include "Database.h" 

using namespace std;

// Access the global database
extern Database db; 

void staff::takeinputfromstaff() {
    cout << "\n--- STAFF LOGIN ---\n";
    cout << "Enter Name: "; cin >> name;
    cout << "Type (Admin/Medical): "; cin >> type_of_staff;
    cout << "Role (receponist/Doctor/nurse): "; cin >> role;
    cout << "UID: "; cin >> UID;
}

void staff::find_typeof_staff(string &choice, unordered_map<string,string> &doctors, string &email_id) const {
    if (type_of_staff == "Admin") {
        admin_staff(choice, doctors);
    } 
    else if (type_of_staff == "Medical") {
        medical_staff(email_id);
    } 
    else {
        cout << "Invalid staff type.\n";
    }
}

void staff::admin_staff(string &choice, unordered_map<string,string> &doctors) const {
    Patient p;
    if (role == "receponist") {
        // 1. Get Patient Info
        p.inputfrompatient();
        // 2. Save to Database (Patient.cpp handles the SQL now)
        p.savetofile(); 
        
        // 3. Handle Account (Auth.cpp handles SQL now)
        handle_account(choice);
        
        // 4. Assign Doctor (Doctor.cpp handles SQL now)
        handle_doctors(doctors, p.gethealthissue());
    }
    else {
        cout << "Work not available for " << role << " right now.\n";
    }
}

void staff::medical_staff(string &email_id) const {
    Patient p;
    if (role == "Doctor") {
        // Just a simulator message now
        cout << "Doctor Mode: Accessing Patient Records from Database...\n";
        p.loadfromfile(); 
    }
    else if (role == "nurse") {
        // Generate a random ID for the report
        int id = generateid(); 
        
        // In a real app, you'd ask for patient name. 
        // Here we simulate it or ask the nurse:
        string pName, issue;
        cout << "Enter Patient Name for Report: "; cin >> pName;
        cout << "Enter Diagnosis/Issue: "; cin >> issue;

        // Save report to Database
        savereport(id, pName, email_id, issue);
    }
    else {
        cout << "Work not available for " << role << " right now.\n";
    }
}