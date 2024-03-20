#include <iostream>
using namespace std;

#define MAX 101
#define DIV 1000000000

long long count[MAX][10];

int main(void)
{
    int n;
    cin >> n;

    for(int i = 0; i < MAX; i++)
    {
        for(int j = 0; j < 10; j++)
            count[i][j] = 0;
    }

    for(int i = 1; i < 10; i++)
        count[1][i] = 1;

    for(int i = 2; i < MAX; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if(j != 9)
                count[i][j+1] = (count[i][j+1] + count[i-1][j]) % DIV;
            if(j != 0)
                count[i][j-1] = (count[i][j-1] + count[i-1][j]) % DIV;
        }
    }
    int sum = 0;
    for(int i = 0; i < 10; i++)
        sum = (sum + count[n][i]) % DIV;
    cout << sum << "\n";
}