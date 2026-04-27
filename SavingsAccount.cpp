#include "SavingsAccount.h"
#include <iostream>

// Default constructor
SavingsAccount::SavingsAccount() : BankAccount(), interestRate(0.0) {}

// Constructor with parameters
SavingsAccount::SavingsAccount(const std::string &accNum, const std::string &Holder, double bal, double interest) : BankAccount(accNum, Holder, bal), interestRate(interest) {}

void SavingsAccount::calculateInterest() {
    double interest = getBalance() * (interestRate / 100);
    deposit(interest);
    std::cout << "Interest: $" << interest <<  " at a rate of " << interestRate << "%" << std::endl;
}