#ifndef PATIENT_H
#define PATIENT_H

#include <string>

class Patient {
private:
    std::string name;
    std::string allergies;
    std::string blood_group;
    std::string health_issue;
    int emergency_contact_no;
    int phone_number;

public:
    void inputfrompatient();
    void savetofile();
    void loadfromfile();
    std::string getname() const;
    std::string gethealthissue() const;
};

#endif