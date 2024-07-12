#include <iostream>
using namespace std;

#define PLUS op[0]
#define MINUS op[1]
#define MULTI op[2]
#define DIV op[3]

int n;
int maxVal = -1000000000;
int minVal = 1000000000;
int* seq;

int getMax(int a, int b)
{
    if(a > b)
        return a;
    return b;
}

int getMin(int a, int b)
{
    if(a < b)
        return a;
    return b;
}

void dfs(int depth, int sum, int plus, int minus, int multi, int div)
{
    if(depth == n-1)
    {
        if(plus)
            sum += seq[depth];
        else if(minus)
            sum -= seq[depth];
        else if(multi)
            sum *= seq[depth];
        else
            sum /= seq[depth];

        maxVal = getMax(sum, maxVal);
        minVal = getMin(sum, minVal);

        return;
    }
    
    if(plus)
        dfs(depth+1, sum + seq[depth], plus-1, minus, multi, div);
    if(minus)
        dfs(depth+1, sum - seq[depth], plus, minus-1, multi, div);
    if(multi)
        dfs(depth+1, sum * seq[depth], plus, minus, multi-1, div);
    if(div)
        dfs(depth+1, sum / seq[depth], plus, minus, multi, div-1);
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

    int op[4];
    for(int i = 0; i < 4; i++)
        cin >> op[i];

    int sum = seq[0];
    dfs(1, sum, PLUS, MINUS, MULTI, DIV);

    cout << maxVal << "\n" << minVal << "\n";
    return 0;
}