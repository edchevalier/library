#include "Resource.hpp"
#include "Book.hpp"
#include "User.hpp"
#include "Client.hpp"
#include "Admin.hpp"
#include <iostream>

int main() {
    std::cout << "===== Test Resource =====" << std::endl;
    Resource r1(1, "Harry Potter 1", "J.K. Rowling");
    Resource r2(2, "Harry Potter 2", "J.K. Rowling");
    r1.printDetails();
    r2.printDetails();

    std::cout << "\n===== Test Book =====" << std::endl;
    Book b1(3, "Le Petit Prince", "Antoine de Saint-Exupéry",
            "Conte poétique et philosophique.", 96, "Classiques");
    Book b2(4, "1984", "George Orwell",
            "Roman d’anticipation sur un régime totalitaire.", 328, "Dystopies");
    b1.printDetails();
    b2.printDetails();

    std::cout << "\n===== Test User =====" << std::endl;
    User u1(100, "Alice", "Durand", "alice@example.com");
    User u2(101, "Bob", "Martin", "bob@example.com");
    u1.printDetails();
    u2.printDetails();

    std::cout << "\n===== Test Admin =====" << std::endl;
    Admin a1(200, "Charles", "Dupont", "charles.admin@example.com");
    a1.printDetails();

    std::cout << "\n===== Test Client =====" << std::endl;
    Client c1(300, "David", "Leroy", "david.client@example.com");
    c1.printDetails();

    std::cout << "\n===== Test polymorphisme =====" << std::endl;
    User* users[3];
    users[0] = &u1;
    users[1] = &a1;
    users[2] = &c1;

    for (int i = 0; i < 3; i++) {
        users[i]->printDetails(); // Appelle la bonne version grâce au virtual
    }

    return 0;
}
