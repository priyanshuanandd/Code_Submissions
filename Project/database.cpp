#include "database.h"
#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
database::database()
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
            users[username] = 
        }
        else
        {
            cout << "N/A" << endl;
        }
    }
};