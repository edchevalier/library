#include "AllClasses.hpp"
#include <iostream>
#include <vector>

int main() {
    Library lib;
    FileManager fileManager;

    std::cout << "===== Chargement des utilisateurs depuis le fichier =====" << std::endl;
    std::vector<User*> users = fileManager.loadUsers("data/utilisateurs.txt");

    std::cout << "\n===== Chargement des ressources depuis le fichier =====" << std::endl;
    std::vector<Resource*> resources = fileManager.loadResources("data/ressources.txt");

    std::cout << "\n===== Affichage des utilisateurs chargés =====" << std::endl;
    for (User* user : users) {
        if (user != nullptr) {
            //user->printDetails();
            lib.addUser(user);
        }
    }

    std::cout << "\n===== Affichage des ressources chargées =====" << std::endl;
    for (Resource* resource : resources) {
        if (resource != nullptr) {
            //resource->printDetails();
            lib.addResource(resource);
        }
    }

    // Lancement d'une session
    Session session(&lib);
    session.run();
    fileManager.saveUsers("utilisateurs.txt", lib.getUsers());
    fileManager.saveResources("ressources.txt", lib.getResources());
    return 0;
}
