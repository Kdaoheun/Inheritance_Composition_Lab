cmake_minimum_required(VERSION 4.0)
project(InheritanceLab)

set(CMAKE_CXX_STANDARD 20)

add_executable(InheritanceLab main.cpp
        BankAccount.h
        SavingsAccount.h
        CheckingAccount.h
        CheckingAccount.cpp
        BankAccount.cpp
        SavingsAccount.cpp
        Transaction.h
)
