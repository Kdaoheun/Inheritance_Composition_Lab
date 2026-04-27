#include "CheckingAccount.h"
#include <iostream>

// Default constructor
CheckingAccount::CheckingAccount() : BankAccount(), transactionFee(0.0) {}

// Constructor with parameters
CheckingAccount::CheckingAccount(const std::string& accNum, const std::string& Holder, double bal, double fee) : BankAccount(accNum, Holder, bal), transactionFee(fee) {}

// Override withdraw to apply transaction fee
void CheckingAccount::withdraw(double amount) {
    double totalAmount = amount + transactionFee;
    if (totalAmount <= 0) {
        std::cout << "Withdraw amount must be greater than zero." << std::endl;
    }
    else if (totalAmount > getBalance()) {
        std::cout << "Insufficient funds including transaction fee." << std::endl;
    }
    else {
        BankAccount::withdraw(totalAmount);
        std::cout << "Transaction fee of $" << transactionFee << " applied." << std::endl;
    }
}