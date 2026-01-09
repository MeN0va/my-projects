#include <iostream>
#include <fstream>
#include <functional>
#include <string>

class User {
    public:
        std::string username, password;

    void hashPassword() {
        std::hash<std::string> h;
        size_t hash = h(password);
        password = std::to_string(hash);
    }

    [[nodiscard]] bool exists() const {
        std::fstream readFile("users.txt");
        std::string fileUsername, filePassword;
        while (readFile >> fileUsername >> filePassword) {
            if (fileUsername == username) {
                readFile.close();
                return true;
            }
        }
        readFile.close();
        return false;
    }

    [[nodiscard]] bool authenticate() const {
        std::fstream readFile("users.txt");
        std::string fileUsername, filePassword;
        while (readFile >> fileUsername >> filePassword) {
            if (fileUsername == username && filePassword == password) {
                readFile.close();
                return true;
            }
        }
        readFile.close();
        return false;
    }
};

int main () {
    std::cout << "╔═══════════════════════════════════════════════╗" << std::endl;
    std::cout << "║ Welcome to the Login and Registration System! ║" << std::endl;
    std::cout << "╚═══════════════════════════════════════════════╝" << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    std::string choice;

    while (true) {
        std::cout << "Type only the option number (e.g. '1'):\n "
                     "1. Register\n"
                     " 2. Login\n"
                     " 3. Exit" << std::endl;
        std::cin >> choice;

        if (choice == "1") {

            std::cout << "To register, fill in next credentials" << std::endl;

            User user1;

            std::cout << "Please, enter your username (no spaces!): " << std::endl;
            std::cin >> user1.username;
            std::cout << "Password: " << std::endl;
            std::cin >> user1.password;

            user1.hashPassword();

            if (user1.exists()) {
                std::cout << "The user already exists." << std::endl;
            } else {
                std::fstream writeFile("users.txt", std::ios::app);
                writeFile << user1.username << " " << user1.password << std::endl;
                writeFile.close();
                std::cout << "You were successfully registered!" << std::endl;
            }

            std::cout << std::endl;

        } else if (choice == "2") {
            std::cout << "Welcome back! Login here" << std::endl;

            User user2;

            std::string username, password;
            std::cout << "Username: " << std::endl;
            std::cin >> user2.username;
            std::cout << "Password: " << std::endl;
            std::cin >> user2.password;

            user2.hashPassword();

            if (user2.authenticate()) {
                std::cout << "Login successful. Welcome back!" << std::endl;
            } else {
                std::cout << "Login failed!" << std::endl;
            }

	    std::cout << std::endl;

        } else if (choice == "3") {
            std::cout << "Thanks for using the system!" << std::endl;
            std::cout << "Exiting the program..." << std::endl;
            break;
        } else {
            std::cout << "Invalid input!" << std::endl;
            continue;
        }
    }

    return 0;
}	
