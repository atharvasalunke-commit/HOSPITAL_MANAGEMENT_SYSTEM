#ifndef REPORT_H
#define REPORT_H

#include <string>

int generateid();
void savereport(int id, const std::string& name, const std::string& email, const std::string& health_issue);

#endif