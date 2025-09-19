#include "DVD.hpp"
#include <iostream>

// ---------- Constructeurs ----------
DVD::DVD() : Video(), chapterNumber(0) {}

DVD::DVD(int id, const std::string& title, const std::string& author,
         int duration, const std::string& productionCompany, int chapterNumber)
    : Video(id, title, author, duration, productionCompany), chapterNumber(chapterNumber) {}

// ---------- Setters ----------
void DVD::setChapterNumber(int chapterNumber) { this->chapterNumber = chapterNumber; }
// ---------- Getters ----------
int DVD::getChapterNumber() const { return chapterNumber; }

// ---------- Méthodes ---------- 
void DVD::printDetails() const {
    std::cout << "[DVD] Title : " << title
              << " | Author : " << author
              << " | ID : " << idResource
              << " | Duration : " << duration << " mins"
              << " | Production Company : " << productionCompany
              << " | Chapters : " << chapterNumber
              << std::endl;
}