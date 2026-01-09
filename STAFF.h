#ifndef STAFF_H
#define STAFF_H

#include <string>
#include <unordered_map>
#include <iostream>

class staff {
private:
    std::string name;
    std::string type_of_staff;
    std::string role;
    int UID;

public:
    void takeinputfromstaff();
    
    // Logic functions
    void find_typeof_staff(std::string &choice, std::unordered_map<std::string, std::string> &doctors, std::string &email_id) const;
    void admin_staff(std::string &choice, std::unordered_map<std::string, std::string> &doctors) const;
    void medical_staff(std::string &email_id) const;
};

#endif