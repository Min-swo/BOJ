#include <iostream>
using namespace std;

#define MAX 1001

int num[MAX];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, ans;
    cin >> n;

    for(int i = 1; i < MAX; i++)
        num[i] = 0;
    
    for(int i = 0; i <= n; i++)
    {
        for(int v = 0; v <= n; v++)
        {
            for(int x = 0; x <= n; x++)
            {
                for(int l = 0; l <= n; l++)
                {
                    if(i + v + x + l == n)
                        num[i + 5 * v + 10 * x + 50 * l] = 1;
                }
            }
        }
    }

    ans = 0;
    for(int i = 1; i < MAX; i++)
    {
        if(num[i])
            ans++;
    }

    cout << ans << "\n";
    return 0;
}