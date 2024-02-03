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
        void saveuserstofile() // update
        {
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
        void adduser(string & username, string & pass) // add user to map
        {
            if (users[username].empty())
            {
                users[username] = make_pair(pass, 0.0);
            }
            else
            {
                cout << "Username already Exists" << endl;
            }
        }

        void deluser(string & username)
        {
            user.erase(username);
        }

        void addadmin(string & username, string & pass)
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

        void login(string & username, string & password)
        {
            if (users[username] == password)
            {
                cout << "Login Successful" << endl;
            }
            else
            {
                cout << "Login Failed"
                     << " "
                     << "Retry..." << endl;
                getch();
            }
        }
        void adminlogin(string & username, string & password)
        {
            if (admin[username] == password)
            {
                cout << "Login Successful,Welcome Admin"
                     << " " << username << endl;
            }
        }
        double getbalance(string username)
        {
            if (!users[username].empty())
            {
                return users[username].second;
            }
            else
            {
                cout << "No Balance" << endl;
            }
        }
    }
};

class Transaction
{
    string type;
    double amount;
    // constructor
    Transaction(cont string &t, double a) : type(t), amount(a) {}
}

class BankAccount
{
private:
    string username;
    double balance;
    vector<Transaction> transaction_list;
    static database db; // static member

public://use users.txt
    BankAccount(string &username, string &pass)
    {
        if (db.login(username, password))
        {
            this->username = username;
            this->balance = db.getbalance(username);
        }
        else
        {
            cerr << "Error while Login" << endl;
        }
    }

    void withdraw(double amnt){


    }

    void deposit(double amnt){


    }

    void accountdetails(){

    }
};

database BankAccount::db;


