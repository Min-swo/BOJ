#include <iostream>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, c, x, y, ans;
    cin >> a >> b >> c >> x >> y;

    if(a + b > 2 * c)
    {
        if(x < y)
        {
            if(b > 2 * c)
                ans = y * 2 * c;
            else
                ans = x * c * 2 + (y - x) * b;
        }
        else
        {
            if(a > 2 * c)
                ans = x * 2 * c;
            else
                ans = y * c * 2 + (x - y) * a;
        }
            
    }
    else
    {
        ans = x * a + y * b;
    }
    cout << ans << "\n";
    return 0;
}