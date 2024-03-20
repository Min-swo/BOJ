#include <iostream>
using namespace std;

#define MAX 1001

int main(void)
{
    int n;
    cin >> n;

    int method[MAX];
    method[1] = 1;
    method[2] = 2;

    for(int i = 3; i <= n; i++)
       method[i] = (method[i-1] + method[i-2]) % 10007;
    cout << method[n] << "\n";
}