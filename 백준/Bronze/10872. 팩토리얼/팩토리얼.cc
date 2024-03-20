#include <iostream>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int fac = 1;
    for(int i = 1; i <= n; i++)
        fac = fac * i;
    
    cout << fac << "\n";
}