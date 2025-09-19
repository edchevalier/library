#pragma once
#include "User.hpp"

class Admin : public User {
    public:
        // Constructeurs
        Admin();
        Admin(int idUser, const std::string& firstName, const std::string& lastName, const std::string& emailAddress);

        // Méthodes
        void printDetails() const override;
};
