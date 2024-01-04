#include <bits/stdc++.h>
using namespace std;

vector<int> sortByBits(vector<int> arr)
{
    multimap<int, int> m;
    for (auto &i : arr)
    {

        int s = i;
        int c = 0;
        while (s != 0)
        {
            if (s % 2 == 1)
            {
                c++;
            }
            s /= 2;
        }
        m.insert(pair<int,int>(c,i));
    }
    arr.clear();
    for (auto &i : m)
    {
        arr.push_back(i.second);
    }
    return arr;
}
int main()
{
    vector<int> arr = {258, 520, 518, 322, 88, 658, 688, 480, 216, 433, 186, 818, 685, 315, 963, 506, 767};
    
    arr = sortByBits(arr);

    for (auto &i : arr)
    {
        cout << i << " ";
    }
    
}