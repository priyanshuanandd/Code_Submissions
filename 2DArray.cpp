#include <iostream>
using namespace std;
void wavewave(int arr[][100], int n, int m)
{
    // Iterating over columns
    //  n rows m columns
    for (int i = 0; i < m; i++)
    {
        // even colums top to bottom and vice versa
        if (i % 2 == 0)
        {
            for (int j = 0; j < n; j++)
            {
                cout << arr[j][i] << " ";
            }
        }
        else
        {
            for (int j = n - 1; j >= 0; j--)
            {
                cout << arr[j][i] << " ";
            }
        }
        cout << endl;
    }
}

void print2d(int arr[][100], int n, int m)
{
    // One of rows and columns must be defined when passing a 2D Array to a function
    // yes , passed by reference

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{

    // giving constraints
    int arr[100][100];
    // n rows m columns
    int n, m;
    cin >> n >> m;

    // take input

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    // printing the 2d array
    // print2d(arr, n, m);

    // wave print

    wavewave(arr, n, m);
    return 0;
}