#ifndef EXPENSE_H
#define EXPENSE_H

#include <string>

class Expense {
public:
    std::string date;
    double amount;
    std::string category;
    std::string description;

    Expense(std::string d, double a, std::string c, std::string desc)
        : date(d), amount(a), category(c), description(desc) {}
    
    void display() const;
};

#endif // EXPENSE_H
