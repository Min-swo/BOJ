#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k;
    cin >> k;
    string ans;
    
    if(k == 0)
        ans = "0";
    while(k != 0)
    {
        if(k % -2 == 0)
        {
            ans = "0" + ans;
            k = k / -2;
        }
        else
        {
            ans = "1" + ans;
            k = (k - 1) / -2;
        }
    }
    cout << ans << "\n";
}