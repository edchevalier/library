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
            std::string durationStr, tracksStr, company;
            if (std::getline(iss, durationStr, '|') &&
                std::getline(iss, tracksStr, '|') &&
                std::getline(iss, company)) {
                double duration = std::stod(durationStr);
                int tracks = std::stoi(tracksStr);
                return new CD(id, title, author, duration, tracks, company);
            }
        } else if (type == "DVD") {
            std::string company, durationStr, chaptersStr;
            if (std::getline(iss, company, '|') &&
                std::getline(iss, durationStr, '|') &&
                std::getline(iss, chaptersStr)) {
                float duration = std::stof(durationStr);
                int chapters = std::stoi(chaptersStr);
                return new DVD(id, title, author, company, duration, chapters);
            }
        } else if (type == "VHS") {
            std::string company, durationStr;
            if (std::getline(iss, company, '|') &&
                std::getline(iss, durationStr)) {
                float duration = std::stof(durationStr);
                return new VHS(id, title, author, company, duration);
            }
        } else if (type == "Digital") {
            std::string typeStr, sizeStr, path;
            if (std::getline(iss, typeStr, '|') &&
                std::getline(iss, sizeStr, '|') &&
                std::getline(iss, path)) {
                double size = std::stod(sizeStr);
                return new Digital(id, title, author, typeStr, size, path);
            }
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

    if (reviews != nullptr) {
        result = "Reviews|" + std::to_string(resource->getIdResource()) + "|" +
                resource->getTitle() + "|" + resource->getAuthor() + "|" +
                reviews->getSummary() + "|" + std::to_string(reviews->getPagesNumber()) + "|" +
                reviews->getCollection() + "|" + reviews->getEditor() + "|" +
                std::to_string(reviews->getNbArticles());
    } else if (book != nullptr) {
        result = "Book|" + std::to_string(resource->getIdResource()) + "|" +
                resource->getTitle() + "|" + resource->getAuthor() + "|" +
                book->getSummary() + "|" + std::to_string(book->getPagesNumber()) + "|" +
                book->getCollection();
    } else if (dvd != nullptr) {
        result = "DVD|" + std::to_string(resource->getIdResource()) + "|" +
                resource->getTitle() + "|" + resource->getAuthor() + "|" +
                dvd->getProductionCompany() + "|" + std::to_string(dvd->getDuration()) + "|" +
                std::to_string(dvd->getChapterNumber());
    } else if (vhs != nullptr) {
        result = "VHS|" + std::to_string(resource->getIdResource()) + "|" +
                resource->getTitle() + "|" + resource->getAuthor() + "|" +
                vhs->getProductionCompany() + "|" + std::to_string(vhs->getDuration());
    } else if (video != nullptr) {
        result = "Video|" + std::to_string(resource->getIdResource()) + "|" +
                resource->getTitle() + "|" + resource->getAuthor() + "|" +
                video->getProductionCompany() + "|" + std::to_string(video->getDuration());
    } else if (cd != nullptr) {
        result = "CD|" + std::to_string(resource->getIdResource()) + "|" +
                resource->getTitle() + "|" + resource->getAuthor() + "|" +
                std::to_string(cd->getDuration()) + "|" + std::to_string(cd->getTracksNumber()) + "|" +
                cd->getProductionCompany();
    } else if (digital != nullptr) {
        result = "Digital|" + std::to_string(resource->getIdResource()) + "|" +
                resource->getTitle() + "|" + resource->getAuthor() + "|" +
                digital->getType() + "|" + std::to_string(digital->getSize()) + "|" +
                digital->getPath();
    } else {
        result = "Resource|" + std::to_string(resource->getIdResource()) + "|" +
                resource->getTitle() + "|" + resource->getAuthor();
    }

    return result;
}