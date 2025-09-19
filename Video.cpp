#include "Video.hpp"

// ---------- Constructeurs ----------
Video::Video() 
    : Resource(), productionCompany(""), duration(0.0f) {}

Video::Video(int id, const std::string& t, const std::string& a,
             const std::string& pc, float d)
    : Resource(id, t, a), productionCompany(pc), duration(d) {}

// ---------- Setters ----------
void Video::setProductionCompany(const std::string& pc) { productionCompany = pc; }
void Video::setDuration(float d) { duration = d; }

// ---------- Getters ----------
std::string Video::getProductionCompany() const { return productionCompany; }
float Video::getDuration() const { return duration; }

// ---------- Méthodes ----------
void Video::printDetails() const {
    std::cout << "[Video] Title : " << title
              << " | Author : " << author
              << " | ID : " << idResource
              << " | Production Company : " << productionCompany
              << " | Duration : " << duration << " min"
              << std::endl;
}
