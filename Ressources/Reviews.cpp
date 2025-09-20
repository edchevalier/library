#include "Reviews.hpp"
#include <iostream>

// ---------- Constructeurs ----------
Reviews::Reviews() : Book(), editor(""), nbArticles(0) {}

Reviews::Reviews(int id, const std::string& title, const std::string& author,
                int pagesNumber, const std::string& collection,
                const std::string& summary, const std::string& editor,
                int nbArticles, const std::vector<std::string>& articles)
    : Book(id, title, author, summary, pagesNumber, collection),
      editor(editor), nbArticles(nbArticles), articles(articles) {}

// ---------- Setters ----------
void Reviews::setEditor(const std::string& editor) { this->editor = editor; }
void Reviews::setNbArticles(int nbArticles) { this->nbArticles = nbArticles; }
void Reviews::setArticles(const std::vector<std::string>& articles) { this->articles = articles; }

// ---------- Getters ----------
std::string Reviews::getEditor() const { return editor; }
int Reviews::getNbArticles() const { return nbArticles; }
std::vector<std::string> Reviews::getArticles() const { return articles; }

// ---------- Méthodes ----------
void Reviews::printDetails() const {
    std::cout << "[Review] Title : " << getTitle()
              << " | Author : " << getAuthor()
              << " | ID : " << getIdResource()
              << " | Pages : " << getPagesNumber()
              << " | Collection : " << getCollection()
              << " | Summary : " << getSummary()
              << " | Editor : " << editor
              << " | Articles : " << nbArticles
              << std::endl;
}