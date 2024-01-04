#include <iostream>
using namespace std;

void spiralprint(int arr[100][100], int n, int m)
{
    
    int startRow = 0;
    int endRow = n - 1;
    int startCol = 0;
    int endCol = m - 1;
    while (startCol <= endCol and startRow <= endRow)
    {
        // column iteration L-R
        for (int i = startCol; i <= endCol; i++)
        {
            cout << arr[startRow][i] << " ";
        }
        
        // Row iteration top top bottom
        for (int i = startRow + 1; i <= endRow; i++)
        {
            cout << arr[i][endCol] << " ";
        }
        //for preventing a double print for a row matrix..read below for more info
        if (startRow == endRow)
        {
            break;
        }
        
        // column iteration R -L
        for (int i = endCol - 1; i >= startCol; i--)
        {
            cout << arr[endRow][i] << " ";
        }

        //for preventing a case when the spiral goes to column matrix and it prints itself twice read the subsequent comment for more info
        if (startCol == endCol)
        {
            break;
        }
        
        // row iteration bottom to top
        for (int i = endRow - 1; i > startRow ; i--)
        {
            cout << arr[i][startCol] << " ";
        }
        startRow++;
        startCol++;
        endCol--;
        endRow--;
    }
    // last thing which is left is to think about the iteration when rows and columns are unequal and in that case at last a row or column matrix would be left and if we go through the current loop the row /column would be printed twice
    // and this will also be the condition on which the code ends
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

    spiralprint(arr, n, m);
    return 0;
}