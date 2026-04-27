//Author: Kobe Daoheung
//Date: 3/9/26
//Assignment: Challenge: Enhancing the Bank Account Management System
//Menu code started from: https://yosemite.instructure.com/courses/70824/pages/c++-menu-program-code-sample

#include <iostream>
#include  <vector>
#include  <limits>
#include <memory>
#include <string>
#include "BankAccount.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"

//function prototypes
int displayMenu();
void runMenu(std::vector<std::unique_ptr<BankAccount>>& accounts);

int main() {
    std::vector<std::unique_ptr<BankAccount>> accounts;

    // Initialization
    runMenu(accounts);

    // Cleanup
    return 0;
}

// Function to display the menu
int displayMenu() {
    std::cout << "\nBank Account Menu\n";
    std::cout << "1. Add Account\n";
    std::cout << "2. Deposit\n";
    std::cout << "3. Withdraw\n";
    std::cout << "4. Show Accounts\n";
    std::cout << "5. Update Account Holder Name\n";
    std::cout << "6. Calculate Interest\n";
    std::cout << "7. Show Transaction History\n";
    std::cout << "0. Exit\n";
    std::cout << "Enter your choice: ";

    int choice;
    std::cin >> choice;
    return choice;
}
// Function to run the menu loop
void runMenu(std::vector<std::unique_ptr<BankAccount>>& accounts ) {

    int choice; //The menu selection

    do {
        //Get a menu selection
        choice = displayMenu();
        //Carry out the menu selection (should call functions)
        switch (choice) {
            case 1: {
                std::cout << "Add Account: 1.Checking 2.Savings\n";
                int accountType;
                std::cin >> accountType;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::string accNum, accHolderName;
                double bal;

                std::cout << "Enter account Number: ";
                std::cin >> accNum;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::cout << "Enter account Holder Name: ";
                std::getline(std::cin, accHolderName);

                std::cout << "Enter account Balance: ";
                std::cin >> bal;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                bool accountExists = false;
                for (auto& account : accounts) {
                    if (account->getAccountNumber() == accNum) {
                        accountExists = true;
                        break;
                    }
                }
                if (accountExists) {
                    std::cout << "Account already exists." << std::endl;
                    break;
                }
                if (accountType == 1) {
                    double transactionFee = 0.0;
                    std::cout << "Enter transaction fee: ";
                    std::cin >> transactionFee;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    accounts.push_back(std::make_unique<CheckingAccount>(accNum, accHolderName, bal, transactionFee));
                }
                else if(accountType == 2) {
                    double interestRate = 0.0;
                    std::cout << "Enter interest rate (%): ";
                    std::cin >> interestRate;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    accounts.push_back(std::make_unique<SavingsAccount>(accNum, accHolderName, bal, interestRate));
                    std::cout << "Account created successfully." << std::endl;
                }
                else {
                    std::cout << "Invalid account type." << std::endl;
                }
                break;
            }
            case 2: {
                std::string accNum;
                double amount;

                std::cout << "Account Number: ";
                std::cin >> accNum;

                bool accountFound = false;

                for (auto& account : accounts) {
                    if (account->getAccountNumber() == accNum) {
                        accountFound = true;
                        std::cout << "Account number: " << account->getAccountNumber() << std::endl;
                        std::cout << "Account Holder Name: " << account->getAccountHolderName() << std::endl;
                        std::cout << "Enter deposit amount: ";
                        std::cin >> amount;
                        account->deposit(amount);
                        std::cout << "New account balance: " << account->getBalance() << std::endl;

                        break;
                    }
                }
                if (!accountFound) {
                    std::cout << "Account not found." << std::endl;
                }
                break;
            }
            case 3: {
                std::string accNum;
                double amount;

                std::cout << "Enter Account Number: ";
                std::cin >> accNum;

                bool accountFound = false;

                for (auto& account : accounts) {
                    if (account->getAccountNumber() == accNum) {
                        accountFound = true;
                        std::cout << "Account number: " << account->getAccountNumber() << std::endl;
                        std::cout << "Account Holder Name: " << account->getAccountHolderName() << std::endl;
                        std::cout << "Enter withdraw amount: ";
                        std::cin >> amount;
                        account->withdraw(amount);
                        std::cout << "New account balance: " << account->getBalance() << std::endl;
                        break;
                    }
                }
                if (!accountFound) {
                    std::cout << "Account not found." << std::endl;
                }
                break;
            }
            case 4: {
                std::cout << "Show Accounts\n";
                for (const auto& account : accounts) {
                    BankAccount::printAccount(*account);
                }
                    break;
            }
                case 5: {
                std::string accNum, accHolderName;

                std::cout << "Enter Account Number: ";
                    std::cin >> accNum;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


                    for (auto& account : accounts) {
                        if (account->getAccountNumber() == accNum) {
                            std::cout << "Enter new account holder name: ";
                            std::getline(std::cin, accHolderName);
                            account->setAccountHolderName(accHolderName);
                            std::cout << "Account holder name updated successfully." << std::endl;
                            break;
                        }
                    }
                    break;
            }
            case 6: {
                std::cout << "Calculate Interest\n";

                std::string accNum;
                std::cout << "Enter Account Number: ";
                std::cin >> accNum;

                bool accountFound = false;

                for (auto& account : accounts) {
                    if (account->getAccountNumber() == accNum) {
                        accountFound = true;
                        std::cout << "Account number: " << account->getAccountNumber() << std::endl;
                        std::cout << "Account Holder Name: " << account->getAccountHolderName() << std::endl;
                        std::cout << "Account Balance: " << account->getBalance() << std::endl;
                        SavingsAccount* savingsAccount = dynamic_cast<SavingsAccount*>(account.get());

                        if (savingsAccount != nullptr) {
                            savingsAccount->calculateInterest();
                            accountFound = true;
                            std::cout << "Interest calculated and added to account balance." << std::endl;
                            std::cout << "New account balance: " << savingsAccount->getBalance() << std::endl;
                        }
                        else {

                            std::cout << "Account is not a savings account. Interest calculation not applicable." << std::endl;
                        }
                        break;
                    }
                }

                if (!accountFound) {
                    std::cout << "Account not found." << std::endl;
                }
                break;
            }
            case 7: {
                std::string accNum;
                std::cout << "Enter Account Number: ";
                std::cin >> accNum;

                bool accountFound = false;

                for (auto& account : accounts) {
                    if (account->getAccountNumber() == accNum) {
                        accountFound = true;
                        std::cout << "Transaction History for Account Number: " << accNum << std::endl;
                        std::cout << "Account Holder Name: " << account->getAccountHolderName() << std::endl;
                        std::cout << "Account Balance: " << account->getBalance() << std::endl;
                        account->printHistory();
                        break;
                    }
                }

                if (!accountFound) {
                    std::cout << "Account not found. Cannot show transaction history." << std::endl;
                }
                break;
            }
            case 0:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
        //End of menu selection if 0 was selected
    } while (choice != 0);
}

