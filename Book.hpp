#pragma once
#include "Resource.hpp"
#include <string>
#include <iostream>

class Book : public Resource {
    private:
        std::string summary;
        int pagesNumber;
        std::string collection;

    public:
        // Constructeurs
        Book();
        Book(int id, const std::string& title, const std::string& author,
             const std::string& summary, int pagesNumber, const std::string& collection);

        // Setters
        void setSummary(const std::string& s);
        void setPagesNumber(int p);
        void setCollection(const std::string& c);

        // Getters
        std::string getSummary() const;
        int getPagesNumber() const;
        std::string getCollection() const;

        // Méthodes
        void printDetails() const override;
};
