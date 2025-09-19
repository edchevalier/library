#pragma once
#include "Video.hpp"
#include <iostream>

class VHS : public Video {
    public:
        // Constructeurs
        VHS();
        VHS(int id, const std::string& title, const std::string& author,
            int duration, const std::string& productionCompany);

        // Méthodes
        void printDetails() const override;

        bool isSearched(const std::string& keyword) const override;
};