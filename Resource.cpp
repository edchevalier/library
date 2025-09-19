#include "Resource.hpp"

// ---------- Constructeurs ----------
Resource::Resource() : idResource(0), title(""), author("") {};

Resource::Resource(int id, const std::string& t, const std::string& a){
    idResource = id;
    title = t;
    author = a;
};

// ---------- Setters ----------
void Resource::setTitle(const std::string& t) { title = t; }
void Resource::setAuthor(const std::string& a) { author = a; }
void Resource::setIdResource(int id) { idResource = id; };

// ---------- Getters ----------
std::string Resource::getTitle() const { return title; }
std::string Resource::getAuthor() const { return author; }
int Resource::getIdResource() const { return idResource; }

// ---------- Méthodes ----------
void Resource::printDetails() const {
    std::cout << "title : " << title
              << " author : " << author
              << " ID Resource : " << idResource
              << std::endl;;
}
