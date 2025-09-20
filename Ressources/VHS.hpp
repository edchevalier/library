#pragma once
#include "Video.hpp"
#include <iostream>

class VHS : public Video {
    public:
        // Constructeurs
        VHS();
        VHS(int id, const std::string& title, const std::string& author,
            const std::string& productionCompany, float duration);

        // Méthodes
        void printDetails() const override;
};