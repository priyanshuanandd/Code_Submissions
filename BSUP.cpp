#include <bits/stdc++.h>
using namespace std;
void upperbound(vector<int> v, int f)
{
    int s = 0;
    int e = v.size() - 1;
    int mid;
    while (e - s > 1)
    {

        mid = (s + e) / 2;
        cout << "s " << s << " e " << e << " mid " << mid << endl;
        if (v[mid] < f)
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
    }
    if (v[s] == f)
    {
        cout << s << endl;
    }
    else if (v[e] == f)
    {
        cout << e << endl;
    }
    else if (v[s] > f)
    {
        cout << "Upper Bound " << v[s] << endl;
    }
    else if (v[e] > f)
    {
        cout << "Upper Bound " << v[e] << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }
}
int main()
{
    vector<int> v = {1, 3, 4, 5, 7, 9, 11};

    int k = 8;

    upperbound(v, k);

    return 0;
}