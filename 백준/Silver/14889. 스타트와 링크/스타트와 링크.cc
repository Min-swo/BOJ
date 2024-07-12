#include <iostream>
#include <vector>
using namespace std;

int n;
int** stat;
int minVal = 100 * 20 * 20;
int* member;

int getMin(int a, int b)
{
    if(a < b)
        return a;
    return b;
}

int getSumDiff(int* memeber)
{
    int sum1 = 0;
    int sum2 = 0;
    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(member[i] && member[j])
                sum1 += (stat[i][j] + stat[j][i]);
            else if(!member[i] && !member[j])
                sum2 += (stat[i][j] + stat[j][i]);
        }
    }

    if(sum1 > sum2)
        return sum1 - sum2;
    return sum2 - sum1;
}

void dfs(int depth, int* memeber, int num)
{
    if(depth == n/2)
    {   
        minVal = getMin(minVal, getSumDiff(member));
        return;
    }

    for(int i = num; i < n; i++)
    {
        member[i] = 1;
        dfs(depth+1, member, i+1);
        member[i] = 0;
    }
    
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    stat = new int*[n];
    for(int i = 0; i < n; i++)
        stat[i] = new int[n];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cin >> stat[i][j];
    }

    member = new int[n];
    dfs(0, member, 0);
    cout << minVal << "\n";

    return 0;
}