#ifndef BANK_H
#define BANK_H

#include <vector>
#include <string>
#include "Branch.h"

class Bank {
private:
    std::string bankName;
    std::vector<Branch> branches;

public:
    Bank(const std::string& name);
    void addBranch(const Branch& branch);
    void removeBranch(const std::string& branchName);
    Branch* getBranch(const std::string& branchName);
};

#endif
