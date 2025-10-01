#include "Admin.hpp"
#include <iostream>

// ---------- Constructeurs ----------
Admin::Admin() : User() {}

Admin::Admin(int id, const std::string& fn, const std::string& ln, const std::string& email)
    : User(id, fn, ln, email) {}

// ---------- Méthodes ----------
void Admin::printDetails() const {
    std::cout << "[Admin] ID : " << idUser
              << " | First Name : " << firstName
              << " | Last Name : " << lastName
              << " | Email : " << emailAddress
              << std::endl;
}
