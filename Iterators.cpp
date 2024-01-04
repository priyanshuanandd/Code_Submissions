#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v = {1,2,3,5};
    //template iterator ka


    vector<int> ::iterator it = v.begin();
    //accessing the iterator container...this container stores the address to the first element of the vector
    cout << *it <<endl;
    //accessing 2nd element
    cout<< *(it+1) << endl;
    
    cout << "new line " << endl;
    for(; it < v.end(); it++)
    {
        cout << *it<< "," ;
    }
    
    return 0;
}