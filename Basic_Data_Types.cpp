#include <bits/stdc++.h>
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>

using namespace std;


inline int power(int a, int b)
{
int x = 1;
while (b)
{
if (b & 1) x *= a;
a *= a;
b >>= 1;
}
return x;
}

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " -> " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
const char* comma = strchr (names + 1, ',');
cout.write (names, comma - names) << " : " << arg1 << " --- "; __f (comma + 1, args...);
}

const int N = 200005;

void solve() {

int arr[10];
cout << arr<<endl;}

int32_t main()
{//helps to reduce time
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*
#ifndef ONLINE_JUDGE
freopen("input.txt",  "r",  stdin);
freopen("output.txt", "w", stdout);
#endif
*/
//prints time

clock_t z = clock();

int t = 1;
// cin >> t;
while (t--) solve();

cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

return 0;
}