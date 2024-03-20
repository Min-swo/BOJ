#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string oct;
    getline(cin, oct);

    int tmp;
    vector<int> ans;
    for(int i = 0; i < oct.length(); i++)
    {
        tmp = oct[i]-'0';
        ans.push_back(tmp / 4);
        tmp = tmp % 4;
        ans.push_back(tmp / 2);
        tmp = tmp % 2;
        ans.push_back(tmp);
    }

    int sig = 0;
    for(int i = 0; i < ans.size(); i++)
    {
        if(sig || ans[i] != 0)
        {
            sig = 1;
            cout << ans[i];
        }
    }
    if(!sig)
        cout << 0;
    cout << "\n";
    return 0;
}