#include "Client.hpp"
#include <iostream>

// ---------- Constructeurs ----------
Client::Client() : User() {}

Client::Client(int id, const std::string& fn, const std::string& ln, const std::string& email)
    : User(id, fn, ln, email) {}

// ---------- Méthodes ----------
void Client::printDetails() const {
    std::cout << "[Client] ID : " << idUser
              << " | First Name : " << firstName
              << " | Last Name : " << lastName
              << " | Email : " << emailAddress
              << std::endl;
}
