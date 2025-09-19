#include "CD.hpp"

// ---------- Constructeurs ----------
CD::CD() 
    : Resource(), duration(0), tracksNumber(0), productionCompany("") {}

CD::CD(int id, const std::string& t, const std::string& a,
           const double d, int tr, const std::string& p)
    : Resource(id, t, a), duration(d), tracksNumber(tr), productionCompany(p) {}

// ---------- Setters ----------
void CD::setDuration(double d) { duration = d; }
void CD::setTracksNumber(int tr) { tracksNumber = tr; }
void CD::setProductionCompany(const std::string& p) { productionCompany = p; }

// ---------- Getters ----------
double CD::getDuration() const { return duration; }
int CD::getTracksNumber() const { return tracksNumber; }
std::string CD::getProductionCompany() const { return productionCompany; }

// ---------- Méthodes ----------
void CD::printDetails() const {
    std::cout << "[CD] Title : " << title
              << " | Author : " << author
              << " | ID : " << idResource
              << " | Duration : " << duration
              << " | Tracks Number : " << tracksNumber
              << " | Production Company : " << productionCompany
              << std::endl;
}
