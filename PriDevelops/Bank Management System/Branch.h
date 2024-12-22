#ifndef BRANCH_H
#define BRANCH_H

#include <vector>
#include <string>
#include "Account.h"
#include "Customer.h"

class Branch
{
private:
    std::string branchName;
    std::vector<Account> accounts;
    std::vector<Customer> customers;

public:
    Branch(const std::string &name);
    void addAccount(const Account &account);
    void removeAccount(const std::string &accountNumber);
    Account *getAccount(const std::string &accountNumber);
    void addCustomer(const Customer &customer);
    void removeCustomer(const std::string &customerID);
    Customer *getCustomer(const std::string &customerID);
    string getName() const
    {
        return branchName;
    }

    void setName(const string &newName)
    {
        branchName = newName;
    }
};

#endif
