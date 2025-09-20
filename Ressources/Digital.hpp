#pragma once
#include "Resource.hpp"
#include <iostream>

class Digital : public Resource {
    private:
        std::string type; 
        double size;
        std::string path;

    public:
        // Constructors
        Digital();
        Digital(int id, const std::string& title, const std::string& author,
                const std::string& type, double size, const std::string& path);

        // Setters
        void setType(const std::string& Type);
        void setSize(double Size);
        void setPath(const std::string& Path);

        // Getters
        std::string getType() const;
        double getSize() const;
        std::string getPath() const;

        // Methods
        void printDetails() const override;
};