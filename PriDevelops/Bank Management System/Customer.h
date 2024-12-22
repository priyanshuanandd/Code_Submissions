#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer {
private:
    std::string customerID;
    std::string name;
    std::string address;
    std::string phoneNumber;
    std::string email;

public:
    Customer(const std::string& id, const std::string& name, const std::string& address,
             const std::string& phone, const std::string& email);
    void updateAddress(const std::string& newAddress);
    void updatePhoneNumber(const std::string& newPhone);
    void updateEmail(const std::string& newEmail);
    std::string getID() const;
    std::string getName() const;
    std::string getAddress() const;
    std::string getPhoneNumber() const;
    std::string getEmail() const;
};

#endif
