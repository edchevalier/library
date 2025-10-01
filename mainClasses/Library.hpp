#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "User.hpp"
#include "Ressources/Resource.hpp"

class Library {
    private:
        std::vector<User*> users;
        std::vector<Resource*> resources;

    public:
        // Constructeurs
        Library();
        ~Library();

        // Gestion des utilisateurs
        void addUser(User* user);
        void removeUser(int userId);
        User* findUser(int userId) const;
        void showAllUsers() const;

        // Gestion des ressources
        void addResource(Resource* resource);
        void removeResource(int resourceId);
        Resource* findResource(int resourceId) const;
        void showAllResources() const;

        // Affichage général
        void showLibraryInfo() const;

        // Getters
        const std::vector<User*>& getUsers() const;
        const std::vector<Resource*>& getResources() const;
};


