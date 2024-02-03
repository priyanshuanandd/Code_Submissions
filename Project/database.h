#pragma once

class database
{
private:
    unordered_map<string, pair<string, double>> users;
    unordered_map<string, string> manager;

public:
    database();
    void adduser(string &username, string &pass);

    void deluser(string &username);

    void addadmin(string &username, string &pass);

    void login(string &username, string &password);

    void adminlogin(string &username, string &password);
};