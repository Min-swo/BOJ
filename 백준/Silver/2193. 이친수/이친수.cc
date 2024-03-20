#include <iostream>
using namespace std;

#define MAX 91

long long count[MAX][2];

int main(void)
{
    int n;
    cin >> n;

    for(int i = 0; i < MAX; i++)
    {
        for(int j = 0; j < 2; j++)
            count[i][j] = 0;
    }

    count[1][1] = 1;
    for(int i = 2; i < MAX; i++)
    {
        count[i][0] = count[i-1][0] + count[i-1][1];
        count[i][1] = count[i-1][0];
    }

    cout << count[n][0] + count[n][1] << "\n";
}