#include "Bank.h"
#include "Branch.h"

Bank::Bank(const std::string& name) : bankName(name) {}

void Bank::addBranch(const Branch& branch) {
    branches.push_back(branch);
}

void Bank::removeBranch(const std::string& branchName) {
    for (auto it = branches.begin(); it != branches.end(); ++it) {
        if (it->getBranchName() == branchName) {
            branches.erase(it);
            return;
        }
    }
}

Branch* Bank::getBranch(const std::string& branchName) {
    for (auto& branch : branches) {
        if (branch.getBranchName() == branchName) {
            return &branch;
        }
    }
    return nullptr;
}
