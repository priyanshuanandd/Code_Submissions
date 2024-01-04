#include <bits/stdc++.h>
using namespace std;
void printvec(vector<pair<int, int>> &v)
{
    for (auto &i : v)
    {
        cout << i.first << " " << i.second << endl;
    }
}
int main()
{
    // initialization method 1
    vector<pair<int, int>> v = {{1, 2}, {2, 3}, {4, 5}};
    printvec(v);
    // initialization method 2
    // taking input in vector of pair
    vector<pair<int, int>> v2;
    int number;
    cin >> number;
    while (number--)
    {
        int p1, p2;
        cin >> p1 >> p2;
        v2.push_back(make_pair(p1,p2));
        //or you can do it with 
        //v2.push_back({x,y});
    }
    printvec(v2);
    return 0;
}