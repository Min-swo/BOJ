#include <iostream>
using namespace std;

int main(void)
{
    int t, n;
    cin >> t;
    
    int cnt[11];
    cnt[1] = 1;
    cnt[2] = 2;
    cnt[3] = cnt[1] + cnt[2] + 1;
    for(int i = 4; i < 11; i++)
        cnt[i] = 0;

    for(int i = 0; i < t; i++)
    {
        cin >> n;
        for(int j = 4; j <= n; j++)
        {   
            if(!cnt[j])
                cnt[j] = cnt[j-1] + cnt[j-2] + cnt[j-3];
        }
        cout << cnt[n] << "\n";
    }

}