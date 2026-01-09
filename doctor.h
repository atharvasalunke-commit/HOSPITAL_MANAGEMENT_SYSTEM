#ifndef DOCTOR_H
#define DOCTOR_H

#include <string>
#include <unordered_map>

void loaddoctors(std::unordered_map<std::string, std::string>& doctors);
void add_doctor(const std::string& specialization, const std::string& name);
void assigndoctor(const std::string& health_issue, std::unordered_map<std::string, std::string>& doctors);
void handle_doctors(std::unordered_map<std::string, std::string>& doctors, const std::string& health_issue);

#endif