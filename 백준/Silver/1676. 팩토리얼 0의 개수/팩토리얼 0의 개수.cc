#include <iostream>
using namespace std;

int cntTwo = 0;
int cntFive = 0;

void cntTwoFive(int n)
{
    while(1)
    {
        if(n % 2 != 0)
            break;
        n = n / 2;
        cntTwo++;   
    }
    while(1)
    {
        if(n % 5 != 0)
            break;
        n = n / 5;
        cntFive++;   
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++)
        cntTwoFive(i);

    if(cntTwo < cntFive)
        cout << cntTwo << "\n";
    else
        cout << cntFive << "\n";\

    return 0;
}