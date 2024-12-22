#include <iostream>
using namespace std;

int main()
{
    char direction;
    int x = 0, y = 0;
    direction = cin.get();
    while (direction != '\n')
    {

        if (direction == 'E')
        {
            x++;
        }
        else if (direction == 'N')
        {
            y++;
        }
        else if (direction == 'W')
        {
            x--;
        }
        else
        {
            y--;
        }
        direction = cin.get();
    }
    cout << x << ";" << y << endl;

    if (x >= 0)
    {
        while (x--)
        {
            cout << "E";
        } /* code */
    }
    else
    {
        while (x++)
        {
            cout << "W";
        }
    }
    cout << endl;
    if (y >= 0)
    {
        while (y--)
        {
            cout << "N";
        } /* code */
    }
    else
    {
        while (y++)
        {
            cout << "S";
        }
    }
    cout << endl;

    return 0;
}