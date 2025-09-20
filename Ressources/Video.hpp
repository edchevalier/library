#pragma once
#include "Resource.hpp"
#include <string>
#include <iostream>

class Video : public Resource {
    protected:
        std::string productionCompany;
        float duration; // en minutes ou heures

    public:
        // Constructeurs
        Video();
        Video(int id, const std::string& title, const std::string& author,
              const std::string& productionCompany, float duration);

        // Setters
        void setProductionCompany(const std::string& pc);
        void setDuration(float d);

        // Getters
        std::string getProductionCompany() const;
        float getDuration() const;

        // Méthodes
        void printDetails() const override;
};
