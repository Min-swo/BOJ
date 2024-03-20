#include <iostream>
using namespace std;

int main(void)
{
    int hr, min;
    cin >> hr >> min;
    
    if(min >= 45)
        min = min - 45;
    else
    {
        if(hr >= 1)
        {
            hr = hr - 1;
            min = min + 15;
        }
        else
        {
            hr = 23;
            min = min + 15;
        }
    }
    
    cout << hr << " " << min;
    
    
    
    
    
}