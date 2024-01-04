#include <iostream>
#include <array>
using namespace std;
void printArray(array<int,6> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void iUpdateWithoutReference(array<int, 6> arr,int index,int value)
{
 arr[index] = value;       
}
void iUpdateWithReference(array<int, 6> &arr,int index,int value)
{
    arr[index] = value;
}
int main()
{
    array<int, 6> arr = {1, 2, 3, 4, 5, 6};
    int index = 2;
    int value = 10;
    iUpdateWithoutReference(arr,index,value);
     printArray(arr);
    iUpdateWithReference(arr,index,value);
    printArray(arr);
    array<int,6> popo {1,2,3};
    array<int,6> yu;
    yu.fill(value);
    printArray(yu);
    
}