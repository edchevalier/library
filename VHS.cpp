#include "VHS.hpp"
#include <iostream>

// ---------- Constructeurs ----------
VHS::VHS() : Video()

VHS::VHS(int id, const std::string& title, const std::string& author,
         int duration, const std::string& productionCompany)
    : Video(id, title, author, duration, productionCompany)

// ---------- Méthodes ---------- 
void VHS::printDetails() const {
    std::cout << "[VHS] Title : " << title
              << " | Author : " << author
              << " | ID : " << idResource
              << " | Duration : " << duration << " mins"
              << " | Production Company : " << productionCompany
              << std::endl;
