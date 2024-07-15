#include <iostream>
#include <vector>
using namespace std;

int n, s, cnt;
int* seq;

void dfs(int cur, int sum)
{
    if(cur != -1 && sum == s)
    {
        cnt++;
    }

    for(int i = cur+1; i < n; i++)
        dfs(i, sum + seq[i]);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> s;
    cnt = 0;

    seq = new int[n];
    for(int i = 0; i < n; i++)
        cin >> seq[i];
    
    dfs(-1, 0);

    cout << cnt << "\n";

    return 0;
}