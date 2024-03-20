#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(void)
{
    long long int a, b, c, d;
    cin >> a >> b >> c >> d;

    string b_str = to_string(b);
    string d_str = to_string(d);

    long long int m, n;
    m = a * pow(10, b_str.length()) + b;
    n = c * pow(10, d_str.length()) + d;
    
    long long int ans = m + n;
    cout << ans << "\n";
}