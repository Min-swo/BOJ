#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int ans, cnt;
    string str;
    getline(cin, str);

    ans = 1;
    for(int i = str.length()-1; i >= 0; i--)
    {
        if(str[i] == 'd')
        {
            ans = ans * 10;
            for(int j = i - 1; str[j] == 'd' && j >= 0; j--)
            {   
                ans = ans * 9;
                i--;
            }
        }
        else
        {
            ans = ans * 26;
            for(int j = i - 1; str[j] == 'c' && j >= 0; j--)
            {   
                ans = ans * 25;
                i--;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}