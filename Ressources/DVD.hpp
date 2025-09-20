#pragma once
#include "Video.hpp"
#include <iostream>

class DVD : public Video {
    private :
        int chapterNumber; 

    public:
        // Constructeurs
        DVD();
        DVD(int id, const std::string& title, const std::string& author,
            const std::string& productionCompany, float duration, int chapterNumber);
        
        // Setters
        void setChapterNumber(int chapterNumber);
        // Getters
        int getChapterNumber() const;

        // Méthodes
        void printDetails() const override;
};