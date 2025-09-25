#include "FileManager.hpp"
#include "Admin.hpp"
#include "Client.hpp"
#include "Ressources/Book.hpp"
#include "Ressources/Video.hpp"
#include "Ressources/CD.hpp"
#include "Ressources/DVD.hpp"
#include "Ressources/VHS.hpp"
#include "Ressources/Digital.hpp"
#include "Ressources/Reviews.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

// Constructeur
FileManager::FileManager() {
}

// Destructeur
FileManager::~FileManager() {
}

std::vector<User*> FileManager::loadUsers(const std::string& filename) {
    std::vector<User*> users;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Erreur: Impossible d'ouvrir le fichier " << filename << std::endl;
        return users;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty()) {
            User* user = parseUser(line);
            if (user != nullptr) {
                users.push_back(user);
            }
        }
    }

    file.close();
    std::cout << "Chargé " << users.size() << " utilisateurs depuis " << filename << std::endl;
    return users;
}

void FileManager::saveUsers(const std::string& filename, const std::vector<User*>& users) {
    std::ofstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Erreur: Impossible d'ouvrir le fichier " << filename << " pour l'écriture" << std::endl;
        return;
    }

    for (const User* user : users) {
        if (user != nullptr) {
            file << userToString(user) << std::endl;
        }
    }

    file.close();
    std::cout << "Sauvegardé " << users.size() << " utilisateurs dans " << filename << std::endl;
}

std::vector<Resource*> FileManager::loadResources(const std::string& filename) {
    std::vector<Resource*> resources;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Erreur: Impossible d'ouvrir le fichier " << filename << std::endl;
        return resources;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty()) {
            Resource* resource = parseResource(line);
            if (resource != nullptr) {
                resources.push_back(resource);
            }
        }
    }

    file.close();
    std::cout << "Chargé " << resources.size() << " ressources depuis " << filename << std::endl;
    return resources;
}

void FileManager::saveResources(const std::string& filename, const std::vector<Resource*>& resources) {
    std::ofstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Erreur: Impossible d'ouvrir le fichier " << filename << " pour l'écriture" << std::endl;
        return;
    }

    for (const Resource* resource : resources) {
        if (resource != nullptr) {
            file << resourceToString(resource) << std::endl;
        }
    }

    file.close();
    std::cout << "Sauvegardé " << resources.size() << " ressources dans " << filename << std::endl;
}

User* FileManager::parseUser(const std::string& line) {
    std::istringstream iss(line);
    std::string type, idStr, firstName, lastName, email;

    if (std::getline(iss, type, '|') &&
        std::getline(iss, idStr, '|') &&
        std::getline(iss, firstName, '|') &&
        std::getline(iss, lastName, '|') &&
        std::getline(iss, email)) {

        int id = std::stoi(idStr);

        if (type == "Admin") {
            return new Admin(id, firstName, lastName, email);
        } else if (type == "Client") {
            return new Client(id, firstName, lastName, email);
        }
    }

    std::cerr << "Erreur lors du parsing de la ligne utilisateur: " << line << std::endl;
    return nullptr;
}

Resource* FileManager::parseResource(const std::string& line) {
    std::istringstream iss(line);
    std::string type, idStr, title, author;

    if (std::getline(iss, type, '|') &&
        std::getline(iss, idStr, '|') &&
        std::getline(iss, title, '|') &&
        std::getline(iss, author, '|')) {

        int id = std::stoi(idStr);

        if (type == "Book") {
            std::string summary, pagesStr, collection;
            if (std::getline(iss, summary, '|') &&
                std::getline(iss, pagesStr, '|') &&
                std::getline(iss, collection)) {
                int pages = std::stoi(pagesStr);
                return new Book(id, title, author, summary, pages, collection);
            }
        } else if (type == "Video") {
            std::string company, durationStr;
            if (std::getline(iss, company, '|') &&
                std::getline(iss, durationStr)) {
                float duration = std::stof(durationStr);
                return new Video(id, title, author, company, duration);
            }
        } else if (type == "CD") {
            return new CD(id, title, author);
        } else if (type == "DVD") {
            return new DVD(id, title, author);
        } else if (type == "VHS") {
            return new VHS(id, title, author);
        } else if (type == "Digital") {
            return new Digital(id, title, author);
        } else if (type == "Reviews") {
            std::string summary, pagesStr, collection, editor, articlesStr;
            if (std::getline(iss, summary, '|') &&
                std::getline(iss, pagesStr, '|') &&
                std::getline(iss, collection, '|') &&
                std::getline(iss, editor, '|') &&
                std::getline(iss, articlesStr)) {
                int pages = std::stoi(pagesStr);
                int articles = std::stoi(articlesStr);
                std::vector<std::string> articlesList;
                return new Reviews(id, title, author, pages, collection, summary, editor, articles, articlesList);
            }
        }
    }

    std::cerr << "Erreur lors du parsing de la ligne ressource: " << line << std::endl;
    return nullptr;
}

std::string FileManager::userToString(const User* user) {
    if (user == nullptr) return "";

    std::string type = "User";
    const Admin* admin = dynamic_cast<const Admin*>(user);
    const Client* client = dynamic_cast<const Client*>(user);

    if (admin != nullptr) {
        type = "Admin";
    } else if (client != nullptr) {
        type = "Client";
    }

    return type + "|" +
           std::to_string(user->getIdUser()) + "|" +
           user->getFirstName() + "|" +
           user->getLastName() + "|" +
           user->getEmailAddress();
}

std::string FileManager::resourceToString(const Resource* resource) {
    if (resource == nullptr) return "";

    std::string result = "";

    const Book* book = dynamic_cast<const Book*>(resource);
    const Video* video = dynamic_cast<const Video*>(resource);
    const CD* cd = dynamic_cast<const CD*>(resource);
    const DVD* dvd = dynamic_cast<const DVD*>(resource);
    const VHS* vhs = dynamic_cast<const VHS*>(resource);
    const Digital* digital = dynamic_cast<const Digital*>(resource);
    const Reviews* reviews = dynamic_cast<const Reviews*>(resource);

    if (book != nullptr) {
        result = "Book|" + std::to_string(resource->getIdResource()) + "|" +
                resource->getTitle() + "|" + resource->getAuthor() + "|" +
                book->getSummary() + "|" + std::to_string(book->getPagesNumber()) + "|" +
                book->getCollection();
    } else if (video != nullptr) {
        result = "Video|" + std::to_string(resource->getIdResource()) + "|" +
                resource->getTitle() + "|" + resource->getAuthor() + "|" +
                video->getProductionCompany() + "|" + std::to_string(video->getDuration());
    } else if (reviews != nullptr) {
        result = "Reviews|" + std::to_string(resource->getIdResource()) + "|" +
                resource->getTitle() + "|" + resource->getAuthor() + "|" +
                reviews->getSummary() + "|" + std::to_string(reviews->getPagesNumber()) + "|" +
                reviews->getCollection() + "|" + reviews->getEditor() + "|" +
                std::to_string(reviews->getNbArticles());
    } else if (cd != nullptr) {
        result = "CD|" + std::to_string(resource->getIdResource()) + "|" +
                resource->getTitle() + "|" + resource->getAuthor();
    } else if (dvd != nullptr) {
        result = "DVD|" + std::to_string(resource->getIdResource()) + "|" +
                resource->getTitle() + "|" + resource->getAuthor();
    } else if (vhs != nullptr) {
        result = "VHS|" + std::to_string(resource->getIdResource()) + "|" +
                resource->getTitle() + "|" + resource->getAuthor();
    } else if (digital != nullptr) {
        result = "Digital|" + std::to_string(resource->getIdResource()) + "|" +
                resource->getTitle() + "|" + resource->getAuthor();
    } else {
        result = "Resource|" + std::to_string(resource->getIdResource()) + "|" +
                resource->getTitle() + "|" + resource->getAuthor();
    }

    return result;
}