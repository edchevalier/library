#include "Ressources/AllResources.hpp"
#include "User.hpp"
#include "Client.hpp"
#include "Admin.hpp"
#include "Session.hpp"
#include "FileManager.hpp"
#include "Library.hpp"
#include <iostream>
#include <vector>

int main() {
    Library lib;
    FileManager fileManager;

    std::cout << "===== Chargement des utilisateurs depuis le fichier =====" << std::endl;
    std::vector<User*> users = fileManager.loadUsers("utilisateurs.txt");

    std::cout << "\n===== Chargement des ressources depuis le fichier =====" << std::endl;
    std::vector<Resource*> resources = fileManager.loadResources("ressources.txt");

    std::cout << "\n===== Affichage des utilisateurs chargés =====" << std::endl;
    for (User* user : users) {
        if (user != nullptr) {
            user->printDetails();
            lib.addUser(user);
        }
    }

    std::cout << "\n===== Affichage des ressources chargées =====" << std::endl;
    for (Resource* resource : resources) {
        if (resource != nullptr) {
            resource->printDetails();
            lib.addResource(resource);
        }
    }

    // Lancement d'une session
    Session session(&lib);
    session.run();

    return 0;
}
