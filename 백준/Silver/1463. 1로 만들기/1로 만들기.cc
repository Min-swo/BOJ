#include <iostream>
using namespace std;

#define MAX 1000001

int main(void)
{
    int n;
    cin >> n;

    int cnt[MAX];
    for(int i = 0; i < MAX; i++)
        cnt[i] = 0;

    cnt[1] = 0;
    for(int i = 2; i < n+1; i++)
    {
        if(!cnt[i])
        {
            if(i % 3 == 0 && i % 2 == 0)
            {
                if(cnt[i/3] < cnt[i/2])
                {
                    if(cnt[i/3] < cnt[i-1])
                        cnt[i] = cnt[i/3] + 1;
                    else
                        cnt[i] = cnt[i-1] + 1;
                }
                else
                {
                    if(cnt[i/2] < cnt[i-1])
                        cnt[i] = cnt[i/2] + 1;
                    else
                        cnt[i] = cnt[i-1] + 1;
                }
            }
            else if(i % 3 == 0)
            {
                if(cnt[i/3] < cnt[i-1])
                        cnt[i] = cnt[i/3] + 1;
                else
                    cnt[i] = cnt[i-1] + 1;
            }
            else if(i % 2 == 0)
            {
                if(cnt[i/2] < cnt[i-1])
                        cnt[i] = cnt[i/2] + 1;
                else
                    cnt[i] = cnt[i-1] + 1;
            }
            else
                cnt[i] = cnt[i-1] + 1;
        }
    }
    cout << cnt[n] << "\n";
}