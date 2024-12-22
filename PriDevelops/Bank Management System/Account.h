#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account {
private:
    std::string accountNumber;
    std::string accountType;
    double balance;

public:
    Account(const std::string& number, const std::string& type, double initialBalance);
    void deposit(double amount);
    void withdraw(double amount);
    double getBalance() const;
    std::string getAccountNumber() const;
    std::string getAccountType() const;
};

#endif
