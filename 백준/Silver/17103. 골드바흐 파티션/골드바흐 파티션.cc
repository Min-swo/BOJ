#include <iostream>
using namespace std;

#define MAX 1000000
int prime[MAX+1];

int goldbah(int k)
{
    int cnt = 0;
    for(int i = 3; i <= k / 2; i += 2)
    {
        if(prime[i] && prime[k - i])
            cnt++;
    }
    if(k == 4)
        return 1;
    return cnt;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n;
    cin >> t;

    prime[1] = 0;
    prime[2] = 1;
    for(int i = 3; i <= MAX; i++)
    {
        prime[i] = 1;
        for(int j = 2; j * j <= i; j++)
        {
            if(i % j == 0)
            {
                prime[i] = 0;
                break;
            }
        }
    }

    for(int i = 0; i < t; i++)
    {
        cin >> n;
        cout << goldbah(n) << "\n";
    }
}