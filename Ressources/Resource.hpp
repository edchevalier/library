#pragma once
#include <string>
#include <iostream>

class Resource {
    protected:
        int idResource;
        std::string title;
        std::string author;
        int borrowedBy; // ID of the user who borrowed the resource, 0 if not borrowed

    public:
        // Constructeurs
        Resource();
        Resource(int idResource, const std::string& title, const std::string& author, int borrowedBy = 0);

        virtual void printDetails() const;

        // Setters
        void setTitle(const std::string& fn);
        void setAuthor(const std::string& ln);
        void setIdResource(int year);
        void setBorrowedBy(int userId);

        // Getters
        std::string getTitle() const;
        std::string getAuthor() const;
        int getIdResource() const;
        int getBorrowedBy() const;

        void borrowStatus() const;
        bool isAvailable() const;
        bool borrowResource(int userId);
        bool returnResource(int userId);

        virtual ~Resource() = default;
};


