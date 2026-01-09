#ifndef AUTH_H
#define AUTH_H

#include <string>

int hashpassword(const std::string& password);
void signup(const std::string& email, int passwordhash);
bool signin(const std::string& email, int passwordhash);
void handle_account(const std::string& choice);

#endif