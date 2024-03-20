#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int getGcd(int a, int b)
{
    int tmp;
    if(a < b)
    {
        tmp = a;
        a = b;
        b = tmp;
    }

    int gcd, r;
    while(1)
    {
        r = a % b;
        if(r == 0)
        {
            gcd = b;
            break;
        }
        a = b;
        b = r;
    }
    return gcd;
}

int main(void)
{
    int n, s, gcd;
    cin >> n >> s;

    int* b = new int[n];
    for(int i = 0; i < n; i++)
        cin >> b[i];
    sort(b, b + n);

    int* dS = new int[n];
    for(int i = 0; i < n; i++)
        dS[i] = abs(s - b[i]);
    sort(dS, dS+n);

    if(n == 1)
    {
        cout << dS[0] << "\n";
        return 0;
    }

    int* dB = new int[n-1];
    for(int i = 0; i < n-1; i++)
        dB[i] = b[i+1] - b[i];

    for(int i = 1; i < n - 1; i++)
    {
        if(i == 1)
            gcd = getGcd(dB[i - 1], dB[i]);
        else
            gcd = getGcd(gcd, dB[i]);
    }
    
    int* ans = new int[n];
    for(int i = 0; i < n; i++)
        ans[i] = getGcd(dS[i], gcd);
    sort(ans, ans+n);

    cout << ans[n-1] << "\n";
    return 0;
}