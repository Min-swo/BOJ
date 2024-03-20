#include <iostream>
using namespace std;

long long int countTwo(long long int k)
{
    long long int cnt = 0;
    for(long long int i = 2; i <= k; i*=2)
        cnt = cnt + k / i;
    return cnt;
}

long long int countFive(long long int k)
{
    long long int cnt = 0;
    for(long long int i = 5; i <= k; i*=5)
        cnt = cnt + k / i;
    return cnt;
}

int main(void)
{
    long long int n, m;
    cin >> n >> m;

    long long int cntTwo = countTwo(n) - countTwo(m) - countTwo(n-m);
    long long int cntFive = countFive(n) - countFive(m) - countFive(n-m);

    if(cntTwo < cntFive)
        cout << cntTwo << "\n";
    else
        cout << cntFive << "\n";
    return 0;
}