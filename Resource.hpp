#pragma once
#include <string>
#include <iostream>

class Resource {
    protected:
        int idResource;
        std::string title;
        std::string author;

    public:
        // Constructeurs
        Resource();
        Resource(int idResource, const std::string& title, const std::string& author);

        virtual void printDetails() const;

        // Setters
        void setTitle(const std::string& fn);
        void setAuthor(const std::string& ln);
        void setIdResource(int year);

        // Getters
        std::string getTitle() const;
        std::string getAuthor() const;
        int getIdResource() const;
};


