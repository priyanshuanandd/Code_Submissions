#include <iostream>
using namespace std;
#include <fstream>
#include <bits/stdc++.h>
class database
{
private:
    unordered_map<string, pair<string, double>> users;
    unordered_map<string, string> admin;

public:
    database() // adds to the map
    {
        // taking user and adding to map
        ifstream userfile("users.txt");

        if (!userfile.is_open())
        {
            cout << "No DataFile" << endl;
        }

        string line;
        while (getline(userfile, line))
        {
            // seperates strings at spaces

            istringstream iss(line);

            string username, pass;
            double bal;
            if (iss >> username >> pass >> bal)
            {
                users[username] = make_pair(pass, bal);
            }
            else
            {
                cout << "Error 404" << endl;
            }
        }
    }
    void saveuserstofile()
    { // update
        ofstream file("users.txt");
        for (auto &i : users)
        {
            file << i.first << " " << i.second.first << " " << i.second.second << endl;
        }
        file.close();
    }

    void saveadminstofile() // update admin
    {
        ofstream file("admin.txt");

        for (auto &i : admin)
        {
            file << i.first << " " << i.second << endl;
        }
        file.close();
    }
    void adduser(string &username, string &pass) // add user to map
    {
        if (users.find(username) == users.end())
        {
            users[username] = make_pair(pass, 0.0);
        }
        else
        {
            cout << "Username already Exists" << endl;
        }
    }

    void deluser(string &username)
    {
        users.erase(username);
    }

    void addadmin(string &username, string &pass)
    {
        if (admin[username].empty())
        {
            admin[username] = pass;
        }
        else
        {
            cout << "Username already Exists" << endl;
        }
    }

    bool login(string &username, string &password)
    {
        if (users[username].first == password)
        {
            cout << "Login Successful" << endl;
            return true;
        }
        else
        {
            cout << "Login Failed"
                 << " "
                 << "Retry..." << endl;
            return true;
        }
    }
    bool adminlogin(string &username, string &password)
    {
        if (admin[username] == password)
        {
            cout << "Login Successful,Welcome Admin"
                 << " " << username << endl;
            return true;
        }
        return false;
    }
    double getbalance(string username)
    {
        if (users.find(username) != users.end())
        {
            return users[username].second;
        }
        else
        {
            cout << "Error No Balance and No User " << endl;
        }
        return 0;
    }
};

database db;
class BankAccount
{
protected:
    string username;
    double balance;
    string password;

public:
    BankAccount(string &username, string &pass)
    {
        if (db.login(username, pass))
        {
            this->balance = db.getbalance(username);
        }
        else
        {
            cout << "Error while Login" << endl;
        }
    }

    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Successfully deposited $" << amount << " to your account." << endl;
            cout << "Your new balance is: $" << balance << endl;
            db.saveuserstofile();
        }
        else
        {
            cout << "Error: Invalid deposit amount." << endl;
        }
    }

    virtual void withdraw(double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout << "Successfully withdrew $" << amount << " from your account." << endl;
            cout << "Your new balance is: $" << balance << endl;
            db.saveuserstofile();
        }
        else
        {
            cout << "Error: Invalid withdrawal amount or insufficient balance." << endl;
        }
    }

    void accountDetails()
    {
        cout << "Account Holder: " << username << endl;
        cout << "Balance: $" << balance << endl;
    }
    void setUsername(string &newUsername)
    {
        username = newUsername;
    }
};

class GoldUser : public BankAccount
{
public:
    GoldUser(string &username, string &pass) : BankAccount(username, pass)
    {
    }
    // Override Withdraw
    void withdraw(double amount) override
    {
        if (amount > 0 && amount <= balance and amount <= 25000)
        {
            balance -= amount;
            cout << "Successfully withdrew $" << amount << " from your Gold account." << endl;
            cout << "Your new balance is: $" << balance << endl;
            db.saveuserstofile();
        }
        else if (amount >= 25000)
        {
            cout << "Upgrade to Platinum Membership\n";
        }
        else
        {
            cout << "Error: Invalid withdrawal amount or insufficient balance." << endl;
        }
    }
};

class PlatinumUser : public BankAccount
{

public:
    PlatinumUser(string &username, string &pass) : BankAccount(username, pass) {}
};

class BankManager
{
private:
    unordered_map<string, string> managers;

public:
    BankManager()
    {
        loadManagersFromFile();
    }
    bool login()
    {
        string username, password;
        cout << "Enter username: ";
        cin >> username;
        if (managers.find(username) != managers.end())
        {
            cout << "Enter password: ";
            cin >> password;

            if (managers[username] == password)
            {
                return true;
            }
        }
        cout << "Incorrect login. Please try again. " << endl;
        return false;
    }

    bool loadManagersFromFile()
    {
        ifstream managerFile("admin.txt");
        if (!managerFile)
        {
            return false;
        }

        string line;
        while (getline(managerFile, line))
        {
            istringstream iss(line);
            string username, password;
            if (iss >> username >> password)
            {
                managers[username] = password;
            }
        }
        managerFile.close();
        return true;
    }
};

int main()
{
    BankManager manager;
    string username = " ", password = " ";
    double withdrawAmt;
    double depositAmt;
    BankAccount acc(username, password);
    GoldUser gacc1(username, password);
    PlatinumUser pacc1(username, password);
    bool login = false;
    bool adminlogin = false;
    int choice = 0, bankingOption = 0;
    while (true)
    {
        if (!login)
        {
            cout << "1.Login\n2. Create Account\n3. Manager Login\n4. Exit\n";
            cout << "Choose Option ___" << endl;
            cin >> choice;

            if (choice == 1)
            {
                cout << "User Type: \n 1.Gold \n2. Platinum\n";
                cout << "Choose Option ___" << endl;
                cin >> choice;
                login = 1;
                db.login(username, password);
                if (choice == 1)
                {
                    gacc1.setUsername(username);
                }
                else if (choice == 2)
                {
                    pacc1.setUsername(username);
                }
                else
                {
                    cout << "Invalid\n";
                }
            }
            else if (choice == 2)
            {
                string name, pass;
                int option;
                cout << "Enter new username: ";
                cin >> name;
                cout << "Enter password: ";
                cin >> pass;
                cout << "User Type: \n 1.Gold \n2. Platinum\n";
                cin >> option;
                db.adduser(name, pass);
                username = name;
                acc.setUsername(username);
            }
            else if (choice == 3)
            {
                if (db.adminlogin(username, password))
                {
                    int option;
                    adminlogin = 1;
                    login = 1;
                    // Manager Options
                    cout << "Manager Options\n";
                    cout << "1. Get List of Users and Account Details\n2. Logout\n";
                    cin >> option;
                    if (option == 1)
                    {
                        ifstream userFile("users.txt");
                        if (userFile.is_open())
                        {
                            string line;
                            while (getline(userFile, line))
                            {
                                cout << line << endl;
                            }
                            userFile.close();
                        }
                    }
                    if (option == 2)
                    {
                        adminlogin = false;
                        login = false;
                    }
                }
            }
            else if (choice == 4)
            {
                break;
            }
        }
        else
        {
            if (adminlogin)
            {
                cout << "Manager Options\n";
                cout << "1. Get List of Users and Account Details\n2. Logout\n";
                cin >> bankingOption;
                if (bankingOption == 1)
                {
                    ifstream userFile("users.txt");
                    if (userFile.is_open())
                    {
                        string line;
                        while (getline(userFile, line))
                        {
                            cout << line << endl;
                        }
                        userFile.close();
                    }
                }
                if (bankingOption == 2)
                {
                    login = false;
                }
            }
            else
            {
                cout << "ChooseAccountType : \n";
                cout << "1.Gold 2.Platinum" << endl;
                cin >> bankingOption;
                int type = bankingOption;

                // Account Options
                cout << "User Options:\n";
                cout << "1. Withdraw\n2. Deposit\n3. Get Account Summary\n4. Logout\n";
                cin >> bankingOption;

                if (bankingOption == 1)
                {
                    if (type == 1)
                    {
                        cout << "Please enter withdrawal amount: ";
                        cin >> withdrawAmt;
                        gacc1.withdraw(withdrawAmt);
                    }
                    else
                    {
                        cout << "Please enter withdrawal amount: ";
                        cin >> withdrawAmt;
                        pacc1.withdraw(withdrawAmt);
                    }
                }
                else if (bankingOption == 2)
                {
                    if (type == 1)
                    {
                        cout << "Please enter deposit amount: ";
                        cin >> depositAmt;
                        gacc1.deposit(depositAmt);
                    }
                    else
                    {
                        cout << "Please enter deposit amount: ";
                        cin >> depositAmt;
                        pacc1.deposit(depositAmt);
                    }
                }
                else if (bankingOption == 3)
                {
                    if (type == 1)
                    {
                        gacc1.accountDetails();
                    }
                    else
                    {
                        pacc1.accountDetails();
                    }
                }
                else if (bankingOption == 5)
                {
                    login = false;
                }
            }
        }
    }
}