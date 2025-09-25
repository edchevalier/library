#pragma once
#include <string>
#include <vector>
#include "User.hpp"
#include "Ressources/Resource.hpp"

class FileManager {
    public:
        // Constructeur
        FileManager();
        ~FileManager();

        // Gestion des utilisateurs
        std::vector<User*> loadUsers(const std::string& filename);
        void saveUsers(const std::string& filename, const std::vector<User*>& users);

        // Gestion des ressources
        std::vector<Resource*> loadResources(const std::string& filename);
        void saveResources(const std::string& filename, const std::vector<Resource*>& resources);

    private:
        // Méthodes utilitaires pour le parsing
        User* parseUser(const std::string& line);
        Resource* parseResource(const std::string& line);
        std::string userToString(const User* user);
        std::string resourceToString(const Resource* resource);
};