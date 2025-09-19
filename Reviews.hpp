#pragma once
#include "Book.hpp"
#include <iostream>

class Reviews : public Book {
    private:
        std::string editor; 
        int nbArticles;
        std::vector<std::string> articles;

    public:
        // Constructors
        Reviews();
        Reviews(int id, const std::string& title, const std::string& author,
                int pagesNumber, const std::string& collection,
                const std::string& summary, const std::string& editor,
                int nbArticles, const std::vector<std::string>& articles);

        // Setters
        void setEditor(const std::string& editor);
        void setNbArticles(int nbArticles);
        void setArticles(const std::vector<std::string>& articles);

        // Getters
        std::string getEditor() const;
        int getNbArticles() const;
        std::vector<std::string> getArticles() const;

        // Methods
        void printDetails() const override;

        bool isSearched(const std::string& keyword) const override;
};