#include <iostream>
using namespace std;

#define MAX 31
int tile[MAX];

int main(void)
{
    int n, sum;
    cin >> n;

    for(int i = 1; i <= n; i = i + 2)
        tile[i] = 0;
    tile[2] = 3;
    tile[4] = 11;

    for(int i = 6; i <= n; i = i + 2)
    {
        sum = 0;
        sum = sum + tile[i-2] * 3;
        for(int j = i-4; j >= 2; j= j - 2)
            sum = sum + tile[j] * 2;
        sum = sum + 2;
        tile[i] = sum;
    }
    cout << tile[n] << "\n";
    return 0;
}