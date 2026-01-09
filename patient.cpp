#include "Patient.h"
#include "Database.h"
#include <iostream>

using namespace std;

extern Database db; 

void Patient::inputfrompatient() {
    cout << "Name: "; cin >> name;
    cout << "Health Issue: "; cin >> health_issue;
    cout << "Blood Group: "; cin >> blood_group;
    cout << "Allergies: "; cin >> allergies;
    cout << "Emergency Contact: "; cin >> emergency_contact_no;
    cout << "Phone: "; cin >> phone_number;
}

void Patient::savetofile() {
   
    string sql = "INSERT INTO patients (name, health_issue, blood_group, allergies, emergency_contact, phone) VALUES ('" 
               + name + "', '" + health_issue + "', '" + blood_group + "', '" + allergies + "', " 
               + to_string(emergency_contact_no) + ", " + to_string(phone_number) + ");";
    
    db.query(sql);
}


void Patient::loadfromfile() {
    cout << "Patient data linked to Database.\n";
}

string Patient::getname() const { return name; }
string Patient::gethealthissue() const { return health_issue; }