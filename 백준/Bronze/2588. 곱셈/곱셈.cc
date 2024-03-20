#include <iostream>
using namespace std;

int main(void)
{
    int a, b;
    cin >> a >> b;
    
    int res1, res2, res3, res;
    res1 = a * (b%10);
    res2 = a * ((b/10)%10);
    res3 = a * (b/100);
    res = a * b;
    
    cout << res1 << "\n" << res2 << "\n" << res3 << "\n" << res;
}