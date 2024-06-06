#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "Expense.h"

class User {
public:
    std::string username;
    std::string password;
    std::vector<Expense> expenses;
    double budget;

    User(std::string u, std::string p)
        : username(u), password(p), budget(0.0) {}

    void addExpense(const Expense& expense);
    void displayExpenses() const;
    double calculateTotalExpenses() const;
    void setBudget(double amount);
    double getRemainingBudget() const;
};

#endif // USER_H
