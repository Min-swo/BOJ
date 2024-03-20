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
    int k, m, n;
    int gcd, lcm;
    cin >> k;
    for(int i = 0; i < k; i++)
    {
        cin >> m >> n;
        gcd = getGcd(m, n);
        lcm = m * n / gcd;
        cout << lcm << "\n";
    }
    return 0;
}