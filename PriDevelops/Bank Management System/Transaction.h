#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

class Transaction {
private:
    std::string transactionID;
    std::string accountNumber;
    std::string transactionType;
    double amount;
    std::string transactionDate;

public:
    Transaction(const std::string& id, const std::string& account, const std::string& type,
                double amt, const std::string& date);
    std::string getTransactionID() const;
    std::string getAccountNumber() const;
    std::string getTransactionType() const;
    double getAmount() const;
    std::string getTransactionDate() const;
};

#endif
