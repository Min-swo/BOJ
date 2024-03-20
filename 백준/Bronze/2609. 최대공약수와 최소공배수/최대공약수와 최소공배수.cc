#include <iostream>
using namespace std;

int getGcd(int m, int n)
{
    int large, small, mod, gcd;
    if(m > n)
    {
        large = m;
        small = n;
    }
    else
    {
        large = n;
        small = m;
    }
    
    while(1)
    {
        mod = large % small;
        if(mod == 0)
        {
            gcd = small;
            break;
        }
        else
        {
            large = small;
            small = mod;
        }
    }
    return gcd;
}

int main(void)
{
    int m, n;
    cin >> m >> n;

    int gcd = getGcd(m, n);
    int lcm = m * n / gcd;

    cout << gcd << "\n" << lcm << "\n";
}