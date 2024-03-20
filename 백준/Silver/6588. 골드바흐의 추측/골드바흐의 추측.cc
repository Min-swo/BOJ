#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define N 1000000

int primeNumbers[N+1];

int isOdd(int k)
{
    if(k % 2 == 0)
        return 0;
    return 1;
}

int isPrime(int k)
{
    if(k == 1)
        return 0;

    for(int i = 2; i * i <= k; i++)
    {
        if(k % i == 0)
            return 0;
    }
    return 1;
}

void getPrimeNumbers(int k)
{
    for(int i = 1; i <= k; i++)
    {
        if(isPrime(i))
            primeNumbers[i] = 1;
        else
            primeNumbers[i] = 0;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, k;
    getPrimeNumbers(N);
    while(1)
    {
        cin >> n;
        if(n == 0)
            break;

        k = -1;
        for(int i = n - 1; i > 0; i = i - 2)
        {
            if(primeNumbers[i] && primeNumbers[n - i])
            {
                k = n - i;
                break;
            }
        }

        if(k == -1)
            cout << "Goldbach's conjecture is wrong.\n";
        else
            cout << n << " = " << k << " + " << n - k << "\n"; 
    }
}