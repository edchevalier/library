#include "User.hpp"
#include "Ressources/Resource.hpp" 

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

bool User::borrowResource(Resource* resource) {
    if (resource == nullptr) {
        std::cout << "Erreur : ressource invalide." << std::endl;
        return false;
    }

    if (resource->borrowResource(idUser)) {
        std::cout << "Ressource '" << resource->getTitle() << "' empruntée avec succès." << std::endl;
        return true;
    } else {
        std::cout << "Impossible d'emprunter la ressource '" << resource->getTitle() << "'. ";
        if (!resource->isAvailable()) {
            std::cout << "Elle est déjà empruntée par un utilisateur." << std::endl;
        }
        return false;
    }
}

bool User::returnResource(Resource* resource) {
    if (resource == nullptr) {
        std::cout << "Erreur : ressource invalide." << std::endl;
        return false;
    }

    if (resource->returnResource(idUser)) {
        std::cout << "Ressource '" << resource->getTitle() << "' rendue avec succès." << std::endl;
        return true;
    } else {
        std::cout << "Impossible de rendre la ressource '" << resource->getTitle() << "'. ";
        return false;
    }
}