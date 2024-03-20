#include <iostream>
using namespace std;

#define MAX 100001
#define DIV 1000000009

long long cnt[MAX][4];

int main(void)
{
    int t, n;
    cin >> t;

    for(int i = 0; i < MAX; i++)
    {
        for(int j = 0; j < 4; j++)
            cnt[i][j] = 0;
    }
    cnt[1][1] = 1;
    
    cnt[2][2] = 1;

    cnt[3][1] = 1;
    cnt[3][2] = 1;
    cnt[3][3] = 1;

    for(int i = 4; i < MAX; i++)
    {
        cnt[i][1] = (cnt[i-1][2] + cnt[i-1][3]) % DIV;
        cnt[i][2] = (cnt[i-2][1] + cnt[i-2][3]) % DIV;
        cnt[i][3] = (cnt[i-3][1] + cnt[i-3][2]) % DIV;
    }

    for(int i = 0; i < t; i++)
    {
        cin >> n;
        cout << (cnt[n][1] + cnt[n][2] + cnt[n][3]) % DIV << "\n";
    }
    return 0;
}