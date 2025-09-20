#include "Ressources/AllResources.hpp"
#include "User.hpp"
#include "Client.hpp"
#include "Admin.hpp"
#include <iostream>
#include <vector>

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
    Client cl1(300, "David", "Leroy", "david.client@example.com");
    cl1.printDetails();

    std::cout << "\n===== Test Video =====" << std::endl;
    Video v1(5, "Inception", "Christopher Nolan", "Warner Bros", 148.0);
    v1.printDetails();

    std::cout << "\n===== Test CD =====" << std::endl;
    CD cd1(6, "Abbey Road", "The Beatles", 47.3, 17, "Apple Records");
    cd1.printDetails();

    std::cout << "\n===== Test DVD =====" << std::endl;
    DVD d1(7, "The Matrix", "Wachowski Sisters", "Warner Bros", 136.0, 28);
    d1.printDetails();

    std::cout << "\n===== Test VHS =====" << std::endl;
    VHS vh1(8, "Titanic", "James Cameron", "Paramount Pictures", 195.0);
    vh1.printDetails();

    std::cout << "\n===== Test Digital =====" << std::endl;
    Digital dig1(9, "Digital Album", "Various Artists", "MP3", 150.5, "/music/digital_album");
    dig1.printDetails();

    std::cout << "\n===== Test Reviews =====" << std::endl;
    std::vector<std::string> articles = {"Article 1", "Article 2", "Article 3"};
    Reviews rev1(10, "Science Review", "Editorial Team", 120, "Scientific Reviews",
                 "Monthly science publication", "Dr. Smith", 3, articles);
    rev1.printDetails();

    std::cout << "\n===== Test polymorphisme Users =====" << std::endl;
    User* users[3];
    users[0] = &u1;
    users[1] = &a1;
    users[2] = &cl1;

    for (int i = 0; i < 3; i++) {
        users[i]->printDetails(); // Appelle la bonne version grâce au virtual
    }

    std::cout << "\n===== Test polymorphisme Resources =====" << std::endl;
    Resource* resources[6];
    resources[0] = &b1;
    resources[1] = &v1;
    resources[2] = &cd1;
    resources[3] = &d1;
    resources[4] = &vh1;
    resources[5] = &dig1;

    for (int i = 0; i < 6; i++) {
        resources[i]->printDetails(); // Polymorphisme pour les ressources
    }

    return 0;
}
