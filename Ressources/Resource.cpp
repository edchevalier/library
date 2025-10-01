#include "Resource.hpp"

// ---------- Constructeurs ----------
Resource::Resource() : idResource(0), title(""), author(""), borrowedBy(0){};

Resource::Resource(int id, const std::string& t, const std::string& a, int b){
    idResource = id;
    title = t;
    author = a;
    borrowedBy = b;
};

// ---------- Setters ----------
void Resource::setTitle(const std::string& t) { title = t; }
void Resource::setAuthor(const std::string& a) { author = a; }
void Resource::setIdResource(int id) { idResource = id; };
void Resource::setBorrowedBy(int userId){ borrowedBy = userId; };

// ---------- Getters ----------
std::string Resource::getTitle() const { return title; }
std::string Resource::getAuthor() const { return author; }
int Resource::getIdResource() const { return idResource; }
int Resource::getBorrowedBy() const { return borrowedBy; }

// ---------- Méthodes ----------
void Resource::printDetails() const {
    std::cout << "title : " << title
              << " author : " << author
              << " ID Resource : " << idResource;
    if (isAvailable()) {
        std::cout << " | Status : Disponible";
    } else {
        std::cout << " | Status : Emprunté par un utilisateur ";
    }
     std::cout  << std::endl;;
}




bool Resource::isAvailable() const {
    return borrowedBy == 0;
}

void Resource::borrowStatus() const {
    if (isAvailable()) {
        std::cout << " | Statut : Disponible";
    } else {
        std::cout << " | Statut : Emprunté par un utilisateur ";
    }
}

bool Resource::borrowResource(int userId) {
    if (isAvailable()) {
        borrowedBy = userId;
        return true;
    }
    return false;
}

bool Resource::returnResource(int userId) {
    if (borrowedBy == userId) {
        borrowedBy = 0;
        return true;
    }
    return false;
}
