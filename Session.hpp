#pragma once
#include <vector>
#include <string>
#include "Library.hpp"
#include "Ressources/Resource.hpp"

class Session {
    private:
        Library* library;
        std::vector<Resource*> results;

    public:
        // Constructeurs
        Session();
        Session(Library* lib);
        ~Session();

        // Gestion de la bibliothèque
        void setLibrary(Library* lib);
        Library* getLibrary() const;

        // Méthodes principales de session
        void run();
        void bye();
        std::string readCommand();

        // Méthodes utilitaires
        void printDetails(int id);
        std::vector<Resource*> search(const std::string& query);
        void clear();

        // Getter pour results
        const std::vector<Resource*>& getResults() const;

        // Méthodes pour les menus
        bool runUserMenu();
        bool runAdminMenu();
        void addResourceMenu();
        void addUserMenu();
        void borrowResourceMenu();
        void returnResourceMenu();
};