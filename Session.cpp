#include "Session.hpp"
#include <iostream>
#include <algorithm>
#include "User.hpp"
#include "Admin.hpp"
#include "Client.hpp"
#include "Ressources/Book.hpp"
#include "Ressources/Reviews.hpp"
#include "Ressources/CD.hpp"
#include "Ressources/DVD.hpp"
#include "Ressources/VHS.hpp"
#include "Ressources/Digital.hpp"

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

    // Choix du mode utilisateur
    std::cout << "\n--- Choix du mode ---" << std::endl;
    std::cout << "1. Mode utilisateur standard" << std::endl;
    std::cout << "2. Mode administrateur" << std::endl;
    std::cout << "Choisissez votre mode: ";

    std::string modeChoice;
    std::cin >> modeChoice;

    bool isAdmin = false;
    if (modeChoice == "2") {
        std::cout << "Entrez le mot de passe administrateur: ";
        std::string password;
        std::cin >> password;

        if (password == "password123") {
            std::cout << "Authentification réussie! Mode administrateur activé." << std::endl;
            isAdmin = true;
        } else {
            std::cout << "Mot de passe incorrect. Basculement en mode utilisateur standard." << std::endl;
            isAdmin = false;
        }
    }

    bool running = true;
    while (running) {
        if (isAdmin) {
            running = runAdminMenu();
        } else {
            running = runUserMenu();
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

bool Session::runUserMenu() {
    std::cout << "\n--- Menu Utilisateur ---" << std::endl;
    std::cout << "1. Afficher les détails d'une ressource" << std::endl;
    std::cout << "2. Effacer les résultats" << std::endl;
    std::cout << "3. Rechercher des ressources" << std::endl;
    std::cout << "4. Afficher les résultats actuels" << std::endl;
    std::cout << "5. Emprunter une ressource" << std::endl;
    std::cout << "6. Rendre une ressource" << std::endl;
    std::cout << "7. Quitter" << std::endl;


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
        borrowResourceMenu();
        return false;
    }
    else if (command == "6") {
        returnResourceMenu();
        return false;
    }

    else if (command == "7") {
        bye();
        return false;
    }
    else {
        std::cout << "Commande invalide. Veuillez choisir entre 1, 2, 3, 4 ou 5." << std::endl;
    }

    return true;
}

bool Session::runAdminMenu() {
    std::cout << "\n--- Menu Administrateur ---" << std::endl;

    // Fonctions classiques
    std::cout << "=== Fonctions de consultation ===" << std::endl;
    std::cout << "1. Afficher les détails d'une ressource" << std::endl;
    std::cout << "2. Effacer les résultats" << std::endl;
    std::cout << "3. Rechercher des ressources" << std::endl;
    std::cout << "4. Afficher les résultats actuels" << std::endl;

    // Fonctions administratives
    std::cout << "\n=== Gestion des ressources ===" << std::endl;
    std::cout << "5. Ajouter une ressource" << std::endl;
    std::cout << "6. Supprimer une ressource" << std::endl;
    std::cout << "7. Afficher toutes les ressources" << std::endl;

    std::cout << "\n=== Gestion des utilisateurs ===" << std::endl;
    std::cout << "8. Ajouter un utilisateur" << std::endl;
    std::cout << "9. Supprimer un utilisateur" << std::endl;
    std::cout << "10. Afficher tous les utilisateurs" << std::endl;

    std::cout << "\n=== Informations générales ===" << std::endl;
    std::cout << "11. Afficher les informations de la bibliothèque" << std::endl;
    std::cout << "12. Quitter" << std::endl;

    std::string command = readCommand();

    // Fonctions classiques
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
    // Fonctions administratives - Ressources
    else if (command == "5") {
        addResourceMenu();

    }
    else if (command == "6") {
        std::cout << "Entrez l'ID de la ressource à supprimer: ";
        int id;
        std::cin >> id;
        library->removeResource(id);
        std::cout << "Ressource supprimée (si elle existait)." << std::endl;
    }
    else if (command == "7") {
        library->showAllResources();
    }
    // Fonctions administratives - Utilisateurs
    else if (command == "8") {
        addUserMenu();
    }
    else if (command == "9") {
        std::cout << "Entrez l'ID de l'utilisateur à supprimer: ";
        int id;
        std::cin >> id;
        library->removeUser(id);
        std::cout << "Utilisateur supprimé (s'il existait)." << std::endl;
    }
    else if (command == "10") {
        library->showAllUsers();
    }
    // Informations générales
    else if (command == "11") {
        library->showLibraryInfo();
    }
    else if (command == "12") {
        bye();
        return false;
    }
    else {
        std::cout << "Commande invalide. Veuillez choisir entre 1 et 12." << std::endl;
    }

    return true;
}

void Session::addResourceMenu() {
    std::cout << "\n=== Ajouter une ressource ===" << std::endl;
    std::cout << "1. Livre (Book)" << std::endl;
    std::cout << "2. Revue (Reviews)" << std::endl;
    std::cout << "3. CD" << std::endl;
    std::cout << "4. DVD" << std::endl;
    std::cout << "5. VHS" << std::endl;
    std::cout << "6. Ressource numérique (Digital)" << std::endl;
    std::cout << "7. Annuler" << std::endl;

    std::cout << "Choisissez le type de ressource à ajouter: ";
    std::string choice;
    std::cin >> choice;

    if (choice == "7") {
        std::cout << "Ajout annulé." << std::endl;
        return;
    }

    // Informations communes
    int id;
    std::string title, author;

    std::cout << "ID de la ressource: ";
    std::cin >> id;
    std::cout << "Titre: ";
    std::cin.ignore();
    std::getline(std::cin, title);
    std::cout << "Auteur: ";
    std::getline(std::cin, author);

    Resource* newResource = nullptr;

    if (choice == "1") { // Book
        std::string summary, collection;
        int pages;

        std::cout << "Résumé: ";
        std::getline(std::cin, summary);
        std::cout << "Nombre de pages: ";
        std::cin >> pages;
        std::cout << "Collection: ";
        std::cin.ignore();
        std::getline(std::cin, collection);

        newResource = new Book(id, title, author, summary, pages, collection);
    }
    else if (choice == "2") { // Reviews
        std::string summary, collection, editor;
        int pages, articles;

        std::cout << "Nombre de pages: ";
        std::cin >> pages;
        std::cout << "Collection: ";
        std::cin.ignore();
        std::getline(std::cin, collection);
        std::cout << "Résumé: ";
        std::getline(std::cin, summary);
        std::cout << "Éditeur: ";
        std::getline(std::cin, editor);
        std::cout << "Nombre d'articles: ";
        std::cin >> articles;

        std::vector<std::string> articlesList;
        newResource = new Reviews(id, title, author, pages, collection, summary, editor, articles, articlesList);
    }
    else if (choice == "3") { // CD
        std::string productionCompany;
        double duration;
        int tracksNumber;

        std::cout << "Durée (minutes): ";
        std::cin >> duration;
        std::cout << "Nombre de pistes: ";
        std::cin >> tracksNumber;
        std::cout << "Compagnie de production: ";
        std::cin.ignore();
        std::getline(std::cin, productionCompany);

        newResource = new CD(id, title, author, duration, tracksNumber, productionCompany);
    }
    else if (choice == "4") { // DVD
        std::string productionCompany;
        float duration;
        int tracksNumber = 1;

        std::cout << "Compagnie de production: ";
        std::getline(std::cin, productionCompany);
        std::cout << "Durée (minutes): ";
        std::cin >> duration;

        newResource = new DVD(id, title, author, productionCompany, duration, tracksNumber);
    }
    else if (choice == "5") { // VHS
        std::string productionCompany;
        float duration;
        int tracksNumber = 1;

        std::cout << "Compagnie de production: ";
        std::getline(std::cin, productionCompany);
        std::cout << "Durée (minutes): ";
        std::cin >> duration;

        newResource = new VHS(id, title, author, productionCompany, duration);
    }
    else if (choice == "6") { // Digital
        std::string fileFormat, url;
        double fileSize;

        std::cout << "Format de fichier: ";
        std::getline(std::cin, fileFormat);
        std::cout << "Taille du fichier (MB): ";
        std::cin >> fileSize;
        std::cout << "URL: ";
        std::cin.ignore();
        std::getline(std::cin, url);

        newResource = new Digital(id, title, author, fileFormat, fileSize, url);
    }
    else {
        std::cout << "Choix invalide." << std::endl;
        return;
    }

    if (newResource != nullptr) {
        library->addResource(newResource);
        std::cout << "Ressource ajoutée avec succès!" << std::endl;
    }
}

void Session::addUserMenu() {
    std::cout << "\n=== Ajouter un utilisateur ===" << std::endl;
    std::cout << "1. Client" << std::endl;
    std::cout << "2. Administrateur" << std::endl;
    std::cout << "3. Annuler" << std::endl;

    std::cout << "Choisissez le type d'utilisateur à ajouter: ";
    std::string choice;
    std::cin >> choice;

    if (choice == "3") {
        std::cout << "Ajout annulé." << std::endl;
        return;
    }

    // Informations communes
    int id;
    std::string email;

    std::cout << "ID de l'utilisateur: ";
    std::cin >> id;
    std::cout << "Email: ";
    std::cin.ignore();
    std::getline(std::cin, email);

    User* newUser = nullptr;

    if (choice == "1") { // Client
        std::string firstName, lastName;
        std::cout << "Prénom: ";
        std::getline(std::cin, firstName);
        std::cout << "Nom: ";
        std::getline(std::cin, lastName);

        newUser = new Client(id, firstName, lastName, email);
    }
    else if (choice == "2") { // Admin
        std::string firstName, lastName;
        std::cout << "Prénom: ";
        std::getline(std::cin, firstName);
        std::cout << "Nom: ";
        std::getline(std::cin, lastName);

        newUser = new Admin(id, firstName, lastName, email);
    }
    else {
        std::cout << "Choix invalide." << std::endl;
        return;
    }

    if (newUser != nullptr) {
        library->addUser(newUser);
        std::cout << "Utilisateur ajouté avec succès!" << std::endl;
    }
}

void Session::borrowResourceMenu() {
    if (library == nullptr) {
        std::cout << "Erreur: Aucune bibliothèque associée à la session." << std::endl;
        return;
    }
    
    std::cout << "\n=== Emprunter une ressource ===" << std::endl;
    int userId, resourceId;
    std::cout << "Entrez votre ID utilisateur: ";
    std::cin >> userId;
    User* user = library->findUser(userId);
    if (user == nullptr) {
        std::cout << "Utilisateur non trouvé." << std::endl;
        return;
    }

    std::cout << "Entrez l'ID de la ressource à emprunter: ";
    std::cin >> resourceId;
    Resource* resource = library->findResource(resourceId);
    if (resource == nullptr) {
        std::cout << "Ressource non trouvée." << std::endl;
        return;
    }

    if (user->borrowResource(resource)) {
        std::cout << "Ressource empruntée avec succès!" << std::endl;
    } else {
        std::cout << "Échec de l'emprunt de la ressource." << std::endl;
    }
}
void Session::returnResourceMenu() {

    std::cout << "\n=== Rendre une ressource ===" << std::endl;
    int userId, resourceId;
    std::cout << "Entrez votre ID utilisateur: ";
    std::cin >> userId;
    User* user = library->findUser(userId);
    if (user == nullptr) {
        std::cout << "Utilisateur non trouvé." << std::endl;
        return;
    }

    std::cout << "Entrez l'ID de la ressource à rendre: ";
    std::cin >> resourceId;
    Resource* resource = library->findResource(resourceId);
    if (resource == nullptr) {
        std::cout << "Ressource non trouvée." << std::endl;
        return;
    }

    if (user->returnResource(resource)) {
        std::cout << "Ressource rendue avec succès!" << std::endl;
    } else {
        std::cout << "Échec de la restitution de la ressource." << std::endl;
    }
}