#include <iostream>
using namespace std;
pair<int,int> staircaseSearch(int arr[][4], int n, int m, int key)
{
    // start
    if (key < arr[0][0] or key > arr[n-1][m-1])
    {
        return {-1,-1};
    }
    
    int start_row = 0;
    int end_column = m - 1;
    int i = 0, j = m - 1;
    //staircaseSearch Starts
    while (i < n and j < m)
    {
        if (arr[i][j] > key)
        {
            j--;
            cout << i << ";;" << j <<endl;
        }
        else if (arr[i][j] < key)
        {
            i++;
            cout << i << ";;" << j <<endl;
        }
        else{
            return {i,j};
        }
    }
    return {-1,-1};
}

int main()
{
    // 2d array sorted column and row wise
    int arr[][4] = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {27, 29, 37, 48},
        {32, 33, 39, 50}};
    int n = 4, m = 4;
    int key;
    cin >> key;
   pair<int,int> chahcha =  staircaseSearch(arr, n, m, key);
   cout << chahcha.first <<"," <<  chahcha.second;
    return 0;
}