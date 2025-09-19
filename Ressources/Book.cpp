#include "Book.hpp"

// ---------- Constructeurs ----------
Book::Book() 
    : Resource(), summary(""), pagesNumber(0), collection("") {}

Book::Book(int id, const std::string& t, const std::string& a,
           const std::string& s, int p, const std::string& c)
    : Resource(id, t, a), summary(s), pagesNumber(p), collection(c) {}

// ---------- Setters ----------
void Book::setSummary(const std::string& s) { summary = s; }
void Book::setPagesNumber(int p) { pagesNumber = p; }
void Book::setCollection(const std::string& c) { collection = c; }

// ---------- Getters ----------
std::string Book::getSummary() const { return summary; }
int Book::getPagesNumber() const { return pagesNumber; }
std::string Book::getCollection() const { return collection; }

// ---------- Méthodes ----------
void Book::printDetails() const {
    std::cout << "[Book] Title : " << title
              << " | Author : " << author
              << " | ID : " << idResource
              << " | Summary : " << summary
              << " | Pages : " << pagesNumber
              << " | Collection : " << collection
              << std::endl;
}
