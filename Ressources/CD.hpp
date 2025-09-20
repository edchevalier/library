#pragma once
#include "Resource.hpp"
#include <iostream>

class CD : public Resource {
    private:
        double duration;
        int tracksNumber;
        std::string productionCompany;

    public:
        // Constructors
        CD();
        CD(int id, const std::string& title, const std::string& author,
                double duration, int tracksNumber, const std::string& productionCompany);

        // Setters
        void setDuration(double duration);
        void setTracksNumber(int trackNumber);
        void setProductionCompany(const std::string& productionCompany);

        // Getters
        double getDuration() const;
        int getTracksNumber() const;
        std::string getProductionCompany() const;

        // Methods
        void printDetails() const override;
};