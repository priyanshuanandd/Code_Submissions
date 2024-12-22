#include <iostream>
using namespace std;

int main()
{
    int count;
    cin >> count;

    for (size_t i = 0; i < count; i++)
    {
        int n, space,container = 0;
        cin >> n >> space;
        while (n--)
        {
            int size, imdb;
            cin >> size >> imdb;
            if (size <= space)
            {
                if (container < imdb)
                {
                    container = imdb;
                }
            }
            
        }
        cout << container << endl;
    }

    return 0;
}