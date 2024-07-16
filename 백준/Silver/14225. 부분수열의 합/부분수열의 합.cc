#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

#define MAX 2000000

int n;
int* seq;
bool arr[MAX];

void dfs(int cur, int sum)
{
    if(sum > 0)
        arr[sum] = true;

    for(int i = cur+1; i < n; i++)
        dfs(i, sum + seq[i]);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    seq = new int[n];
    for(int i = 0; i < n; i++)
        cin >> seq[i];

    for(int i = 0; i < MAX; i++)
        arr[i] = false;

    dfs(-1, 0);

    for(int i = 1; i < MAX; i++)
    {
        if(arr[i] == false)
        {
            cout << i << "\n";
            break;
        }
    }

    return 0;
}