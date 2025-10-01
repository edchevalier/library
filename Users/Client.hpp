#pragma once
#include "User.hpp"

class Client : public User {
    public:
        // Constructeurs
        Client();
        Client(int idUser, const std::string& firstName, const std::string& lastName, const std::string& emailAddress);

        // Méthodes
        void printDetails() const override;
};
