#include <iostream>
#include "Expense.h"

void Expense::display() const {
    std::cout << "Date: " << date << ", Amount: " << amount
              << ", Category: " << category << ", Description: " << description << std::endl;
}
