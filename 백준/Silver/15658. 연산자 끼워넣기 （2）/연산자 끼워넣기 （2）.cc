#include <iostream>
using namespace std;

int n;
int maxVal = -1000000000;
int minVal = 1000000000;
int* seq;
int op[4];


void dfs(int cur, int result, int plus, int minus, int multi, int div)
{
    if(cur == n)
    {
        maxVal = max(maxVal, result);
        minVal = min(minVal, result);
        return;
    }

    if(plus > 0)
        dfs(cur+1, result+seq[cur], plus-1, minus, multi, div);
    if(minus > 0)
        dfs(cur+1, result-seq[cur], plus, minus-1, multi, div);
    if(multi > 0)
        dfs(cur+1, result*seq[cur], plus, minus, multi-1, div);
    if(div > 0)
        dfs(cur+1, result/seq[cur], plus, minus, multi, div-1);
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

    for(int i = 0; i < 4; i++)
        cin >> op[i];

    int result = seq[0];
    dfs(1, result, op[0], op[1], op[2], op[3]);

    cout << maxVal << "\n" << minVal << "\n";

    return 0;
}