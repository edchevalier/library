#include "Digital.hpp"

// ---------- Constructeurs ----------
Digital::Digital() 
    : Resource(), type(""), size(0), path("") {}

Digital::Digital(int id, const std::string& t, const std::string& a,
           const std::string& ty, double s, const std::string& p)
    : Resource(id, t, a), type(ty), size(s), path(p) {}

// ---------- Setters ----------
void Digital::setType(const std::string& ty) { type = ty; }
void Digital::setSize(double s) { size = s; }
void Digital::setPath(const std::string& p) { path = p; }

// ---------- Getters ----------
std::string Digital::getType() const { return type; }
double Digital::getSize() const { return size; }
std::string Digital::getPath() const { return path; }

// ---------- Méthodes ----------
void Digital::printDetails() const {
    std::cout << "[Digital] Title : " << title
              << " | Author : " << author
              << " | ID : " << idResource
              << " | Type : " << type
              << " | Size : " << size
              << " | Path : " << path
              << std::endl;
}
