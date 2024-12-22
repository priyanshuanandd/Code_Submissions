#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;

// Function to calculate the Manhattan value of a permutation
int manhattanValue(const vector<int> &perm)
{
    int value = 0;
    for (int i = 0; i < perm.size(); ++i)
    {
        value += abs(perm[i] - (i + 1));
    }
    return value;
}

// Function to generate all Manhattan values for permutations of size n
set<int> allManhattanValues(int n)
{
    vector<int> array(n);
    for (int i = 0; i < n; ++i)
    {
        array[i] = i + 1;
    }

    set<int> manhattanValues;
    do
    {
        int value = manhattanValue(array);
        manhattanValues.insert(value);
    } while (next_permutation(array.begin(), array.end()));

    return manhattanValues;
}

int main()
{
    int n;
    //cout << "Enter the size of the array: ";
    cin >> n;

    set<int> manhattanValues = allManhattanValues(n);

   // cout << "All possible Manhattan values for permutations of size " << n << ": ";
    for (int value : manhattanValues)
    {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}
