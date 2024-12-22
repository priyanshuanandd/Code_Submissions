#include <iostream>
using namespace std;
int distCheck(int noOfCars, int distDone, int petrol[])
{
    int myGas = petrol[0];
    for (int i = 2; i <= noOfCars; i++)
    {
        int distToOtherCar = i - 1;
        if (myGas > 0)
        {
            distDone++;
            myGas--;
        }
        if (distDone == distToOtherCar)
        {
            myGas += petrol[i-1];
        }
        if (myGas == 0)
        {
            return distDone;
        }
        
    }
    if (myGas > 0)
    {
        distDone += myGas;
    }
    
    return distDone;
}
int main()
{
    int testcases;
    cin >> testcases;
    for (int test = 0; test < testcases; test++)
    {
        int noOfCars;
        cin >> noOfCars;
        int petrol[noOfCars];
        for (int i = 0; i < noOfCars; i++)
        {
            cin >> petrol[i];
        }
        int distDone = 0;

        // LOGIC STARTS
        cout << distCheck(noOfCars, distDone, petrol)<<endl;
    }
    return 0;
}