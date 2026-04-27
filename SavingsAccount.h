#ifndef INHERITANCELAB_SAVINGSACCOUNT_H
#define INHERITANCELAB_SAVINGSACCOUNT_H
#include "BankAccount.h"

class SavingsAccount : public BankAccount {
public:
    //Constructs
    SavingsAccount();
    SavingsAccount(const std::string& accNum, const std::string& Holder, double bal, double interest);

    //Used for calc interest
    void calculateInterest();

private:
    double interestRate;
};

#endif //INHERITANCELAB_SAVINGSACCOUNT_H