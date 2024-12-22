
#include <iostream>
#include <map>
#include <string.h>
using namespace std;
int binomialCoefficients(int n, int k)
{
    if (k == 0 || k == n)
        return 1;
    return binomialCoefficients(n - 1, k - 1) + binomialCoefficients(n - 1, k);
}
int main()

    cout << s1 <<endl;
    return 0;
}