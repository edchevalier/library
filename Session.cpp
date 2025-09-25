#include "Session.hpp"
#include <iostream>
#include <algorithm>

Session::Session() : library(nullptr) {
}

Session::Session(Library* lib) : library(lib) {
}

Session::~Session() {
    results.clear();
}

void Session::setLibrary(Library* lib) {
    library = lib;
}

Library* Session::getLibrary() const {
    return library;
}

void Session::run() {
    std::cout << "=== Début de la session ===" << std::endl;
    std::cout << "Bienvenue dans le système de gestion de bibliothèque!" << std::endl;

    if (library == nullptr) {
        std::cout << "Erreur: Aucune bibliothèque associée à la session." << std::endl;
        return;
    }

    bool running = true;
    while (running) {
        std::cout << "\n--- Menu Principal ---" << std::endl;
        std::cout << "1. Afficher les détails d'une ressource (printDetails)" << std::endl;
        std::cout << "2. Effacer les résultats (clear)" << std::endl;
        std::cout << "3. Rechercher des ressources (search)" << std::endl;
        std::cout << "4. Afficher les résultats actuels" << std::endl;
        std::cout << "5. Quitter (bye)" << std::endl;

        std::string command = readCommand();

        if (command == "1") {
            std::cout << "Entrez l'ID de la ressource: ";
            int id;
            std::cin >> id;
            printDetails(id);
        }
        else if (command == "2") {
            clear();
        }
        else if (command == "3") {
            std::cout << "Entrez votre requête de recherche: ";
            std::cin.ignore();
            std::string query;
            std::getline(std::cin, query);
            search(query);
        }
        else if (command == "4") {
            std::cout << "=== Résultats actuels ===" << std::endl;
            if (results.empty()) {
                std::cout << "Aucun résultat en mémoire." << std::endl;
            } else {
                std::cout << "Nombre de résultats: " << results.size() << std::endl;
                for (const Resource* resource : results) {
                    resource->printDetails();
                    std::cout << std::endl;
                }
            }
        }
        else if (command == "5") {
            bye();
            running = false;
        }
        else {
            std::cout << "Commande invalide. Veuillez choisir entre 1, 2, 3, 4 ou 5." << std::endl;
        }
    }
}

void Session::bye() {
    std::cout << "=== Fin de la session ===" << std::endl;
    std::cout << "Au revoir et merci d'avoir utilisé notre système de bibliothèque!" << std::endl;
    clear();
}

std::string Session::readCommand() {
    std::cout << "Choisissez une option: ";
    std::string command;
    std::cin >> command;
    return command;
}

void Session::printDetails(int id) {
    if (library == nullptr) {
        std::cout << "Erreur: Aucune bibliothèque associée à la session." << std::endl;
        return;
    }

    Resource* resource = library->findResource(id);
    if (resource != nullptr) {
        std::cout << "=== Détails de la ressource ID " << id << " ===" << std::endl;
        resource->printDetails();
        std::cout << std::endl;
    } else {
        std::cout << "Aucune ressource trouvée avec l'ID " << id << std::endl;
    }
}

std::vector<Resource*> Session::search(const std::string& query) {
    results.clear();

    if (library == nullptr) {
        std::cout << "Erreur: Aucune bibliothèque associée à la session." << std::endl;
        return results;
    }

    const std::vector<Resource*>& resources = library->getResources();

    for (Resource* resource : resources) {
        if (resource->getTitle().find(query) != std::string::npos ||
            resource->getAuthor().find(query) != std::string::npos) {
            results.push_back(resource);
        }
    }

    std::cout << "=== Résultats de recherche pour: \"" << query << "\" ===" << std::endl;
    if (results.empty()) {
        std::cout << "Aucun résultat trouvé." << std::endl;
    } else {
        std::cout << "Nombre de résultats trouvés: " << results.size() << std::endl;
        for (const Resource* resource : results) {
            resource->printDetails();
            std::cout << std::endl;
        }
    }

    return results;
}

void Session::clear() {
    results.clear();
    std::cout << "Liste des résultats effacée." << std::endl;
}

const std::vector<Resource*>& Session::getResults() const {
    return results;
}