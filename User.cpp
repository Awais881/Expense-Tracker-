#include <iostream>
#include "User.h"

void User::addExpense(const Expense& expense) {
    expenses.push_back(expense);
}

void User::displayExpenses() const {
    for (const auto& expense : expenses) {
        expense.display();
    }
}

double User::calculateTotalExpenses() const {
    double total = 0.0;
    for (const auto& expense : expenses) {
        total += expense.amount;
    }
    return total;
}

void User::setBudget(double amount) {
    budget = amount;
}

double User::getRemainingBudget() const {
    return budget - calculateTotalExpenses();
}
