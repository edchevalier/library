#pragma once
#include <string>
#include <iostream>

class User {
    protected:
        int idUser;
        std::string firstName;
        std::string lastName;
        std::string emailAddress;

    public:
        // Constructeurs
        User();
        User(int idUser, const std::string& firstName, const std::string& lastName, const std::string& emailAddress);

        virtual void printDetails() const;

        // Setters
        void setFirstName(const std::string& fn);
        void setLastName(const std::string& ln);
        void setEmailAddress(const std::string& email);
        void setIdUser(int id);

        // Getters
        std::string getFirstName() const;
        std::string getLastName() const;
        std::string getEmailAddress() const;
        int getIdUser() const;
};


