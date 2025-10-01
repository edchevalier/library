#include "Library.hpp"
#include <algorithm>

Library::Library() {
}

Library::~Library() {
    for (User* user : users) {
        delete user;
    }
    for (Resource* resource : resources) {
        delete resource;
    }
}

void Library::addUser(User* user) {
    if (user != nullptr) {
        users.push_back(user);
    }
}

void Library::removeUser(int userId) {
    auto it = std::find_if(users.begin(), users.end(),
        [userId](const User* user) {
            return user->getIdUser() == userId;
        });

    if (it != users.end()) {
        delete *it;
        users.erase(it);
    }
}

User* Library::findUser(int userId) const {
    auto it = std::find_if(users.begin(), users.end(),
        [userId](const User* user) {
            return user->getIdUser() == userId;
        });

    return (it != users.end()) ? *it : nullptr;
}

void Library::showAllUsers() const {    
    std::cout << "=== Utilisateurs de la biblioth�que ===" << std::endl;
    if (users.empty()) {
        std::cout << "Aucun utilisateur enregistr�." << std::endl;
    } else {
        for (const User* user : users) {
            user->printDetails();
            std::cout << std::endl;
        }
    }
}

void Library::addResource(Resource* resource) {
    if (resource != nullptr) {
        resources.push_back(resource);
    }
}

void Library::removeResource(int resourceId) {
    auto it = std::find_if(resources.begin(), resources.end(),
        [resourceId](const Resource* resource) {
            return resource->getIdResource() == resourceId;
        });

    if (it != resources.end()) {
        delete *it;
        resources.erase(it);
    }
}

Resource* Library::findResource(int resourceId) const {
    auto it = std::find_if(resources.begin(), resources.end(),
        [resourceId](const Resource* resource) {
            return resource->getIdResource() == resourceId;
        });

    return (it != resources.end()) ? *it : nullptr;
}

void Library::showAllResources() const {
    std::cout << "=== Ressources de la biblioth�que ===" << std::endl;
    if (resources.empty()) {
        std::cout << "Aucune ressource disponible." << std::endl;
    } else {
        for (const Resource* resource : resources) {
            resource->printDetails();
            std::cout << std::endl;
        }
    }
}

void Library::showLibraryInfo() const {
    std::cout << "=== Informations de la biblioth�que ===" << std::endl;
    std::cout << "Nombre d'utilisateurs: " << users.size() << std::endl;
    std::cout << "Nombre de ressources: " << resources.size() << std::endl;
    std::cout << std::endl;

    //showAllUsers();
    std::cout << std::endl;
    //showAllResources();
}

const std::vector<User*>& Library::getUsers() const {
    return users;
}

const std::vector<Resource*>& Library::getResources() const {
    return resources;
}