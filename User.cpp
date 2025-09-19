#include "User.hpp"

// Constructeurs 
User::User() : idUser(0), firstName(""), lastName(""), emailAddress("") {}

User::User(int id, const std::string& fn, const std::string& ln, const std::string& email)
    : idUser(id), firstName(fn), lastName(ln), emailAddress(email) {}

//Méthodes
void User::printDetails() const {
    std::cout << "User ID : " << idUser
              << " First Name : " << firstName
              << " Last Name : " << lastName
              << " Email : " << emailAddress
              << std::endl;
}

// Setters
void User::setFirstName(const std::string& fn) { firstName = fn; }
void User::setLastName(const std::string& ln) { lastName = ln; }
void User::setEmailAddress(const std::string& email) { emailAddress = email; }
void User::setIdUser(int id) { idUser = id; }

// Getters
std::string User::getFirstName() const { return firstName; }
std::string User::getLastName() const { return lastName; }
std::string User::getEmailAddress() const { return emailAddress; }
int User::getIdUser() const { return idUser; }
