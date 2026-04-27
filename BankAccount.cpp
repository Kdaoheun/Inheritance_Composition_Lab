#include "BankAccount.h"
#include <iostream>
#include <limits>
#include <ctime>


BankAccount::BankAccount() {
    accountNumber = "None";
    accountHolderName = "None";
    balance = 0.0;
}

BankAccount::BankAccount(std::string accNum, std::string Holder,double bal) {
    accountNumber = accNum;
    accountHolderName = Holder;
    balance = bal;
}

BankAccount::BankAccount(const BankAccount &other) {
    accountNumber = other.accountNumber;
    accountHolderName = other.accountHolderName;
    balance = other.balance;
}

BankAccount& BankAccount::operator=(const BankAccount &other) {
    if (this != &other) {
        accountNumber = other.accountNumber;
        accountHolderName = other.accountHolderName;
        balance = other.balance;
    }
    return *this;
}

BankAccount::~BankAccount() {}

BankAccount& BankAccount::operator+=(double amount) {
    deposit(amount);
    return *this;
}

BankAccount& BankAccount::operator-=(double amount) {
    withdraw(amount);
    return *this;
}

bool BankAccount::operator>(const BankAccount &other) const {
    return balance > other.balance;
}

bool BankAccount::operator<(const BankAccount &other) const {
    return balance < other.balance;
}

bool BankAccount::operator==(const BankAccount &other) const {
    return accountNumber == other.accountNumber;
}

std::string BankAccount::getAccountNumber() const {
    return accountNumber;
}
std::string BankAccount::getAccountHolderName() const {
    return accountHolderName;
}
double BankAccount::getBalance() const {
    return balance;
}

void BankAccount::setAccountHolderName(const std::string &Holder) {
    accountHolderName = Holder;
}

void BankAccount::printAccount(const BankAccount &account) {
    std::cout << "Account number: " << account.accountNumber << std::endl;
    std::cout << "Account Holder Name: " << account.accountHolderName << std::endl;
    std::cout << "Account Balance: " << account.balance << std::endl;
}

BankAccount BankAccount::createAccountFromInput() {
    std::string accNum, Holder;
    double bal;

    std::cout << "Enter account Number: ";
    std::cin >> accNum;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter account Holder Name: ";
    std::getline(std::cin, Holder);

    std::cout << "Enter account Balance: ";
    std::cin >> bal;

    return BankAccount(accNum, Holder, bal);
}

void BankAccount::printHistory() const {
    std::cout << "Transaction History:" << std::endl;
    if (transactionHistory.empty()) {
        std::cout << "No transactions recorded." << std::endl;
        return;
    }
    for (const auto &transaction : transactionHistory) {
        std::cout << "Type: " << transaction.type << ", Amount: $" << transaction.amount << ", Timestamp: " << transaction.timestamp << std::endl;
    }
}

void BankAccount::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        std::cout << "Deposited $" << amount << std::endl;

        Transaction t;
        t.type = "Deposit";
        t.amount = amount;
        std::time_t now = std::time(nullptr);
        t.timestamp = std::ctime(&now);

        transactionHistory.push_back(t);
    }
    else {
        std::cout << "Invalid deposit amount." << std::endl;
    }
}

void BankAccount::withdraw(double amount) {
    if (amount <= 0) {
        std::cout << "Withdraw amount must be greater than zero." << std::endl;
    }
    else if (amount > balance) {
        std::cout << "Insufficient funds." << std::endl;
    }
    else {
        balance -= amount;
        std::cout << "Withdrew $" << amount << std::endl;

        Transaction t;
        t.type = "Withdraw";
        t.amount = amount;
        std::time_t now = std::time(nullptr);
        t.timestamp = std::ctime(&now);
        transactionHistory.push_back(t);
    }
}