#include "VHS.hpp"
#include <iostream>

// ---------- Constructeurs ----------
VHS::VHS() : Video() {
}

VHS::VHS(int id, const std::string& title, const std::string& author,
         const std::string& productionCompany, float duration)
    : Video(id, title, author, productionCompany, duration) {
}

// ---------- Méthodes ----------
void VHS::printDetails() const {
    std::cout << "[VHS] Title : " << title
              << " | Author : " << author
              << " | ID : " << idResource
              << " | Duration : " << duration << " mins"
              << " | Production Company : " << productionCompany
              << std::endl;
}
