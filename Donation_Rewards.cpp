#include <iostream>
using namespace std;
void BloodDonation(int n)
{
    if(n<=3)
    {
        cout<<"BRONZE" << endl;
    }
    else if(n>3 && n<=6)
    {
        cout<<"SILVER" << endl;
    }
    else{
        cout<<"GOLD" << endl;
    }
}
int main() {
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        BloodDonation(n);
    }

    return 0;
}