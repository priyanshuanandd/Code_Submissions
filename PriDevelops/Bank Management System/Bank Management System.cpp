#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
// Base class Person
map<string, string> customerLogins;    // Maps customer IDs to passwords
map<string, string> bankManagerLogins; // Maps manager IDs to passwords
const string adminID = "admin";
const string adminPassword = "adminpass";

bool authenticate(string id, string password, map<string, string> &credentials)
{
    auto it = credentials.find(id);
    if (it != credentials.end() && it->second == password)
    {
        return true;
    }
    return false;
}

class Person
{
protected:
    string id;
    string name;
    string address;
    string phoneNumber;
    string email;

public:
    Person(const string &id, const string &name, const string &address,
           const string &phone, const string &email)
        : id(id), name(name), address(address), phoneNumber(phone), email(email) {}

    virtual ~Person() = default;

    void updateAddress(const string &newAddress) { address = newAddress; }
    void updatePhoneNumber(const string &newPhone) { phoneNumber = newPhone; }
    void updateEmail(const string &newEmail) { email = newEmail; }

    string getID() const { return id; }
    string getName() const { return name; }
    string getAddress() const { return address; }
    string getPhoneNumber() const { return phoneNumber; }
    string getEmail() const { return email; }
};

// Derived class Customer
class Customer : public Person
{
public:
    Customer(const string &id, const string &name, const string &address,
             const string &phone, const string &email)
        : Person(id, name, address, phone, email) {}
};

// Derived class BankManager
class BankManager : public Person
{
public:
    BankManager(const string &id, const string &name, const string &address,
                const string &phone, const string &email)
        : Person(id, name, address, phone, email) {}

    void manageBranch() { cout << "Managing branch operations." << endl; }
    void approveLoan() { cout << "Approving loan requests." << endl; }
};

// Class representing an Account
class Account
{
private:
    string accountNumber;
    string accountType;
    double balance;

public:
    Account(const string &number, const string &type, double initialBalance)
        : accountNumber(number), accountType(type), balance(initialBalance) {}

    void deposit(double amount) { balance += amount; }
    void withdraw(double amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
        }
        else
        {
            cout << "Insufficient balance." << endl;
        }
    }

    double getBalance() const { return balance; }
    string getAccountNumber() const { return accountNumber; }
    string getAccountType() const { return accountType; }
};

// Class representing a Branch
class Branch
{
private:
    string branchName;
    vector<Account> accounts;
    vector<Customer> customers;

public:
    Branch(const string &name) : branchName(name) {}

    void addAccount(const Account &account) { accounts.push_back(account); }
    void removeAccount(const string &accountNumber)
    {
        for (auto it = accounts.begin(); it != accounts.end(); ++it)
        {
            if (it->getAccountNumber() == accountNumber)
            {
                accounts.erase(it);
                return;
            }
        }
    }

    Account *getAccount(const string &accountNumber)
    {
        for (auto &account : accounts)
        {
            if (account.getAccountNumber() == accountNumber)
            {
                return &account;
            }
        }
        return nullptr;
    }

    void addCustomer(const Customer &customer) { customers.push_back(customer); }
    void removeCustomer(const string &customerID)
    {
        for (auto it = customers.begin(); it != customers.end(); ++it)
        {
            if (it->getID() == customerID)
            {
                customers.erase(it);
                return;
            }
        }
    }

    Customer *getCustomer(const string &customerID)
    {
        for (auto &customer : customers)
        {
            if (customer.getID() == customerID)
            {
                return &customer;
            }
        }
        return nullptr;
    }

    string getBranchName() const { return branchName; }
    string getName() const
    {
        return branchName;
    }

    void setName(const string &newName)
    {
        branchName = newName;
    }
};

// Class representing a Bank
class Bank
{
private:
    string bankName;
    vector<Branch> branches;

public:
    Bank(const string &name) : bankName(name) {}

    void addBranch(const Branch &branch) { branches.push_back(branch); }
    void removeBranch(const string &branchName)
    {
        for (auto it = branches.begin(); it != branches.end(); ++it)
        {
            if (it->getBranchName() == branchName)
            {
                branches.erase(it);
                return;
            }
        }
    }

    Branch *getBranch(const string &branchName)
    {
        for (auto &branch : branches)
        {
            if (branch.getBranchName() == branchName)
            {
                return &branch;
            }
        }
        return nullptr;
    }
};
void manageBranch(Branch &branch)
{
    while (true)
    {
        cout << "\nBranch Management Menu\n";
        cout << "1. View Branch Details\n";
        cout << "2. Update Branch Information\n";
        cout << "3. Manage Branch Staff\n";
        cout << "4. Exit to Previous Menu\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            // View Branch Details
            cout << "Branch Name: " << branch.getName() << endl;
            // Add more details as needed
            break;
        }
        case 2:
        {
            // Update Branch Information
            string newName;
            cout << "Enter new branch name: ";
            cin.ignore();
            getline(cin, newName);
            branch.setName(newName);
            cout << "Branch name updated successfully.\n";
            break;
        }
        case 3:
        {
            // Manage Branch Staff
            cout << "Manage branch staff functionality here.\n";
            // Implement staff management operations
            break;
        }
        case 4:
            return; // Exit to previous menu
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    }
}
void addBankManager()
{
    string managerID, managerPassword;
    cout << "Enter new bank manager ID: ";
    cin >> managerID;
    cout << "Enter new bank manager password: ";
    cin >> managerPassword;
    bankManagerLogins[managerID] = managerPassword;
    cout << "Bank Manager added successfully.\n";
}

int main()
{
    Bank myBank("My Bank");
    Branch mainBranch("Main Branch");
    myBank.addBranch(mainBranch);

    // Add some initial logins
    customerLogins["cust1"] = "pass1";
    bankManagerLogins["mgr1"] = "mgrpass1";

    while (true)
    {
        cout << "\nBank Management System CLI\n";
        cout << "1. Customer Login\n";
        cout << "2. Bank Manager Login\n";
        cout << "3. Admin Login\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        if (choice == 4)
        {
            break; // Exit the loop and end the program
        }

        switch (choice)
        {
        case 1:
        {
            // Customer Login
            string customerID, customerPassword;
            cout << "Enter customer ID: ";
            cin >> customerID;
            cout << "Enter password: ";
            cin >> customerPassword;

            if (authenticate(customerID, customerPassword, customerLogins))
            {
                cout << "Customer logged in successfully.\n";
                // Add customer-specific operations here
            }
            else
            {
                cout << "Invalid customer ID or password.\n";
            }
            break;
        }
        case 2:
        {
            // Bank Manager Login
            string managerID, managerPassword;
            cout << "Enter manager ID: ";
            cin >> managerID;
            cout << "Enter password: ";
            cin >> managerPassword;

            if (authenticate(managerID, managerPassword, bankManagerLogins))
            {
                cout << "Bank Manager logged in successfully.\n";
                // Bank Manager operations
                while (true)
                {
                    cout << "\nBank Manager Menu\n";
                    cout << "1. Manage Branch\n";
                    cout << "2. Exit to Main Menu\n";
                    cout << "Enter your choice: ";

                    int managerChoice;
                    cin >> managerChoice;

                    if (managerChoice == 2)
                    {
                        break; // Exit to main menu
                    }

                    switch (managerChoice)
                    {
                    case 1:
                    {
                        // Manage Branch
                        manageBranch(mainBranch);
                        break;
                    }
                    default:
                        cout << "Invalid choice. Please try again.\n";
                        break;
                    }
                }
            }
            else
            {
                cout << "Invalid manager ID or password.\n";
            }
            break;
        }
        case 3:
        {
            // Admin Login
            string adminIDInput, adminPasswordInput;
            cout << "Enter admin ID: ";
            cin >> adminIDInput;
            cout << "Enter password: ";
            cin >> adminPasswordInput;

            if (adminIDInput == adminID && adminPasswordInput == adminPassword)
            {
                cout << "Admin logged in successfully.\n";
                // Admin operations
                while (true)
                {
                    cout << "\nAdmin Menu\n";
                    cout << "1. Add Customer\n";
                    cout << "2. Add Account\n";
                    cout << "3. Manage Branch\n";
                    cout << "4. Add Bank Manager\n";
                    cout << "5. Exit to Main Menu\n";
                    cout << "Enter your choice: ";

                    int adminChoice;
                    cin >> adminChoice;

                    if (adminChoice == 5)
                    {
                        break; // Exit to main menu
                    }

                    switch (adminChoice)
                    {
                    case 1:
                    {
                        // Add Customer
                        string id, name, address, phone, email;
                        cout << "Enter customer ID: ";
                        cin >> id;
                        cout << "Enter customer name: ";
                        cin.ignore();
                        getline(cin, name);
                        cout << "Enter customer address: ";
                        getline(cin, address);
                        cout << "Enter customer phone: ";
                        cin >> phone;
                        cout << "Enter customer email: ";
                        cin >> email;
                        Customer newCustomer(id, name, address, phone, email);
                        mainBranch.addCustomer(newCustomer);
                        customerLogins[id] = "password"; // Default password assignment
                        cout << "Customer added successfully.\n";
                        break;
                    }
                    case 2:
                    {
                        // Add Account
                        string number, type;
                        double initialBalance;
                        cout << "Enter account number: ";
                        cin >> number;
                        cout << "Enter account type: ";
                        cin >> type;
                        cout << "Enter initial balance: ";
                        cin >> initialBalance;
                        Account newAccount(number, type, initialBalance);
                        mainBranch.addAccount(newAccount);
                        cout << "Account added successfully.\n";
                        break;
                    }
                    case 3:
                    {
                        // Manage Branch
                        manageBranch(mainBranch);
                        break;
                    }
                    case 4:
                    {
                        // Add Bank Manager
                        addBankManager();
                        break;
                    }
                    default:
                        cout << "Invalid choice. Please try again.\n";
                        break;
                    }
                }
            }
            else
            {
                cout << "Invalid admin ID or password.\n";
            }
            break;
        }
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    }

    cout << "Exiting the system.\n";
    return 0;
}
