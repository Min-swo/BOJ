#include <iostream>
using namespace std;

int getGcd(int a, int b)
{
    int r, gcd;
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
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n;
    long long sum;
    int* numbers;
    cin >> t;

    for(int i = 0; i < t; i++)
    {
        sum = 0;
        cin >> n;
        numbers = new int[n];
        for(int j = 0; j < n; j++)
            cin >> numbers[j];
        
        for(int j = 0; j < n - 1; j++)
        {
            for(int k = j + 1; k < n; k++)
            {
                if(numbers[j] < numbers[k])
                    sum = sum + getGcd(numbers[k], numbers[j]);
                else
                    sum = sum + getGcd(numbers[j], numbers[k]);
            }
        }
        cout << sum << "\n";
        delete(numbers);
    }
}