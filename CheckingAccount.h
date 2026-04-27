#ifndef INHERITANCELAB_CHECKINGACCOUNT_H
#define INHERITANCELAB_CHECKINGACCOUNT_H
#include "BankAccount.h"

class CheckingAccount : public BankAccount {
public:
    //Constructors
    CheckingAccount();
    CheckingAccount(const std::string& accNum, const std::string& Holder, double bal, double fee);

    void withdraw(double amount) override;

private:
    double transactionFee;
};


#endif //INHERITANCELAB_CHECKINGACCOUNT_H