#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Expense.h"
#include "User.h"

std::vector<User> users;
User* loggedInUser = nullptr;

void loadUsers() {
    std::ifstream file("users.txt");
    if (file.is_open()) {
        std::string username, password;
        while (file >> username >> password) {
            users.emplace_back(username, password);
        }
        file.close();
    }
}

void saveUsers() {
    std::ofstream file("users.txt");
    if (file.is_open()) {
        for (const auto& user : users) {
            file << user.username << " " << user.password << std::endl;
        }
        file.close();
    } else {
        std::cerr << "Unable to open file";
    }
}

User* findUser(const std::string& username) {
    for (auto& user : users) {
        if (user.username == username) {
            return &user;
        }
    }
    return nullptr;
}

void registerUser() {
    std::string username, password;

    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    if (findUser(username)) {
        std::cout << "Username already exists. Try a different one.\n";
        return;
    }

    users.emplace_back(username, password);
    saveUsers();
    std::cout << "User registered successfully!\n";
}

void loginUser() {
    std::string username, password;

    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    User* user = findUser(username);
    if (user && user->password == password) {
        loggedInUser = user;
        std::cout << "Login successful!\n";
    } else {
        std::cout << "Invalid username or password.\n";
    }
}

void addExpense() {
    if (!loggedInUser) {
        std::cout << "Please log in first.\n";
        return;
    }

    std::string date, category, description;
    double amount;

    std::cout << "Enter date (YYYY-MM-DD): ";
    std::cin >> date;
    std::cout << "Enter amount: ";
    std::cin >> amount;
    std::cout << "Enter category: ";
    std::cin >> category;
    std::cout << "Enter description: ";
    std::cin.ignore(); // To clear the newline character left by std::cin
    std::getline(std::cin, description);

    Expense newExpense(date, amount, category, description);
    loggedInUser->addExpense(newExpense);
}

void listExpenses() {
    if (!loggedInUser) {
        std::cout << "Please log in first.\n";
        return;
    }

    loggedInUser->displayExpenses();
}

void setBudget() {
    if (!loggedInUser) {
        std::cout << "Please log in first.\n";
        return;
    }

    double amount;
    std::cout << "Enter budget amount: ";
    std::cin >> amount;
    loggedInUser->setBudget(amount);
    std::cout << "Budget set successfully!\n";
}

void displaySummary() {
    if (!loggedInUser) {
        std::cout << "Please log in first.\n";
        return;
    }

    double totalExpenses = loggedInUser->calculateTotalExpenses();
    double remainingBudget = loggedInUser->getRemainingBudget();

    std::cout << "Total Expenses: " << totalExpenses << std::endl;
    std::cout << "Remaining Budget: " << remainingBudget << std::endl;
}

int main() {
    loadUsers();

    int choice;
    while (true) {
        std::cout << "1. Register\n2. Login\n3. Add Expense\n4. List Expenses\n5. Set Budget\n6. Display Summary\n7. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                addExpense();
                break;
            case 4:
                listExpenses();
                break;
            case 5:
                setBudget();
                break;
            case 6:
                displaySummary();
                break;
            case 7:
                return 0;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
